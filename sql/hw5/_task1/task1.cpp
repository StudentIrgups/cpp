#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

#include <iostream>
#include <string>

#include "publisher.h"
#include "book.h"
#include "shop.h"
#include "stock.h"
#include "sale.h"

int main() {
    try {
        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(
            "host=localhost port=5432 dbname=bookstore "
            "user=postgres password=postgres");

        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));

        session.mapClass<publisher>("publisher");
        session.mapClass<book>     ("book");
        session.mapClass<shop>     ("shop");
        session.mapClass<stock>    ("stock");
        session.mapClass<sale>     ("sale");

        session.createTables();
        std::cout << "[OK] Tables created\n";

        {
            Wt::Dbo::Transaction t(session);

            auto pub = session.add(std::make_unique<publisher>());
            pub.modify()->name = "O'Reilly";

            auto bk = session.add(std::make_unique<book>());
            bk.modify()->title      = "C++ Primer";
            bk.modify()->publisher_ = pub;             

            auto sh = session.add(std::make_unique<shop>());
            sh.modify()->name = "BookStore #1";

            auto st = session.add(std::make_unique<stock>());
            st.modify()->book_ = bk;                    
            st.modify()->shop_ = sh;                    
            st.modify()->count = 10;

            auto sl = session.add(std::make_unique<sale>());
            sl.modify()->stock_    = st;               
            sl.modify()->price     = 1500;
            sl.modify()->date_sale = "2025-01-15";
            sl.modify()->count     = 2;

            t.commit();
            std::cout << "[OK] Data inserted\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}