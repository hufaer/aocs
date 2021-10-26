#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - �������� �������� ���������������
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// ��������������
class Parallelepiped : public Shape {
public:
    virtual ~Parallelepiped() {}
    // ���� ���������� ��������������� �� �����
    virtual void In(FILE* file);
    // ��������� ���� ���������� ���������������
    virtual void InRnd();
    // ����� ���������� ��������������� � ������������� �����
    virtual void Out(FILE* file);
    // ���������� ������� ����������� ���������������
    virtual double SurfaceArea();

private:
    int a, b, c; // �����
};

#endif //__parallelepiped__