#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    char seguir='s';
    int opcion=0;

    eUsuario listaUsuarios[LIM_USUARIOS];
    eProducto listaProductos[LIM_PRODUCTOS];
    eTransaccion listaTransacciones[LIM_TRANSACCIONES];
    int status;

    //Inicializo vector de usuarios
    eUsuario_init(listaUsuarios, LIM_USUARIOS);
    //Inicializo vector de productos
    eProducto_init(listaProductos, LIM_PRODUCTOS);
    //Inicializo vector de transacciones
    eTransaccion_init(listaTransacciones, LIM_TRANSACCIONES);

    while(seguir=='s')
    {
        limpiarPantalla();

        printf(" 1. ALTA DE USUARIO\n");
        printf(" 2. MODIFICAR DATOS DEL USUARIO\n");
        printf(" 3. BAJA DEL USUARIO\n");
        printf(" 4. PUBLICAR PRODUCTO\n");
        printf(" 5. MODIFICAR PUBLICACION\n");
        printf(" 6. CANCELAR PUBLICACION\n");
        printf(" 7. COMPRAR PRODUCTO\n");
        printf(" 8. LISTAR PUBLICACIONES DE USUARIO\n");
        printf(" 9. LISTAR PUBLICACIONES\n");
        printf("10. LISTAR USUARIOS\n\n");
        printf("11. SALIR\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                status = eUsuario_alta(listaUsuarios, LIM_USUARIOS);
                if(status == 0)
                {
                    printf("Alta de Usuario OK");
                }
                break;
            case 2:
                status = eUsuario_modificacion(listaUsuarios, LIM_USUARIOS);
                if(status == 0)
                {
                    printf("Modificacion de Usuario OK");
                }
                break;
            case 3:
                status = eUsuario_baja(listaUsuarios, LIM_USUARIOS);
                if(status == 0)
                {
                    printf("Baja de Usuario OK");
                }
                break;
            case 4:
                status = eProducto_publicar(listaProductos, listaUsuarios, LIM_PRODUCTOS, LIM_USUARIOS);
                if(status == 0)
                {
                    printf("Publicacion de Producto OK");
                }
                break;
            case 5:
                status = ePublicacion_modificar(listaProductos, listaUsuarios, LIM_PRODUCTOS, LIM_USUARIOS);
                if(status == 0)
                {
                    printf("Modificacion de Publicacion OK");
                }
                break;
            case 6:
                status = ePublicacion_cancelar(listaProductos, listaUsuarios, LIM_PRODUCTOS, LIM_USUARIOS);
                if(status == 0)
                {
                    printf("Cancelacion de Publicacion OK");
                }
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion no contemplada, por favor vuelva a elegir");
                break;
        }

        if(seguir=='s')
        {
            printf("\n");
            pausarEjecucion();
        }
    }

    return 0;
}
