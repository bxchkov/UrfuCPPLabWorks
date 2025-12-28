/*
Лабораторная работа 8
Задание 1
Тема: Перегрузка операторов ввода-вывода для пользовательских классов.
*/

#define _CRT_SECURE_NO_WARNINGS // Для использования strcpy без предупреждений в Visual Studio

#include <iostream>
#include <cstring>
#include <windows.h> // Для SetConsoleOutputCP

using namespace std;

// Класс-обертка над C-строкой (char*)
class Stroka {
private:
    char* str; // Указатель на динамический массив символов
    int len;   // Длина строки

public:
    // Конструктор с параметром по умолчанию
    // Если аргумент не передан, создается пустая строка ""
    Stroka(const char* s = "") {
        len = strlen(s);
        str = new char[len + 1]; // +1 для нуль-терминатора
        strcpy(str, s);
    }

    // Конструктор копирования (Rule of Three: 1/3)
    // Необходим для корректной передачи объектов по значению и инициализации (Stroka s2 = s1;)
    Stroka(const Stroka& other) {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }

    // Оператор присваивания (Rule of Three: 2/3)
    // Необходим для присваивания уже существующим объектам (s2 = s1;)
    Stroka& operator=(const Stroka& other) {
        if (this != &other) { // Защита от самоприсваивания
            delete[] str;     // Освобождаем старую память
            len = other.len;
            str = new char[len + 1]; // Выделяем новую
            strcpy(str, other.str);  // Копируем данные
        }
        return *this;
    }

    // Деструктор (Rule of Three: 3/3)
    // Освобождает память при уничтожении объекта
    ~Stroka() {
        delete[] str;
    }

    // Дружественная функция перегрузки оператора вывода в поток (cout << obj)
    // friend дает доступ к приватным полям (str)
    friend ostream& operator<<(ostream& os, const Stroka& obj) {
        if (obj.str) {
            os << obj.str;
        }
        return os; // Возвращаем поток для цепочки вызовов (cout << s1 << s2)
    }

    // Дружественная функция перегрузки оператора ввода из потока (cin >> obj)
    friend istream& operator>>(istream& is, Stroka& obj) {
        char buffer[1024]; // Временный буфер для чтения
        is >> buffer;      // Читает до первого пробела!

        // Если нужно читать строку с пробелами, можно использовать:
        // is.getline(buffer, 1024);

        // Очищаем старое содержимое объекта
        delete[] obj.str;

        // Копируем из буфера в объект
        obj.len = strlen(buffer);
        obj.str = new char[obj.len + 1];
        strcpy(obj.str, buffer);

        return is;
    }
};

// Функция проверки задания
void task1() {
    cout << "--- Задание 1: Перегрузка ввода/вывода ---" << endl;

    Stroka s; // Создается пустая строка
    cout << "Введите строку (без пробелов): ";
    cin >> s; // Вызывается operator>>

    cout << "Вы ввели: " << s << endl; // Вызывается operator<<

    // Тест конструктора копирования
    Stroka s2 = s;
    cout << "Копия вашей строки: " << s2 << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Установка кодировки UTF-8 для консоли
    task1();
    return 0;
}
