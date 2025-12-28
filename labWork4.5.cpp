/*
Лабораторная работа 4
Задание 5
Программа, использующая динамическую память для работы с массивом строк
*/

#define _CRT_SECURE_NO_WARNINGS // Для strcpy, sprintf, strcat

#include <iostream>
#include <windows.h>
#include <cstdlib> // malloc, free
#include <cstdio>  // sprintf
#include <cstring> // strcpy, strcat

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    const int numStrings = 3;
    // Массив указателей на char. Сам массив strings находится в стеке,
    // но каждый его элемент будет указывать на динамическую память в куче.
    char *strings[numStrings];

    // Выделяем память и формируем строки
    for (int i = 0; i < numStrings; ++i) {
        // Выделяем память под каждую строку (20 байт)
        strings[i] = (char *) malloc(20 * sizeof(char));

        if (strings[i] == NULL) {
            // Обработка ошибки выделения памяти (в реальном коде нужно освободить ранее выделенное)
            cout << "Ошибка выделения памяти" << endl;
            return 1;
        }

        // Формируем строку вида "qwerty1", "qwerty2", ...
        strcpy(strings[i], "qwerty"); // Копируем базу

        char numStr[5]; // Буфер для числа
        sprintf(numStr, "%d", i + 1); // Преобразуем число i+1 в строку

        strcat(strings[i], numStr); // Добавляем число к "qwerty"
    }

    // Выводим строки
    cout << "Массив динамических строк:" << endl;
    for (int i = 0; i < numStrings; ++i) {
        cout << "strings[" << i << "]: " << strings[i] << endl;
    }

    // Освобождаем выделенную память
    // Важно освободить каждый выделенный блок отдельно
    for (int i = 0; i < numStrings; ++i) {
        free(strings[i]);
    }

    return 0;
}
