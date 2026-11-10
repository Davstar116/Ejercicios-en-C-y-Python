#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// Definición de variables globales
struct node {
    int data;
    struct node *next;
    struct node *previo;  // Apuntador al nodo anterior
};

struct node *start = NULL;  // start es el pointer al primer nodo
struct node *found = NULL;  // found es el pointer al nodo encontrado
int count = 0;              // Número de nodos

// Definición de funciones
void insertFirst(int);       // Inserta un nodo al principio de la lista
void insertLast(int);        // Inserta un nodo al final de la lista
void insertAfter(int, int);  // Inserta un nodo después de otro
int find(int);               // Buscar un nodo
void traverse();             // Realiza el recorrido de la lista
void traverseInv();          // Realiza el recorrido inverso de la lista
void deleteFirst();          // Remueve el primer nodo de la lista
void deleteLast();           // Remueve el último elemento de la lista
void create();               // Función auxiliar, crea una lista

int main() {
    int dato, opcion;
    setlocale(LC_ALL, "");  // para caracteres del Español
    printf(" 1 - Insertar al inicio de la linked list.\n");
    printf(" 2 - Insertar al final de la linked list.\n");
    printf(" 3 - Insertar después de otro.\n");
    printf(" 4 - Buscar un nodo en la lista.\n");
    printf(" 5 - Desplegar la linked list (traverse).\n");
    printf(" 6 - Desplegar la linked list en orden inverso (traverseInv).\n");
    printf(" 7 - Borrar elemento al inicio\n");
    printf(" 8 - Borrar elemento al final.\n");
    printf(" 9 - Terminar\n");
    create();  // Crea una lista de prueba

    while (true) {
        printf("Teclee la opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:  // insertar al inicio
                printf("Teclee valor del elemento a insertar al inicio\n");
                scanf("%d", &dato);
                insertFirst(dato);
                break;
            case 2:  // insertar al final
                printf("Teclee valor del elemento a insertar al final\n");
                scanf("%d", &dato);
                insertLast(dato);
                break;
            case 3:  // insertar después
                printf("Teclee valor de la llave.\n");
                scanf("%d", &dato);
                int llave = find(dato);
                if (llave == -2) {  // find regresa -2 si la lista está vacía
                    break;
                }
                if (llave == -1) {  // find regresa -1 si no se encuentra
                    printf("No se encontró %d en la lista.\n", dato);
                    break;
                }
                printf("Teclee valor de nodo a insertar después de llave.\n");
                scanf("%d", &dato);
                insertAfter(llave, dato);
                break;
            case 4:  // buscar
                printf("Teclee valor del elemento a buscar.\n");
                scanf("%d", &dato);
                int encontrado = find(dato);
                if (encontrado == -2) {  // find regresa -2 si la lista está vacía
                    break;
                }
                if (encontrado == -1) {  // find regresa -1 si no se encuentra
                    printf("No se encontró %d en la lista.\n", dato);
                } else {
                    printf("Se encontró %d en la lista.\n", dato);
                }
                break;
            case 5:  // recorrer
                traverse();
                break;
            case 6:  // recorrer en orden inverso
                traverseInv();
                break;
            case 7:  // borrar el primero
                deleteFirst();
                break;
            case 8:  // borrar el último
                deleteLast();
                break;
            case 9:
                printf("Gracias por participar");
                exit(0);
            default:
                printf("Opción inválida, intente de nuevo\n");
        }
    }
    return 0;
}

void insertFirst(int dato) {
    struct node *t;
    t = malloc(sizeof(struct node));
    count++;
    if (start == NULL) {  // primera vez
        start = t;
        start->data = dato;
        start->next = NULL;
        start->previo = NULL;  // El primer nodo no tiene nodo previo
        return;
    }
    t->data = dato;
    t->next = start;
    t->previo = NULL;  // El nuevo primer nodo no tiene previo
    start->previo = t;
    start = t;
}

void insertLast(int dato) {
    struct node *t, *temp;
    t = malloc(sizeof(struct node));
    count++;
    if (start == NULL) {  // Primera vez
        start = t;
        start->data = dato;
        start->next = NULL;
        start->previo = NULL;
        return;
    }
    temp = start;
    while (temp->next != NULL) {  // busca el último nodo
        temp = temp->next;        // navega al siguiente nodo
    }
    temp->next = t;
    t->data = dato;
    t->next = NULL;
    t->previo = temp;  // Apunta al anterior nodo
}

int find(int datoBuscado) {
    struct node *t;
    t = start;
    if (t == NULL) {
        printf("Linked list vacía.\n");
        return -2;
    }
    while (t->next != NULL) {  // busca
        if (t->data == datoBuscado) {
            found = t;
            return t->data;
        } else {
            t = t->next;
        }
    }
    if (t->data == datoBuscado) {  // en caso de que sea el último
        found = t;
        return t->data;
    }
    return -1;
}

void insertAfter(int llave, int dato) {
    struct node *nuevo, *actual;
    if (start == NULL) {
        printf("Linked list vacía.\n");
        return;
    }
    int temp = find(llave);  // función find deja en found el nodo encontrado
    actual = found;          // found (global) apunta al nodo encontrado
    nuevo = malloc(sizeof(struct node));
    nuevo->data = dato;
    nuevo->next = actual->next;
    nuevo->previo = actual;  // Apuntamos al nodo anterior

    if (actual->next != NULL) {
        actual->next->previo = nuevo;  // Ajustamos el previo del siguiente nodo
    }
    actual->next = nuevo;
    count++;
    printf("Se insertó %d después de %d.\n", dato, llave);
}

void traverse() {
    struct node *t;
    t = start;
    if (t == NULL) {
        printf("Linked list vacía.\n");
        return;
    }
    printf("Hay %d elemento(s) en la linked list.\n", count);
    while (t->next != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("%d\n", t->data);
}

void traverseInv() {
    struct node *t;
    t = start;
    if (t == NULL) {
        printf("Linked list vacía.\n");
        return;
    }
    // Ir al último nodo
    while (t->next != NULL) {
        t = t->next;
    }
    printf("Recorrido inverso: ");
    while (t != NULL) {
        printf("%d <- ", t->data);
        t = t->previo;
    }
    printf("NULL\n");
}

void deleteFirst() {
    struct node *t;
    int n;
    if (start == NULL) {
        printf("Linked list vacía.\n");
        return;
    }
    n = start->data;
    t = start->next;
    if (t != NULL) {
        t->previo = NULL;  // El nuevo primer nodo no tiene previo
    }
    free(start);
    start = t;
    count--;
    printf("%d eliminado del inicio de la linked list.\n", n);
}

void deleteLast() {
    struct node *t, *u;
    int n;
    if (start == NULL) {
        printf("Linked list vacía.\n");
        return;
    }

    count--;

    if (start->next == NULL) {  // un solo nodo en la lista
        n = start->data;
        free(start);
        start = NULL;
        printf("%d eliminado del final de la linked list.\n", n);
        return;
    }

    t = start;

    while (t->next != NULL) {
        t = t->next;
    }

    n = t->data;
    if (t->previo != NULL) {
        t->previo->next = NULL;
    }

    free(t);
    printf("%d eliminado del final de la linked list.\n", n);
}

void create() {
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
}