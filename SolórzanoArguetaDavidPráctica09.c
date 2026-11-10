#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20
#define DELETED -1

typedef struct {
    int key;
    int value;
} HashTableItem;

HashTableItem* hashTable[TABLE_SIZE];

// Función
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insertar elemento
void insert(int key, int value) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i * i) % TABLE_SIZE] != NULL && hashTable[(index + i * i) % TABLE_SIZE]->key != DELETED) {
        i++;
    }
    HashTableItem* newItem = (HashTableItem*)malloc(sizeof(HashTableItem));
    newItem->key = key;
    newItem->value = value;
    hashTable[(index + i * i) % TABLE_SIZE] = newItem;
}

// Buscar elemento
HashTableItem* search(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i * i) % TABLE_SIZE] != NULL) {
        if (hashTable[(index + i * i) % TABLE_SIZE]->key == key) {
            return hashTable[(index + i * i) % TABLE_SIZE];
        }
        i++;
    }
    return NULL;
}

// Eliminar tabla
void delete(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i * i) % TABLE_SIZE] != NULL) {
        if (hashTable[(index + i * i) % TABLE_SIZE]->key == key) {
            hashTable[(index + i * i) % TABLE_SIZE]->key = DELETED;
            hashTable[(index + i * i) % TABLE_SIZE]->value = 0;
            return;
        }
        i++;
    }
}

// Mostrar contenido
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL || hashTable[i]->key == DELETED) {
            printf("%d: (~,~)\n", i);
        } else {
            printf("%d: (%d,%d)\n", i, hashTable[i]->key, hashTable[i]->value);
        }
    }
}

int main() {
    // Insertar elementos
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    insert(24, 11);
    insert(64, 11);
    insert(84, 11);

    // Mostrar tabla
    display();

    // Borrar elemento
    delete(42);
    printf("\nDespués de borrar el elemento con clave 42:\n");
    display();

    return 0;
}