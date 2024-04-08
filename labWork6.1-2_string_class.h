// string_class.h
#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>
#include <cstring>

class MyString {
private:
    char* str; // Переменная для хранения символов строки

public:
    // Конструкторы
    MyString(); // Конструктор по умолчанию
    MyString(const char* s); // Конструктор с параметром
    MyString(const MyString& other); // Конструктор копирования

    // Деструктор
    ~MyString();

    // Перегруженные операторы
    MyString& operator=(const MyString& other); // Оператор присваивания
    MyString operator+(const MyString& other) const; // Оператор конкатенации
    bool operator==(const MyString& other) const; // Оператор сравнения

    // Методы
    int length() const; // Метод для определения длины строки

    // Методы ввода и вывода строки
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
};

#endif //STRING_CLASS_H