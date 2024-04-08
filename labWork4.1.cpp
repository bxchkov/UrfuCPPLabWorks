/*
Лабораторная работа 4
Задание 1
Тестирование функций для работ со строками
*/

#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    char str1[] = "qwerty",
         str2[] = "1234567890";

    cout << strlen(str1) << endl;
    cout << strcat(str1, str2) << endl;
    cout << strcmp(str1, str2) << endl;
    cout << strcpy(str1, str2) << endl;
}