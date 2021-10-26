//------------------------------------------------------------------------------
// tetrahedron.cpp - �������� ��������� ��� ������ � ���������� ����������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// ���� ���������� ����������� ��������� �� ������
void Tetrahedron::In(FILE* file) {
    fscanf(file, "%d", &a);
}

// ��������� ���� ���������� ����������� ���������
void Tetrahedron::InRnd() {
    a = Shape::rnd20.Get();
}

//------------------------------------------------------------------------------
// ����� ���������� ����������� ��������� � �����
void Tetrahedron::Out(FILE* file) {
    fprintf(file, "It is Regular Tetrahedron. Edge length: a = %d. Surface area = %f. Material dencity: %lf\n",
        a, SurfaceArea(), materialDencity);
}

//------------------------------------------------------------------------------
// ���������� ������� ����������� ����������� ���������
double Tetrahedron::SurfaceArea() {
    return double(sqrt(3) * a * a);
}