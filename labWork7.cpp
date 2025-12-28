/*
Лабораторная работа 7
Тема: Наследование и полиморфизм. Графика в консоли.
Задание: Реализовать иерархию классов (Точка -> Круг/Сектор -> Кольцо) с возможностью перемещения по экрану.
*/

#include <iostream>
#include <windows.h> // Основная библиотека Windows API (нужна для графики: HDC, Pen, Brush и SetConsoleOutputCP)
#include <conio.h>   // Библиотека для работы с консольным вводом (_kbhit, _getch)
#include <ctime>     // Для функции time(), чтобы инициализировать генератор случайных чисел

using namespace std;

// =========================================================
// БАЗОВЫЙ КЛАСС Point (Абстрактный класс)
// =========================================================
class Point {
protected:
    // protected означает, что эти данные доступны внутри этого класса
    // и внутри классов-наследников (Krug, Ring), но закрыты для остальных.
    int x, y;       // Координаты центра объекта
    COLORREF color; // Специальный тип данных Windows для хранения цвета (формат RGB)

public:
    // Конструктор: инициализирует координаты и цвет при создании объекта
    Point(int xn, int yn, COLORREF c) : x(xn), y(yn), color(c) {}

    // Виртуальный деструктор.
    // Важен при полиморфизме: если удалять объект наследника через указатель на базовый класс,
    // виртуальный деструктор гарантирует, что вызовется деструктор и наследника тоже.
    virtual ~Point() {}

    // Чисто виртуальные функции (pure virtual).
    // "= 0" означает, что у класса Point нет реализации этих методов.
    // Это делает класс АБСТРАКТНЫМ: мы не можем создать объект типа Point, только наследников.
    // Наследники ОБЯЗАНЫ реализовать эти методы.
    virtual void Show(HDC hdc) = 0; // Метод для отрисовки
    virtual void Hide(HDC hdc) = 0; // Метод для скрытия (стирания)

    // Метод получения текущих координат (геттер)
    void GetLocat(int &xl, int &yl) {
        xl = x; yl = y;
    }

    // Метод движения (Fly) - общий для всех фигур.
    // Реализует цикл анимации: Стереть -> Изменить координаты -> Нарисовать -> Подождать.
    void Fly(HDC hdc, int cost) {
        int xx = x, yy = y;
        
        // _kbhit() возвращает true, если была нажата клавиша на клавиатуре.
        // Цикл работает, пока клавиша НЕ нажата.
        while (!_kbhit()) {
            Hide(hdc); // 1. Стираем фигуру в старой позиции (рисуем черным)

            // 2. Вычисляем новые координаты (случайное блуждание)
            // rand() % (cost + 1) дает число от 0 до cost.
            // Вычитая cost/2, получаем смещение в диапазоне [-cost/2, +cost/2].
            xx += (rand() % (cost + 1) - cost / 2);
            yy += (rand() % (cost + 1) - cost / 2);

            // Проверка границ экрана (чтобы фигура не улетела за пределы видимости)
            if (xx < 50) xx = 50; if (xx > 600) xx = 600;
            if (yy < 50) yy = 50; if (yy > 400) yy = 400;

            x = xx; y = yy; // Обновляем текущие координаты

            UpdateFeatures(); // Вызов метода для изменения свойств (полиморфизм в действии)
            Show(hdc);        // 3. Рисуем фигуру в новой позиции
            
            Sleep(100);       // 4. Пауза 100 миллисекунд, чтобы глаз успел заметить движение
        }
        _getch(); // Считываем нажатую клавишу из буфера, чтобы очистить его
    }

    // Виртуальный метод для изменения свойств фигуры "на лету".
    // В базовом классе он пустой, но наследники могут его переопределить.
    virtual void UpdateFeatures() {}
};

// =========================================================
// КЛАСС Krug (Наследник Point)
// =========================================================
class Krug : public Point {
protected:
    int radius; // Радиус круга
    int angle;  // Угол (используется для рисования сектора/пакмана)

public:
    // Конструктор Krug вызывает конструктор базового класса Point
    Krug(int xn, int yn, int r, COLORREF c)
        : Point(xn, yn, c), radius(r), angle(30) {}

    // Реализация метода Show (рисование)
    // override указывает компилятору, что мы переопределяем виртуальный метод родителя.
    void Show(HDC hdc) override {
        // 1. Создаем "кисть" (Brush) заданного цвета для заливки фигуры
        HBRUSH hBrush = CreateSolidBrush(color);
        // 2. Выбираем эту кисть в контекст устройства (говорим Windows рисовать ею)
        SelectObject(hdc, hBrush);

        // 3. Рисуем сектор (Pie).
        // Аргументы: контекст, координаты прямоугольника (left, top, right, bottom),
        // и координаты двух точек, определяющих начало и конец дуги.
        Pie(hdc, x - radius, y - radius, x + radius, y + radius, 
            x + radius, y, x, y - angle); 

        // 4. Удаляем кисть, чтобы не засорять память (важно в GDI!)
        DeleteObject(hBrush);
    }

    // Реализация метода Hide (скрытие)
    void Hide(HDC hdc) override {
        COLORREF oldColor = color; // Запоминаем текущий цвет
        color = RGB(0, 0, 0);      // Устанавливаем черный цвет (цвет фона консоли)
        Show(hdc);                 // Рисуем фигуру черным цветом (она "исчезает")
        color = oldColor;          // Возвращаем исходный цвет
    }

    // Переопределение метода изменения свойств.
    // При каждом шаге анимации меняется угол сектора и цвет.
    void UpdateFeatures() override {
        angle = (angle + 5) % 80; // Угол "дышит" от 0 до 80
        // Генерируем случайный цвет RGB
        color = RGB(rand() % 256, rand() % 256, rand() % 256);
    }
};

// =========================================================
// КЛАСС Ring (Наследник Krug)
// =========================================================
// Наследуется от Krug, так как Кольцо - это Круг с дыркой.
class Ring : public Krug {
private:
    int width; // Ширина кольца (толщина бублика)

public:
    // Конструктор Ring вызывает конструктор Krug
    Ring(int xn, int yn, int r, COLORREF c, int w)
        : Krug(xn, yn, r, c), width(w) {}

    // Переопределение метода Show
    void Show(HDC hdc) override {
        // 1. Сначала вызываем метод родителя (Krug::Show), чтобы нарисовать внешний сектор
        Krug::Show(hdc);

        // 2. Теперь рисуем "дырку" внутри
        // Создаем черную кисть
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);

        // Вычисляем радиус внутренней дырки
        int r2 = radius - width;

        // Рисуем эллипс (круг) черного цвета поверх основного круга
        Ellipse(hdc, x - r2, y - r2, x + r2, y + r2);

        DeleteObject(hBrush);
    }

    // Метод Hide наследуется от Krug автоматически.
    // Он вызовет Ring::Show с черным цветом, что корректно сотрет всё кольцо.
};

// =========================================================
// ФУНКЦИЯ ОКОННОЙ ПРОЦЕДУРЫ
// =========================================================
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// =========================================================
// ГЛАВНАЯ ФУНКЦИЯ
// =========================================================
int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    cout << "Создание графического окна для анимации..." << endl;

    // Регистрация класса окна
    const char CLASS_NAME[] = "LabWork7WindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    RegisterClass(&wc);

    // Создание окна
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Lab Work 7 - Animation",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (hwnd == NULL) {
        cout << "Ошибка создания окна!" << endl;
        return 1;
    }

    ShowWindow(hwnd, SW_SHOW);
    HDC hdc = GetDC(hwnd);

    cout << "Окно создано!" << endl;
    cout << "Нажмите любую клавишу для начала движения объектов..." << endl;
    _getch();

    // Создание объектов
    Krug testKrug(150, 150, 50, RGB(255, 255, 0));
    Ring testRing(400, 250, 70, RGB(0, 255, 255), 15);

    cout << "Двигается Круг (Сектор). Нажмите клавишу, чтобы перейти к следующему..." << endl;
    testKrug.Fly(hdc, 40);

    cout << "Двигается Кольцо. Нажмите клавишу, чтобы выйти..." << endl;
    testRing.Fly(hdc, 30);

    // Очистка
    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);

    cout << "\nПрограмма завершена." << endl;

    return 0;
}
