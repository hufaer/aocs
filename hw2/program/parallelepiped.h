#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// параллелепипед
class Parallelepiped : public Shape {
public:
    virtual ~Parallelepiped() {}
    // Ввод параметров параллелепипеда из файла
    virtual void In(FILE* file);
    // Случайный ввод параметров параллелепипеда
    virtual void InRnd();
    // Вывод параметров параллелепипеда в форматируемый поток
    virtual void Out(FILE* file);
    // Вычисление площади поверхности параллелепипеда
    virtual double SurfaceArea();

private:
    int a, b, c; // ребра
};

#endif //__parallelepiped__
