#include <stdio.h>
#include <gmp.h>
#include <time.h>  
#include <string.h>
#include <stdlib.h>

void calcular_digitos_pi(int n);
void explicar_serie_chudnovsky();
void calcular_termino(int k, mpf_t termino);
int contar_digitos_correctos(const char *pi_calculado, const char *pi_referencia);

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
                if (num_digitos > 0) {
                    // Medir el tiempo de inicio
                    clock_t inicio = clock();
                    
                    calcular_digitos_pi(num_digitos);
                    
                    // Medir el tiempo de fin
                    clock_t fin = clock();
                    
                    // Calcular el tiempo transcurrido
                    double tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
                    printf("Tiempo de ejecucion: %.2f segundos\n", tiempo_transcurrido);
                } else {
                    printf("Por favor, ingrese un numero positivo.\n");
                }
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
    int k, limite;
    mpf_set_default_prec(n * 3.32 + 50);  // Ajuste de la precisión en bits

    mpf_t pi, sumatoria, constante, termino;
    mpf_init(pi);
    mpf_init(sumatoria);
    mpf_set_ui(sumatoria, 0);

    mpf_init(constante);
    mpf_sqrt_ui(constante, 10005);
    mpf_mul_ui(constante, constante, 426880);

    limite = n / 14 + 1;

    mpf_init(termino);

    // Calcular la sumatoria de la serie de Chudnovsky
    for (k = 0; k < limite; k++) {
        calcular_termino(k, termino);
        mpf_add(sumatoria, sumatoria, termino);
    }

    mpf_div(pi, constante, sumatoria);

    // Convertir el valor de pi a una cadena para comparar
    char *pi_str = NULL;
    gmp_asprintf(&pi_str, "%.*Ff", n, pi);

    // Valor de referencia de Pi con alta precisión
    const char *pi_referencia = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    // Contar cuántos dígitos coinciden con el valor de referencia
    int digitos_correctos = contar_digitos_correctos(pi_str, pi_referencia);

    gmp_printf("Valor de pi calculado con precision de %d digitos: %.*Ff\n", n, n, pi);
    printf("Precision alcanzada: %d digitos correctos\n", digitos_correctos);

    // Liberar memoria
    mpf_clear(pi);
    mpf_clear(sumatoria);
    mpf_clear(constante);
    mpf_clear(termino);
    free(pi_str);
}

void calcular_termino(int k, mpf_t termino) {
    mpf_t numerador, denominador, temp, base;
    mpz_t factorial_6k, factorial_3k, factorial_k;

    mpf_init(numerador);
    mpf_init(denominador);
    mpf_init(temp);
    mpf_init(base);
    mpz_init(factorial_6k);
    mpz_init(factorial_3k);
    mpz_init(factorial_k);

    // Calculo de factoriales
    mpz_fac_ui(factorial_6k, 6 * k);
    mpz_fac_ui(factorial_3k, 3 * k);
    mpz_fac_ui(factorial_k, k);

    // Calculo del numerador
    mpf_set_z(numerador, factorial_6k);
    mpf_mul_ui(numerador, numerador, 13591409 + 545140134 * k);
    if (k % 2 != 0) {
        mpf_neg(numerador, numerador);
    }

    // Calculo del denominador
    mpf_set_z(denominador, factorial_3k);
    mpf_pow_ui(denominador, denominador, 3);
    mpf_set_z(temp, factorial_k);
    mpf_pow_ui(temp, temp, 3);
    mpf_mul(denominador, denominador, temp);

    mpf_set_ui(base, 640320);
    mpf_pow_ui(temp, base, 3 * k); // Calcular 640320^(3*k)
    mpf_mul(denominador, denominador, temp);

    // Calculo del termino
    mpf_div(termino, numerador, denominador);

    // Limpieza
    mpf_clear(numerador);
    mpf_clear(denominador);
    mpf_clear(temp);
    mpf_clear(base);
    mpz_clear(factorial_6k);
    mpz_clear(factorial_3k);
    mpz_clear(factorial_k);
}

void explicar_serie_chudnovsky() {
    printf("La serie de Chudnovsky es una serie rápida de convergencia para el cálculo de Pi. Utiliza una combinación de factoriales y potencias para lograr una alta precisión en el cálculo de Pi con relativamente pocos términos.\n");
}

int contar_digitos_correctos(const char *pi_calculado, const char *pi_referencia) {
    int i = 0;
    while (pi_calculado[i] && pi_referencia[i] && pi_calculado[i] == pi_referencia[i]) {
        i++;
    }
    return i;
}
