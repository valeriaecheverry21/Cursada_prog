#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "FCliente.h"
#include "Fventas.h"
#define OKP 1
#define OK 0
#define DENIED -1



int main()
{
    ArrayList* clienteList;
    ArrayList* ventaList;

    char seguir='s';
    int opcion=0;

    clienteList = al_newArrayList();
    ventaList = al_newArrayList();


    C_fileToListText(clienteList);
    V_fileToListText(ventaList);




    while(seguir=='s')
        {
            printf("1- Alta de cliente \n");
            printf("2- Modificación de cliente \n");
            printf("3- Baja de cliente\n");
            printf("4- Listar clientes\n");
            printf("5- Realizar una venta\n");
            printf("6- Anular una venta\n");
            printf("7- Informar ventas\n");
            printf("8- Informar ventas por producto\n");
            printf("9- Salir\n");
            printf("ingrese opcion:");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(AltaDeCliente(clienteList) == DENIED) printf("no se pudo cargar el cliente al sistema");

                    system("pause");
                    break;
                case 2:
                    system("cls");

                    if(modificarCliente(clienteList) == DENIED) printf("no se pudo modificar el cliente \n");

                    system("pause");
                    break;
                case 3:
                    system("cls");

                    if(bajaDeCliente(clienteList) == DENIED) printf("hubo un error al dar de baja al cliente");

                    system("pause");
                    break;
                case 4:
                    system("cls");

                    if(listarClientes(clienteList) == DENIED) printf("hubo un error al listar los clientes");

                    system("pause");
                   break;
                case 5:
                    system("cls");

                    if(realizarVenta(clienteList, ventaList) == DENIED) printf("hubo un error al realizar una venta");

                    system("pause");
                    break;
                case 6:
                    system("cls");
                     if(bajaDeVenta(ventaList) == DENIED) printf("hubo un error al eliminar una venta");
                    system("pause");
                    break;
                case 7:
                    system("cls");

                    system("pause");
                    break;
                case 8:
                    system("cls");

                    system("pause");
                    break;
                case 9:
                    seguir = 'n';
                    break;
                default:
                    system("cls");
                    printf("ingreso mal la opcion, por favor ingrese de nuevo");
                    system("pause");
                    break;


            }
            system("cls");

        }

    C_listToFileText(clienteList);
    V_listToFileText(ventaList);

    return 0;
}
