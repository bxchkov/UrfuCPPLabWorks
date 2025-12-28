// string_class.cpp
#define _CRT_SECURE_NO_WARNINGS // Для strcpy, strcat

#include "labWork6.1-2_string_class.h"

// Конструктор по умолчанию
// Инициализирует строку как пустую (nullptr или пустая строка "").
// Здесь используется nullptr, что требует проверок в других методах.
MyString::MyString() : str(nullptr) {}

// Конструктор с параметром (const char*)
// Выделяет память и копирует переданную строку.
MyString::MyString(const char* s) {
    if (s == nullptr) {
        str = nullptr;
    } else {
        // Выделяем память: длина строки + 1 байт для нуль-терминатора
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Конструктор копирования
// Создает глубокую копию объекта (копирует содержимое памяти, а не указатель).
MyString::MyString(const MyString& other) {
    if (other.str == nullptr) {
        str = nullptr;
    } else {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
}

// Деструктор
// Освобождает динамически выделенную память.
MyString::~MyString() {
    delete[] str; // delete[] корректно работает с nullptr, проверка не обязательна
}

// Оператор присваивания
// Позволяет присваивать один объект MyString другому (s1 = s2).
MyString& MyString::operator=(const MyString& other) {
    // Проверка на самоприсваивание (s1 = s1), чтобы не удалить свои же данные
    if (this != &other) {
        // Освобождаем старую память
        delete[] str;

        // Копируем данные из другого объекта
        if (other.str == nullptr) {
            str = nullptr;
        } else {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
    }
    return *this; // Возвращаем ссылку на текущий объект
}

// Оператор конкатенации (+)
// Создает новый объект, содержащий результат объединения двух строк.
MyString MyString::operator+(const MyString& other) const {
    MyString result;

    // Если вторая строка пуста, результат равен первой
    if (other.str == nullptr) {
        result = *this;
    }
    // Если первая строка пуста, результат равен второй
    else if (str == nullptr) {
        result = other;
    }
    // Иначе объединяем
    else {
        // Выделяем память под сумму длин + 1
        // Важно: result.str здесь перезаписывается, но так как result создан конструктором по умолчанию,
        // result.str изначально nullptr, утечки нет. Но лучше использовать временный указатель.
        // В данном случае мы напрямую присваиваем result.str, так как это приватное поле, а мы внутри класса.
        result.str = new char[length() + other.length() + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
    }
    return result;
}

// Оператор сравнения (==)
bool MyString::operator==(const MyString& other) const {
    // Обработка случаев с nullptr
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

// Оператор вывода в поток (<<)
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    if (str.str != nullptr) {
        os << str.str;
    }
    return os;
}

// Оператор ввода из потока (>>)
std::istream& operator>>(std::istream& is, MyString& str) {
    char temp[1000]; // Буфер фиксированного размера (ограничение!)
    is >> temp; // Читает до первого пробела

    // Используем оператор присваивания, создавая временный объект MyString из temp
    str = MyString(temp);

    return is;
}
