/*
Лабораторная работа 2
Программа для обработки матриц
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <limits>

using namespace std;

// Размер матрицы (через код или закомментированный вариант через ввод в консоль)
// int n;
// cout << "Размер матрицы? (например - 5):\n";
// cin >> n;
const int n = 5;

int findMin(int pInt[n][n], int n) {
    int minVal = pInt[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
    }
    return minVal;
}

int findMax(int pInt[n][n], int n) {
    int maxVal = pInt[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
    }
    return maxVal;
}

int findMinLowerTriangle(int pInt[n][n], int n) {
    int minVal = pInt[n-1][0]; // Инициализируем минимум первым элементом нижней строки

    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
    }
    return minVal;
}

int findMaxLowerTriangle(int pInt[n][n], int n) {
    int maxVal = pInt[n-1][0]; // Инициализируем максимум первым элементом нижней строки

    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
    }
    return maxVal;
}

int findMinUpperTriangle(int pInt[n][n], int n) {
    int minVal = pInt[0][0]; // Инициализируем минимум первым элементом верхней строки

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
    }
    return minVal;
}

int findMaxUpperTriangle(int pInt[n][n], int n) {
    int maxVal = pInt[0][0]; // Инициализируем максимум первым элементом верхней строки

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
    }
    return maxVal;
}

int findMinDiagonal(int pInt[n][n], int n) {
    int minVal = pInt[0][0]; // Инициализируем минимум первым элементом на главной диагонали

    for (int i = 1; i < n; i++) {
        if (pInt[i][i] < minVal) {
            minVal = pInt[i][i];
        }
    }
    return minVal;
}

int findMaxDiagonal(int pInt[n][n], int n) {
    int maxVal = pInt[0][0]; // Инициализируем максимум первым элементом на главной диагонали

    for (int i = 1; i < n; i++) {
        if (pInt[i][i] > maxVal) {
            maxVal = pInt[i][i];
        }
    }
    return maxVal;
}

int findMinSecondaryDiagonal(int pInt[n][n], int n) {
    int minVal = pInt[0][n - 1]; // Инициализируем минимум последним элементом на второстепенной диагонали

    for (int i = 1; i < n; i++) {
        if (pInt[i][n - 1 - i] < minVal) {
            minVal = pInt[i][n - 1 - i];
        }
    }
    return minVal;
}

int findMaxSecondaryDiagonal(int pInt[n][n], int n) {
    int maxVal = pInt[0][n - 1]; // Инициализируем максимум последним элементом на второстепенной диагонали

    for (int i = 1; i < n; i++) {
        if (pInt[i][n - 1 - i] > maxVal) {
            maxVal = pInt[i][n - 1 - i];
        }
    }
    return maxVal;
}

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

void findColumnSums(int pInt[n][n], int n) {
    cout << "Суммы элементов в каждом столбце матрицы:\n";
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pInt[i][j];
        }
        cout << "Сумма элементов в столбце " << j + 1 << ": " << sum << endl;
    }
}

void findMinRowValues(int pInt[n][n], int n) {
    cout << "Минимальные значения в каждой строке матрицы:\n";
    for (int i = 0; i < n; i++) {
        int minVal = std::numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] < minVal) {
                minVal = pInt[i][j];
            }
        }
        cout << "Минимальное значение в строке " << i + 1 << ": " << minVal << endl;
    }
}

void findMaxRowValues(int pInt[n][n], int n) {
    cout << "Максимальные значения в каждой строке матрицы:\n";
    for (int i = 0; i < n; i++) {
        int maxVal = std::numeric_limits<int>::min();
        for (int j = 0; j < n; j++) {
            if (pInt[i][j] > maxVal) {
                maxVal = pInt[i][j];
            }
        }
        cout << "Максимальное значение в строке " << i + 1 << ": " << maxVal << endl;
    }
}

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

void findTriangleSums(int pInt[n][n], int n) {
    int upperSum = 0;
    int lowerSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                upperSum += pInt[i][j];
            }
            if (i >= j) {
                lowerSum += pInt[i][j];
            }
        }
    }

    cout << "Сумма элементов верхнетреугольной части: " << upperSum << endl;
    cout << "Сумма элементов нижнетреугольной части: " << lowerSum << endl;
}

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
            double diff = std::abs(pInt[i][j] - average);
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

    srand(time(0));

    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int min = -10;
            int max = 10;

            int randomNumber = rand() % (max - min + 1) + min;

            matrix[i][j] = randomNumber;
        }

    }

    cout << "Элементы матрицы:\n";
    for (int i = 0; i < n; ++i, cout << endl) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
    }
    cout << endl;

    // Нахождение минимума матрицы
    int minMatrix = findMin(matrix, n);
    cout << "Минимум матрицы: " << minMatrix << endl;

    // Нахождение максимума матрицы
    int maxMatrix = findMax(matrix, n);
    cout << "Максимум матрицы: " << maxMatrix << endl;

    // Нахождение минимума в нижнетреугольной части матрицы
    int minLowerTriangle = findMinLowerTriangle(matrix, n);
    cout << "Минимум в нижнетреугольной части матрицы: " << minLowerTriangle << endl;

    // Нахождение максимума в нижнетреугольной части матрицы
    int maxLowerTriangle = findMaxLowerTriangle(matrix, n);
    cout << "Максимум в нижнетреугольной части матрицы: " << maxLowerTriangle << endl;

    // Нахождение минимума в верхнетреугольной части матрицы
    int minUpperTriangle = findMinUpperTriangle(matrix, n);
    cout << "Минимум в верхнетреугольной части матрицы: " << minUpperTriangle << endl;

    // Нахождение максимума в верхнетреугольной части матрицы
    int maxUpperTriangle = findMaxUpperTriangle(matrix, n);
    cout << "Максимум в верхнетреугольной части матрицы: " << maxUpperTriangle << endl;

    // Нахождение минимума на главной диагонали матрицы
    int minDiagonal = findMinDiagonal(matrix, n);
    cout << "Минимум на главной диагонали матрицы: " << minDiagonal << endl;

    // Нахождение максимума на главной диагонали матрицы
    int maxDiagonal = findMaxDiagonal(matrix, n);
    cout << "Максимум на главной диагонали матрицы: " << maxDiagonal << endl;

    // Нахождение минимума на второстепенной диагонали матрицы
    int minSecondaryDiagonal = findMinSecondaryDiagonal(matrix, n);
    cout << "Минимум на второстепенной диагонали матрицы: " << minSecondaryDiagonal << endl;

    // Нахождение максимума на второстепенной диагонали матрицы
    int maxSecondaryDiagonal = findMaxSecondaryDiagonal(matrix, n);
    cout << "Максимум на второстепенной диагонали матрицы: " << maxSecondaryDiagonal << endl;

    // Нахождение среднеарифметического значения элементов матрицы
    double average = findAverageMatrix(matrix, n);
    cout << "Среднеарифметическое значение элементов матрицы: " << average << endl;

    // Нахождение среднеарифметического значения элементов нижнетреугольной части матрицы
    double averageLowerTriangle = findAverageLowerTriangle(matrix, n);
    cout << "Среднеарифметическое значение элементов нижнетреугольной части матрицы: " << averageLowerTriangle << endl;

    // Нахождение среднеарифметического значения элементов верхнетреугольной части матрицы
    double averageUpperTriangle = findAverageUpperTriangle(matrix, n);
    cout << "Среднеарифметическое значение элементов верхнетреугольной части матрицы: " << averageUpperTriangle << endl;

    // Нахождение суммы элементов в каждой строке матрицы
    findRowSums(matrix, n);

    // Нахождение суммы элементов в каждом столбце матрицы
    findColumnSums(matrix, n);

    // Нахождение минимальных значений в каждой строке матрицы
    findMinRowValues(matrix, n);

    // Нахождение максимальных значений в каждой строке матрицы
    findMaxRowValues(matrix, n);

    // Нахождение минимальных значений в каждом столбце матрицы
    findMinColumnValues(matrix, n);

    // Нахождение максимальных значений в каждом столбце матрицы
    findMaxColumnValues(matrix, n);

    // Нахождение среднеарифметических значений в каждой строке матрицы
    findAverageRowValues(matrix, n);

    // Нахождение среднеарифметических значений в каждом столбце матрицы
    findAverageColumnValues(matrix, n);

    // Нахождение суммы нижнетреугольной и верхнетреугольной частей матрицы
    findTriangleSums(matrix, n);

    // Нахождение элемента, наиболее близкого к среднеарифметическому значению
    int closestElement = findClosestToAverage(matrix, n);
    cout << "Элемент, наиболее близкий к среднеарифметическому значению: " << closestElement << endl;
}

