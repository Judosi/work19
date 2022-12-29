#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct employee Employee;

struct employee
{
    char lastname[32];
    char name[32];
    char patronymic[32];
    char position[32];
    char floor[32];
    int day;
    int month;
    int year;
    int experience;
};

int main(void)
{
    setlocale(LC_ALL, "RUS");
    char fname[20] = "number.txt";
    char fname2[255] = "database.txt";

    FILE* out;

    
    puts("\n\n\n");
    float step;
    int writeDown;
    puts("������� ��� ��� ������� y = x^2 + sin 5x; [0.1; 2.1]");
    scanf("%f", &step);
    puts("����������?");
    scanf("%f", &writeDown);
    float i = 0.1;
    if (writeDown) 
    {
        if ((out = fopen(fname, "a")) == NULL) 
        {
            printf("������ �������� ����� ��� ������");
            return 0;
        }
        printf("��������\n");
    }
    else 
    {
        if ((out = fopen(fname, "wt")) == NULL) 
        {
            printf("������ �������� ����� ��� ������");
            return 0;
        }
        printf("������");
    }
    while (i < 2.1) {
        fprintf(out, "\n |  %4.4f  |  %4.4f   |", i, i * i + sin(5 * i));
        i += step;
    }
    fclose(out);

    Employee report;
    puts("������� ������� ����������: ");
    scanf("%s", report.lastname);
    puts("������� ��� ����������:");
    scanf("%s", report.name);
    puts("������� �������� ����������:");
    scanf("%s", report.patronymic);
    puts("������� ��������� ����������:");
    scanf("%s", report.position);
    puts("������� ��� ����������:");
    scanf("%s", report.floor);
    puts("������� ���� ����� ���������� �� ������:");
    scanf("%d", &report.day);
    puts("������� ����� ����� ���������� �� ������:");
    scanf("%d", &report.month);
    puts("������� ��� ����� ���������� �� ������:");
    scanf("%d", &report.year);
    puts("������� ���� ����������:");
    scanf("%d", &report.experience);

    if ((out = fopen(fname2, "a")) == NULL)
    {
        printf("������ �������� ����� ��� ������");
        return 0;
    }
    printf("��������\n");
    fprintf(out, "���������: %s %s %s.\n", report.lastname, report.name, report.patronymic);
    fprintf(out, "���������: %s.\n", report.position);
    fprintf(out, "���: %s.\n", report.floor);
    fprintf(out, "���� ����� ���������� �� ������: %d:%d:%d.\n", report.day, report.month, report.year);
    fprintf(out, "���� ���������: %d.\n", report.experience);
    return 1;
    fclose(out);
}