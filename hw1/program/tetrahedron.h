#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание правильного тетраэдра
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

// правильный тетраэдр
struct tetrahedron {
    int a; // ребро
};

// Ввод параметров тетраэдра из файла
void In(tetrahedron& t, FILE* file);

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron& t);

// Вывод параметров тетраэдра в форматируемый поток
void Out(tetrahedron& t, FILE* file);

// Вычисление площади поверхности тетраэдра
double SurfaceArea(tetrahedron& t);

#endif //__tetrahedron__
