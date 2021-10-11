#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры
//------------------------------------------------------------------------------

#include "stdio.h"
#include "parallelepiped.h"
#include "sphere.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    double materialDensity; // плотность материала
    // значения ключей для каждой из фигур
    enum key { PARALLELEPIPED, SPHERE, TETRAHEDRON };
    key k; // ключи
    // используемые альтернативы
    union { // используем простейшую реализацию
        parallelepiped p;
        sphere s;
        tetrahedron t;
    };
};

// Ввод обобщенной фигуры
shape* In(FILE* file, int k);

// Случайный ввод обобщенной фигуры
shape* InRnd();

// Вывод обобщенной фигуры
void Out(shape& s, FILE* file);

// Вычисление периметра обобщенной фигуры
double SurfaceArea(shape& s);

#endif
