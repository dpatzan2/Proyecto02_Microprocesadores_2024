#include <stdio.h>
#include <math.h>
#include <omp.h>

void calcular_digitos_pi(int n);
void explicar_serie_chudnovsky();
double factorial(long num);

int main() {
    int opcion;
    do {
        printf("Menu:\n");
        printf("1. Calcular digitos de pi\n");
        printf("2. Explicacion serie Chudnovsky\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int num_digitos;
                printf("Ingrese el numero de digitos a calcular: ");
                scanf("%d", &num_digitos);
                calcular_digitos_pi(num_digitos);
                break;
            }
            case 2:
                explicar_serie_chudnovsky();
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Por favor intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}

void calcular_digitos_pi(int n) {
    int k;
    double numeroPI = 0.0;
    double numerador, denominador;
    int limite = (n + 3) / 14; 

    printf("Calculo de %d digitos de Pi usando la serie de Chudnovsky...\n", n);


    #pragma omp parallel for private(numerador, denominador) reduction(+:numeroPI)
    for (k = 0; k < limite; k++) {
        numerador = pow(-1, k) * factorial(6 * k) * (13591409 + 545140134 * k);
        denominador = factorial(3 * k) * pow(factorial(k), 3) * pow(640320, (3 * k + 1.5));
        numeroPI += numerador / denominador;
    }

    numeroPI *= 12;
    numeroPI = 1.0 / numeroPI;


    printf("Valor de pi calculado con precision de %d digitos: %.14f\n", n, numeroPI);
}

void explicar_serie_chudnovsky() {
    printf("La serie de Chudnovsky es una serie rapida de convergencia para el calculo de Pi...\n");
}


double factorial(long num) {
    double result = 1.0;
    for (long i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}
