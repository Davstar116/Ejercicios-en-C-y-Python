#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura para almacenar los datos de los empleados
struct Empleado {
    int numEmpleado;
    char nombre[30];
    char apellido[30];
    char departamento[20];
    float sueldo;
};

// Función que imprime el reporte de un empleado
void imprimeReporte(struct Empleado emp) {
    printf("===========================\n");
    printf("Número    : %d\n", emp.numEmpleado);
    printf("Nombre    : %s\n", emp.nombre);
    printf("Apellido  : %s\n", emp.apellido);
    printf("Depto.    : %s\n", emp.departamento);
    printf("Sueldo    : $%.2f\n", emp.sueldo);
}

int main() {
    // Archivo de entrada
    char archivo[] = "C:/Users/david/Desktop/Practica/Empleados.txt";
    struct Empleado emp;
    
    // Variables locales
    char buff[255];
    int result;
    FILE *fp;

    // Abrimos el archivo en modo lectura
    fp = fopen(archivo, "r");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leemos la primera línea (encabezado) y la ignoramos
    fgets(buff, 255, (FILE*)fp);

    // Desplegamos el encabezado del reporte
    printf("Listado de Empleados\n");

    // Procesamos el archivo mientras no se alcance el fin de archivo (EOF)
    while (fscanf(fp, "%d %s %s %s %f", &emp.numEmpleado, emp.nombre, emp.apellido, emp.departamento, &emp.sueldo) != EOF) {
        imprimeReporte(emp);
    }

    // Cerramos el archivo
    fclose(fp);

    return 0;
}