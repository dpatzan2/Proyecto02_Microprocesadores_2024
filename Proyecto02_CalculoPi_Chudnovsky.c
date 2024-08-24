#include <stdio.h>
#include <math.h>

void calcular_digitos_pi(int n);
void explicar_serie_chudnovsky();

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

    printf("Calculo de %d digitos de Pi usando la serie de Chudnovsky...\n", n);
}

void explicar_serie_chudnovsky() {
    printf("La serie de Chudnovsky es una serie rapida de convergencia para el calculo de Pi...\n");
}
