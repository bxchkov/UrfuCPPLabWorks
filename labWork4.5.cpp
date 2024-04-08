/*
Лабораторная работа 4
Задание 5
Программа, использующая динамическую память для работы с массивом строк
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    // Создаем массив строк
    const int numStrings = 3;
    char *strings[3];

    // Выделяем память и копируем строки
    for (int i = 0; i < numStrings; ++i) {
        // Выделяем память под строку
        strings[i] = (char *) malloc(20 * sizeof(char)); // Условимся, что макс. длина строки - 19

        // Копируем данные в строку
        strcpy(strings[i], "qwerty"); // Копируем "String" в строку
        char numStr[2];
        sprintf(numStr, "%d", i + 1); // Конвертируем номер строки в строку
        strcat(strings[i], numStr); // Конкатенируем номер строки с "String "
    }

    // Выводим строки
    for (int i = 0; i < numStrings; ++i) {
        cout << "Строка " << i + 1 << ": " << strings[i] << endl;
    }

    // Освобождаем выделенную память
    for (auto &string: strings) {
        free(string);
    }
}