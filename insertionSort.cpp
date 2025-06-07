#include "insertionSort.h"

// Función de ordenamiento Insertion Sort para un vector de enteros de 32 bits
void insertionSort(std::vector<int32_t>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int32_t key = arr[i];
        int j = i - 1;
        // Mueve los elementos mayores que key una posición adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}