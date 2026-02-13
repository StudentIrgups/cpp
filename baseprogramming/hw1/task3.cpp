#include <iostream>
struct address {
    std::string city;
    std::string street;
    int house;
    int room;
    int postCode;
};

void structPrint(address &data) {
    std::cout << "Город: " << data.city << std::endl;
    std::cout << "Улица: " << data.street << std::endl;
    std::cout << "Дом: " << data.house << std::endl;
    std::cout << "Квартира: " << data.room << std::endl;
    std::cout << "Индекс: " << data.postCode << std::endl;
    std::cout << std::endl;
}

int main(void) {
    address adr1;
    adr1.city = "Moscow";
    adr1.street = "Pushkina";
    adr1.house = 100;
    adr1.room = 15;
    adr1.postCode = 654789;

    address adr2;
    adr2.city = "Moscow";
    adr2.street = "Lenina";
    adr2.house = 10;
    adr2.room = 17;
    adr2.postCode = 369478;

    structPrint(adr1);
    structPrint(adr2);
    return 0;
}