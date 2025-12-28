/*
Лабораторная работа 8
Задание 2
Тема: Шаблоны функций (Templates) и перегрузка операторов для пользовательских типов.
*/

#include <iostream>
#include <cstring>   // Для strcmp
#include <algorithm> // Для std::swap
#include <windows.h> // Для SetConsoleOutputCP

using namespace std;

// =========================================================
// КЛАСС Money (Пользовательский тип данных)
// =========================================================
class Money {
    long dollars;
    int cents;
public:
    // Конструктор по умолчанию
    Money() : dollars(0), cents(0) {}

    // Конструктор с параметрами
    Money(long d, int c) : dollars(d), cents(c) {}

    // Перегрузка оператора "больше" (>)
    // Необходима, чтобы шаблонная функция сортировки могла сравнивать объекты Money
    int operator>(const Money& amt) const {
        if (dollars > amt.dollars) return 1;
        if (dollars == amt.dollars && cents > amt.cents) return 1;
        return 0;
    }

    // Дружественная функция вывода для удобства (cout << money)
    friend ostream& operator<<(ostream& os, const Money& amt) {
        os << "$" << amt.dollars << "." << (amt.cents < 10 ? "0" : "") << amt.cents;
        return os;
    }
};

// =========================================================
// ШАБЛОНЫ ФУНКЦИЙ
// =========================================================

// Шаблон функции сортировки пузырьком
// Работает с любым типом T, у которого определен оператор >
template <class T>
void Sort(T mas[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(mas[i] > mas[j]) {
                swap(mas[i], mas[j]); // std::swap меняет элементы местами
            }
        }
    }
}

// Шаблон функции поиска максимума из двух элементов
template <class T>
T getmax(T t1, T t2) {
    return t1 > t2 ? t1 : t2;
}

// Специализация шаблона (перегрузка) для C-строк (const char*)
// Стандартный оператор > сравнивает адреса указателей, а не содержимое строк.
// Поэтому для строк нужна отдельная версия с strcmp.
const char* getmax(const char* s1, const char* s2) {
    // strcmp возвращает > 0, если s1 лексикографически больше s2
    return strcmp(s1, s2) > 0 ? s1 : s2;
}

// Шаблон функции поиска максимума в массиве
template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0];
    for(size_t i = 1; i < size; i++)
        if(t[i] > retval) retval = t[i];
    return retval;
}

// =========================================================
// ТЕСТИРОВАНИЕ
// =========================================================
void task2() {
    cout << "--- Тест 1: Сортировка массива объектов Money ---" << endl;
    Money mas[] = { Money(19,10), Money(99,99), Money(99,95), Money(19,95) };

    cout << "До сортировки:" << endl;
    for(const auto& m : mas) cout << m << " ";
    cout << endl;

    Sort(mas, 4); // Вызов шаблонной функции сортировки

    cout << "После сортировки (по возрастанию):" << endl;
    for(const auto& m : mas) cout << m << " ";
    cout << endl << endl;


    cout << "--- Тест 2: Шаблон getmax ---" << endl;
    int i1 = 3, i2 = 5;
    cout << "Максимум из чисел " << i1 << " и " << i2 << ": " << getmax(i1, i2) << endl;

    const char* s1 = "apple";
    const char* s2 = "orange";
    cout << "Максимум из строк \"" << s1 << "\" и \"" << s2 << "\": " << getmax(s1, s2) << endl;


    cout << "--- Тест 3: Шаблон getmax для массива ---" << endl;
    int i_mas[] = {3, 9, 5, 8};
    cout << "Максимум в массиве чисел: " << getmax(i_mas, 4) << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    task2();
    return 0;
}
