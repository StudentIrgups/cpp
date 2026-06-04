//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <iostream>
#include "my_list.hpp"

//юнит-тест
TEST_CASE( "Test of list 1", "[list]" ) {
    List myList;
    myList.PushBack(345);
    myList.PushBack(45632456);
    myList.PushFront(36544);
    
    SECTION("PushPopBack") {
        myList.PushBack(334);
        CHECK( myList.PopBack() == 334 );
        //CHECK( myList.PopBack() == 334 );
    }
    SECTION("PushPopFron") {
        myList.PushFront(335);
        CHECK( myList.PopFront() == 335 );
        //CHECK( myList.PopFront() == 335 );
    }
    SECTION("Throws") {        
        REQUIRE_THROWS([&]() { 
            myList.PopBack(); 
            myList.PopBack(); 
            myList.PopBack();             
            myList.PopBack();  
        }() );
    }
}

int main() {
    return Catch::Session().run();
}