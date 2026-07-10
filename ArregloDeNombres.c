#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMA 5

void MostrarPersonas(char **nombre, int tama);

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