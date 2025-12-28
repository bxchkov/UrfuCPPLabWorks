// string_class.h
#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>
#include <cstring> // Для функций strlen, strcpy, strcat

// Класс MyString инкапсулирует работу с динамическими C-строками (char*)
class MyString {
private:
    char* str; // Указатель на массив символов в динамической памяти

public:
    // --- Конструкторы ---

    // Конструктор по умолчанию: создает пустую строку
    MyString();

    // Конструктор с параметром: создает строку из C-строки (const char*)
    MyString(const char* s);

    // Конструктор копирования: создает новую строку как копию существующего объекта MyString
    // Необходим для корректного управления памятью (глубокое копирование)
    MyString(const MyString& other);

    // --- Деструктор ---
    // Освобождает выделенную память при уничтожении объекта
    ~MyString();

    // --- Перегруженные операторы ---

    // Оператор присваивания: копирует содержимое одной строки в другую
    // Возвращает ссылку на текущий объект для цепочки присваиваний (a = b = c)
    MyString& operator=(const MyString& other);

    // Оператор сложения (конкатенации): возвращает новый объект, содержащий объединение двух строк
    MyString operator+(const MyString& other) const;

    // Оператор сравнения на равенство
    bool operator==(const MyString& other) const;

    // --- Методы ---

    // Возвращает длину строки
    int length() const;

    // Возвращает указатель на C-строку (для совместимости)
    const char* c_str() const { return str; }

    // --- Дружественные функции ввода/вывода ---
    // Объявлены как friend, чтобы иметь доступ к приватным членам класса (str)

    // Вывод в поток (например, cout)
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    // Ввод из потока (например, cin)
    friend std::istream& operator>>(std::istream& is, MyString& str);
};

#endif //STRING_CLASS_H
