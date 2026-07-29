#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *TipoProductos[]={"Galletas", "Snacks", "Cigarrilos", "Caramelos", "Bebidas"};

//Estructuras
struct Producto
{
    int ProductoID;
    int Cantidad;
    char *TipoProductos;
    float PrecioUnitario;
}typedef Producto;

struct Cliente
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;

//FUNCIONES

void cargarClientes(Cliente *clientes, int cantidad);
float costoTotal(Producto *producto);
void mostrarClientes(Cliente *clientes, int cantidad);
void LiberarMemoria(Cliente *clientes, int cantidad);
int main()
{
    int cantidadCliente = 0;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadCliente);
    fflush(stdin);

    if (cantidadCliente < 1 || cantidadCliente > 5)
    {
        printf("Cantidad de clientes invalida, debe estar entre 1 y 5\n");
        return 1;
    }
    
    Cliente *Clientes = malloc(cantidadCliente * sizeof(Cliente));

    cargarClientes(Clientes, cantidadCliente);
    mostrarClientes(Clientes, cantidadCliente);
    LiberarMemoria(Clientes, cantidadCliente);
    return 0;
}

void cargarClientes(Cliente *clientes, int cantidad)

{
    for (int i = 0; i < cantidad; i++)
    {
        clientes[i].ClienteID = i + 1;

        char buff[100];
        printf("Ingrese el nombre del cliente %d:\n", i+1);
        gets(buff);
        clientes[i].NombreCliente = malloc((strlen(buff)+1)*sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);

        clientes[i].CantidadProductosAPedir = 1 + rand()%5;
        clientes[i].Productos = malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = 1 + rand()%10;
            clientes[i].Productos[j].TipoProductos = TipoProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand()%91;
        }
        
    }
    
}

float costoTotal(Producto *producto)
{
    float resultado = 0;
    resultado = producto->Cantidad * producto->PrecioUnitario;
    return resultado;
}

void mostrarClientes(Cliente *clientes, int cantidad)
{
            printf("-------LISTA CLIENTES--------\n");
    for (int i = 0; i < cantidad; i++)
    {
        float total = 0;
        printf("ID del Cliente: %d\n", clientes[i].ClienteID);
        printf("Nombre del cliente: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("ID del producto: %d", clientes[i].Productos[j].ProductoID);
            printf("Cantidad de productos: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Productos: %s\n", clientes[i].Productos[j].TipoProductos);
            printf("Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            float costo = costoTotal(&clientes[i].Productos[j]);
            total += costo;
        }
        printf("TOTAL A PAGAR : %.2f\n", total);
    }
    
}

void LiberarMemoria(Cliente *clientes, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);
}