#include <stdio.h>

// Funcion printArray
void printArray(int arr[], int size);

int main() {
    // Ejercicio 1
    int array1[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    
    // Despliega array1
    printf("array1 es: ");
    printArray(array1, 8);
    printf("\n");

    // Ejercicio 2
    int matrix[5][5];
    
    // Inicializacion matriz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = i * j;
        }
    }

    // Despliega matriz
    for (int i = 0; i < 5; i++) {
        printf("matrix[%d] es: ", i);
        printArray(matrix[i], 5);
        printf("\n");
    }

    return 0;
}

// Implementacion printArray
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
}