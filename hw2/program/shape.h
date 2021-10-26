#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

//------------------------------------------------------------------------------
// класс, обобщающий все имеющиес€ фигуры
class Shape {
protected:
    static Random rnd20;
    static Random rnd3;
    static Random rnd10000;
    double materialDencity;

public:
    virtual ~Shape() {};
    // ¬вод обобщенной фигуры
    static Shape* StaticIn(FILE* file, int k);
    virtual void In(FILE* file) = 0;
    // —лучайный ввод обобщенной фигуры
    static Shape* StaticInRnd();
    virtual void InRnd() = 0;
    // ¬ывод обобщенной фигуры
    virtual void Out(FILE* file) = 0;
    // ¬ычисление площади поверхности обобщенной фигуры
    virtual double SurfaceArea() = 0;
};

#endif
