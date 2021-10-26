#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание правильного тетраэдра
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// правильный тетраэдр
class Tetrahedron : public Shape {
public:
    virtual ~Tetrahedron() {}
    // Ввод параметров правильного тетраэдра из файла
    virtual void In(FILE* file);
    // Случайный ввод параметров правильного тетраэдра
    virtual void InRnd();
    // Вывод параметров правильного тетраэдра в форматируемый поток
    virtual void Out(FILE* file);
    // Вычисление площади поверхности правильного тетраэдра
    virtual double SurfaceArea();

private:
    int a; // ребро
};

#endif //__tetrahedron__