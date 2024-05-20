
#include "helper.h"
int main()
{
    Usuario *uA=newUsuario("Francisco",1,"P",3000,"AvPeron");
    Usuario *uB=newUsuario("Franco",2,"C",5000,"AvLasheras");
    Usuario *uC=newUsuario("Maria",2,"C",4000,"AvPeperina");
    Usuario *uD=newUsuario("Milena",1,"P",3000,"Caballito");
    Lista *lista=newListaZonas();
    AgregamosUsuariosAlaZona(uA,lista);
    AgregamosUsuariosAlaZona(uB,lista);
    AgregamosUsuariosAlaZona(uC,lista);
    AgregamosUsuariosAlaZona(uD,lista);

    ListarYInformarPorZonas(lista);
    ConsumoPromedio_consumoMaxCom_totalFact(lista);
    return 0;
}
