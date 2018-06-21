#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "FCliente.h"




sCliente* C_contructParamClientes(int id, char nombre[], char apellido[], int documento)
{
    sCliente* cliente;

    cliente =(sCliente*) malloc(sizeof(sCliente));

    if(cliente != NULL)
    {
        cliente->idCliente = id;

        cliente->nombre = dinamicCharacter(nombre);
        cliente->apellido = dinamicCharacter(apellido);

        cliente->documento = documento;

    }

    return cliente;
}


sCliente* C_cargarCliente(int id)
{
    sCliente* cliente;

    char nombre[100];
    char apellido[100];
    int documento;
    printf("ingrese un nombre:");
    cargarCaracter(100, nombre);

    printf("ingrese el apellido:");
    cargarCaracter(100, apellido);

    printf("ingrese el documneto");
    scanf("%d",&documento);

    cliente = C_contructParamClientes(id,nombre, apellido, documento);

    return cliente;
}

int C_getId(ArrayList* clienteList)
{
    int flagEncontrado = DENIED,i, j,id;



    sCliente* cliente1, *cliente2;

    if(clienteList == NULL) return DENIED;


    if(clienteList->isEmpty(clienteList) == 1)
    {
        id = 1000;
    }
    else
    {


        cliente1 =(sCliente*) clienteList->get(clienteList, 0);
        id = cliente1->idCliente +1;


        for(i = 1; i < clienteList->len(clienteList); i++)
        {
            cliente1 =(sCliente*) clienteList->get(clienteList, i);

            if(cliente1->idCliente == id)
            {
                id = cliente1->idCliente +1;
            }
            else
            {

                for(j = i + 1; j < clienteList->len(clienteList); j++)
                {
                    cliente2 =(sCliente*) clienteList->get(clienteList, j);

                    if(id == cliente2->idCliente) break;

                }


                if(j < clienteList->len(clienteList)) flagEncontrado = OK;

            }

            if(flagEncontrado == DENIED)
            {
                id = cliente1->idCliente + 1;
            }
            else
            {
                break;
            }
        }

    }

    return id;
}


int C_getIndex(ArrayList* clientetList)
{
    int i = DENIED, id;
    sCliente* cliente;

    if(clientetList == NULL) return i;

    C_showAllClientes(clientetList, C_showClienteId);

    printf("ingrese el id:");
    scanf("%d", &id);


    for(i = 0; i < clientetList->len(clientetList);i++)
    {
        cliente = (sCliente*) clientetList->get(clientetList, i);

        if(cliente->idCliente = id) break;

    }

    return i;
}



int C_fileToListText(ArrayList* clienteList)
{
    FILE* pFile;

    int returnAux = DENIED;
    char idCliente[50], nombre[100], apellido[100], documeto[50];
    sCliente* cliente;

    pFile = fopen("cliente.txt", "r");

    if(clienteList == NULL || pFile == NULL) return returnAux;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idCliente, nombre, apellido, documeto);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idCliente, nombre, apellido, documeto);
        cliente = C_contructParamClientes(atoi(idCliente), nombre, apellido, atoi(documeto));
        returnAux = clienteList->add(clienteList, cliente);
    }

    return returnAux;
}

int C_listToFileText(ArrayList* clienteList)
{
    FILE* pFIle;
    int i, returnAux = DENIED;
    sCliente* cliente;

    pFIle = fopen("cliente.txt", "w+");

    if(clienteList == NULL || pFIle == NULL) return returnAux;

    fprintf(pFIle, "id,nombre,apellido,documento\n");

    for(i = 0; i < clienteList->len(clienteList); i++)
    {
        cliente = clienteList->get(clienteList, i);
        if(cliente != NULL)
        {
            fprintf(pFIle, "%d,%s,%s,%d\n", cliente->idCliente, cliente->nombre, cliente->apellido, cliente->documento);
            returnAux = OK;
        }
    }

    return returnAux;
}




void C_showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*))
{
    int i;

    sCliente* cliente;



    for(i = 0; i < clienteList->len(clienteList); i++)
    {

        cliente = clienteList->get(clienteList, i);

        funcion(cliente);

        printf("\n");

    }

}

void C_showCliente(sCliente* cliente){printf("%s %s", cliente->nombre, cliente->apellido);}

void C_showClienteData(sCliente* cliente)
{
    printf("----------------------------------------------------------------------\n\n");
    printf("cliente: %s %s\n\n", cliente->apellido, cliente->nombre);
    printf("DNI:%d\n\n", cliente->documento);

}

void C_showClienteId(sCliente* cliente)
{
    printf("%d)%s %s", cliente->idCliente, cliente->nombre, cliente->apellido);
}





int C_compareCliente(void* clienteA, void* clienteB)
{

    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) < 0)
    {
        return -1;
    }

    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) > 0)
    {
        return 1;
    }


    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) == 0)
    {

        if(strcmp(((sCliente*)clienteA)->nombre, ((sCliente*)clienteB)->nombre ) < 0)
        {
            return -1;
        }

        if(strcmp(((sCliente*)clienteA)->nombre, ((sCliente*)clienteB)->nombre ) > 0)
        {
            return 1;
        }

    }
}
