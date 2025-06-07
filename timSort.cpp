#include "timSort.h"

const int RUN = 32;

// Ordena un pequeño segmento usando insertion sort
void insertionSortTim(std::vector<int32_t>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int32_t temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

// Fusiona dos segmentos ordenados
void mergeTim(std::vector<int32_t>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    std::vector<int32_t> left(len1), right(len2);
    for (int i = 0; i < len1; ++i)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; ++i)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];
}

// Implementación principal de TimSort
void timSort(std::vector<int32_t>& arr) {
    int n = arr.size();
    // Ordena segmentos pequeños con insertion sort
    for (int i = 0; i < n; i += RUN)
        insertionSortTim(arr, i, std::min(i + RUN - 1, n - 1));

    // Fusiona segmentos de tamaño RUN
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);
            if (mid < right)
                mergeTim(arr, left, mid, right);
        }
    }
}