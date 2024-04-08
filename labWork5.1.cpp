/*
Лабораторная работа 5
Задание 1
Программа (улучшенная) выводящая содержимое текстового файла
*/

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    string filename;
    cout << "Введите имя файла для просмотра:";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Файл " << filename << " не открыт" << endl;
        return 1;
    }

    cout << file.rdbuf();
}