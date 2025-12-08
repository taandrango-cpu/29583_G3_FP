#include <stdio.h>

int main() {
    int matriz[10][10];
    int N;
    int i, j;


    printf("Ingrese la dimension N de la matriz cuadrada (N <= 10): ");
    scanf("%d", &N);

    if (N > 10 || N < 1) {
        printf("Error: La dimensión debe estar entre 1 y 10.\n");
        return 1;
    }

    printf("\n--- Ingrese los elementos de la matriz ---\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n--- Matriz recorrida en sentido inverso ---\n");
    printf("(Desde la ultima fila y columna hacia la primera)\n\n");
    for (i = N - 1; i >= 0; i--) {
        for (j = N - 1; j >= 0; j--) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
