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
#define ChooseAction "Выберите действие: "
#define Distance "Расстояние: "
#define NoAction "Нет такого действия. Прощайте."
#define dRegistrationStop "0. Закончить регистрацию"
#define ChooseVehicleOrZeroToStop "Выберите транспорт или 0 для окончания процесса регстирации:" 
#define RegisteredVehicles "Зарегистрированные транспортные средства: "