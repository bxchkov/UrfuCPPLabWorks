// string_class.cpp
#define _CRT_SECURE_NO_WARNINGS // Для strcpy, strcat

#include "labWork6.4_string_class.h"

// Конструктор по умолчанию
MyString::MyString() : str(nullptr) {}

// Конструктор с параметром
MyString::MyString(const char* s) {
    if (s == nullptr) {
        str = nullptr;
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
    if (other.str == nullptr) {
        str = nullptr;
    } else {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
}

// Конструктор с указанием размера динамической памяти
// Выделяет память, но делает строку пустой (ставит \0 в начало)
MyString::MyString(size_t size) {
    str = new char[size + 1]; // +1 для нуль-терминатора
    str[0] = '\0'; // Инициализируем как пустую строку
}

// Деструктор
MyString::~MyString() {
    delete[] str;
}

// Оператор присваивания
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        if (other.str == nullptr) {
            str = nullptr;
        } else {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
    }
    return *this;
}

// Оператор конкатенации
MyString MyString::operator+(const MyString& other) const {
    MyString result;
    if (other.str == nullptr) {
        result = *this;
    } else if (str == nullptr) {
        result = other;
    } else {
        result.str = new char[length() + other.length() + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
    }
    return result;
}

// Оператор сравнения
bool MyString::operator==(const MyString& other) const {
    if (str == nullptr && other.str == nullptr) return true;
    if (str == nullptr || other.str == nullptr) return false;
    return (strcmp(str, other.str) == 0);
}

// Метод для определения длины строки
int MyString::length() const {
    if (str == nullptr) {
        return 0;
    }
    return strlen(str);
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    if (str.str != nullptr) {
        os << str.str;
    }
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, MyString& str) {
    char temp[1000];
    is >> temp;
    str = MyString(temp);
    return is;
}
