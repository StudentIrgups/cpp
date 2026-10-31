#include <iostream>
#include "sql_query_builder.h"

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::string query = query_builder.BuildQuery();
    std::cout << "Запрос 1: " << query << std::endl;

    SqlSelectQueryBuilder qb2;
    qb2.AddFrom("students");
    std::cout << "Запрос 2: " << qb2.BuildQuery() << std::endl;

    SqlSelectQueryBuilder qb3;
    qb3.AddWhere("id", "42")
       .AddFrom("students")
       .AddColumn("name");
    std::cout << "Запрос 3: " << qb3.BuildQuery() << std::endl;

    SqlSelectQueryBuilder qb4;
    qb4.AddFrom("first")
       .AddFrom("second");
    std::cout << "Запрос 4: " << qb4.BuildQuery() << std::endl;

    return 0;
}