#include "radixSort.h"


// Función auxiliar para obtener el dígito en la posición exp
static void countingSort(std::vector<int32_t>& arr, int exp) {
    int n = arr.size();
    std::vector<int32_t> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(std::vector<int32_t>& arr) {
    if (arr.empty()) return;

    // Encuentra el valor absoluto máximo para manejar negativos
    int32_t maxVal = *std::max_element(arr.begin(), arr.end(), [](int32_t a, int32_t b) {
        return std::abs(a) < std::abs(b);
    });
    maxVal = std::abs(maxVal);

    // Ordena los números positivos y negativos por separado
    std::vector<int32_t> positives, negatives;
    for (int32_t num : arr) {
        if (num >= 0)
            positives.push_back(num);
        else
            negatives.push_back(-num); // Convierte a positivo para ordenar
    }

    // Radix sort para positivos
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(positives, exp);

    // Radix sort para negativos
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(negatives, exp);

    // Reconstruye el arreglo: negativos (en orden inverso y negativos), luego positivos
    int idx = 0;
    for (int i = negatives.size() - 1; i >= 0; --i)
        arr[idx++] = -negatives[i];
    for (int i = 0; i < positives.size(); ++i)
        arr[idx++] = positives[i];
}