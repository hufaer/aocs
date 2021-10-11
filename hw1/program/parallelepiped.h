#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

// параллелепипед
struct parallelepiped {
    int a, b, c; // ребра
};

// Ввод параметров параллелепипеда из файла
void In(parallelepiped& p, FILE* file);

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped& p);

// Вывод параметров параллелепипеда в форматируемый поток
void Out(parallelepiped& p, FILE* file);

// Вычисление площади поверхности параллелепипеда
double SurfaceArea(parallelepiped& p);

#endif //__parallelepiped__
