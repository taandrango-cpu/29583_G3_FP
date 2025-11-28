#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menuPrincipal();
void subMenuExpresiones();
void resolverEcuacion2doGrado();
void pausar();

int main() {
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int opcion;
    do {
        system("cls");

        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Resolver Expresiones Matematicas (Sub-menu)\n");
        printf("2. Resolver Ecuacion de 2do Grado\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                subMenuExpresiones();
                break;
            case 2:
                resolverEcuacion2doGrado();
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                pausar();
        }
    } while(opcion != 3);
}

void subMenuExpresiones() {
    int subOpcion;
    float a, b, c, resultado;

    do {
        system("cls");

        printf("\n--- SUB-MENU: EXPRESIONES ---\n");
        printf("1. Suma de cuadrados: (a^2 + b^2)\n");
        printf("2. Promedio de 3 numeros: (a+b+c)/3\n");
        printf("3. Hipotenusa de un triangulo: sqrt(a^2 + b^2)\n");
        printf("4. Area de un circulo: pi * r^2\n");
        printf("5. Convertir Celsius a Fahrenheit: (C * 9/5) + 32\n");
        printf("6. Evaluar funcion y = 2x^2 + 5\n");
        printf("7. Regresar al Menu Principal\n");
        printf("Seleccione una expresion: ");
        scanf("%d", &subOpcion);

        if (subOpcion >= 1 && subOpcion <= 6) {
            switch(subOpcion) {
                case 1:
                    printf("\n--- Suma de Cuadrados ---\n");
                    printf("Ingrese valor a: "); scanf("%f", &a);
                    printf("Ingrese valor b: "); scanf("%f", &b);
                    resultado = pow(a, 2) + pow(b, 2);
                    printf("Resultado: %.2f\n", resultado);
                    break;
                case 2:
                    printf("\n--- Promedio ---\n");
                    printf("Ingrese nota 1: "); scanf("%f", &a);
                    printf("Ingrese nota 2: "); scanf("%f", &b);
                    printf("Ingrese nota 3: "); scanf("%f", &c);
                    resultado = (a + b + c) / 3;
                    printf("El promedio es: %.2f\n", resultado);
                    break;
                case 3:
                    printf("\n--- Hipotenusa ---\n");
                    printf("Ingrese cateto a: "); scanf("%f", &a);
                    printf("Ingrese cateto b: "); scanf("%f", &b);
                    resultado = sqrt(pow(a, 2) + pow(b, 2));
                    printf("La hipotenusa es: %.2f\n", resultado);
                    break;
                case 4:
                    printf("\n--- Area Circulo ---\n");
                    printf("Ingrese el radio r: "); scanf("%f", &a);
                    resultado = 3.14159 * pow(a, 2);
                    printf("El area del circulo es: %.2f\n", resultado);
                    break;
                case 5:
                    printf("\n--- Celsius a Fahrenheit ---\n");
                    printf("Ingrese grados Celsius: "); scanf("%f", &a);
                    resultado = (a * 9.0/5.0) + 32;
                    printf("Grados Fahrenheit: %.2f\n", resultado);
                    break;
                case 6:
                    printf("\n--- Funcion cuadratica simple ---\n");
                    printf("Ingrese valor de x: "); scanf("%f", &a);
                    resultado = 2 * pow(a, 2) + 5;
                    printf("El valor de y es: %.2f\n", resultado);
                    break;
            }
            pausar();
        } else if (subOpcion != 7) {
            printf("Opcion incorrecta.\n");
            pausar();
        }

    } while(subOpcion != 7);
}

void resolverEcuacion2doGrado() {
    system("cls");

    float a, b, c, determinante, x1, x2;

    printf("\n--- ECUACION DE 2DO GRADO (ax^2 + bx + c = 0) ---\n");
    printf("Ingrese coeficiente a: "); scanf("%f", &a);
    printf("Ingrese coeficiente b: "); scanf("%f", &b);
    printf("Ingrese coeficiente c: "); scanf("%f", &c);

    if (a == 0) {
        printf("Error: 'a' no puede ser 0 en una ecuacion cuadratica.\n");
    } else {
        determinante = pow(b, 2) - (4 * a * c);

        if (determinante > 0) {
            x1 = (-b + sqrt(determinante)) / (2 * a);
            x2 = (-b - sqrt(determinante)) / (2 * a);
            printf("Dos soluciones reales:\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        } else if (determinante == 0) {
            x1 = -b / (2 * a);
            printf("Una solucion real (raiz doble):\n");
            printf("x = %.2f\n", x1);
        } else {
            printf("No tiene soluciones reales (determinante negativo).\n");
            float parteReal = -b / (2 * a);
            float parteImag = sqrt(-determinante) / (2 * a);
            printf("Soluciones complejas: %.2f + %.2fi y %.2f - %.2fi\n",
                    parteReal, parteImag, parteReal, parteImag);
        }
    }
    pausar();
}

void pausar() {
    printf("\n");
    system("pause");
}
