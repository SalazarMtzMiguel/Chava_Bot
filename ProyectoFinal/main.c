#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10

struct Producto {
    long long codigo_barras;
    char producto[45];
    float precio_compra;
    float precio_venta;
    float existencia;
};

void ingresarProducto(struct Producto *p) {
    printf("Ingrese el CODIGO_BARRAS (12 dígitos): ");
    scanf("%lld", &p->codigo_barras);

    printf("Ingrese el PRODUCTO (máximo 45 caracteres): ");
    scanf(" %[^\n]", p->producto);

    printf("Ingrese el PRECIO_COMPRA: ");
    scanf("%f", &p->precio_compra);

    printf("Ingrese el PRECIO_VENTA: ");
    scanf("%f", &p->precio_venta);

    printf("Ingrese la EXISTENCIA: ");
    scanf("%f", &p->existencia);
}

void mostrarProducto(struct Producto *p) {
    printf("\n----- Información del Último Producto Ingresado -----\n");
    printf("CODIGO_BARRAS: %lld\n", p->codigo_barras);
    printf("PRODUCTO: %s\n", p->producto);
    printf("PRECIO_COMPRA: %.2f\n", p->precio_compra);
    printf("PRECIO_VENTA: %.2f\n", p->precio_venta);
    printf("EXISTENCIA: %.2f\n", p->existencia);
    printf("-----------------------------------------------------\n");
}

int main() {
    struct Producto producto;
    int opcion, opcionSubMenu;
    int productoIngresado = 0; // Variable para controlar si se ha ingresado un producto

    do {
        printf("\n----- Menú Principal -----\n");
        printf("1. Empresa\n");
        printf("2. Empleados\n");
        printf("3. Clientes\n");
        printf("4. Productos\n");
        printf("5. Pedidos\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
            case 2:
            case 3:
            case 5:
                // Regresar al inicio del bucle
                break;
            case 4:
                do {
                    printf("\n----- Menú de Productos -----\n");
                    printf("1. Código de barras\n");
                    printf("2. Producto\n");
                    printf("3. Precio de compra\n");
                    printf("4. Precio de venta\n");
                    printf("5. Existencia\n");
                    printf("6. Salir al Menú Principal\n");
                    printf("Seleccione una opción: ");
                    scanf("%d", &opcionSubMenu);

                    switch (opcionSubMenu) {
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                            ingresarProducto(&producto);
                            mostrarProducto(&producto);
                            productoIngresado = 1;
                            break;
                        case 6:
                            // Regresar al menú principal
                            break;
                        default:
                            printf("Opción no válida. Inténtelo de nuevo.\n");
                    }
                } while (opcionSubMenu != 6);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 6);

    if (productoIngresado) {
        mostrarProducto(&producto);
    }

    return 0;
}