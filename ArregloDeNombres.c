#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMA 5

void MostrarPersonas(char **nombre, int tama);
int BuscarNombrePorPalabra(char **nombre, char *palabra, int tama);
void BuscarNombrePorId(char **nombre, int indice, int tama);

int main()
{
    char *buff;
    char *nombre[TAMA];
    buff = (char *)malloc(100*sizeof(char));
    for (int i = 0; i < TAMA; i++)
    {
        printf("Ingrese el nombre Num [%d]\n", i+1);
        gets(buff);
        nombre[i] = (char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombre[i], buff);
    }
    MostrarPersonas(nombre, TAMA);


    int eleccion = 0;
    int indice;
    printf("Busqueda de nombre\n1 para ID\n2 para palabra");
    scanf("%d", &eleccion);
    fflush(stdin);
    
    if (eleccion == 1)
    {
        printf("Ingrese el id del nombre: ");
        scanf("%d", &indice);
        BuscarNombrePorId(nombre, indice, TAMA);
    } else if (eleccion == 2)
    {
        char *palabra = malloc(100 * sizeof(char));
        printf("Ingrese la palabra\n");
        fflush(stdin);
        gets(palabra);
        
        int resultado = BuscarNombrePorPalabra(nombre, palabra, TAMA);
        if (resultado != -1)
        {
            puts(nombre[resultado]);
        } else
        {
            printf("Nombre no encontrado\n");
        }
        
        free(palabra);
    }
    
    for (int i = 0; i < TAMA; i++)
    {
        free(nombre[i]);
    }
    free (buff);
    return 0;
}

void MostrarPersonas(char **nombre, int tama)
{
    for (int i = 0; i < TAMA; i++)
    {
        printf("---NOMBRE N %d---\n", i+1);
        puts(nombre[i]);
    }
}

int BuscarNombrePorPalabra(char **nombre, char *palabra, int tama)
{
    for (int i = 0; i < tama; i++)
    {
        if (strstr(nombre[i], palabra))
        {
            return i;
        }
    }
    return -1;
}

void BuscarNombrePorId(char **nombre, int indice, int tama)
{
    if (indice >= 0 && indice < tama)
    {
        puts(nombre[indice]);
    }
    else
    {
        printf("Valor no encontrado\n");
    }
    
}