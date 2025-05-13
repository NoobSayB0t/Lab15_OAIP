#include <iostream>
#include <chrono>
using namespace std;

int arrLength = 0;

void fillRandomArray(int length, int data[]) {
    for (int i = 0; i != length; ++i) {
        data[i] = rand() % 1000;
    }
}

void mergeSort(int data[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);

    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int j = 0; j < n2; j++) R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        data[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void bubbleSort(int data[], int length) {
    for (int i = 0; i != length; ++i) {
        for (int j = 0; j != length - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите размер массивов A и B: ";
    cin >> arrLength;

    int arrA[10000], arrB[10000], arrC[20000];
    int countC = 0;

    fillRandomArray(arrLength, arrA);
    fillRandomArray(arrLength, arrB);

    cout << "\nМассив A:" << endl;
    for (int i = 0; i != arrLength; ++i) cout << arrA[i] << " ";

    cout << "\n\nМассив B:" << endl;
    for (int i = 0; i != arrLength; ++i) cout << arrB[i] << " ";

    for (int i = 0; i != arrLength; ++i) {
        if (arrA[i] % 2 != 0) arrC[countC++] = arrA[i];
        if (arrB[i] % 2 != 0) arrC[countC++] = arrB[i];
    }

    cout << "\n\nМассив C (нечетные элементы из A и B):" << endl;
    for (int i = 0; i != countC; ++i) cout << arrC[i] << " ";

    auto startTime = chrono::steady_clock::now();
    mergeSort(arrC, 0, countC - 1);
    auto endTime = chrono::steady_clock::now();
    auto mergeTime = chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    cout << "\n\nМассив C после сортировки слиянием:" << endl;
    for (int i = 0; i != countC; ++i) cout << arrC[i] << " ";
    cout << "\nВремя сортировки слиянием: " << mergeTime.count() << " мкс" << endl;

    startTime = chrono::steady_clock::now();
    bubbleSort(arrC, countC);
    endTime = chrono::steady_clock::now();
    auto bubbleTime = chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    cout << "\nМассив C после сортировки пузырьком:" << endl;
    for (int i = 0; i != countC; ++i) cout << arrC[i] << " ";
    cout << "\nВремя сортировки пузырьком: " << bubbleTime.count() << " мкс" << endl;
}
