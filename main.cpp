//Ejercicio: REPASO VARIABLES Y FUNCIONES LAB2
//Autor:DEK
//Fecha: 20/03/2020
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;
#include "prototipos.h"
#include "funciones.h"


int main()
{
    int opc;

    Materia v_mat[CANT]={0};
    EstructABC V_ABC[CANT]={0};
    float vector_punto_E[16]={0};
    struct Ingresos Ing_maxF={0};

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
        case 1: cargarDatosMaterias(v_mat);
                break;
        case 2: cargarDatosIngresos(V_ABC, vector_punto_E, &Ing_maxF, v_mat);
                break;
        case 3: estadisticas(v_mat, V_ABC, vector_punto_E, &Ing_maxF);
                break;
        case 4: mostrarMaterias(v_mat);
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
