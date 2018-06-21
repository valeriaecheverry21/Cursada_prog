#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Controller.h"
#include "FCliente.h"
#include "Fventas.h"






int AltaDeCliente(ArrayList* clienteList)
{
    int returnAux = DENIED, id;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    id = C_getId(clienteList);

    printf("ingrese los datos del cliente: \n\n");
    cliente = C_cargarCliente(id);

    returnAux = clienteList->add(clienteList, cliente);

    return returnAux;

}


int modificarCliente(ArrayList* clienteList)
{
    int returnAux = DENIED, i, id;
    sCliente* cliente;


    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        i = C_getIndex(clienteList);

        cliente = clienteList->get(clienteList, i);

        id = cliente->idCliente;

        cliente = C_cargarCliente(id);

        returnAux = clienteList->set(clienteList, i, cliente);

    }
    else
    {
        printf("isEmpty!!!\n");
        returnAux = OK;
    }

    return returnAux;
}



int bajaDeCliente(ArrayList* clienteList)
{
    int i, returnAux = DENIED;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        i = C_getIndex(clienteList);

        cliente = clienteList->pop(clienteList, i);

        if(cliente != NULL)
        {
            printf("el cliente:");
            C_showCliente(cliente);
            printf("ha sido eliminado\n");
            returnAux = OK;
        }
    }
    else
    {
        printf("isEmpty!!!\n");
        returnAux = OK;
    }

    return returnAux;
}


int listarClientes(ArrayList* clienteList)
{
    int returnAux = DENIED;
    ArrayList* listaOrdenada;

    if(clienteList->isEmpty(clienteList) == OK)
    {
        listaOrdenada = clienteList->clone(clienteList);

        listaOrdenada->sort(listaOrdenada, C_compareCliente, 1);


        C_showAllClientes(listaOrdenada, C_showClienteData);

        returnAux = OK;
    }
    else
    {
        if(clienteList->isEmpty(clienteList) == OKP)
        {
            printf("isEmpty!!!\n");
            returnAux = OK;
        }
    }




    return returnAux;
}



int realizarVenta(ArrayList* clienteList, ArrayList* ventaList)
{
    int i, idVenta, returnAux = DENIED;

    sCliente* cliente;
    sVenta* venta;

    if(clienteList == NULL || ventaList == NULL) return returnAux;


    if(clienteList->isEmpty(clienteList) == OK)
    {
        printf("ingrese el id del cliente que realiza la compra:\n");
        i = C_getIndex(clienteList);

        cliente = (sCliente*) clienteList->get(clienteList, i);

        idVenta = V_getId(ventaList);

        venta = V_cargarVenta(idVenta, cliente->idCliente);

        returnAux = ventaList->add(ventaList, venta);
    }
    else
    {
        if(clienteList->isEmpty(clienteList) == OKP)
        {
            printf("isEmpty!!!\n");
            returnAux = OK;
        }
    }

    return returnAux;

}


int bajaDeVenta(ArrayList* ventaList)
{
    int i, returnAux = DENIED;
    sVenta* venta;

    if(ventaList == NULL) return returnAux;

    if(ventaList->isEmpty(ventaList) != OKP)
    {
        i = V_getIndex(ventaList);

        venta = ventaList->pop(ventaList, i);

        if(venta != NULL)
        {
            printf("la venta:");
            V_showVentas(venta);
            printf("ha sido eliminado\n");
            returnAux = OK;
        }
    }
    else
    {
        if(ventaList->isEmpty(ventaList) == OKP)
        {
            printf("isEmpty!!!\n");
            returnAux = OK;
        }
    }

    return returnAux;
}
