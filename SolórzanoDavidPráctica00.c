#include <stdio.h>
#include <math.h>

// MedAri
double calcular_media_aritmetica(double datos[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += datos[i];
    }
    return suma / n;
}

// MedGeo
double calcular_media_geometrica(double datos[], int n) {
    double producto = 1.0;
    for (int i = 0; i < n; i++) {
        producto *= datos[i];
    }
    return pow(producto, 1.0 / n);
}

// DesEst
double calcular_desviacion_estandar(double datos[], int n, double media) {
    double suma_cuadrados = 0.0;
    for (int i = 0; i < n; i++) {
        suma_cuadrados += (datos[i] - media) * (datos[i] - media);
    }
    return sqrt(suma_cuadrados / n);
}

int main() {
    // Valores
    double maximas[] = {22.2, 24.6, 23.5, 22.8, 21.6, 19.4, 22.0};
    double minimas[] = {7.8, 10.2, 13.0, 12.1, 14.2, 8.9, 9.8};

    int n = sizeof(maximas) / sizeof(maximas[0]);

    // Max
    double media_max = calcular_media_aritmetica(maximas, n);
    double media_geo_max = calcular_media_geometrica(maximas, n);
    double desviacion_std_max = calcular_desviacion_estandar(maximas, n, media_max);

    // Min
    double media_min = calcular_media_aritmetica(minimas, n);
    double media_geo_min = calcular_media_geometrica(minimas, n);
    double desviacion_std_min = calcular_desviacion_estandar(minimas, n, media_min);

    // Resultados
    printf("Estadisticas para temperaturas maximas:\n");
    printf("Media Aritmetica: %.2f\n", media_max);
    printf("Media Geometrica: %.2f\n", media_geo_max);
    printf("Desviacion Estandar: %.2f\n", desviacion_std_max);

    printf("\nEstadisticas para temperaturas minimas:\n");
    printf("Media Aritmetica: %.2f\n", media_min);
    printf("Media Geometrica: %.2f\n", media_geo_min);
    printf("Desviacion Estandar: %.2f\n", desviacion_std_min);

    return 0;
}