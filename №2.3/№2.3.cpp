#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 10; // Максимальний розмір матриці

// Функція для друку матриці
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int rows, cols;
    cout << "Enter the number of rows of the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    // Створення псевдодинамічного масиву (матриці)
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Формування матриці з використанням ГСЧ
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 21 - 10; // Генерація чисел від -10 до 10
        }
    }

    cout << "The matrix is formed:" << endl;
    printMatrix(matrix, rows, cols);

    // Знаходження суми непарних чисел побічної діагоналі
    int oddSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j) == (rows - 1) && matrix[i][j] % 2 != 0) {
                oddSum += matrix[i][j];
            }
        }
    }

    cout << "The sum of odd numbers of the side diagonal: " << oddSum << endl;

    // Звільнення пам'яті
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}