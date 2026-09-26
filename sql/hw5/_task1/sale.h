#pragma once

#include <Wt/Dbo/Dbo.h>
#include <string>

class stock;

class sale {
public:
    int price = 0;
    std::string date_sale;
    int count = 0;

    Wt::Dbo::ptr<stock> stock_;          

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, price,     "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::field(a, count,     "count");
        Wt::Dbo::belongsTo(a, stock_, "id_stock");
    }
};