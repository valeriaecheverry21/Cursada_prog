#ifndef FVENTAS_H_INCLUDED
#define FVENTAS_H_INCLUDED

#define OKP 1
#define OK 0
#define DENIED -1


typedef struct
{
    int idVenta;
    char* nombre;
    char* codigo;
    int idCliente;

}sVenta;


sVenta* V_contructParamVenta(int idVenta, char nombre[], char codigo[], int idCliente);

sVenta* V_cargarVenta(int idVenta, int idCliente);

int V_getId(ArrayList* ventaList);

int V_getIndex(ArrayList* ventatList);


int V_fileToListText(ArrayList* ventaList);

int V_listToFileText(ArrayList* ventaList);



void V_showAllVentas(ArrayList* ventaList, void (*funcion)(sVenta*));

void V_showVentas(sVenta* venta);

void V_showVentasId(sVenta* venta);

#endif // FVENTAS_H_INCLUDED
