/*
Лабораторная работа 1
Задание 1
Программа возведения числа в степень
*/

#include <iostream>
#include <windows.h>

using namespace std;

// exponentiation - возведение в степень
// exponent - степень

int exponentiation(int number, int exponent) {
    int i, result = 1;

    for (i = 1; i <= exponent; i++) {
        result = result * number;
    }

    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int number, exponent, result;
    cout << "Введите основание степени\n";
    cin >> number;
    cout << "Введите степень\n";
    cin >> exponent;

    for (int i = 0; i <= exponent; i++) {
        result = exponentiation(number, i);
        cout << number << "^" << i << " = " << result << endl;
    }
}

