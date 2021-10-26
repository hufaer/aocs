#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - �������� �������� ����������� ���������
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// ���������� ��������
class Tetrahedron : public Shape {
public:
    virtual ~Tetrahedron() {}
    // ���� ���������� ����������� ��������� �� �����
    virtual void In(FILE* file);
    // ��������� ���� ���������� ����������� ���������
    virtual void InRnd();
    // ����� ���������� ����������� ��������� � ������������� �����
    virtual void Out(FILE* file);
    // ���������� ������� ����������� ����������� ���������
    virtual double SurfaceArea();

private:
    int a; // �����
};

#endif //__tetrahedron__