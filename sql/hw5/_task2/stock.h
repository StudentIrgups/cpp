#pragma once

#include <Wt/Dbo/Dbo.h>

class book;
class shop;
class sale;

class stock {
public:
    int count = 0;
    Wt::Dbo::ptr<book> book_;
    Wt::Dbo::ptr<shop> shop_;
    Wt::Dbo::collection<Wt::Dbo::ptr<sale>> sales;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book_, "id_book");
        Wt::Dbo::belongsTo(a, shop_, "id_shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "id_stock");
    }
};