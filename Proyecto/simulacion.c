#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- DEFINICIÓN DE CONSTANTES Y ESTRUCTURAS ---
#define MAX_CLIENTES 50

// Esta estructura representa la "Abstracción de Datos" mencionada en tu marco teórico
typedef struct {
    int id;                 // Cédula o ID único
    char nombre[50];
    float limiteCredito;    // El tope máximo que puede deber
    float deudaActual;      // Cuánto debe actualmente
    int puntos;             // Puntos de fidelización acumulados
    int activo;             // 1 = Existe, 0 = Espacio vacío
} Cliente;

// Base de datos simulada en memoria RAM
Cliente baseDatos[MAX_CLIENTES];
int totalClientes = 0;

// --- PROTOTIPOS DE FUNCIONES ---
void inicializarSistema();
void registrarCliente();
int buscarCliente(int idBuscado);
void procesarVenta();
void realizarAbono();
void mostrarReporte();

// --- FUNCIÓN PRINCIPAL (MAIN) ---
int main() {
    int opcion;
    inicializarSistema(); // Limpia la memoria al iniciar

    do {
        printf("\n=== SISTEMA DE GESTION CRM & CREDITOS ===\n");
        printf("1. Registrar Nuevo Cliente\n");
        printf("2. Realizar Venta (Calcula Puntos y Valida Credito)\n");
        printf("3. Realizar Abono a Deuda\n");
        printf("4. Ver Reporte de Clientes\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: registrarCliente(); break;
            case 2: procesarVenta(); break;
            case 3: realizarAbono(); break;
            case 4: mostrarReporte(); break;
            case 5: printf("Saliendo del sistema...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while(opcion != 5);

    return 0;
}

// --- IMPLEMENTACIÓN DE FUNCIONES ---

void inicializarSistema() {
    for(int i = 0; i < MAX_CLIENTES; i++) {
        baseDatos[i].activo = 0;
    }
}

void registrarCliente() {
    if(totalClientes >= MAX_CLIENTES) {
        printf("Error: Base de datos llena.\n");
        return;
    }

    int i = totalClientes;

    printf("\n--- REGISTRO DE CLIENTE ---\n");
    printf("Ingrese Cedula/Pasaporte: ");
    scanf("%d", &baseDatos[i].id);

    printf("Ingrese Nombre (sin espacios para este demo): ");
    scanf("%s", baseDatos[i].nombre);

    printf("Establezca Limite de Credito ($): ");
    scanf("%f", &baseDatos[i].limiteCredito);

    // Inicializamos valores en 0
    baseDatos[i].deudaActual = 0.0;
    baseDatos[i].puntos = 0;
    baseDatos[i].activo = 1; // Marcamos como ocupado

    totalClientes++;
    printf(">> Cliente registrado exitosamente.\n");
}

// Algoritmo de Búsqueda Secuencial (Lineal)
int buscarCliente(int idBuscado) {
    for(int i = 0; i < totalClientes; i++) {
        if(baseDatos[i].activo == 1 && baseDatos[i].id == idBuscado) {
            return i; // Retorna la posición en el arreglo
        }
    }
    return -1; // No encontrado
}

void procesarVenta() {
    int id, pos, tipoVenta;
    float monto;

    printf("\n--- PROCESAR VENTA ---\n");
    printf("ID del Cliente: ");
    scanf("%d", &id);

    pos = buscarCliente(id);

    if(pos == -1) {
        printf("Error: Cliente no encontrado.\n");
        return;
    }

    printf("Cliente seleccionado: %s | Deuda Actual: $%.2f | Limite: $%.2f\n",
            baseDatos[pos].nombre, baseDatos[pos].deudaActual, baseDatos[pos].limiteCredito);

    printf("Monto de la venta ($): ");
    scanf("%f", &monto);

    printf("Tipo de Venta (1 = Contado, 2 = Credito): ");
    scanf("%d", &tipoVenta);

    // --- AQUÍ ESTÁ TU IDEA A DEFENDER (Lógica Condicional vs Heurística) ---
    if(tipoVenta == 2) {
        // Verificamos si la nueva deuda superaría el límite
        if( (baseDatos[pos].deudaActual + monto) > baseDatos[pos].limiteCredito ) {
            printf("\n[ALERTA DE SEGURIDAD] Venta BLOQUEADA.\n");
            printf("Motivo: Excede el limite de credito autorizado.\n");
            printf("Disponible para credito: $%.2f\n", baseDatos[pos].limiteCredito - baseDatos[pos].deudaActual);
            return; // Detiene la función, no vende.
        } else {
            // Si pasa la validación, sumamos deuda
            baseDatos[pos].deudaActual += monto;
            printf(">> Credito aprobado. Nueva deuda: $%.2f\n", baseDatos[pos].deudaActual);
        }
    }

    // --- APLICACIÓN DE PUNTOS (Fidelización) ---
    // Regla: 1 punto por cada $10 gastados
    int puntosGanados = (int)(monto / 10);
    baseDatos[pos].puntos += puntosGanados;

    printf(">> Venta finalizada. El cliente gano %d puntos.\n", puntosGanados);
}

void realizarAbono() {
    int id, pos;
    float abono;

    printf("\n--- REALIZAR ABONO ---\n");
    printf("ID del Cliente: ");
    scanf("%d", &id);

    pos = buscarCliente(id);
    if(pos != -1) {
        printf("Deuda Actual: $%.2f. Ingrese monto a abonar: ", baseDatos[pos].deudaActual);
        scanf("%f", &abono);

        if(abono > baseDatos[pos].deudaActual) {
            printf("Error: No puede abonar mas de lo que debe.\n");
        } else {
            baseDatos[pos].deudaActual -= abono;
            printf(">> Abono registrado. Nuevo saldo pendiente: $%.2f\n", baseDatos[pos].deudaActual);
        }
    } else {
        printf("Cliente no encontrado.\n");
    }
}

void mostrarReporte() {
    printf("\n--- REPORTE DE ESTADO DE CLIENTES ---\n");
    printf("ID\tNombre\t\tDeuda\t\tLimite\t\tPuntos\n");
    printf("----------------------------------------------------------------\n");
    for(int i = 0; i < totalClientes; i++) {
        if(baseDatos[i].activo) {
            printf("%d\t%s\t\t$%.2f\t$%.2f\t%d\n",
                baseDatos[i].id,
                baseDatos[i].nombre,
                baseDatos[i].deudaActual,
                baseDatos[i].limiteCredito,
                baseDatos[i].puntos);
        }
    }
    printf("----------------------------------------------------------------\n");
}
