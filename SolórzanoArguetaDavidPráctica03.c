#include <stdio.h>
#include <string.h>

// Funcion calculaLong
int calculaLong(const char *cadena);

// Funcion tieneLetra
void tieneLetra(const char *cadena, char letra);

int main() {
    // Areglo de punteros a char
    const char *UNAM[] = {
        "Universidad",
        "Nacional",
        "Autonoma",
        "de",
        "Mexico"
    };
    
    int longitudTotal = 0;

    // Calcular la longitud total del arreglo UNAM
    for (int i = 0; i < sizeof(UNAM) / sizeof(UNAM[0]); i++) {
        int longitud = calculaLong(UNAM[i]);
        longitudTotal += longitud;
    }

    // Imprimir la longitud total del arreglo UNAM
    printf("La longitud del String UNAM es de %d caracteres.\n", longitudTotal);

    // Verificar si cada palabra contiene la letra 'a'
    for (int i = 0; i < sizeof(UNAM) / sizeof(UNAM[0]); i++) {
        tieneLetra(UNAM[i], 'a');
    }

    return 0;
}

// Impl Funcion calculaLong
int calculaLong(const char *cadena) {
    int longitud = strlen(cadena);  // Calcula la longitud de la cadena
    printf("\"%s\" tiene %d letras.\n", cadena, longitud);
    return longitud;
}

// Impl Funcion tieneLetra
void tieneLetra(const char *cadena, char letra) {
    // Busca la letra
    const char *resultado = strchr(cadena, letra);
    if (resultado != NULL) {
        printf("La palabra \"%s\" SI tiene la letra %c.\n", cadena, letra);
    } else {
        printf("La palabra \"%s\" NO tiene la letra %c.\n", cadena, letra);
    }
}