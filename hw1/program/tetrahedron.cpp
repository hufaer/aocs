//------------------------------------------------------------------------------
// tetrahedron.cpp - содержит процедуры для работы с правильным тетраэдром
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// Ввод параметров тетраэдра из файла
void In(tetrahedron& t, FILE* file) {
    fscanf(file, "%d", &t.a);
}

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron& t) {
    t.a = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров тетраэдра в файл
void Out(tetrahedron& t, FILE* file) {
    fprintf(file, "It is Regular Tetrahedron. Edge length: a = %d. Surface area = %f. Material dencity: ",
        t.a, SurfaceArea(t));
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности тетраэдра
double SurfaceArea(tetrahedron& t) {
    return double(sqrt(3) * t.a * t.a);
}
