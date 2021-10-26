//------------------------------------------------------------------------------
// sphere.cpp - �������� ��������� ��� ������ �� ������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "stdio.h"
#include "math.h"
#include "sphere.h"

//------------------------------------------------------------------------------
// ���� ���������� ����� �� ������
void Sphere::In(FILE* file) {
    fscanf(file, "%d", &r);
}

// ��������� ���� ���������� �����
void Sphere::InRnd() {
    r = Shape::rnd20.Get();
}

//------------------------------------------------------------------------------
// ����� ���������� ����� � �����
void Sphere::Out(FILE* file) {
    fprintf(file, "It is Sphere. Radius: r = %d. Surface area = %f. Material dencity: %lf\n",
        r, SurfaceArea(), materialDencity);
}

//------------------------------------------------------------------------------
// ���������� ������� ����������� �����
double Sphere::SurfaceArea() {
    return double(4 * M_PI * r * r);;
}