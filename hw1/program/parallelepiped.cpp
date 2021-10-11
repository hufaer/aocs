//------------------------------------------------------------------------------
// parallelepiped.cpp - содержит процедуры для работы с параллелепипедом
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "stdio.h"
#include "math.h"
#include "parallelepiped.h"

//------------------------------------------------------------------------------
// Ввод параметров параллелепипеда из файла
void In(parallelepiped& p, FILE* file) {
    fscanf(file, "%d", &p.a);
    fscanf(file, "%d", &p.b);
    fscanf(file, "%d", &p.c);
}

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped& p) {
    p.a = Random();
    p.b = Random();
    p.c = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров параллелепипеда в файл
void Out(parallelepiped& p, FILE* file) {
    fprintf(file, "It is Parallelepiped. First edge: a = %d. Second edge: b = %d. Third edge: c = %d. Surface area = %f. Material dencity: ",
        p.a, p.b, p.c, SurfaceArea(p));
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности параллелепипеда
double SurfaceArea(parallelepiped& p) {
    return double(2 * (p.a * p.b + p.b * p.c + p.a * p.c));
}
