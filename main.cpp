//Ejercicio: REPASO VARIABLES Y FUNCIONES LAB2
//Autor:DEK
//Fecha: 20/03/2020
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;

const int CANT=20;
#include "prototipos.h"
#include "funciones.h"


int main()
{
    int opc;

    ///Para datos de las materias
    int numeroMaterias[CANT]={0};
    int cantidadInscriptos[CANT]={0}; ///pongo la cantidad; cuando uso arranco de 0, termino en 19
    int cantidadProfes[CANT]={0};
    char nombreMaterias[CANT][30];
    for(int i;i<CANT;i++) nombreMaterias[i][29]='\0';
    ///LOS ARRAYS ANTERIORES  NO EXIGIAN PONER EN 0,
    ///PERO COMO SE VA A PROBAR CON LOTES DE DATOS CHICOS LOS PONGO EN
    ///0 PARA EVITAR ERRORES


    ///PARA RESOLVER PUNTOS
    ///a
    bool accesos[CANT];
    ///b
    float cantidadHoras[CANT];
    ///c
    int  materiasDias[CANT][31];

    ///PREPARO LOS VECTORES QUE NECESITAN INICIALIZARSE
    ponerFalse(accesos, CANT);
    ponerCeroVecF(cantidadHoras,CANT);
    ponerCeroMatriz(materiasDias, CANT, 31);

    while(true){
      system("cls");
      cout<<"--------ANALISIS CURSOS--------"<<endl;
      cout<<"     1.  INGRESO DE DATOS DE MATERIAS"<<endl;
      cout<<"     2.  INGRESO DE DATOS DE ACCESOS"<<endl,
      cout<<"     3.  ESTADISTICAS"<<endl;
      cout<<"     4.  MOSTRAR DATOS DE MATERIAS"<<endl;
      cout<<"     0. SALIR"<<endl;
      cout<<"-----SELECCIONE UNA OPCION ----- "<<endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: cargarDatosMaterias(numeroMaterias, nombreMaterias, cantidadInscriptos,cantidadProfes);
                break;
        case 2: cargarDatosIngresos(accesos, cantidadHoras, materiasDias);
                break;
        case 3: estadisticas(numeroMaterias, accesos, cantidadHoras, materiasDias, cantidadInscriptos,cantidadProfes, nombreMaterias);
                break;
        case 4: mostrarMaterias(cantidadInscriptos,cantidadProfes, nombreMaterias, numeroMaterias);
                break;
        default:  cout<<"OPCION INCORRECTA"<<endl;;
                break;
        case 0: return 0;
                break;

      }
      system("pause");
    }
    return 0;
}
