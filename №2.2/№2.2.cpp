#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int MAX_SIZE = 100; // Maximum size of the sequence
    double sequence[MAX_SIZE];
    int n;

    // Input the size of the sequence and its elements
    cout << "Enter the size of the sequence: ";
    cin >> n;
    cout << "Enter the elements of the sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // Calculate the product of negative and the product of positive elements
    double negativeProduct = 1.0;
    double positiveProduct = 1.0;
    for (int i = 0; i < n; i++) {
        if (sequence[i] < 0) {
            negativeProduct *= sequence[i];
        }
        else {
            positiveProduct *= sequence[i];
        }
    }

    // Compare the absolute values of the product of negative and the product of positive elements
    double negativeAbsoluteValue = abs(negativeProduct);
    double positiveAbsoluteValue = abs(positiveProduct);
    if (negativeAbsoluteValue > positiveAbsoluteValue) {
        cout << "The absolute value of the product of negative elements (" << negativeAbsoluteValue
            << ") is greater than the absolute value of the product of positive elements (" << positiveAbsoluteValue << ")." << endl;
    }
    else if (negativeAbsoluteValue < positiveAbsoluteValue) {
        cout << "The absolute value of the product of positive elements (" << positiveAbsoluteValue
            << ") is greater than the absolute value of the product of negative elements (" << negativeAbsoluteValue << ")." << endl;
    }
    else {
        cout << "The absolute value of the product of negative elements and the absolute value of the product of positive elements are equal." << endl;
    }

    return 0;
}