#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - �������� �������� ���������� �������������� ������
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

//------------------------------------------------------------------------------
// �����, ���������� ��� ��������� ������
class Shape {
protected:
    static Random rnd20;
    static Random rnd3;
    static Random rnd10000;
    double materialDencity;

public:
    virtual ~Shape() {};
    // ���� ���������� ������
    static Shape* StaticIn(FILE* file, int k);
    virtual void In(FILE* file) = 0;
    // ��������� ���� ���������� ������
    static Shape* StaticInRnd();
    virtual void InRnd() = 0;
    // ����� ���������� ������
    virtual void Out(FILE* file) = 0;
    // ���������� ������� ����������� ���������� ������
    virtual double SurfaceArea() = 0;
};

#endif
