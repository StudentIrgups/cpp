#pragma once

#include <Wt/Dbo/Dbo.h>
#include <string>

class publisher;
class stock;

class book {
public:
    std::string title;
    Wt::Dbo::ptr<publisher> publisher_;
    Wt::Dbo::collection<Wt::Dbo::ptr<stock>> stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher_, "id_publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "id_book");
    }
};