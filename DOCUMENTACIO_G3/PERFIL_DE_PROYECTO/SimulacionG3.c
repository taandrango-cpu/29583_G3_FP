#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- DEFINICIÓN DE CONSTANTES ---
#define MAX_CLIENTES 50
#define LIMITE_INFINITO -1

typedef struct {
    int id;
    char nombre[50];
    double limiteCredito;
    double deudaActual;
    int puntos;
    int activo;
} Cliente;

Cliente baseDatos[MAX_CLIENTES];
int totalClientes = 0;

// --- PROTOTIPOS ---
void inicializarSistema();
void registrarCliente();
int buscarCliente(int idBuscado);
void procesarVenta();
void realizarAbono();
void mostrarReporte();
void limpiarBuffer();
void limpiarPantalla(); // NUEVA
void pausar();          // NUEVA

// --- MAIN ---
int main() {
    int opcion;
    inicializarSistema();

    do {
        limpiarPantalla(); // Limpia antes de mostrar el menú cada vez
        printf("\n=== SISTEMA DE GESTION CRM & CREDITOS ===\n");
        printf("1. Registrar Nuevo Cliente\n");
        printf("2. Realizar Venta\n");
        printf("3. Realizar Abono a Deuda\n");
        printf("4. Ver Reporte de Clientes\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");

        // Validación básica de entrada del menú
        if (scanf("%d", &opcion) != 1) {
            limpiarBuffer(); // Si mete una letra, limpiamos el error
            opcion = 0;      // Forzamos opción inválida
        }

        switch(opcion) {
            case 1:
                registrarCliente();
                pausar(); // Espera y luego limpia al volver al loop
                break;
            case 2:
                procesarVenta();
                pausar();
                break;
            case 3:
                realizarAbono();
                pausar();
                break;
            case 4:
                mostrarReporte();
                pausar();
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break; // Aquí no pausamos, sale directo
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                pausar();
        }
    } while(opcion != 5);

    return 0;
}

// --- HERRAMIENTAS VISUALES ---

// Función para limpiar pantalla compatible con Windows y Linux/Mac
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para limpiar el buffer de entrada (enter residuales)
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función UX: Mantiene el mensaje en pantalla hasta que el usuario decida continuar
void pausar() {
    printf("\n>> Presione ENTER para volver al menu...");
    limpiarBuffer(); // Aseguramos que no haya enters viejos
    getchar();       // Espera a que el usuario toque tecla
}

// --- LÓGICA DE NEGOCIO ---

void inicializarSistema() {
    for(int i = 0; i < MAX_CLIENTES; i++) {
        baseDatos[i].activo = 0;
    }
}

void registrarCliente() {
    limpiarPantalla(); // Limpiamos para que el formulario se vea ordenado

    if(totalClientes >= MAX_CLIENTES) {
        printf("Error: Base de datos llena.\n");
        return;
    }

    int i = totalClientes;
    int idTemp;
    double limTemp;

    printf("\n--- REGISTRO DE CLIENTE ---\n");

    do {
        printf("Ingrese Cedula/Pasaporte: ");
        scanf("%d", &idTemp);
        if(idTemp <= 0) printf("Error: ID invalido.\n");
    } while(idTemp <= 0);
    baseDatos[i].id = idTemp;

    printf("Ingrese Nombre (sin espacios): ");
    scanf("%s", baseDatos[i].nombre);

    do {
        printf("Limite de Credito (-1 para ILIMITADO): ");
        scanf("%lf", &limTemp);
        if(limTemp < 0 && limTemp != -1) printf("Error: Monto invalido.\n");
    } while(limTemp < 0 && limTemp != -1);

    baseDatos[i].limiteCredito = limTemp;
    baseDatos[i].deudaActual = 0.0;
    baseDatos[i].puntos = 0;
    baseDatos[i].activo = 1;

    totalClientes++;
    printf(">> Cliente registrado exitosamente.\n");
}

int buscarCliente(int idBuscado) {
    for(int i = 0; i < totalClientes; i++) {
        if(baseDatos[i].activo == 1 && baseDatos[i].id == idBuscado) {
            return i;
        }
    }
    return -1;
}

void procesarVenta() {
    limpiarPantalla();
    int id, pos, tipoVenta;
    double monto;

    printf("\n--- PROCESAR VENTA ---\n");
    printf("ID del Cliente: ");
    scanf("%d", &id);

    pos = buscarCliente(id);

    if(pos == -1) {
        printf("Error: Cliente no encontrado.\n");
        return;
    }

    printf("Cliente: %s | Deuda: $%.2lf | Limite: ", baseDatos[pos].nombre, baseDatos[pos].deudaActual);
    if(baseDatos[pos].limiteCredito == LIMITE_INFINITO) printf("ILIMITADO\n");
    else printf("$%.2lf\n", baseDatos[pos].limiteCredito);

    do {
        printf("Monto de la venta ($): ");
        scanf("%lf", &monto);
        if(monto <= 0) printf("Error: Monto debe ser positivo.\n");
    } while(monto <= 0);

    do {
        printf("Tipo (1=Contado, 2=Credito): ");
        scanf("%d", &tipoVenta);
    } while(tipoVenta != 1 && tipoVenta != 2);

    if(tipoVenta == 2) {
        if(baseDatos[pos].limiteCredito != LIMITE_INFINITO &&
           (baseDatos[pos].deudaActual + monto) > baseDatos[pos].limiteCredito) {
            printf("\n[ALERTA] Credito Insuficiente.\n");
            return;
        } else {
            baseDatos[pos].deudaActual += monto;
            printf(">> Credito aprobado.\n");
        }
    }

    int puntosGanados = (int)(monto / 10);
    baseDatos[pos].puntos += puntosGanados;
    printf(">> Venta finalizada. +%d puntos.\n", puntosGanados);
}

void realizarAbono() {
    limpiarPantalla();
    int id, pos;
    double abono;

    printf("\n--- REALIZAR ABONO ---\n");
    printf("ID del Cliente: ");
    scanf("%d", &id);

    pos = buscarCliente(id);
    if(pos != -1) {
        printf("Deuda Actual: $%.2lf\n", baseDatos[pos].deudaActual);

        do {
            printf("Monto a abonar: ");
            scanf("%lf", &abono);
            if(abono <= 0) printf("Error: Debe ser positivo.\n");
            else if(abono > baseDatos[pos].deudaActual) printf("Error: Excede la deuda.\n");
        } while(abono <= 0 || abono > baseDatos[pos].deudaActual);

        baseDatos[pos].deudaActual -= abono;
        printf(">> Abono registrado. Restante: $%.2lf\n", baseDatos[pos].deudaActual);
    } else {
        printf("Cliente no encontrado.\n");
    }
}

void mostrarReporte() {
    limpiarPantalla();
    printf("\n--- REPORTE DE ESTADO ---\n");
    printf("ID\tNombre\t\tDeuda\t\tLimite\t\tPuntos\n");
    printf("----------------------------------------------------------------\n");
    for(int i = 0; i < totalClientes; i++) {
        if(baseDatos[i].activo) {
            printf("%d\t%s\t\t$%.2lf\t", baseDatos[i].id, baseDatos[i].nombre, baseDatos[i].deudaActual);
            if(baseDatos[i].limiteCredito == LIMITE_INFINITO) printf("ILIMITADO\t");
            else printf("$%.2lf\t", baseDatos[i].limiteCredito);
            printf("%d\n", baseDatos[i].puntos);
        }
    }
    printf("----------------------------------------------------------------\n");
}
