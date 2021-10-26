//------------------------------------------------------------------------------
// sphere.cpp - содержит процедуры для работы со сферой
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "stdio.h"
#include "math.h"
#include "sphere.h"

//------------------------------------------------------------------------------
// Ввод параметров сферы из потока
void Sphere::In(FILE* file) {
    fscanf(file, "%d", &r);
}

// Случайный ввод параметров сферы
void Sphere::InRnd() {
    r = Shape::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров сферы в поток
void Sphere::Out(FILE* file) {
    fprintf(file, "It is Sphere. Radius: r = %d. Surface area = %f. Material dencity: %lf\n",
        r, SurfaceArea(), materialDencity);
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности сферы
double Sphere::SurfaceArea() {
    return double(4 * M_PI * r * r);;
}