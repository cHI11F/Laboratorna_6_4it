#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

void fillArrayRandom(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 - 50;
    }
}

void printArray(const double arr[], int size) {
    cout << "Array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(4) << arr[i] << " ";
    }
    cout << endl;
}

double productPositiveElements(const double arr[], int size) {
    double posProduct = 1.0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            posProduct *= arr[i];
        }
    }
    return posProduct;
}

double sumElementsBeforeMinimum(const double arr[], int size) {
    double minElement = arr[0];
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }

    double sum = 0.0;
    for (int i = 0; i < minIndex; ++i) {
        sum += arr[i];
    }
    return sum;
}

void orderEvenOddElements(double arr[], int size) {
    vector<double> evenElements;
    vector<double> oddElements;

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            evenElements.push_back(arr[i]);
        }
        else {
            oddElements.push_back(arr[i]);
        }
    }

    sort(evenElements.begin(), evenElements.end());
    sort(oddElements.begin(), oddElements.end());

    int index = 0;
    for (double evenElement : evenElements) {
        arr[index++] = evenElement;
    }
    for (double oddElement : oddElements) {
        arr[index++] = oddElement;
    }
}

int main() {
    int n;
    cout << "Array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size (should be greater than 0)" << endl;
        return 1;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    double* arr = new double[n];

    fillArrayRandom(arr, n);

    printArray(arr, n);

    double posProduct = productPositiveElements(arr, n);
    cout << "Product(P): " << posProduct << endl;

    double sumBeforeMin = sumElementsBeforeMinimum(arr, n);
    cout << "Sum(BM): " << sumBeforeMin << endl;

    orderEvenOddElements(arr, n);

    printArray(arr, n);

    delete[] arr;

    return 0;
}