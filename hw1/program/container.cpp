//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container& c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container& c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container& c, FILE* file) {
    int k;
    while (fscanf(file, "%d", &k) != EOF) {
        if ((c.cont[c.len] = In(file, k)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container& c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container& c, FILE* file) {
    fprintf(file, "Container contains %d elements.\n", c.len);
    for (int i = 0; i < c.len; i++) {
        fprintf(file, "%d: ", i + 1);
        Out(*(c.cont[i]), file);
    }
}

//------------------------------------------------------------------------------
// Вывод обработки данных контейнера
void ProcessingVar21(container& c, FILE* file) {
    double sum = 0.0;
    for (int i = 0; i < c.len; i++) {
       sum += SurfaceArea(*(c.cont[i]));
    }
    double mean = sum / c.len;
    fprintf(file, "Arithmetic mean: %f\n", mean);

    int k = 0;
    fprintf(file, "Surface areas processed:\n");
    for (int i = 0; i < c.len; i++) {
        if (SurfaceArea(*(c.cont[i])) >= mean) {
            k++;
            fprintf(file, "%d. ", k);
            Out(*(c.cont[i]), file);
            //fprintf(file, "%d. %f   ", SurfaceArea(*(c.cont[i])));
        }
    }

}
