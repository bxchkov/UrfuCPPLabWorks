// string_class.h
#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>
// Мы убираем <cstring> из хедера, чтобы использовать свои функции,
// но для size_t и NULL он может понадобиться, или <cstddef>.
// В данном случае оставим, но будем использовать свои статические методы.
#include <cstring>

class MyString {
private:
    char* str; // Указатель на динамический массив символов

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

    // Статические методы для работы со строками (аналоги <cstring>)
    // Реализованы самостоятельно в рамках лабораторной работы
    static int stringLength(const char* str);
    static char* stringCopy(char* destination, const char* source);
    static int stringCompare(const char* a, const char* b);
    static char* stringConcat(char* destination, const char* source);
};

#endif //STRING_CLASS_H
