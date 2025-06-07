#include <iostream>
#include <vector>
#include <cstdint>
#include <chrono>
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "stdSort.h"
#include "timSort.h"
#include "lectura.h"
#include "radixSort.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " archivo.lcp" << std::endl;
        return 1;
    }
    std::string algoritmo = argv[2];
    // Lee el arreglo desde el archivo binario pasado como argumento
    std::vector<int32_t> arr_original = leer_arreglo(argv[1]);

    if (arr_original.empty()) {
        std::cerr << "No se pudo leer el arreglo o está vacío." << std::endl;
        return 1;
    }

    // Haz una copia para ordenar (esto asegura que siempre ordenas el mismo arreglo)
    std::vector<int32_t> arr = arr_original;

    // Medición de tiempo SOLO del algoritmo
    auto start = std::chrono::high_resolution_clock::now();

    // Llama al algoritmo que quieras probar
    if (algoritmo == "insertionSort") {
        insertionSort(arr);
    } else if (algoritmo == "mergeSort") {
        mergeSort(arr);
    } else if (algoritmo == "quickSort") {
        quickSort(arr);
    } else if (algoritmo == "heapSort") {
        heapSort(arr);
    } else if (algoritmo == "stdSort") {
        stdSort(arr);
    } else if (algoritmo == "timSort") {
        timSort(arr);
    } else if(algoritmo == "radixSort"){
        radixSort(arr);
    } else {
        std::cerr << "Algoritmo no reconocido: " << algoritmo << std::endl;
        return 1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    double tiempo = std::chrono::duration<double>(end - start).count();

    std::cout << algoritmo << ";" << argv[1] << ";" << tiempo << std::endl;


    return 0;
}