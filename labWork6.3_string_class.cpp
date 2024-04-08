// string_class.cpp
#include "labWork6.3_string_class.h"

// Конструктор по умолчанию
MyString::MyString() : str(nullptr) {}

// Конструктор с параметром
MyString::MyString(const char* s) {
    if (s == nullptr) {
        str = nullptr;
    } else {
        int len = MyString::stringLength(s);
        str = new char[len + 1];
        MyString::stringCopy(str, s);
    }
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
    if (other.str == nullptr) {
        str = nullptr;
    } else {
        int len = MyString::stringLength(other.str);
        str = new char[len + 1];
        MyString::stringCopy(str, other.str);
    }
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
            int len = MyString::stringLength(other.str);
            str = new char[len + 1];
            MyString::stringCopy(str, other.str);
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
        int len1 = MyString::stringLength(str);
        int len2 = MyString::stringLength(other.str);
        result.str = new char[len1 + len2 + 1];
        MyString::stringCopy(result.str, str);
        MyString::stringConcat(result.str, other.str);
    }
    return result;
}

// Оператор сравнения
bool MyString::operator==(const MyString& other) const {
    return MyString::stringCompare(str, other.str) == 0;
}

// Метод для определения длины строки
int MyString::length() const {
    return (str == nullptr) ? 0 : MyString::stringLength(str);
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

// Кастомные функции работы со строками


int MyString::stringLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* MyString::stringCopy(char* destination, const char* source) {
    char* temp = destination; // Создаем временный указатель на начало destination

    // Копируем каждый символ из source в destination, пока не достигнем конца строки
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }

    // Устанавливаем завершающий нулевой символ для destination
    *destination = '\0';

    return temp; // Возвращаем указатель на начало destination
}

int MyString::stringCompare(const char* a, const char* b) {
    // Ищем первый различающийся символ до тех пор, пока не дойдем до конца одной из строк
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    // если обе строки закончились, то они равны
    if (*a == '\0' && *b == '\0') {
        return 0;
    }

    // тут мы сравниваем первый различающийся символ
    if (*a > *b) {
        return 1;
    } else {
        return -1;
    }
}

char* MyString::stringConcat(char* destination, const char* source) {
    char* temp = destination; // Создаем временный указатель на начало destination

    // Перемещаем указатель destination до конца строки
    while (*destination != '\0') {
        ++destination;
    }

    // Копируем содержимое source в конец destination, пока не достигнем завершающего нулевого символа
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }

    // Устанавливаем завершающий нулевой символ для destination
    *destination = '\0';

    return temp; // Возвращаем указатель на начало destination
}