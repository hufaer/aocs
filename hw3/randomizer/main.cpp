#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "stdio.h"

// Файл для записи сгенерированных входных данных.
FILE* file_;
// запись данных для параллелепипеда, сферы, правильного тетраэдра
void writeParallelepipedData();
void writeSphereData();
void writeTetrahedronData();
// случайное число в пределах заданного диапазона.
int getRandomNumber(int min, int max);

int main(int argc, char* argv[]) {
if (argc != 3) {
printf("first argument must be the number of figures or 'r' - random number, and the second must be full path of file to write the result in");
return 1;
}

int size;
srand(static_cast<unsigned int>(time(0)));
if (!strcmp(argv[1], "r")) {
size = getRandomNumber(1, 10000);
}
else {
size = atoi(argv[1]);
if (size < 1 || size > 10000) {
printf("number of figures must be positive and no more than 10000");
return 2;
}
}
file_ = fopen(argv[2], "w");

int figure;
for (int fig = 0; fig < size; ++fig) {
figure = getRandomNumber(1, 3);
fprintf(file_, "%d %lf ", figure, (double)getRandomNumber(1, 100000) / RAND_MAX * (10000 - 1) + 1);
switch (figure) {
case 1:
writeParallelepipedData();
break;
case 2:
writeSphereData();
break;
case 3:
writeTetrahedronData();
break;
}
}

return 0;
}

// Запись корректных длин ребер параллелепипеда
void writeParallelepipedData() {
int a, b, c;
a = getRandomNumber(1, 100);
b = getRandomNumber(1, 100);
c = getRandomNumber(1, 100);

fprintf(file_, "%d %d %d ", a, b, c);
}

// Запись корректной длины ребра правильного тетраэдра
void writeTetrahedronData() {
int a;
a = getRandomNumber(1, 100);
fprintf(file_, "%d ", a);
}

// Запись корректного радиуса сферы
void writeSphereData() {
int r;
r = getRandomNumber(1, 100);
fprintf(file_, "%d ", r);
}

// получение случайного числа от min до max включительно
int getRandomNumber(int min, int max) {
return rand() % (max - min + 1) + min;
}
