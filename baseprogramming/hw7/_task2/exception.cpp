#include "exception.h"

const char* what() noexcept {
    return "Ошибка создания фигуры. Причина: ";
}