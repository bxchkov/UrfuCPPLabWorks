/*
Лабораторная работа 4
Задание 4
Программа, использующая динамическую память (calloc) для работы со строками
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <cstdlib> // Для calloc, free
#include <cstring> // Для strcpy

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    // calloc (Contiguous Allocation) выделяет блок памяти для массива элементов
    // и инициализирует все байты нулями.
    // Аргументы: количество элементов, размер одного элемента.

    // Выделяем память под "qwerty" (7 элементов char)
    // В отличие от malloc, память сразу заполнена нулями, что гарантирует наличие нуль-терминатора,
    // если мы скопируем строку короче выделенного размера.
    char *str1 = (char *) calloc(7, sizeof(char));
    if (str1 == NULL) {
        cout << "Ошибка выделения памяти" << endl;
        return 1;
    }

    // Выделяем память под "1234567890" (11 элементов char)
    char *str2 = (char *) calloc(11, sizeof(char));
    if (str2 == NULL) {
        cout << "Ошибка выделения памяти" << endl;
        free(str1);
        return 1;
    }

    // Копируем строки
    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    cout << "str1 (calloc): " << str1 << endl;
    cout << "str2 (calloc): " << str2 << endl;

    // Освобождаем память
    free(str1);
    free(str2);

    return 0;
}
