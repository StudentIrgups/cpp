#pragma once
#include <iostream>

enum class evehicles {
    camel,
    camelFast,
    centaur,
    allTerrainBoots,    
    flyingCarpet,
    eagle,
    broom
};

struct svehicle {
    evehicles vehicle;
    std::string name{""};
    int speed{0};
    int timeMove{0};
};

const svehicle gvehicles[] = {
    { evehicles::camel,           "Верблюд",          10, 30 },
    { evehicles::camelFast,       "Верблюд-скороход", 40, 10 },
    { evehicles::centaur,         "Кентавр",          15, 8 },
    { evehicles::allTerrainBoots, "Сапоги вездеходы", 6, 60 }
};

const svehicle avehicles[] = {
    { evehicles::flyingCarpet, "Ковёр самолёт", 10 },
    { evehicles::eagle,        "Орёл",          8 },
    { evehicles::broom,        "Метла",         20 }
};

enum class actions {
    RegistrationStop = 0,
    Registration = 1,
    StartRace    = 2
};

#define Hello "Добро пожаловать в гоночный симулятор!"
#define TakeTypeOfRace "Выберите тип гонки: "
#define TakeDistance "Укажите длину дистанции(только положительную): "
#define RegistrationSuccess " успешно зарегистрирован."
#define NeedNoLessThenTwoTypesOfVehilces "Должно быть зарегистрировано хотя бы 2 транспортных средства"
#define RegistrationVehicle "1. Зарегистрировать транспорт"
#define StartRaceing "2. Начать гонку"
#define ChooseAction "Выберите действие: "
#define Distance "Расстояние: "
#define NoAction "Нет такого действия. Прощайте."
#define dRegistrationStop "0. Закончить регистрацию"
#define ChooseVehicleOrZeroToStop "Выберите транспорт или 0 для окончания процесса регстирации:" 
#define RegisteredVehicles "Зарегистрированные транспортные средства: "
#define Results "Результаты гонки:"
#define Time "Время: "
#define AnotherRace "1. Провести ещё одну гонку"
#define Exit "2. Выход"
#define NoThisType "Нет такого типа гонки"
#define NoSuchTypeVehicle "Нет такого транспорта\n"