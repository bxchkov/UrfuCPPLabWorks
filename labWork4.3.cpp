/*
Лабораторная работа 4
Задание 3
Программа, использующая динамическую память (malloc) для работы со строками
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    // Выделяем память под строки str1 и str2
    char *str1 = (char *) malloc(7 * sizeof(char)); // "qwerty" состоит из 6 символов, плюс 1 для нулевого символа
    char *str2 = (char *) malloc(11 * sizeof(char)); // "1234567890" состоит из 10 символов, плюс 1 для нулевого символа

    // Копируем содержимое статических строк в динамически выделенные строки
    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    cout << str1 << endl;
    cout << str2 << endl;

    // Освобождаем выделенную память
    free(str1);
    free(str2);
}