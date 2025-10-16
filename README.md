## Objetivos
- Comparar el rendimiento entre **Counting Sort** y **Shaker Sort**.  
- Medir y registrar los tiempos de ejecución de ambos algoritmos en un mismo entorno.  
- Asegurar que ambos métodos trabajen sobre el **mismo arreglo base** para mantener condiciones equitativas.  
- Analizar el comportamiento de cada algoritmo en función del tamaño.
---

## Requisitos del sistema
| Elemento | Especificación |
|--------------|-------------|
| **Lenguaje** | C++ |
| **Compilador** | Dev-C++ 6.3 |
| **Sistema operativo** | Windows 10 Pro (64 bits) |
| **Medición de tiempo** | `std::chrono::high_resolution_clock` |
| **Salida de resultados** | Archivo `.csv` generado con `ofstream` |

---

## Compilación

1. Abre el ejemplo.cpp en **Dev-C++**.  
2. Compile y ejecute el codigo.
3. Ingrese a la carpeta del proyecto y abra el archivo .csv que se generara automaticamente.
4. Si desea probar algun algoritmo con un arreglo especifico, ingrese a la carpeta src y abra el algoritmo.cpp que desea probar.
5. Se generara a su vez un .csv solo con las medidas de su arreglo probado.


---

## Ejecución del programa

1. Ejecuta el archivo compilado (por ejemplo, `main.exe`).  
2. En el menú principal, selecciona el algoritmo que deseas ejecutar:  
   ```
   1. Counting Sort
   2. Shaker Sort
   3. Salir
   ```
3. Al finalizar la ejecución, se generará automáticamente en la misma carpeta un archivo llamado:
   ```
   resultados.csv
   ```
   Este archivo contiene los tiempos de ejecución y la cantidad de datos procesados.

---

## Detalles del benchmark

- Los **arreglos de prueba son predeterminados**, asegurando que ambos algoritmos trabajen con los **mismos datos** en cada ejecución.  
- Cada método se ejecuta varias veces para obtener un promedio de tiempo más representativo.  
- Los tiempos se miden usando la librería estándar `<chrono>`.

---

## Información técnica

| Parámetro | Valor |
|------------|-------|
| Lenguaje | C++17 |
| Compilador | Dev-C++ 6.3 |
| Sistema operativo | Windows 10 Pro (64 bits) |
| Núcleos CPU usados | 1 |
| Tiempo medido con | `std::chrono::high_resolution_clock` |
| Semillas | No utilizadas (arreglos fijos) |
| Commit hash final | *(por agregar tras el último commit)* |

---

## Archivo de salida (`resultados.csv`)

Ejemplo de contenido:

```
Algoritmo,Tamaño,Tiempo(ms)
Counting Sort,10000,0.42
Shaker Sort,10000,19.88
Counting Sort,50000,1.05
Shaker Sort,50000,510.73
```

---

## Estructura del proyecto

```
📁 COMPARACION-DE-ALGORITMOS-DE-ORDENACION---G1-EQUIPO-02/
│
├── README.md           # Readme con indicaciones
├── .gitignore          # Para excluir archivos .exe
├── docs/               # Documento actual
│        -Manuscrito     # Articulo cientifico
│        -Diapositiva    # Diapositiva para presentacion
├── include/ 
│        -Archivo .cpp   # Programa principal
├── src/ 
│        -Countingsort.cpp  # Codigos aislados de Countingsort 
│        -Shakersort.cpp      y Shakersort
├── data/ 
│        -Datos.exe         # Datos de entrada probados
├── results/
         -resultados.csv    #Resultados enlistados
---

## Resultados esperados
- **Counting Sort:** Complejidad teórica O(n + k).  
  Rinde mejor con números enteros y rangos limitados.  
- **Shaker Sort:** Complejidad teórica O(n²).  
  Su desempeño mejora cuando los datos están parcialmente ordenados.

---

## ✉️ Autores
**[Russbell Juan Pablo Arratia Paz]**
**[Alexander Efrain Contreras Rodriguez]**  
**[Danitza Carmen Capía Quiñonez]**  
Proyecto académico — Curso de Programación avanzada.  
2025  