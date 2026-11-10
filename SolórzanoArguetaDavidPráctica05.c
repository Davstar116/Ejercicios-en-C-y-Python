#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 5  // Tamaño del stack y la cola

// Variables stack
int stack[SIZE];
int top = -1;

// Variables cola
int queue[SIZE];
int front = -1, rear = -1;

// Stack
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peekStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Cola
void insert(int value) {
    if (rear == SIZE - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) {
            front = 0;  // Primera insercion
        }
        rear++;
        queue[rear] = value;
    }
}

int removeQueue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

int peekQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue[front];
    }
}

// Funcion principal
int main() {
    int num;
    char input[10];
    
    // Ciclo leer y agregar
    printf("Teclee %d enteros:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%s", input);

        // Entrada a numero
        int valid = 1;
        for (int j = 0; input[j] != '\0'; j++) {
            if (!isdigit(input[j])) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            num = atoi(input);
            push(num);      // Agregar al stack
            insert(num);    // Agregar a la cola
        } else {
            printf("Entrada no válida. Por favor ingrese solo números enteros.\n");
            i--;  // Reintentar
        }
    }

    // Desplegar stack
    printf("Contenido del Stack:\n");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");

    // Desplegar cola
    printf("Contenido de la Cola:\n");
    while (front != -1 && front <= rear) {
        printf("%d ", removeQueue());
    }
    printf("\n");

    return 0;
}