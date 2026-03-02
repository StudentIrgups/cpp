#include "exception.h"

badFigure::badFigure(std::string str) {
    __error = str;
}

std::string badFigure::what() {
    return "Ошибка создания фигуры. Причина: " + __error;
}

