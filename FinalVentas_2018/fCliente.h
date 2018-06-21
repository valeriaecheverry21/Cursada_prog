#ifndef FCLIENTE_H_INCLUDED
#define FCLIENTE_H_INCLUDED
#define OKP 1
#define OK 0
#define DENIED -1



typedef struct
{
    int idCliente;
    char* nombre;
    char* apellido;
    int documento;

}sCliente;


sCliente* C_contructParamClientes(int id, char nombre[], char apellido[], int documento);

sCliente* C_cargarCliente(int id);

int C_getId(ArrayList* clienteList);

int C_getIndex(ArrayList* clientetList);

int C_fileToListText(ArrayList* clienteList);

int C_listToFileText(ArrayList* clienteList);



void C_showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*));
void C_showCliente(sCliente* cliente);
void C_showClienteData(sCliente* cliente);
void C_showClienteId(sCliente* cliente);



int C_compareCliente(void* clienteA, void* clienteB);


#endif // FCLIENTE_H_INCLUDED
