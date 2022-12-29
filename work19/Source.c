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
    puts("Введите шаг для функции y = x^2 + sin 5x; [0.1; 2.1]");
    scanf("%f", &step);
    puts("Дозаписать?");
    scanf("%f", &writeDown);
    float i = 0.1;
    if (writeDown) 
    {
        if ((out = fopen(fname, "a")) == NULL) 
        {
            printf("Ошибка открытия файла для записи");
            return 0;
        }
        printf("Дозапись\n");
    }
    else 
    {
        if ((out = fopen(fname, "wt")) == NULL) 
        {
            printf("Ошибка открытия файла для записи");
            return 0;
        }
        printf("Запись");
    }
    while (i < 2.1) {
        fprintf(out, "\n |  %4.4f  |  %4.4f   |", i, i * i + sin(5 * i));
        i += step;
    }
    fclose(out);

    Employee report;
    puts("Введите фамилию сотрудника: ");
    scanf("%s", report.lastname);
    puts("Введите имя сотрудника:");
    scanf("%s", report.name);
    puts("Введите отчество сотрудника:");
    scanf("%s", report.patronymic);
    puts("Введите должность сотрудника:");
    scanf("%s", report.position);
    puts("Введите пол сотрудника:");
    scanf("%s", report.floor);
    puts("Введите день приёма сотрудника на работу:");
    scanf("%d", &report.day);
    puts("Введите месяц приёма сотрудника на работу:");
    scanf("%d", &report.month);
    puts("Введите год приёма сотрудника на работу:");
    scanf("%d", &report.year);
    puts("Введите стаж сотрудника:");
    scanf("%d", &report.experience);

    if ((out = fopen(fname2, "a")) == NULL)
    {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    printf("Дозапись\n");
    fprintf(out, "Сотрудник: %s %s %s.\n", report.lastname, report.name, report.patronymic);
    fprintf(out, "Должность: %s.\n", report.position);
    fprintf(out, "Пол: %s.\n", report.floor);
    fprintf(out, "Дата приёма сотрудника на работу: %d:%d:%d.\n", report.day, report.month, report.year);
    fprintf(out, "Стаж работника: %d.\n", report.experience);
    return 1;
    fclose(out);
}