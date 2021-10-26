#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

//------------------------------------------------------------------------------
// класс, обобщающий все имеющиеся фигуры
class Shape {
protected:
    static Random rnd20;
    static Random rnd3;
    static Random rnd100000;
    double materialDencity;

public:
    virtual ~Shape() {};
    // Ввод обобщенной фигуры
    static Shape* StaticIn(FILE* file, int k);
    virtual void In(FILE* file) = 0;
    // Случайный ввод обобщенной фигуры
    static Shape* StaticInRnd();
    virtual void InRnd() = 0;
    // Вывод обобщенной фигуры
    virtual void Out(FILE* file) = 0;
    // Вычисление площади поверхности обобщенной фигуры
    virtual double SurfaceArea() = 0;
};

#endif
