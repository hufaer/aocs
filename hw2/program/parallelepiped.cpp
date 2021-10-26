//------------------------------------------------------------------------------
// parallelepiped.cpp - �������� ��������� ��� ������ � ����������������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "parallelepiped.h"

//------------------------------------------------------------------------------
// ���� ���������� ��������������� �� ������
void Parallelepiped::In(FILE* file) {
    fscanf(file, "%d", &a);
    fscanf(file, "%d", &b);
    fscanf(file, "%d", &c);
}

// ��������� ���� ���������� ���������������
void Parallelepiped::InRnd() {
    a = Shape::rnd20.Get();
    b = Shape::rnd20.Get();
    c = Shape::rnd20.Get();
}

//------------------------------------------------------------------------------
// ����� ���������� ��������������� � �����
void Parallelepiped::Out(FILE* file) {
    fprintf(file, "It is Parallelepiped. First edge: a = %d. Second edge: b = %d. Third edge: c = %d. Surface area = %f. Material density: %lf\n",
        a, b, c, SurfaceArea(), materialDencity);
}

//------------------------------------------------------------------------------
// ���������� ������� ����������� ���������������
double Parallelepiped::SurfaceArea() {
    return double(2 * (a * b + b * c + a * c));
}