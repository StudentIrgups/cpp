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
    std::string name;
    int param;
};

const svehicle gvehicles[] = {
    { evehicles::camel,           "Верблюд",          1 },
    { evehicles::camelFast,       "Верблюд-скороход", 1 },
    { evehicles::centaur,         "Кентавр",          1 },
    { evehicles::allTerrainBoots, "Сапоги вездеходы", 1 }
};

const svehicle avehicles[] = {
    { evehicles::flyingCarpet, "Ковёр самолёт", 2 },
    { evehicles::eagle,        "Орёл", 2 },
    { evehicles::broom,        "Метла", 2 }
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