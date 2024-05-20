//
// Created by Fran on 18/05/2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "helper.h"
#define consumoMinC 100
#define consumoMinP 50
#define tarifaP 400
#define tarifaC 500
//Creamos un Nuevo usuario

Usuario *newUsuario(char *nombre,int nroDeZona,char *tipoDeConsumo,int consumo,char *calle)
{
    Usuario *aux = malloc(sizeof(Usuario));
    if (aux == NULL) {
        printf("Error\n");
        return NULL;
    } else {
        aux->consumo = consumo;
        strcpy(aux->calle,calle);
        strcpy(aux->nombre, nombre);
        aux->nroDeZona = nroDeZona;
        strcpy(aux->TipoDeConsumo, tipoDeConsumo);
        strcpy(aux->calle, calle);
        aux->sig = NULL;
        return aux;
    }
}

Zona *newZona(int nroDeZona)
{
    Zona *aux = malloc(sizeof(Zona));
    if (aux == NULL) {
        printf("Error\n");
        return NULL;
    } else {
        aux->nroDeZona = nroDeZona;
        aux->usuario = NULL;
        aux->sig = NULL;
        return aux;
    }
}

Lista *newListaZonas() {
    Lista *aux = malloc(sizeof(Lista));
    if (aux == NULL) {
        printf("Error\n");
        return NULL;
    } else {
        aux->cab = NULL;
        return aux;
    }
}

void AgregamosUsuariosAlaZona(Usuario *usuarioAI, Lista *lista) {
    Zona *aux = lista->cab;

    // Buscar la zona correspondiente
    while (aux != NULL && aux->nroDeZona != usuarioAI->nroDeZona) {
        aux = aux->sig;
    }

    // Si la zona no existe, crear una nueva y agregarla a la lista
    if (aux == NULL) {
        aux = newZona(usuarioAI->nroDeZona);
        aux->sig = lista->cab;
        lista->cab = aux;
    }

    // Agregar el usuario a la zona
    Usuario *usuarioAux = aux->usuario;
    if (usuarioAux == NULL) {
        aux->usuario = usuarioAI;
    } else {
        while (usuarioAux->sig != NULL) {
            usuarioAux = usuarioAux->sig;
        }
        usuarioAux->sig = usuarioAI;
    }
}

void ListarYInformarPorZonas(Lista *lista) {
    Zona *aux = lista->cab;
    while (aux != NULL) {
        printf("\n--- Listado de Usuarios para la Zona %d ---\n", aux->nroDeZona);
        Usuario *usuarioAux = aux->usuario;
        while (usuarioAux != NULL) {
            int importe = 0;
            if (strcmp(usuarioAux->TipoDeConsumo, "P") == 0 && usuarioAux->consumo >= consumoMinP) {
                importe = usuarioAux->consumo * tarifaP;
            } else if (strcmp(usuarioAux->TipoDeConsumo, "C") == 0 && usuarioAux->consumo >= consumoMinC) {
                importe = usuarioAux->consumo * tarifaC;
            }
            if (importe > 0) {
                printf("Zona: %d\nTipo: %s\nNombre: %s\nCalle: %s\nConsumo: %d\nImporte: %d\n\n",aux->nroDeZona, usuarioAux->TipoDeConsumo, usuarioAux->nombre,usuarioAux->calle, usuarioAux->consumo, importe);
            }
            usuarioAux = usuarioAux->sig;
        }
        aux = aux->sig;
    }
}
void ConsumoPromedio_consumoMaxCom_totalFact(Lista *lista) {
    Zona *aux = lista->cab;
    while (aux != NULL) {
        printf("Zona %d:\n", aux->nroDeZona);
        Usuario *auxU = aux->usuario;
        int totalComercialMax = 0; // Inicializar a 0
        int t = 0;
        int c = 0;
        int cantidadUsuariosComerciales = 0;

        // Definir y asignar valores a consumoMinC y consumoMinP

        while (auxU != NULL) {
            // Cálculo del consumo máximo de usuarios comerciales
            if (strcmp(auxU->TipoDeConsumo, "C") == 0) {
                if (auxU->consumo > totalComercialMax) {
                    totalComercialMax = auxU->consumo;
                }
            }

            // Cálculo del total de consumos mínimos y cantidad de usuarios con consumo mínimo
            // Asegúrate de que la condición sea la adecuada para tus necesidades
            if (auxU->consumo == consumoMinC || auxU->consumo == consumoMinP) {
                t += auxU->consumo;
            }

            // Contador de usuarios comerciales
            if (strcmp(auxU->TipoDeConsumo, "C") == 0) {
                cantidadUsuariosComerciales++;
            }

            auxU = auxU->sig;
        }

        // Impresión de los resultados
        printf("Consumo máximo de usuarios comerciales: %d\n", totalComercialMax);
        printf("Cantidad de usuarios comerciales: %d\n", cantidadUsuariosComerciales);

        aux = aux->sig;
    }
}

