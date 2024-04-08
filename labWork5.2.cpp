/*
Лабораторная работа 5
Задание 2
Программа, подсчитывающая кол-во пустых и непустых символов в текстовом файле
*/

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    const char filename[] = "test.txt";

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Файл " << filename << " не открыт" << endl;
        return 1;
    }

    int emptyCount = 0;
    int nonEmptyCount = 0;

    // Функция для подсчета пустых и непустых символов
    char ch;
    while (file.get(ch)) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            emptyCount++;
        } else {
            nonEmptyCount++;
        }
    }

    file.clear(); // Сбрасываем флаги состояния для чтения файла с начала
    file.seekg(0, ios::beg); // Устанавливаем указатель на начало файла
    cout << file.rdbuf() << endl;

    // Вывод результатов
    cout << "Количество пустых символов: " << emptyCount << endl;
    cout << "Количество непустых символов: " << nonEmptyCount << endl;
}