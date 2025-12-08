#include <stdio.h>

int main() {
    int matriz[10][10];
    int N;
    int fila_usuario;
    int max;
    int i, j;

    printf("Ingrese la dimension N de la matriz (N <= 10): ");
    scanf("%d", &N);

    if (N > 10 || N < 1) {
        printf("Error: Dimension no válida.\n");
        return 1;
    }

    printf("Ingrese los valores de la matriz %dx%d:\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nIngrese el numero de fila para buscar el máximo (0 a %d): ", N - 1);
    scanf("%d", &fila_usuario);

    if (fila_usuario < 0 || fila_usuario >= N) {
        printf("Error: La fila %d no existe.\n", fila_usuario);
        return 1;
    }

    max = matriz[fila_usuario][0];


    for (j = 1; j < N; j++) {

        if (matriz[fila_usuario][j] > max) {
            max = matriz[fila_usuario][j];
        }
    }

    printf("El valor maximo en la fila %d es: %d\n", fila_usuario, max);

    return 0;
}
