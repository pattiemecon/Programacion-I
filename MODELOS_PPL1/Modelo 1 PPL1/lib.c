#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define STR_BUFFER 100
#define OCUPADO 0
#define LIBRE 1
#define BAJA 2

//Implementaci�n de funciones de la entidad Usuario
void eUsuario_init(eUsuario listado[], int limite)
{
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].id = 0;
        }
    }
}

int eUsuario_buscarLugarLibre(eUsuario listado[], int limite)
{
    int retorno = -1;
    int i;
    int posicionLibre = -1; //Guarda la primer posicion con estado LIBRE que encuentra
    int posicionBaja = -1; //Guarda la primer posicion con estado BAJA que encuentra

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                posicionLibre = i;
                break;
            }
        }

        if(posicionLibre < 0) //No hay posiciones con estado LIBRE, busco la primer posici�n con estado BAJA
        {
            for(i=0;i<limite;i++)
            {
                if(listado[i].estado == BAJA)
                {
                    posicionBaja = i;
                    break;
                }
            }

            if(posicionBaja >= 0)
            {
                retorno = posicionBaja; //Retorno la primera posici�n con estado BAJA
            }
        }
        else
        {
            retorno = posicionLibre; //Retorno la primera posici�n con estado LIBRE
        }
    }

    return retorno;
}

int eUsuario_siguienteId(eUsuario listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO || listado[i].estado == BAJA) //Tengo en cuenta las bajas l�gicas para no duplicar id al rehabilitar
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}

int eUsuario_buscarPorId(eUsuario listado[], int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eUsuario_mostrarUno(eUsuario parametro)
{
     printf("\n %d - %s", parametro.id, parametro.nombre);

}

void eUsuario_mostrarUnoConClave(eUsuario parametro)
{
     printf("\n %d - %s - %s", parametro.id, parametro.nombre, parametro.clave);

}

void eUsuario_mostrarUnoConEstado(eUsuario parametro)
{
    switch(parametro.estado)
    {
    case LIBRE: //No muestro las posiciones con estado LIBRE porque contienen basura
        break;
    case BAJA:
        printf("\n %d - %s - %s", parametro.id, parametro.nombre, "[BAJA]");
        break;
    case OCUPADO:
        printf("\n %d - %s", parametro.id, parametro.nombre);
        break;
    default:
        printf("\n %d - %s - %s", parametro.id, parametro.nombre, "[N/A]");
        break;
    }
}

int eUsuario_mostrarListadoConOcupados(eUsuario listado[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                retorno = 1;
                //Se muestra al menos un elemento del array
                eUsuario_mostrarUno(listado[i]);
            }
        }

        if(retorno == 0)
        {
            printf("\n*** NO HAY USUARIOS PARA MOSTRAR ***");
        }
    }

    return retorno;
}

int eUsuario_mostrarListadoConClave(eUsuario listado[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                retorno = 1;
                //Se muestra al menos un elemento del array
                eUsuario_mostrarUnoConClave(listado[i]);
            }
        }

        if(retorno == 0)
        {
            printf("\n*** NO HAY USUARIOS PARA MOSTRAR ***");
        }
    }

    return retorno;
}

int eUsuario_mostrarListado(eUsuario listado[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==BAJA || listado[i].estado==OCUPADO)
            {
                retorno = 1;
                //Se muestra al menos un elemento del array
                eUsuario_mostrarUnoConEstado(listado[i]);
            }
        }

        if(retorno == 0)
        {
            printf("\n*** NO HAY USUARIOS PARA MOSTRAR ***");
        }
    }

    return retorno;
}

int eUsuario_alta(eUsuario listado[], int limite)
{
    int retorno = -1;
    eUsuario temporario;
    int indice;
    char confirma[3];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        //Busca lugar libre en el array
        indice = eUsuario_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            //Campos con valores iniciales calculados
            temporario.id = eUsuario_siguienteId(listado, limite);
            temporario.estado = OCUPADO;

            retorno = -4;
            //Campos con valores pedidos al usuario
            do
            {
                pedirString("Ingrese nombre: ", temporario.nombre, TAM_NOMBRE);
                if(strcmp(temporario.nombre, "") == 0)
                {
                    printf("El dato es obligatorio, por favor reingrese\n");
                }
            } while(strcmp(temporario.nombre, "") == 0);

            do
            {
                pedirString("Ingrese clave: ", temporario.clave, TAM_CLAVE);
                if(strcmp(temporario.clave, "") == 0)
                {
                    printf("El dato es obligatorio, por favor reingrese\n");
                }
            } while(strcmp(temporario.clave, "") == 0);

            retorno = -5;
            //Confirmaci�n de la acci�n por parte del usuario
            do
            {
                printf("\nSe va a dar de alta:");
                eUsuario_mostrarUnoConClave(temporario);
                pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                {
                    printf("Debe ingresar S o N. Por favor reingrese\n");
                }
            } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

            if(stricmp(confirma, "S") == 0)
            {
                retorno = 0;
                //OK
                listado[indice] = temporario;
            }
            else //retorno = -5
            {
                printf("Accion cancelada por el usuario\n");
            }
        }
        else //retorno = -2
        {
            printf("No hay espacio suficiente para agregar datos\n");
        }
    }
    return retorno;
}

int eUsuario_baja(eUsuario listado[], int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    int id;
    char confirma[3];
    int cancelaAccion = 0;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eUsuario_mostrarListadoConOcupados(listado, limite);

            switch(muestraListado)
            {
            case 0:
                printf("\nNo hay elementos para dar de baja"); //retorno = -2
                break;
            case 1:
                id = pedirEnteroSinValidar("\nIngrese ID a borrar: ");
                indice = eUsuario_buscarPorId(listado, limite, id);
                if(indice < 0)
                {
                    printf("No se encontro el ID ingresado. Por favor reingrese\n");
                }
                else
                {
                    retorno = -3;
                    //Confirmaci�n de la acci�n por parte del usuario
                    do
                    {
                        printf("\nSe va a dar de baja:");
                        eUsuario_mostrarUno(listado[indice]);
                        pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                        if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                        {
                            printf("Debe ingresar S o N. Por favor reingrese\n");
                        }
                    } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

                    if(stricmp(confirma, "S") == 0)
                    {
                        retorno = 0;
                        //OK
                        listado[indice].estado = BAJA;
                    }
                    else //retorno = -3
                    {
                        printf("Accion cancelada por el usuario\n");
                        cancelaAccion = 1;
                    }
                }

                break;
            default:
                printf("\Error al listar...\n"); //retorno = -2
                break;
            }
        } while(indice < 0 && muestraListado == 1 && cancelaAccion == 0);
    }

    return retorno;
}

int eUsuario_modificacion(eUsuario listado[], int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    eUsuario temporario;
    char confirma[3];
    int modificoDato = 0;
    int cancelaAccion = 0;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eUsuario_mostrarListadoConClave(listado, limite);

            switch(muestraListado)
            {
            case 0:
                printf("\nNo hay elementos para modificar"); //retorno = -2
                break;
            case 1:
                temporario.id = pedirEnteroSinValidar("\nIngrese ID a modificar: ");
                indice = eUsuario_buscarPorId(listado, limite, temporario.id);
                if(indice < 0)
                {
                    printf("No se encontro el ID ingresado. Por favor reingrese\n");
                }
                else
                {
                    temporario = listado[indice];

                    retorno = -3;
                    //Modificaci�n de campos con confirmaci�n atributo por atributo
                    do
                    {
                        pedirString("\nModifica nombre? (S/N): ", confirma, 3);
                        if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                        {
                            printf("Debe ingresar S o N. Por favor reingrese\n");
                        }
                    } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);
                    if(stricmp(confirma, "S") == 0)
                    {
                        do
                        {
                            pedirString("Ingrese nuevo nombre: ", temporario.nombre, TAM_NOMBRE);
                            if(strcmp(temporario.nombre, "") == 0)
                            {
                                printf("El dato es obligatorio, por favor reingrese\n");
                            }
                        } while(strcmp(temporario.nombre, "") == 0);
                        modificoDato = 1;
                    }

                    do
                    {
                        pedirString("\nModifica clave? (S/N): ", confirma, 3);
                        if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                        {
                            printf("Debe ingresar S o N. Por favor reingrese\n");
                        }
                    } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);
                    if(stricmp(confirma, "S") == 0)
                    {
                        do
                        {
                            pedirString("Ingrese nueva clave: ", temporario.clave, TAM_CLAVE);
                            if(strcmp(temporario.clave, "") == 0)
                            {
                                printf("El dato es obligatorio, por favor reingrese\n");
                            }
                        } while(strcmp(temporario.clave, "") == 0);
                        modificoDato = 1;
                    }

                    if(modificoDato == 1)
                    {
                        retorno = -4;
                        //Confirmaci�n de la acci�n por parte del usuario
                        do
                        {
                            printf("\nSe va a modificar:");
                            eUsuario_mostrarUnoConClave(listado[indice]);
                            printf("\nPor:");
                            eUsuario_mostrarUnoConClave(temporario);
                            pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                            if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                            {
                                printf("Debe ingresar S o N. Por favor reingrese\n");
                            }
                        } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);
                    }

                    if(stricmp(confirma, "S") == 0 && modificoDato == 1)
                    {
                        retorno = 0;
                        //OK
                        listado[indice] = temporario;
                    }
                    else //(retorno = -3 || retorno = -4)
                    {
                        printf("Accion cancelada por el usuario\n");
                        cancelaAccion = 1;
                    }
                }

                break;
            default:
                printf("\Error al listar...\n"); //retorno = -2
                break;
            }
        } while(indice < 0 && muestraListado == 1 && cancelaAccion == 0);
    }

    return retorno;
}

//Implementaci�n de las funciones de la entidad Producto
void eProducto_init(eProducto listado[], int limite)
{
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idUsuario = 0;
        }
    }
}

int eProducto_buscarLugarLibre(eProducto listado[], int limite)
{
    int retorno = -1;
    int i;
    int posicionLibre = -1; //Guarda la primer posicion con estado LIBRE que encuentra
    int posicionBaja = -1; //Guarda la primer posicion con estado BAJA que encuentra

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                posicionLibre = i;
                break;
            }
        }

        if(posicionLibre < 0) //No hay posiciones con estado LIBRE, busco la primer posici�n con estado BAJA
        {
            for(i=0;i<limite;i++)
            {
                if(listado[i].estado == BAJA)
                {
                    posicionBaja = i;
                    break;
                }
            }

            if(posicionBaja >= 0)
            {
                retorno = posicionBaja; //Retorno la primera posici�n con estado BAJA
            }
        }
        else
        {
            retorno = posicionLibre; //Retorno la primera posici�n con estado LIBRE
        }
    }

    return retorno;
}

int eProducto_siguienteId(eProducto listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO || listado[i].estado == BAJA) //Tengo en cuenta las bajas l�gicas para no duplicar id al rehabilitar
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}

int eProducto_buscarPorId(eProducto listado[], int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProducto_buscarPorIdUsuarioNombre(eProducto listado[], int limite, int idUsuario, char nombre[])
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idUsuario == idUsuario && stricmp(listado[i].nombre, nombre) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eProducto_mostrarUno(eProducto parametro)
{
     printf("\n %d - %s - %10.2f - %d", parametro.id, parametro.nombre, parametro.precio, parametro.stock);

}

void eProducto_mostrarUnoConEstado(eProducto parametro)
{
    switch(parametro.estado)
    {
    case LIBRE: //No muestro las posiciones con estado LIBRE porque contienen basura
        break;
    case BAJA:
        printf("\n %d - %s - %10.2f - %d - %s", parametro.id, parametro.nombre, parametro.precio, parametro.stock, "[BAJA]");
        break;
    case OCUPADO:
        printf("\n %d - %s - %10.2f - %d", parametro.id, parametro.nombre, parametro.precio, parametro.stock);
        break;
    default:
        printf("\n %d - %s - %10.2f - %d - %s", parametro.id, parametro.nombre, parametro.precio, parametro.stock, "[N/A]");
        break;
    }
}

void eProducto_mostrarUnoConUsuario(eProducto parametro, char nombreUsuario[])
{
     printf("\n %d - %s || %d - %s - %10.2f - %d", parametro.idUsuario, nombreUsuario, parametro.id, parametro.nombre, parametro.precio, parametro.stock);
}

int eProducto_mostrarListadoConOcupados(eProducto listado[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                retorno = 1;
                //Se muestra al menos un elemento del array
                eProducto_mostrarUno(listado[i]);
            }
        }

        if(retorno == 0)
        {
            printf("\n*** NO HAY PRODUCTOS PARA MOSTRAR ***");
        }
    }

    return retorno;
}

int eProducto_mostrarListadoPorUsuario(eProducto listado[], int limite, int idUsuario, char nombreUsuario[])
{
    int retorno = -1;
    int i;

    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO && listado[i].idUsuario == idUsuario)
            {
                retorno = 1;
                //Se muestra al menos un elemento del array
                eProducto_mostrarUnoConUsuario(listado[i], nombreUsuario);
            }
        }

        if(retorno == 0)
        {
            printf("\n*** NO HAY PRODUCTOS PARA MOSTRAR ***");
        }
    }

    return retorno;
}

int eProducto_mostrarListado(eProducto listado[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==BAJA || listado[i].estado==OCUPADO)
            {
                retorno = 1;
                //Se muestra al menos un elemento del array
                eProducto_mostrarUnoConEstado(listado[i]);
            }
        }

        if(retorno == 0)
        {
            printf("\n*** NO HAY PRODUCTOS PARA MOSTRAR ***");
        }
    }

    return retorno;
}

int eProducto_alta(eProducto listado[], int limite, int idUsuario, char nombreUsuario[])
{
    int retorno = -1;
    eProducto temporario;
    int indice;
    char confirma[3];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        //Busca lugar libre en el array
        indice = eProducto_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            //Campos con valores iniciales calculados
            temporario.id = eProducto_siguienteId(listado, limite);
            temporario.idUsuario = idUsuario;
            temporario.estado = OCUPADO;

            retorno = -4;
            //Campos con valores pedidos al usuario
            do
            {
                pedirString("Ingrese nombre del producto: ", temporario.nombre, TAM_NOMBRE);
                if(strcmp(temporario.nombre, "") == 0)
                {
                    printf("El dato es obligatorio, por favor reingrese\n");
                }
            } while(strcmp(temporario.nombre, "") == 0);

            do
            {
                temporario.precio = pedirFlotanteSinValidar("Ingrese precio: ");
                if(temporario.precio <= 0)
                {
                    printf("\nDebe ingresar un valor positivo");
                }
            } while(temporario.precio <= 0);

            do
            {
                temporario.stock = pedirEnteroSinValidar("Ingrese stock: ");
                if(temporario.stock <= 0)
                {
                    printf("\nDebe ingresar un numero positivo");
                }
            } while(temporario.stock <= 0);

            retorno = -5;
            //Confirmaci�n de la acci�n por parte del usuario
            do
            {
                printf("\nSe va a dar de alta:");
                eProducto_mostrarUnoConUsuario(temporario, nombreUsuario);
                pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                {
                    printf("Debe ingresar S o N. Por favor reingrese\n");
                }
            } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

            if(stricmp(confirma, "S") == 0)
            {
                retorno = 0;
                //OK
                listado[indice] = temporario;
            }
            else //retorno = -5
            {
                printf("Accion cancelada por el usuario\n");
            }
        }
        else //retorno = -2
        {
            printf("No hay espacio suficiente para agregar datos\n");
        }
    }
    return retorno;
}

void eProducto_publicar(eProducto listaProductos[], eUsuario listaUsuarios[], int limiteProductos, int limiteUsuarios)
{
    int indice;
    int idUsuario;
    char confirma[3];
    int cancelaAccion = 0;
    int status;

    do
    {
        status = eUsuario_mostrarListadoConOcupados(listaUsuarios, limiteUsuarios);

        switch(status)
        {
        case 0:
            printf("\nNo hay usuarios para listar");
            break;
        case 1:
            idUsuario = pedirEnteroSinValidar("\nIngrese ID de Usuario que publicara: ");
            indice = eUsuario_buscarPorId(listaUsuarios, limiteUsuarios, idUsuario);
            if(indice < 0)
            {
                printf("No se encontro el ID ingresado. Por favor reingrese\n");
            }
            else
            {
                //Confirmaci�n de la acci�n por parte del usuario
                do
                {
                    printf("\nSe va a publicar un producto para el usuario:");
                    eUsuario_mostrarUno(listaUsuarios[indice]);
                    pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                    if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                    {
                        printf("Debe ingresar S o N. Por favor reingrese\n");
                    }
                } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

                if(stricmp(confirma, "S") == 0)
                {
                    status = eProducto_alta(listaProductos, limiteProductos, idUsuario, listaUsuarios[indice].nombre);
                    if(status == 0)
                    {
                        printf("Alta de publicacion OK");
                    }
                }
                else //Usuario cancela acci�n
                {
                    printf("Accion cancelada por el usuario\n");
                    cancelaAccion = 1;
                }
            }

            break;
        default:
            printf("\Error al listar...\n"); //retorno = -2
            break;
        }
    } while(indice < 0 && status == 1 && cancelaAccion == 0);
}

/*
int eProducto_baja(eProducto listado[], int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    int id;
    char confirma[3];
    int cancelaAccion = 0;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eProducto_mostrarListado(listado, limite);

            switch(muestraListado)
            {
            case 0:
                printf("\nNo hay elementos para dar de baja"); //retorno = -2
                break;
            case 1:
                id = pedirEnteroSinValidar("\nIngrese ID a borrar: ");
                indice = eUsuario_buscarPorId(listado, limite, id);
                if(indice < 0)
                {
                    printf("No se encontro el ID ingresado. Por favor reingrese\n");
                }
                else
                {
                    retorno = -3;
                    //Confirmaci�n de la acci�n por parte del usuario
                    do
                    {
                        printf("\nSe va a dar de baja:");
                        eUsuario_mostrarUno(listado[indice]);
                        pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                        if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                        {
                            printf("Debe ingresar S o N. Por favor reingrese\n");
                        }
                    } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

                    if(stricmp(confirma, "S") == 0)
                    {
                        retorno = 0;
                        //OK
                        listado[indice].estado = BAJA;
                    }
                    else //retorno = -3
                    {
                        printf("Accion cancelada por el usuario\n");
                        cancelaAccion = 1;
                    }
                }

                break;
            default:
                printf("\Error al listar...\n"); //retorno = -2
                break;
            }
        } while(indice < 0 && muestraListado == 1 && cancelaAccion == 0);
    }

    return retorno;
}

int eUsuario_modificacion(eUsuario listado[], int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    eUsuario temporario;
    char confirma[3];
    int modificoDato = 0;
    int cancelaAccion = 0;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eUsuario_mostrarListadoConClave(listado, limite);

            switch(muestraListado)
            {
            case 0:
                printf("\nNo hay elementos para modificar"); //retorno = -2
                break;
            case 1:
                temporario.id = pedirEnteroSinValidar("\nIngrese ID a modificar: ");
                indice = eUsuario_buscarPorId(listado, limite, temporario.id);
                if(indice < 0)
                {
                    printf("No se encontro el ID ingresado. Por favor reingrese\n");
                }
                else
                {
                    temporario = listado[indice];

                    retorno = -3;
                    //Modificaci�n de campos con confirmaci�n atributo por atributo
                    do
                    {
                        pedirString("\nModifica nombre? (S/N): ", confirma, 3);
                        if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                        {
                            printf("Debe ingresar S o N. Por favor reingrese\n");
                        }
                    } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);
                    if(stricmp(confirma, "S") == 0)
                    {
                        do
                        {
                            pedirString("Ingrese nuevo nombre: ", temporario.nombre, TAM_NOMBRE);
                            if(strcmp(temporario.nombre, "") == 0)
                            {
                                printf("El dato es obligatorio, por favor reingrese\n");
                            }
                        } while(strcmp(temporario.nombre, "") == 0);
                        modificoDato = 1;
                    }

                    do
                    {
                        pedirString("\nModifica clave? (S/N): ", confirma, 3);
                        if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                        {
                            printf("Debe ingresar S o N. Por favor reingrese\n");
                        }
                    } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);
                    if(stricmp(confirma, "S") == 0)
                    {
                        do
                        {
                            pedirString("Ingrese nueva clave: ", temporario.clave, TAM_CLAVE);
                            if(strcmp(temporario.clave, "") == 0)
                            {
                                printf("El dato es obligatorio, por favor reingrese\n");
                            }
                        } while(strcmp(temporario.clave, "") == 0);
                        modificoDato = 1;
                    }

                    if(modificoDato == 1)
                    {
                        retorno = -4;
                        //Confirmaci�n de la acci�n por parte del usuario
                        do
                        {
                            printf("\nSe va a modificar:");
                            eUsuario_mostrarUnoConClave(listado[indice]);
                            printf("\nPor:");
                            eUsuario_mostrarUnoConClave(temporario);
                            pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                            if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                            {
                                printf("Debe ingresar S o N. Por favor reingrese\n");
                            }
                        } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);
                    }

                    if(stricmp(confirma, "S") == 0 && modificoDato == 1)
                    {
                        retorno = 0;
                        //OK
                        listado[indice] = temporario;
                    }
                    else //(retorno = -3 || retorno = -4)
                    {
                        printf("Accion cancelada por el usuario\n");
                        cancelaAccion = 1;
                    }
                }

                break;
            default:
                printf("\Error al listar...\n"); //retorno = -2
                break;
            }
        } while(indice < 0 && muestraListado == 1 && cancelaAccion == 0);
    }

    return retorno;
}
*/
//Implementaci�n de las funciones generales
float calcularCociente(float dividendo, float divisor)
{
    float resultado;
    resultado = dividendo / divisor;

    return resultado;
}

int validarCociente(float dividendo, float divisor)
{
    int resultado;

    if(divisor == 0)
    {
        if(dividendo == 0)
        {
            resultado = 2; //Indeterminacion
        }
        else
        {
            resultado = 1; //Infinito
        }
    }
    else
    {
        resultado = 0; //OK
    }

    return resultado;
}

void limpiarPantalla(void)
{
    system("cls");
}

void pausarEjecucion(void)
{
    system("pause");
}

int validarEnteroDecimal(float numero)
{
    int numeroEntero = (int)numero;
    int retorno;

    if(numero != numeroEntero)
    {
        retorno = 1; //No es entero
    }
    else
    {
        retorno = 0; //Es entero
    }

    return retorno;
}

int pedirEntero(char mensaje[], int minimo, int maximo)
{
    int numero;
    float ingreso;
    int esDecimal;

    printf("%s", mensaje);
    do
    {
        scanf("%f", &ingreso);
        esDecimal = validarEnteroDecimal(ingreso);
        if(esDecimal == 1)
        {
            printf("ERROR Debe ingresar un numero sin digitos decimales: ");
        }
    } while(esDecimal == 1);

    numero = (int)ingreso;
    numero = validarEntero(numero, minimo, maximo);

    return numero;
}

int validarEntero(int dato, int minimo, int maximo)
{
    while(dato < minimo || dato > maximo)
    {
        printf("ERROR Ingrese un numero entre %d y %d: ", minimo, maximo);
        scanf("%d", &dato);
    }

    return dato;
}

int pedirEnteroSinValidar(char mensaje[])
{
    int numero;
    float ingreso;
    int esDecimal;

    printf("%s", mensaje);
    do
    {
        scanf("%f", &ingreso);
        esDecimal = validarEnteroDecimal(ingreso);
        if(esDecimal == 1)
        {
            printf("ERROR Debe ingresar un numero sin digitos decimales: ");
        }
    } while(esDecimal == 1);

    numero = (int)ingreso;

    return numero;
}

void pedirString(char mensaje[], char cadena[], int longitud)
{
    char stringBuffer[STR_BUFFER];
    longitud = longitud - 2; //Resto dos para contemplar \n y \0

    if(longitud > STR_BUFFER - 2)
    {
        printf("\nLa longitud de la cadena no puede superar %d caracteres", STR_BUFFER - 2);
    }
    else
    {
        printf("%s", mensaje);
        fflush(stdin);
        fgets(stringBuffer, STR_BUFFER, stdin);

        validarString(stringBuffer, longitud);

        strcpy(cadena, stringBuffer);
        cadena[strlen(cadena) - 1] = '\0'; //Quito el \n que deja antes de \0 el fgets
    }
}

void validarString(char cadena[], int longitud)
{
    while(strlen(cadena) - 1 > longitud)
    {
        printf("ERROR El texto ingresado supera los %d caracteres\npor favor reingrese: ", longitud);
        fflush(stdin);
        fgets(cadena, STR_BUFFER, stdin);
    }
}

float pedirFlotanteSinValidar(char mensaje[])
{
    float numero;

    printf("%s", mensaje);
    scanf("%f", &numero);

    return numero;
}
