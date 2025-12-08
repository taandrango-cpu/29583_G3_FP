#include <stdio.h>

int main() {
    int matriz[10][10];
    int N, M;
    int i, j;
    int res = 0;

    printf("Ingrese el numero de filas (N <= 10): ");
    scanf("%d", &N);
    printf("Ingrese el numero de columnas (M <= 10): ");
    scanf("%d", &M);

    if (N > 10 || M > 10) {
        printf("Error: Las dimensiones no pueden ser mayores a 10.\n");
        return 1;
    }

    printf("\n--- Ingrese los componentes de la matriz ---\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            printf("Ingrese componente [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            res = res + matriz[i][j];
        }
    }

    printf("\nLa suma de los componentes es: %d\n", res);

    return 0;
}
