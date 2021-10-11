//------------------------------------------------------------------------------
// sphere.cpp - содержит процедуры для работы со сферой
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "sphere.h"

//------------------------------------------------------------------------------
// Ввод параметров сферы из файла
void In(sphere& s, FILE* file) {
    fscanf(file, "%d", &s.r);
}

// Случайный ввод параметров сферы
void InRnd(sphere& s) {
    s.r = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров сферы в файл
void Out(sphere& s, FILE* file) {
    fprintf(file, "It is Sphere. Radius: r = %d. Surface area = %f. Material dencity: ",
        s.r, SurfaceArea(s));
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности сферы
double SurfaceArea(sphere& s) {
    return double(4 * acos(-1.0) * s.r * s.r);
}
