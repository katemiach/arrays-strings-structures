#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для виділення пам'яті під одновимірний масив
int* formArray(int size) {
    return new int[size];
}

// Функція для заповнення одновимірного масиву випадковими числами
void initArray(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101 - 50; // Випадкові числа від -50 до 50
    }
}

// Функція для друку одновимірного масиву
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція для видалення N елементів з одновимірного масиву, починаючи з номера K
void deleteElements(int*& arr, int& size, int k, int n) {
    if (size == 0 || k >= size || n > size - k) {
        cout << "Error: Invalid input for deletion." << endl;
        return;
    }

    int* temp = new int[size - n];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i < k || i >= k + n) {
            temp[j++] = arr[i];
        }
    }
    delete[] arr;
    arr = temp;
    size -= n;
}

// Функція для виділення пам'яті під двовимірний масив
int** formMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Функція для заповнення двовимірного масиву випадковими числами
void initMatrix(int** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101 - 50; // Випадкові числа від -50 до 50
        }
    }
}

// Функція для друку двовимірного масиву
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для додавання стовпця з числами на початок двовимірного масиву
void addColumn(int**& matrix, int& rows, int& cols) {
    int** temp = new int* [rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = new int[cols + 1];
        temp[i][0] = i + 1; // Нові елементи стовпця ініціалізуються числами
        for (int j = 0; j < cols; j++) {
            temp[i][j + 1] = matrix[i][j];
        }
    }

    // Звільнення пам'яті старого масиву
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = temp;
    cols++;
}

int main() {
    int choice, size, k, n, rows, cols;
    int* arr = nullptr;
    int** matrix = nullptr;

    do {
        cout << "1. Form 1D array" << endl;
        cout << "2. Print 1D array" << endl;
        cout << "3. Delete elements from 1D array" << endl;
        cout << "4. Form 2D array" << endl;
        cout << "5. Print 2D array" << endl;
        cout << "6. Add column to 2D array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter size of the array: ";
            cin >> size;
            arr = formArray(size);
            initArray(arr, size);
            break;
        case 2:
            if (arr == nullptr) {
                cout << "Error: 1D array not formed yet." << endl;
            }
            else {
                printArray(arr, size);
            }
            break;
        case 3:
            if (arr == nullptr) {
                cout << "Error: 1D array not formed yet." << endl;
            }
            else {
                cout << "Enter starting index (k) and number of elements to delete (n): ";
                cin >> k >> n;
                deleteElements(arr, size, k, n);
            }
            break;
        case 4:
            cout << "Enter number of rows and columns: ";
            cin >> rows >> cols;
            matrix = formMatrix(rows, cols);
            initMatrix(matrix, rows, cols);
            break;
        case 5:
            if (matrix == nullptr) {
                cout << "Error: 2D array not formed yet." << endl;
            }
            else {
                printMatrix(matrix, rows, cols);
            }
            break;
        case 6:
            if (matrix == nullptr) {
                cout << "Error: 2D array not formed yet." << endl;
            }
            else {
                addColumn(matrix, rows, cols);
            }
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    // Звільнення пам'яті
    delete[] arr;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}