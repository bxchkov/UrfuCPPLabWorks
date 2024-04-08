/*
Лабораторная работа 4
Задание 2
Программа для работы со строками
*/

#include <iostream>
#include <windows.h>

using namespace std;

// Определение длины строки (способ 1: использование цикла while)
int stringLength1(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Определение длины строки (способ 2: использование указателей)
int stringLength2(char *str) {
    char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

// Определение длины строки (способ 3: рекурсивная функция)
int stringLength3(char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + stringLength3(str + 1);
    }
}

// Функция копирования строк
char *stringCopy(char *destination, const char *source) {
    char *temp = destination; // Создаем временный указатель на начало destination

    // Копируем каждый символ из source в destination, пока не достигнем конца строки
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }

    // Устанавливаем завершающий нулевой символ для destination
    *destination = '\0';

    return temp; // Возвращаем указатель на начало destination
}

// Функция сравнения строк
int stringCompare(const char *a, const char *b) {
    // Ищем первый различающийся символ до тех пор, пока не дойдем до конца одной из строк
    // мы можем не проверять *b != '\0`, поскольку первым условием для продолжения цикла
    // является равенство *a и *b. Если *a равно *b и *a не равно '\0', значит *b тоже не равен '\0'
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    // если обе строки закончились, то они равны
    if (*a == '\0' && *b == '\0') {
        return 0;
    }

    // тут мы сравниваем первый различающийся символ
    if (*a > *b) {
        return 1;
    } else {
        return -1;
    }
}

char *stringConcat(char *destination, const char *source) {
    char *temp = destination; // Создаем временный указатель на начало destination

    // Перемещаем указатель destination до конца строки
    while (*destination != '\0') {
        ++destination;
    }

    // Копируем содержимое source в конец destination, пока не достигнем завершающего нулевого символа
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }

    // Устанавливаем завершающий нулевой символ для destination
    *destination = '\0';

    return temp; // Возвращаем указатель на начало destination
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    char str1[] = "qwerty", str2[] = "1234567890";

    // использование функций длины строки
    cout << "Длина str1 = " << stringLength1(str1) << ", str2 = ";
    cout << stringLength1(str2) << endl;
    cout << "Длина str1 = " << stringLength2(str1) << ", str2 = ";
    cout << stringLength2(str2) << endl;
    cout << "Длина str1 = " << stringLength3(str1) << ", str2 = ";
    cout << stringLength3(str2) << endl;

    // вызов stringCopy;
    cout << "Результат копирования str1 (" << str1 << ") и str2 (" << str2 << "): " << stringCopy(str1, str2)
    << endl;

    // вызов stringCompare;
    cout << "Результат сравнения str1 (" << str1 << ") и str2 (" << str2 << "): " << stringCompare(str1, str2)
    << endl;

    // вызов stringConcat;
    cout << "Результат конкатенации str1 (" << str1 << ") и str2 (" << str2 << "): " << stringConcat(str1, str2)
    << endl;
}