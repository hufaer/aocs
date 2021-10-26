//------------------------------------------------------------------------------
// parallelepiped.cpp - содержит процедуры дл€ работы с параллелепипедом
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "parallelepiped.h"

//------------------------------------------------------------------------------
// ¬вод параметров параллелепипеда из потока
void Parallelepiped::In(FILE* file) {
    fscanf(file, "%d", &a);
    fscanf(file, "%d", &b);
    fscanf(file, "%d", &c);
}

// —лучайный ввод параметров параллелепипеда
void Parallelepiped::InRnd() {
    a = Shape::rnd20.Get();
    b = Shape::rnd20.Get();
    c = Shape::rnd20.Get();
}

//------------------------------------------------------------------------------
// ¬ывод параметров параллелепипеда в поток
void Parallelepiped::Out(FILE* file) {
    fprintf(file, "It is Parallelepiped. First edge: a = %d. Second edge: b = %d. Third edge: c = %d. Surface area = %f. Material density: %lf\n",
        a, b, c, SurfaceArea(), materialDencity);
}

//------------------------------------------------------------------------------
// ¬ычисление площади поверхности параллелепипеда
double Parallelepiped::SurfaceArea() {
    return double(2 * (a * b + b * c + a * c));
}