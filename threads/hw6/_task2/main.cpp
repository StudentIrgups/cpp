#include <iostream>
#include <map>
#include <vector>
#include "sql_query_builder.h"

int main() {
    SqlSelectQueryBuilder qb1;
    qb1.AddColumn("name").AddColumn("phone");
    qb1.AddFrom("students");
    qb1.AddWhere("id", "42").AddWhere("name", "John");
    std::cout << "Запрос 1: " << qb1.BuildQuery() << std::endl;

    SqlSelectQueryBuilder qb2;
    qb2.AddColumns({"name", "phone", "email"});
    qb2.AddFrom("students");
    std::cout << "Запрос 2: " << qb2.BuildQuery() << std::endl;

    SqlSelectQueryBuilder qb3;
    qb3.AddColumn("name");
    qb3.AddFrom("students");
    qb3.AddWhere(std::map<std::string, std::string>{
        {"id", "42"},
        {"name", "John"},
        {"age", "20"}
    });
    std::cout << "Запрос 3: " << qb3.BuildQuery() << std::endl;

    SqlSelectQueryBuilder qb4;
    qb4.AddColumn("name")
       .AddColumns({"phone", "email"})
       .AddFrom("students")
       .AddWhere("id", "42")
       .AddWhere(std::map<std::string, std::string>{
           {"name", "John"},
           {"city", "Moscow"}
       });
    std::cout << "Запрос 4: " << qb4.BuildQuery() << std::endl;

    SqlSelectQueryBuilder qb5;
    qb5.AddColumns({"a", "b", "c"});
    std::cout << "Запрос 5: " << qb5.BuildQuery() << std::endl;

    return 0;
}