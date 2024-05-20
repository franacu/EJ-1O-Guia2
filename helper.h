//
// Created by Fran on 18/05/2024.
//

#ifndef EJ8_GUIA2_HELPER_H
#define EJ8_GUIA2_HELPER_H
typedef struct usuario {
    char nombre[100];
    int nroDeZona;
    char TipoDeConsumo[2]; // 'P' para particular, 'C' para comercial
    int consumo;
    char calle[100];
    struct usuario *sig;
} Usuario;

typedef struct zona {
    int nroDeZona;
    Usuario *usuario;
    struct zona *sig;
} Zona;

typedef struct lista
{
    Zona *cab;
} Lista;
Usuario *newUsuario(char *nombre,int nroDeZona,char *tipoDeConsumo,int consumo,char *calle);
Zona *newZona(int NroDeZona);
Lista *newListaZonas();
void AgregamosUsuariosAlaZona(Usuario *usuario,Lista *lista);
void ListarYInformarPorZonas(Lista *lista);
void ConsumoPromedio_consumoMaxCom_totalFact(Lista *lista);
#endif //EJ8_GUIA2_HELPER_H
