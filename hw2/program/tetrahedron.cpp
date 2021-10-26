//------------------------------------------------------------------------------
// tetrahedron.cpp - содержит процедуры для работы с правильным тетраэдром
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// Ввод параметров правильного тетраэдра из потока
void Tetrahedron::In(FILE* file) {
    fscanf(file, "%d", &a);
}

// Случайный ввод параметров правильного тетраэдра
void Tetrahedron::InRnd() {
    a = Shape::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров правильного тетраэдра в поток
void Tetrahedron::Out(FILE* file) {
    fprintf(file, "It is Regular Tetrahedron. Edge length: a = %d. Surface area = %f. Material dencity: %lf\n",
        a, SurfaceArea(), materialDencity);
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности правильного тетраэдра
double Tetrahedron::SurfaceArea() {
    return double(sqrt(3) * a * a);
}