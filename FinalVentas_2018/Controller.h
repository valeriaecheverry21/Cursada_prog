#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#define OKP 1
#define OK 0
#define DENIED -1




int AltaDeCliente(ArrayList* clienteList);


int modificarCliente(ArrayList* clienteList);


int bajaDeCliente(ArrayList* clienteList);


int listarClientes(ArrayList* clienteList);


int realizarVenta(ArrayList* clienteList, ArrayList* ventaList);


int bajaDeVenta(ArrayList* ventaList);


#endif // CONTROLLER_H_INCLUDED
