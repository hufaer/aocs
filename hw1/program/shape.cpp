//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "shape.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape* In(FILE* file, int k) {
    shape* sp;
    double materialDensity;
    fscanf(file, "%lf", &materialDensity);
    switch (k) {
    case 1:
        sp = new shape;
        sp->k = shape::PARALLELEPIPED;
        sp->materialDensity = materialDensity;
        In(sp->p, file);
        return sp;
    case 2:
        sp = new shape;
        sp->k = shape::SPHERE;
        sp->materialDensity = materialDensity;
        In(sp->s, file);
        return sp;
    case 3:
        sp = new shape;
        sp->k = shape::TETRAHEDRON;
        sp->materialDensity = materialDensity;
        In(sp->t, file);
        return sp;
    default:
        return 0;
    }
}


// Случайный ввод обобщенной фигуры
shape* InRnd() {
    shape* sp;
    auto k = rand() % 3 + 1;
    double materialDensity = (double)rand() / RAND_MAX * (10000 - 1) + 1;
    switch (k) {
    case 1:
        sp = new shape;
        sp->k = shape::PARALLELEPIPED;
        sp->materialDensity = materialDensity;
        InRnd(sp->p);
        return sp;
    case 2:
        sp = new shape;
        sp->k = shape::SPHERE;
        sp->materialDensity = materialDensity;
        InRnd(sp->s);
        return sp;
    case 3:
        sp = new shape;
        sp->k = shape::TETRAHEDRON;
        sp->materialDensity = materialDensity;
        InRnd(sp->t);
        return sp;
    default:
        return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape& s, FILE* file) {
    switch (s.k) {
    case shape::PARALLELEPIPED:
        Out(s.p, file);
        break;
    case shape::SPHERE:
        Out(s.s, file);
        break;
    case shape::TETRAHEDRON:
        Out(s.t, file);
        break;
    default:
        fprintf(file, "Incorrect figure!");
        return;
    }
    fprintf(file, "%f\n", s.materialDensity);
}


//------------------------------------------------------------------------------
// Вычисление площади поверхности фигуры
double SurfaceArea(shape& s) {
    switch (s.k) {
    case shape::PARALLELEPIPED:
        return SurfaceArea(s.p);
        break;
    case shape::SPHERE:
        return SurfaceArea(s.s);
        break;
    case shape::TETRAHEDRON:
        return SurfaceArea(s.t);
        break;
    default:
        return 0.0;
    }
}
