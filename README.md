## Compilación

```sh
g++ main.cpp lectura.cpp insertionSort.cpp mergeSort.cpp quickSort.cpp heapSort.cpp timSort.cpp radixSort.cpp stdSort.cpp -o main.exe
```

## Generación de archivos de prueba

Para generar archivos binarios de prueba, compila y ejecuta `generar_lcp.cpp`:

```sh
g++ generar_lcp.cpp -o generar_lcp.exe
```

Ejemplo para generar un archivo de 1 millón de enteros desordenados:
```sh
generar_lcp.exe desordenado archivo.lcp 1000000
```
Tipos de archivos soportados (`asc`, `desc`, `desordenado`, `parcial`).



## Notas
- Ejecutar un algoritmo específico manualmente:
  ```sh
  main.exe archivo.lcp algoritmo
  ```
  Ejemplo:
  ```sh
  main.exe 1MB.lcp quickSort
  ```
