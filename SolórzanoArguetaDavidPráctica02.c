#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Variables
int arreglo[MAX_SIZE];
int num_elementos = 0;

// Funciones
int insertar(int dato);
int busquedaBinaria(int dato);
void desplegarArreglo();
int getUnRandom();

// Funcion principal
int main() {
    int i, numero_elementos, elemento_generado;
    int repetidos = 0, insertados = 0, no_insertados = 0;

    // Numeros pseudoaleatorios
    srand(time(NULL));

    // Solicitar numero
    printf("Ingrese el número de elementos que desea cargar en el arreglo (maximo %d): ", MAX_SIZE);
    scanf("%d", &numero_elementos);

    if (numero_elementos > MAX_SIZE) {
        printf("Número de elementos excede el tamaño máximo permitido (%d).\n", MAX_SIZE);
        return 1;
    }

    // Insertar
    for (i = 0; i < numero_elementos; i++) {
        elemento_generado = getUnRandom();
        if (busquedaBinaria(elemento_generado) != -1) {
            // Elemento ya en el arreglo
            printf("El elemento %d ya está en el arreglo.\n", elemento_generado);
            repetidos++;
        } else {
            // Nuevo elemento
            if (insertar(elemento_generado)) {
                insertados++;
            } else {
                no_insertados++;
            }
        }
    }

    // Resultados
    printf("Número de elementos insertados: %d\n", insertados);
    printf("Número de elementos no insertados: %d\n", no_insertados);
    printf("Número de elementos repetidos: %d\n", repetidos);

    desplegarArreglo();

    return 0;
}

// Insertar un elemento
int insertar(int dato) {
    int i, j;

    // Si el arreglo esta lleno
    if (num_elementos >= MAX_SIZE) {
        return 0;
    }

    // Encuentra posicion
    for (i = 0; i < num_elementos; i++) {
        if (arreglo[i] > dato) {
            break;
        }
    }

    // Desplaza elementos
    for (j = num_elementos; j > i; j--) {
        arreglo[j] = arreglo[j - 1];
    }

    // Nuevo dato
    arreglo[i] = dato;
    num_elementos++;

    return 1;
}

// Buscar elemento busqueda binaria
int busquedaBinaria(int dato) {
    int bajo = 0, alto = num_elementos - 1, medio;

    while (bajo <= alto) {
        medio = (bajo + alto) / 2;
        if (arreglo[medio] == dato) {
            return medio;
        } else if (arreglo[medio] < dato) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }

    return -1;
}

// Desplegar arreglo
void desplegarArreglo() {
    int i;
    printf("Contenido del arreglo:\n");
    for (i = 0; i < num_elementos; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

// Generar un numero pseudoaleatorio
int getUnRandom() {
    return rand() % 10000; // Genera un número entre 0 y 9999
}