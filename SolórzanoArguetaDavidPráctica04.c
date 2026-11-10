#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // String de terminacion
    const char endString[] = "00";
    
    // Almacenar cadenas leidas
    char buffer[256];
    
    // Apuntador almacenar dinamicamente las cadenas
    char *dynamicStr = NULL;
    
    // Inicializar el espacio dinamico
    dynamicStr = (char *) malloc(1);
    if (dynamicStr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    dynamicStr[0] = '\0'; // Asignar el primer byte

    // Solicitar la introduccion de cadenas
    printf("Teclee n líneas de texto (para terminar teclee 00):\n");

    // Ciclo while
    while (1) {
        // Leer cadena
        fgets(buffer, sizeof(buffer), stdin);
        
        // Eliminar salto
        buffer[strcspn(buffer, "\n")] = 0;

        // Comparar cadenas
        if (strcmp(buffer, endString) == 0) {
            break;
        }

        // Concatenar espacio en blanco
        strcat(buffer, " ");

        // Extender espacio dinamico
        dynamicStr = (char *) realloc(dynamicStr, strlen(dynamicStr) + strlen(buffer) + 1);
        if (dynamicStr == NULL) {
            printf("Error al reasignar memoria.\n");
            return 1;
        }

        // Concatenar ultima cadena
        strcat(dynamicStr, buffer);
    }

    // Resultado
    printf("Resultado: %s\n", dynamicStr);

    // Liberar memoria
    free(dynamicStr);

    return 0;
}