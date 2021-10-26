#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - содержит описание сферы
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// сфера
class Sphere : public Shape {
public:
    virtual ~Sphere() {}
    // Ввод параметров сферы из файла
    virtual void In(FILE* file);
    // Случайный ввод параметров сферы
    virtual void InRnd();
    // Вывод параметров сферы в форматируемый поток
    virtual void Out(FILE* file);
    // Вычисление площади поверхности сферы 
    virtual double SurfaceArea();

private:
    int r; // радиус
};

#endif //__sphere__
