#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - �������� �������� �����
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// �����
class Sphere : public Shape {
public:
    virtual ~Sphere() {}
    // ���� ���������� ����� �� �����
    virtual void In(FILE* file);
    // ��������� ���� ���������� �����
    virtual void InRnd();
    // ����� ���������� ����� � ������������� �����
    virtual void Out(FILE* file);
    // ���������� ������� ����������� ����� 
    virtual double SurfaceArea();

private:
    int r; // ������
};

#endif //__sphere__