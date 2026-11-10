#include <stdio.h>
#include <locale.h>
#include <stdlib.h> // para srand, rand y malloc
#include <time.h>   // para time
#include <unistd.h> // para la funcion sleep

// Tamano maximo de la cola
#define MAX 10

// Variables globales
int queue[MAX];  // Cola priorizada
int front = -1, rear = -1; // Indicadores de la cola

// Funcion para insertar
void insert(int proceso) {
    if (rear == MAX - 1) {
        printf("La cola está llena, no se puede insertar más procesos.\n");
        return;
    }

    // Si cola vacia
    if (front == -1) {
        front = rear = 0;
        queue[rear] = proceso;
    } else {
        int i;
        // Encontrar posicion
        for (i = rear; i >= front && queue[i] > proceso; i--) {
            queue[i + 1] = queue[i]; // Mover elementos hacia la derecha
        }
        queue[i + 1] = proceso;
        rear++;
    }
}

// Remover elemento de mayor prioridad
int removeFirst() {
    if (front == -1) {
        printf("La cola está vacía.\n");
        return -1;
    }

    int proceso = queue[front];
    if (front == rear) {
        // Si solo queda un elemento en la cola
        front = rear = -1;
    } else {
        front++; // Avanzar el front
    }
    return proceso;
}

// Mostrar cola
void display() {
    if (front == -1) {
        printf("La cola está vacía.\n");
        return;
    }

    printf("Procesos en cola:\n");
    for (int i = front; i <= rear; i++) {
        printf("Proceso: %d\n", queue[i]);
    }
    printf("~~~~~~~~~~~~~~~~\n");
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL)); // Numeros pseudoaleatorios

    // Llenar la cola
    for (int i = 0; i < MAX; i++) {
        int proceso = rand() % 1000; // Generar numero aleatorio
        insert(proceso);
    }

    // Mostrar los procesos
    display();

    // Remover procesos
    while (front != -1) {
        printf("Esperando 1 segundo\n");
        sleep(1); // Esperar 1 segundo

        int proceso_removido = removeFirst();
        printf("Se removió el proceso %d\n", proceso_removido);
    }

    printf("La cola está vacía.\n");

    return 0;
}