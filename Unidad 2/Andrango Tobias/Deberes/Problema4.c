#include <stdio.h>

int main() {
    int matriz[10][10];
    int N, filaA, filaB, aux;
    int i, j;

    printf("\n Intercambio de filas\n");
    printf("Ingrese la dimension N de la matriz (N <= 10): ");
    scanf("%d", &N);

    printf("Ingrese los valores de la matriz:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nIngrese la primera fila a intercambiar (0 a %d): ", N - 1);
    scanf("%d", &filaA);
    printf("Ingrese la segunda fila a intercambiar (0 a %d): ", N - 1);
    scanf("%d", &filaB);


    if (filaA >= 0 && filaA < N && filaB >= 0 && filaB < N) {

        for (j = 0; j < N; j++) {

            aux = matriz[filaA][j];
            matriz[filaA][j] = matriz[filaB][j];
            matriz[filaB][j] = aux;
        }

        printf("\nMatriz despues del intercambio:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Error: Una o ambas filas estan fuera de rango.\n");
    }

    return 0;
}
