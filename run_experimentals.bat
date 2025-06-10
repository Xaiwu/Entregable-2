@echo off
echo algoritmo;archivo;tiempo > resultados.csv

REM Lista de algoritmos
set algos=insertionSort mergeSort quickSort heapSort stdSort timSort radixSort


set archivos=1000.lcp 20000.lcp 100000.lcp 1MB.lcp 5MB.lcp 10MB.lcp 50MB.lcp 100MB.lcp 


REM Repetir los experimentos 20 veces
for /L %%c in (1,1,20) do (
    for %%a in (%algos%) do (
        if "%%a"=="insertionSort" (
            for %%f in (1000.lcp 20000.lcp 100000.lcp 1MB.lcp 5MB.lcp 10MB.lcp 50MB.lcp 100MB.lcp) do (
                echo Ejecutando %%a con %%f
                main.exe %%f %%a >> resultados.csv
            )
        ) else (
            if "%%a"=="quickSort" (
                for %%f in (1000.lcp 20000.lcp 100000.lcp 1MB.lcp 5MB.lcp 10MB.lcp 50MB.lcp 100MB.lcp) do (
                    echo Ejecutando %%a con %%f
                    main.exe %%f %%a >> resultados.csv
                )
            ) else (
                for %%f in (%archivos%) do (
                    echo Ejecutando %%a con %%f
                    main.exe %%f %%a >> resultados.csv
                )
            )
        )
    )
)

pause
