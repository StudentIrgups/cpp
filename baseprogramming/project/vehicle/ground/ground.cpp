#include "ground.h"

ground::ground(int type) {
    if (type == 1) {
        name = "Верблюд";
    }
    if (type == 2) {
        name = "Верблюд-быстроход";
    }
    if (type == 3) {
        name = "Кентавр";
    }
    if (type == 4) {
        name = "Сапоги вездеходы";
    }

}