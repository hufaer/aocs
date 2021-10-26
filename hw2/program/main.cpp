//------------------------------------------------------------------------------
// main.cpp - �������� ������� �������, 
// �������������� ������� ������������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime>   // ��� ������� time()  
#include <cstring>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\nWaited:\ncommand -f infile outfile01 outfile02\n"
        "Or:\ncommand -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\nWaited:\ncommand -f infile outfile01 outfile02\n"
        "Or:\ncommand -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start");
    Container c;

    if (!strcmp(argv[1], "-f")) {
        FILE* file;
        file = fopen(argv[2], "r");
        c.In(file);
    }
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
        // ��������� ���� � �������� ��������������
        srand(static_cast<unsigned int>(time(0)));
        // ���������� ���������� ����������� ��������� �����
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // ����� ����������� ���������� � ����
    FILE* file1;
    file1 = fopen(argv[3], "w");
    fprintf(file1, "Filled container:\n");
    c.Out(file1);

    // ����� 2� ����� �������
    FILE* file2;
    file2 = fopen(argv[4], "w");
    c.ProcessingVar21(file2);

    printf("\nFinished");
    return 0;
}