/*
Лабораторная работа 6
Задание 2
Описание класса для работы со строкой, как со стандартным типом данных
*/

#include <iostream>
#include <windows.h>
#include "labWork6.3_string_class.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    MyString s1("Hello");
    MyString s2(" World?");
    MyString s3 = s1 + s2;

    cout << "Строка1: " << s1 << endl;
    cout << "Строка2: " << s2 << endl;
    cout << "Строка3: " << s3 << endl;

    if (s1 == s2) {
        cout << "Строка1 = Строка2" << endl;
    } else {
        cout << "Строка1 != Строка2" << endl;
    }

    cout << "Длина Строка3: " << s3.length() << endl;

    MyString s4;
    cout << "Введите строку:";
    cin >> s4;
    cout << "Вы ввели: " << s4 << endl;
}