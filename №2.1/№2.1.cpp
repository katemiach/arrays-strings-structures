#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Ініціалізація масиву випадковими числами
void initArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100; // Генеруємо випадкові числа від -100 до 100
    }
}

// Друк масиву
void printArray(int* arr, int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Видалення елементів з парними індексами
void deleteEvenIndexElements(int* arr, int& n) {
    int* temp = new int[n / 2 + 1];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            temp[j++] = arr[i];
        }
    }
    n = j;
    copy(temp, temp + n, arr);
    delete[] temp;
}

// Додавання K елементів в кінець
void addElements(int* arr, int& n, int k) {
    int* temp = new int[n + k];
    copy(arr, arr + n, temp);
    for (int i = n; i < n + k; i++) {
        temp[i] = rand() % 201 - 100;
    }
    n += k;
    copy(temp, temp + n, arr);
    delete[] temp;
}

// Обмін місцями мінімального та максимального елементів
void swapMinMax(int* arr, int n) {
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }
    swap(arr[minIndex], arr[maxIndex]);
}

// Пошук першого негативного елемента
int findFirstNegative(int* arr, int n) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] < 0) return comparisons;
    }
    return -1;
}

// Сортування масиву методом бульбашки
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Пошук першого негативного елемента у відсортованому масиві
int findFirstNegativeSorted(int* arr, int n) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] < 0) return comparisons;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n]; // Виділяємо пам'ять для масиву

    // 1) Сформувати масив з n елементів за допомогою датчика випадкових чисел
    initArray(arr, n);

    // 2) Роздрукувати отриманий масив
    printArray(arr, n);

    // 3) Виконати видалення зазначених елементів з масиву
    deleteEvenIndexElements(arr, n);

    // 4) Вивести отриманий результат
    printArray(arr, n);

    // 5) Виконати додавання зазначених елементів в масив
    int k;
    cout << "Enter number of elements to add: ";
    cin >> k;
    addElements(arr, n, k);

    // 6) Вивести отриманий результат
    printArray(arr, n);

    // 7) Виконати перестановку елементів у масиві
    swapMinMax(arr, n);

    // 8) Вивести отриманий результат
    printArray(arr, n);

    // 9) Виконати пошук вказаних в масиві елементів і підрахувати кількість порівнянь
    int comparisons = findFirstNegative(arr, n);
    if (comparisons == -1) {
        cout << "No negative elements found" << endl;
    }
    else {
        cout << "First negative element found after " << comparisons << " comparisons" << endl;
    }

    // 10) Вивести отриманий результат (вже виведено в п.9)

    // 11) Виконати сортування масиву зазначеним методом
    bubbleSort(arr, n);

    // 12) Вивести отриманий результат
    printArray(arr, n);

    // 13) Виконати пошук вказаних елементів у відсортованому масиві і підрахувати кількість порівнянь
    comparisons = findFirstNegativeSorted(arr, n);
    if (comparisons == -1) {
        cout << "No negative elements found" << endl;
    }
    else {
        cout << "First negative element found after " << comparisons << " comparisons" << endl;
    }

    // 14) Вивести отриманий результат (вже виведено в п.13)

    delete[] arr; // Звільняємо виділену пам'ять
    return 0;
}