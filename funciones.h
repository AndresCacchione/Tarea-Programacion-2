#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///Funciones

//void cargarDatosMaterias(struct materias vMat[20]){

void cargarDatosMaterias(int numeroMaterias[CANT],char nombreMaterias[20][30], int cantidadInscriptos[20], int cantidadProfes[20]){
  int i, materia, inscriptos, profesores;
  const int CANTIDAD=4;
  char nombre[30];
  for(i=0;i<CANTIDAD; i++){
    system("cls");
    cout<<"INGRESE EL NUMERO DE LA MATERIA: ";
    cin>>materia;
    numeroMaterias[materia-1]=materia;///PERMITE QUE, CON ALGUNA PEQUEÑA MODIFICACIÓN, LAS MATERIAS TENGAN NUMEROS NO CORRELATIVOS
    cout<<"INGRESE EL NOMBRE: ";
    cin>>nombre;
    strcpy(nombreMaterias[materia-1],nombre);

    cout<<"INGRESE LA CANTIDAD DE ALUMNOS INSCRIPTOS: ";
    cin>>inscriptos;
    cantidadInscriptos[materia-1]=inscriptos;

    cout<<"INGRESE LA CANTIDAD DE PROFESORES: ";
    cin>>profesores;
    cantidadProfes[materia-1]=profesores;


  }
}

void ponerFalse(bool v[CANT], int tam){
  int i;
  for(i=0;i<tam;i++){
    v[i]=false;///0
  }
}

void ponerCeroVecF(float v[CANT], int tam){
  int i;
  for(i=0;i<tam;i++){
    v[i]=0;
  }
}

void ponerCeroMatriz(int m[CANT][31], int filas, int columnas){
  int i,j;
  for(i=0;i<filas;i++)
    for(j=0;j<columnas;j++)
      m[i][j]=0;

}

void cargarDatosIngresos(bool accesos[CANT], float horas[CANT], int m[CANT][31]){
  int legajo, dia, mes, materia;
  float tiempo;
  cout<<"INGRESE EL LEGAJO: ";
  cin>>legajo;
  while(legajo!=0){
    cout<<"INGRESE EL DIA DE ACCESO: ";
    cin>>dia;
    cout<<"INGRESE EL MES DE ACCESO: ";
    cin>>mes;
    cout<<"INGRESE EL NUMERO DE MATERIA: ";
    cin>>materia;
    cout<<"INGRESE LA CANTIDAD DE HORAS: ";
    cin>>tiempo;
    ///SE ALMACENAN LOS VALORES INGRESADOS EN LOS ARRAYS CORRESPONDIENTES
    ///Punto a)
    accesos[materia-1]=true;///Se cambia el estado para indicar que la materia tuvo acceso
    ///Punto b)
    horas[materia-1]+=tiempo;///Se acumula la cantidad de horas para cada materia
    ///punto c
    if(mes==3){
      m[materia-1][dia-1]++; ///Se cuenta la cantidad de veces que los estudiantes ingresaron
    ///a una materia en un día en particular
    }
    cout<<"INGRESE EL LEGAJO: ";
    cin>>legajo;
  }

}

void estadisticas(int numMaterias[], bool accesos[], float horas[CANT], int m[CANT][31], int *cantAlus, int *cantProfes,
                  char nombreMaterias[20][30]){
  char opc;
  while(true){
    system("cls");
    cout<<"----------------ESTADISTICAS----------------"<<endl;
    cout<<"A. MATERIAS SIN ACCESOS"<<endl;
    cout<<"B. MATERIA CON MAS HORAS DE ACCESO"<<endl;
    cout<<"C. HORAS DE ACCESO POR DIA Y MATERIA EN MARZO"<<endl;
    cout<<"D. CANTIDAD DE ALUMNOS POR PROFESOR"<<endl;
    cout<<"E. DIA DE MENOS ACCESOS MARZO QUINCENA 2"<<endl;
    cout<<"F. LISTADO ORDENADO"<<endl;
    cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"------------SELECCIONE UNA OPCION-------------"<<endl;
    cin>>opc;
    system("cls");
    switch(opc){
      case 'A':
      case 'a':
                puntoA(accesos, nombreMaterias);
                break;
      case 'B':
      case 'b':
                puntoB(horas);
                break;
      case 'C':
      case 'c':
                puntoC(m);
                break;
      case 'D':
      case 'd':
                puntoD(cantAlus, cantProfes);
                break;
      case 'E':
      case 'e':
                puntoE();
                break;
      case 'F':
      case 'f':
                puntoF(numMaterias, cantAlus, cantProfes, nombreMaterias);
                break;


      default:  cout<<"OPCION INCORRECTA"<<endl;
                break;
      case '0': return;


    }
    system("pause");
  }
}

///FUNCIONES PARA RESOLVER LOS PUNTOS

void puntoA(bool *accesos,char nombre_materia[CANT][30]){
  int i;
  for(i=0;i<CANT;i++){
    if(accesos[i]==false){
      cout<<"LA MATERIA "<<i+1<<" NO REGISTRO ACCESOS"<<endl;

    }
    ///¿QUE HARÍA FALTA PARA QUE MUESTRE EL NOMBRE DE LA MATERIA?
  }
}


///PUNTOS A RESOLVER. DEJE LAS FUNCIONES VACIAS (SOLO {}) PARA QUE EL PROGRAMA COMPILE
void puntoB(float *horas){
  int materiaMaxima=calcularMaximo(horas, 20)+1;
  cout<<"LA MATERIA CON MAYOR CANTIDAD DE HORAS ES: "<<materiaMaxima<<endl;
  system("pause");
}

int calcularMaximo(float *horas, int tam){
  int i, posMax=0;
  for(i=1;i<tam;i++){
    if(horas[i]>horas[posMax]){
        posMax=i;
    }
  }
  return posMax;
}

void puntoC(int m[CANT][31]){
  int i, j;
  for(i=0;i<CANT;i++){
      cout<<"PARA LA MATERIA: "<<i+1<<endl;
    for(j=0;j<31;j++){
      cout<<"DIA: "<<j+1<<"\t"<<"CANTIDAD DE ACCESOS: "<<m[i][j]<<endl;
    }
  system("pause");
  }
}

void puntoD(int *cA, int *cP){
  int i;
  for(i=0;i<CANT;i++){
    if(cP[i]!=0){
        cout<<"MATERIA: "<<i+1<<"\t";
      cout<<"ALUMNOS POR PROFESOR: "<<(float) cA[i]/cP[i]<<endl;
    }
  }

}
void puntoE(){
  cout<<"A HACERLO!!!"<<endl;
}
/*void puntoE(float *v, int tam){
  int diaMin;
  diaMin=calcularMinimoSinCero(v,tam)+16;
  cout<<"EL DIA DE MENOS INGRESOS FUE: "<<diaMin<<endl;
  system("pause");
  }
}
*/

void puntoF(int *numeroMateria, int *cantAlus, int *cantProfes, char nombreMaterias[20][30]){
  int i, j, posMax;
  int auxProfe, auxAlu, auxNumero;
  char auxMateria[30];
  for(i=0;i<CANT-1;i++){
    posMax=i;
    for(j=i+1;j<CANT;j++){
      if(cantAlus[j]>cantAlus[posMax]){
        posMax=j;///SE HALLA LA POSICIÓN DEL MÁXIMO EN EL VECTOR
      }
    }
      ///SE REALIZAN LOS INTERCAMBIOS PARA ORDENAR LOS 3 ARRAYS
      if(numeroMateria[i]!=0){///para que ignore los valores no ingresados
        auxNumero=numeroMateria[i];
        numeroMateria[i]=numeroMateria[posMax];
        numeroMateria[posMax]=auxNumero;

        auxAlu=cantAlus[i];
        cantAlus[i]=cantAlus[posMax];
        cantAlus[posMax]=auxAlu;

        auxProfe=cantProfes[i];
        cantProfes[i]=cantProfes[posMax];
        cantProfes[posMax]=auxProfe;

        strcpy(auxMateria, nombreMaterias[i]);
        strcpy(nombreMaterias[i], nombreMaterias[posMax]);
        strcpy(nombreMaterias[posMax], auxMateria);
        }
    }
  mostrarMaterias(cantAlus, cantProfes, nombreMaterias, numeroMateria);

}

void mostrarMaterias(int cantAlus[20], int cantProfes[20], char nombreMaterias[][30],  int *nMat){
  int i;
  for(i=0;i<CANT;i++){
  if(nMat[i]!=0){
    cout<<"NUMERO DE MATERIA: "<<nMat[i]<<"\t";
    cout<<"NOMBRE MATERIA: "<<nombreMaterias[i]<<endl;
    cout<<"CANTIDAD DE ALUMNOS: "<<cantAlus[i]<<"\t CANTIDAD DE PROFESORES: "<<cantProfes[i]<<endl;
    system("pause");
   }
  }


}




#endif // FUNCIONES_H_INCLUDED
