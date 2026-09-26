#pragma once

#include <Wt/Dbo/Dbo.h>
#include <string>

class stock;

class shop {
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<stock>> stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "id_shop");
    }
};