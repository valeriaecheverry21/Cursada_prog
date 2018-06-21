#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Fventas.h"



sVenta* V_contructParamVenta(int idVenta, char nombre[], char codigo[], int idCliente)
{
    sVenta* venta;

    venta =(sVenta*) malloc(sizeof(sVenta));

    if(venta != NULL)
    {
        venta->idVenta = idVenta;

        venta->nombre = dinamicCharacter(nombre);
        venta->codigo = dinamicCharacter(codigo);

        venta->idCliente = idCliente;

    }

    return venta;
}


sVenta* V_cargarVenta(int idVenta, int idCliente)
{
    sVenta* venta;

    char nombre[100];
    char codigo[100];

    printf("ingrese un nombre del producto:");
    cargarCaracter(100, nombre);

    printf("ingrese el codigo del producto:");
    cargarCaracter(100, codigo);

    venta = C_contructParamClientes(idVenta, nombre, codigo, idCliente);

    return venta;
}

int V_getId(ArrayList* ventaList)
{
    int flagEncontrado = DENIED,i, j,id;



    sVenta* venta1, *venta2;

    if(ventaList == NULL) return DENIED;


    if(ventaList->isEmpty(ventaList) == 1)
    {
        id = 1000;
    }
    else
    {


        venta1 =(sVenta*) ventaList->get(ventaList, 0);
        id = venta1->idVenta + 1;


        for(i = 1; i < ventaList->len(ventaList); i++)
        {
            venta1 =(sVenta*) ventaList->get(ventaList, i);

            if(venta1->idVenta == id)
            {
                id = venta1->idVenta +1;
            }
            else
            {

                for(j = i + 1; j < ventaList->len(ventaList); j++)
                {
                    venta2 =(sVenta*) ventaList->get(ventaList, j);

                    if(id == venta2->idVenta) break;

                }


                if(j < ventaList->len(ventaList)) flagEncontrado = OK;

            }

            if(flagEncontrado == DENIED)
            {
                id = venta1->idVenta + 1;
            }
            else
            {
                break;
            }
        }

    }

    return id;
}


int V_getIndex(ArrayList* ventaList)
{
    int i = DENIED, id;
    sVenta* venta;

    if(ventaList == NULL) return i;

    V_showAllVentas(ventaList, V_showVentasId);

    printf("ingrese el id:");
    scanf("%d", &id);


    for(i = 0; i < ventaList->len(ventaList);i++)
    {
        venta = (sVenta*) ventaList->get(ventaList, i);

        if(venta->idVenta = id) break;

    }

    return i;
}




int V_fileToListText(ArrayList* ventaList)
{
    FILE* pFile;

    int returnAux = DENIED;
    char idVenta[50], nombre[100], codigo[100], idCliente[50];
    sVenta* venta;

    pFile = fopen("ventas.txt", "r");

    if(ventaList == NULL || pFile == NULL) return returnAux;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idVenta, nombre, codigo, idCliente);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idVenta, nombre, codigo, idCliente);
        venta = V_contructParamVenta(atoi(idVenta), nombre, codigo, atoi(idCliente));

        returnAux = ventaList->add(ventaList, venta);
    }

    return returnAux;
}

int V_listToFileText(ArrayList* ventaList)
{
    FILE* pFIle;
    int i, returnAux = DENIED;
    sVenta* venta;

    pFIle = fopen("ventas.txt", "w+");

    if(ventaList == NULL || pFIle == NULL) return returnAux;

    fprintf(pFIle, "id,nombre,codigo,idCliente\n");

    for(i = 0; i < ventaList->len(ventaList); i++)
    {
        venta = (sVenta*) ventaList->get(ventaList, i);
        if(venta != NULL)
        {
            fprintf(pFIle, "%d,%s,%s,%d\n", venta->idVenta, venta->nombre, venta->codigo, venta->idCliente);
            returnAux = OK;
        }
    }

    return returnAux;
}



void V_showAllVentas(ArrayList* ventaList, void (*funcion)(sVenta*))
{
    int i;

    sVenta* venta;



    for(i = 0; i < ventaList->len(ventaList); i++)
    {

        venta = (sVenta*) ventaList->get(ventaList, i);

        funcion(venta);

        printf("\n");

    }

}

void V_showVentas(sVenta* venta){printf("%s %s", venta->nombre, venta->codigo);}


void V_showVentasId(sVenta* venta)
{
    printf("%d)%s %s", venta->idVenta, venta->nombre, venta->codigo);
}



