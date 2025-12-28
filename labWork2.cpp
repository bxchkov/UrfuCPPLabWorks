/*
Лабораторная работа 2
Программа для обработки матриц
*/

#include <iostream>
#include <cstdlib> // Для rand(), srand()
#include <windows.h> // Для SetConsoleOutputCP
#include <limits> // Для std::numeric_limits
#include <cmath> // Для std::abs
#include <ctime> // Для time()

using namespace std;

// Размер матрицы (через код или закомментированный вариант через ввод в консоль)
// int n;
// cout << "Размер матрицы? (например - 5):\n";
// cin >> n;
const int n = 5; // Константа размера матрицы

// Функция поиска минимального элемента во всей матрице
int findMin(int pInt[n][n], int n) {
    int minVal = pInt[0][0]; // Предполагаем, что первый элемент - минимальный
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j]; // Если нашли меньше, обновляем минимум
            }
        }
    }
    return minVal;
}

// Функция поиска максимального элемента во всей матрице
int findMax(int pInt[n][n], int n) {
    int maxVal = pInt[0][0]; // Предполагаем, что первый элемент - максимальный
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j]; // Если нашли больше, обновляем максимум
            }
        }
    }
    return maxVal;
}

// Функция поиска минимума в нижней треугольной части (включая главную диагональ)
// Нижний треугольник: элементы, где индекс строки >= индекса столбца (i >= j)
// В текущей реализации логика перебора немного сложная (n-i), проверим корректность.
// Обычно нижний треугольник это j <= i.
int findMinLowerTriangle(int pInt[n][n], int n) {
    // Инициализация: берем элемент, который точно в нижнем треугольнике (левый нижний угол)
    int minVal = pInt[n-1][0];

    // Перебор элементов нижнего треугольника
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) { // j идет от 0 до i включительно
             if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
    }
    return minVal;
}

// Функция поиска максимума в нижней треугольной части
int findMaxLowerTriangle(int pInt[n][n], int n) {
    int maxVal = pInt[n-1][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
    }
    return maxVal;
}

// Функция поиска минимума в верхней треугольной части (включая главную диагональ)
// Верхний треугольник: элементы, где индекс строки <= индекса столбца (i <= j)
int findMinUpperTriangle(int pInt[n][n], int n) {
    int minVal = pInt[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // j идет от i до конца строки
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
    }
    return minVal;
}

// Функция поиска максимума в верхней треугольной части
int findMaxUpperTriangle(int pInt[n][n], int n) {
    int maxVal = pInt[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
    }
    return maxVal;
}

// Функция поиска минимума на главной диагонали (i == j)
int findMinDiagonal(int pInt[n][n], int n) {
    int minVal = pInt[0][0];

    for (int i = 1; i < n; i++) {
        if (pInt[i][i] < minVal) {
            minVal = pInt[i][i];
        }
    }
    return minVal;
}

// Функция поиска максимума на главной диагонали
int findMaxDiagonal(int pInt[n][n], int n) {
    int maxVal = pInt[0][0];

    for (int i = 1; i < n; i++) {
        if (pInt[i][i] > maxVal) {
            maxVal = pInt[i][i];
        }
    }
    return maxVal;
}

// Функция поиска минимума на побочной диагонали (i + j == n - 1)
int findMinSecondaryDiagonal(int pInt[n][n], int n) {
    int minVal = pInt[0][n - 1];

    for (int i = 1; i < n; i++) {
        // Элемент побочной диагонали в строке i имеет индекс столбца n - 1 - i
        if (pInt[i][n - 1 - i] < minVal) {
            minVal = pInt[i][n - 1 - i];
        }
    }
    return minVal;
}

// Функция поиска максимума на побочной диагонали
int findMaxSecondaryDiagonal(int pInt[n][n], int n) {
    int maxVal = pInt[0][n - 1];

    for (int i = 1; i < n; i++) {
        if (pInt[i][n - 1 - i] > maxVal) {
            maxVal = pInt[i][n - 1 - i];
        }
    }
    return maxVal;
}

// Среднее арифметическое всех элементов
double findAverageMatrix(int pInt[n][n], int n) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += pInt[i][j];
            count++;
        }
    }

    return sum / count;
}

// Среднее арифметическое нижнего треугольника
double findAverageLowerTriangle(int pInt[n][n], int n) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            sum += pInt[i][j];
            count++;
        }
    }

    return sum / count;
}

// Среднее арифметическое верхнего треугольника
double findAverageUpperTriangle(int pInt[n][n], int n) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum += pInt[i][j];
            count++;
        }
    }

    return sum / count;
}

// Суммы элементов по строкам
void findRowSums(int pInt[n][n], int n) {
    cout << "Суммы элементов в каждой строке матрицы:\n";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += pInt[i][j];
        }
        cout << "Сумма элементов в строке " << i + 1 << ": " << sum << endl;
    }
}

// Суммы элементов по столбцам
void findColumnSums(int pInt[n][n], int n) {
    cout << "Суммы элементов в каждом столбце матрицы:\n";
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pInt[i][j]; // Индексы: i - строка, j - столбец
        }
        cout << "Сумма элементов в столбце " << j + 1 << ": " << sum << endl;
    }
}

// Минимальные значения по строкам
void findMinRowValues(int pInt[n][n], int n) {
    cout << "Минимальные значения в каждой строке матрицы:\n";
    for (int i = 0; i < n; i++) {
        int minVal = std::numeric_limits<int>::max(); // Инициализация максимально возможным int
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
        cout << "Минимальное значение в строке " << i + 1 << ": " << minVal << endl;
    }
}

// Максимальные значения по строкам
void findMaxRowValues(int pInt[n][n], int n) {
    cout << "Максимальные значения в каждой строке матрицы:\n";
    for (int i = 0; i < n; i++) {
        int maxVal = std::numeric_limits<int>::min(); // Инициализация минимально возможным int
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
        cout << "Максимальное значение в строке " << i + 1 << ": " << maxVal << endl;
    }
}

// Минимальные значения по столбцам
void findMinColumnValues(int pInt[n][n], int n) {
    cout << "Минимальные значения в каждом столбце матрицы:\n";
    for (int j = 0; j < n; j++) {
        int minVal = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
        cout << "Минимальное значение в столбце " << j + 1 << ": " << minVal << endl;
    }
}

// Максимальные значения по столбцам
void findMaxColumnValues(int pInt[n][n], int n) {
    cout << "Максимальные значения в каждом столбце матрицы:\n";
    for (int j = 0; j < n; j++) {
        int maxVal = std::numeric_limits<int>::min();
        for (int i = 0; i < n; i++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
        cout << "Максимальное значение в столбце " << j + 1 << ": " << maxVal << endl;
    }
}

// Среднее арифметическое по строкам
void findAverageRowValues(int pInt[n][n], int n) {
    cout << "Среднеарифметические значения в каждой строке матрицы:\n";
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += pInt[i][j];
        }
        double average = sum / n;
        cout << "Среднеарифметическое значение в строке " << i + 1 << ": " << average << endl;
    }
}

// Среднее арифметическое по столбцам
void findAverageColumnValues(int pInt[n][n], int n) {
    cout << "Среднеарифметические значения в каждом столбце матрицы:\n";
    for (int j = 0; j < n; j++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pInt[i][j];
        }
        double average = sum / n;
        cout << "Среднеарифметическое значение в столбце " << j + 1 << ": " << average << endl;
    }
}

// Суммы треугольных частей
void findTriangleSums(int pInt[n][n], int n) {
    int upperSum = 0;
    int lowerSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) { // Верхний треугольник
                upperSum += pInt[i][j];
            }
            if (i >= j) { // Нижний треугольник
                lowerSum += pInt[i][j];
            }
        }
    }

    cout << "Сумма элементов верхнетреугольной части: " << upperSum << endl;
    cout << "Сумма элементов нижнетреугольной части: " << lowerSum << endl;
}

// Поиск элемента, наиболее близкого к среднему арифметическому
int findClosestToAverage(int pInt[n][n], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += pInt[i][j];
        }
    }

    double average = sum / (n * n);

    int closestElement = pInt[0][0];
    double minDiff = std::numeric_limits<double>::max();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double diff = std::abs(pInt[i][j] - average); // Модуль разности
            if (diff < minDiff) {
                minDiff = diff;
                closestElement = pInt[i][j];
            }
        }
    }

    return closestElement;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    srand(time(0)); // Инициализация генератора случайных чисел текущим временем

    int matrix[n][n];

    // Заполнение матрицы случайными числами
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int min = -10;
            int max = 10;

            // Генерация числа в диапазоне [min, max]
            int randomNumber = rand() % (max - min + 1) + min;

            matrix[i][j] = randomNumber;
        }

    }

    // Вывод матрицы
    cout << "Элементы матрицы:\n";
    for (int i = 0; i < n; ++i, cout << endl) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t"; // \t - табуляция для выравнивания
        }
    }
    cout << endl;

    // Вызов функций анализа матрицы
    int minMatrix = findMin(matrix, n);
    cout << "Минимум матрицы: " << minMatrix << endl;

    int maxMatrix = findMax(matrix, n);
    cout << "Максимум матрицы: " << maxMatrix << endl;

    int minLowerTriangle = findMinLowerTriangle(matrix, n);
    cout << "Минимум в нижнетреугольной части матрицы: " << minLowerTriangle << endl;

    int maxLowerTriangle = findMaxLowerTriangle(matrix, n);
    cout << "Максимум в нижнетреугольной части матрицы: " << maxLowerTriangle << endl;

    int minUpperTriangle = findMinUpperTriangle(matrix, n);
    cout << "Минимум в верхнетреугольной части матрицы: " << minUpperTriangle << endl;

    int maxUpperTriangle = findMaxUpperTriangle(matrix, n);
    cout << "Максимум в верхнетреугольной части матрицы: " << maxUpperTriangle << endl;

    int minDiagonal = findMinDiagonal(matrix, n);
    cout << "Минимум на главной диагонали матрицы: " << minDiagonal << endl;

    int maxDiagonal = findMaxDiagonal(matrix, n);
    cout << "Максимум на главной диагонали матрицы: " << maxDiagonal << endl;

    int minSecondaryDiagonal = findMinSecondaryDiagonal(matrix, n);
    cout << "Минимум на второстепенной диагонали матрицы: " << minSecondaryDiagonal << endl;

    int maxSecondaryDiagonal = findMaxSecondaryDiagonal(matrix, n);
    cout << "Максимум на второстепенной диагонали матрицы: " << maxSecondaryDiagonal << endl;

    double average = findAverageMatrix(matrix, n);
    cout << "Среднеарифметическое значение элементов матрицы: " << average << endl;

    double averageLowerTriangle = findAverageLowerTriangle(matrix, n);
    cout << "Среднеарифметическое значение элементов нижнетреугольной части матрицы: " << averageLowerTriangle << endl;

    double averageUpperTriangle = findAverageUpperTriangle(matrix, n);
    cout << "Среднеарифметическое значение элементов верхнетреугольной части матрицы: " << averageUpperTriangle << endl;

    findRowSums(matrix, n);
    findColumnSums(matrix, n);
    findMinRowValues(matrix, n);
    findMaxRowValues(matrix, n);
    findMinColumnValues(matrix, n);
    findMaxColumnValues(matrix, n);
    findAverageRowValues(matrix, n);
    findAverageColumnValues(matrix, n);
    findTriangleSums(matrix, n);

    int closestElement = findClosestToAverage(matrix, n);
    cout << "Элемент, наиболее близкий к среднеарифметическому значению: " << closestElement << endl;

    return 0;
}
