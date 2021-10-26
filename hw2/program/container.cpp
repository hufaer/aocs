//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{ 0 } { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE* file) {
    int k;
    while (fscanf(file, "%d", &k) != EOF) {
        if ((storage[len] = Shape::StaticIn(file, k)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Shape::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//----------------------------  --------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE* file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i + 1);
        storage[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// Вывод обработки данных контейнера
void Container::ProcessingVar21(FILE* file) {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += storage[i]->SurfaceArea();
    }
    double mean = sum / len;
    fprintf(file, "Arithmetic mean: %f\n", mean);

    int k = 0;
    fprintf(file, "Surface areas processed:\n");
    for (int i = 0; i < len; i++) {
        if (storage[i]->SurfaceArea() >= mean) {
            k++;
            fprintf(file, "%d. ", k);
            storage[i]->Out(file);
            //Out(*(c.cont[i]), file);
            //fprintf(file, "%d. %f   ", SurfaceArea(*(c.cont[i])));
        }
    }
}