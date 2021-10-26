//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "parallelepiped.h"
#include "sphere.h"
#include "tetrahedron.h"
//------------------------------------------------------------------------------
Random Shape::rnd20(1, 20);
Random Shape::rnd3(1, 3);
Random Shape::rnd100000(1, 100000);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Shape* Shape::StaticIn(FILE* file, int k) {
    Shape* sp = nullptr;
    double materialDencity;
    fscanf(file, "%lf", &materialDencity);
    switch (k) {
    case 1:
        sp = new Parallelepiped;
        sp->materialDencity = materialDencity;
        break;
    case 2:
        sp = new Sphere;
        sp->materialDencity = materialDencity;
        break;
    case 3:
        sp = new Tetrahedron;
        sp->materialDencity = materialDencity;
        break;
    default:
        return 0;
    }
    sp->In(file);
    return sp;
}

// Случайный ввод обобщенной фигуры
Shape* Shape::StaticInRnd() {
    auto k = Shape::rnd3.Get();
    double materialDencity = (double)Shape::rnd100000.Get() / RAND_MAX * (10000 - 1) + 1;
    Shape* sp = nullptr;
    switch (k) {
    case 1:
        sp = new Parallelepiped;
        sp->materialDencity = materialDencity;
    case 2:
        sp = new Sphere;
        sp->materialDencity = materialDencity;
    case 3:
        sp = new Tetrahedron;
        sp->materialDencity = materialDencity;
    }
    sp->InRnd();
    return sp;
}
