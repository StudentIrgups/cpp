#pragma once

#include <Wt/Dbo/Dbo.h>
#include <string>

class book;

class publisher {
public:
    std::string name;

    Wt::Dbo::collection<Wt::Dbo::ptr<book>> books;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "id_publisher");
    }
};