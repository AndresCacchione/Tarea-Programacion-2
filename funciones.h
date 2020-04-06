#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///Funciones

//void cargarDatosMaterias(struct materias vMat[20]){

void cargarDatosMaterias(Materia *v_mat)
{
    int num_mat;
    for(int i=0;i<CANT; i++)
    {
    system("cls");
    cout<<"INGRESE EL NUMERO DE LA MATERIA: ";
    cin>>num_mat;

    cout<<"INGRESE EL NOMBRE: ";
    cin.ignore();
    cin.getline(v_mat[num_mat-1].nombre_materia,30);
    cout<<"INGRESE LA CANTIDAD DE ALUMNOS INSCRIPTOS: ";
    cin>>v_mat[num_mat-1].cant_alum_insc;
    cout<<"INGRESE LA CANTIDAD DE PROFESORES: ";
    cin>>v_mat[num_mat-1].cant_profe;
    }
}


void cargarDatosIngresos(struct EstructABC *V_ABC, float *vector_punto_E, Ingresos *Ing_maxF, Materia *v_mat){
  struct Ingresos Ing;

  cout<<"INGRESE EL LEGAJO: ";
  cin>>Ing.legajo;
  while(Ing.legajo!=0){
    cout<<"INGRESE EL DIA DE ACCESO: ";
    cin>>Ing.dia_acceso;
    cout<<"INGRESE EL MES DE ACCESO: ";
    cin>>Ing.mes_acceso;
    cout<<"INGRESE EL NUMERO DE MATERIA: ";
    cin>>Ing.num_materia;
    cout<<"INGRESE LA CANTIDAD DE HORAS: ";
    cin>>Ing.cant_hs;
    ///SE ALMACENAN LOS VALORES INGRESADOS EN LOS ARRAYS CORRESPONDIENTES
    ///Punto a)

    v_mat[Ing.num_materia-1].num_materia=Ing.num_materia;
    V_ABC[Ing.num_materia-1].accesos=true;///Se cambia el estado para indicar que la materia tuvo acceso
    ///Punto b)
    V_ABC[Ing.num_materia-1].cantidadHoras+=Ing.cant_hs;///Se acumula la cantidad de horas para cada materia
    ///punto c
    if(Ing.mes_acceso==3)
        {
        V_ABC[Ing.num_materia-1].dias[Ing.dia_acceso-1]++; ///Se cuenta la cantidad de veces que los estudiantes ingresaron
        ///a una materia en un día en particular

        if(Ing.dia_acceso>15)
        {
            vector_punto_E[Ing.dia_acceso-16]+=Ing.cant_hs;
        }
    }
    *Ing_maxF = may_acceso(Ing_maxF, &Ing);


    cout<<"INGRESE EL LEGAJO: ";
    cin>>Ing.legajo;
  }
}

struct Ingresos may_acceso(Ingresos *Ing_maxF,Ingresos *Ing)
{
    if((*Ing).cant_hs>(*Ing_maxF).cant_hs)
    {
        *Ing_maxF=*Ing;
    }
return *Ing_maxF;
};

void estadisticas(struct Materia *v_mat, struct EstructABC *V_ABC, float *vector_punto_E, Ingresos *Ing_maxF){
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
                puntoA(v_mat, V_ABC);
                break;
      case 'B':
      case 'b':
                puntoB(V_ABC);
                break;
      case 'C':
      case 'c':
                puntoC(V_ABC);
                break;
      case 'D':
      case 'd':
                puntoD(v_mat);
                break;
      case 'E':
      case 'e':
                puntoE(vector_punto_E, 16);
                break;
      case 'F':
      case 'f':
                puntoF(Ing_maxF);
                break;

      case 'G':
      case 'g':
                puntoG(v_mat);
                break;


      default:  cout<<"OPCION INCORRECTA"<<endl;
                break;
      case '0': return;


    }
    system("pause");
  }
}

///FUNCIONES PARA RESOLVER LOS PUNTOS

void puntoA(Materia *v_mat, EstructABC *V_ABC)
{
  for(int i=0;i<CANT;i++)
    {
    if(V_ABC[i].accesos==false)
    {
      cout<<"LA MATERIA "<< v_mat[i].nombre_materia <<" NO REGISTRO ACCESOS"<<endl;
    }
    }
}


///PUNTOS A RESOLVER. DEJE LAS FUNCIONES VACIAS (SOLO {}) PARA QUE EL PROGRAMA COMPILE
void puntoB(struct EstructABC *V_ABC){
  int materiaMaxima=calcularMaximo(V_ABC, CANT)+1;
  cout<<"LA MATERIA CON MAYOR CANTIDAD DE HORAS ES: "<<materiaMaxima<<endl;
  system("pause");
}

int calcularMaximo(struct EstructABC *V_ABC, int tam){
  int posMax=0;
  for(int i=1;i<tam;i++){
    if(V_ABC[i].cantidadHoras>V_ABC[posMax].cantidadHoras){
        posMax=i;
    }
  }
  return posMax;
}

void puntoC(EstructABC *V_ABC){

  for(int i=0;i<CANT;i++){
      cout<<"PARA LA MATERIA: "<<i+1<<endl;
    for(int j=0;j<31;j++){
      cout<<"DIA: "<<j+1<<"\t"<<"CANTIDAD DE ACCESOS: "<<V_ABC[i].dias[j]<<endl;
    }
  system("pause");
  }
}

void puntoD(Materia *v_mat){

  for(int i=0;i<CANT;i++){
    if(v_mat[i].cant_profe!=0){
        cout<<"MATERIA: "<<i+1<<"\t";
      cout<<"ALUMNOS POR PROFESOR: "<<(float) v_mat[i].cant_alum_insc/v_mat[i].cant_profe<<endl;
    }
  }
}

void puntoE(float *vector_punto_E, int tam)
{
  int diaMin;
  diaMin = calcularMinimoSinCero(vector_punto_E, tam)+16;
  if(diaMin==15)
  {
      cout<<"NO HUBO INGRESOS EN LA QUINCENA"<<endl;
  }
  cout<<"EL DIA DE MENOS INGRESOS FUE: "<<diaMin<<endl;
  system("pause");
}


int calcularMinimoSinCero(float *vector_punto_E, int tam)
{
    bool primer_minimo=true;
    int pos_min=-1;
    for(int i=0; i<tam;i++)
    {
        if(vector_punto_E[i]>0)
        {
            if(primer_minimo || (vector_punto_E[i] < vector_punto_E[pos_min]))
            {
                pos_min=i;
                primer_minimo=false;
            }
        }
    }
return pos_min;
}


void puntoF(Ingresos *Ing_maxF)
{
    cout<<"El ingreso individual de mayor duracion fue realizado por el legajo "<<(*Ing_maxF).legajo << endl;
    cout<<"Y fue realizado el dia "<< (*Ing_maxF).dia_acceso << "/"<< (*Ing_maxF).mes_acceso<<endl;
}


void puntoG(Materia *v_mat)
{
  Materia v_mat_ordenar[CANT];
  copiar(v_mat,v_mat_ordenar);

  int i, j, posMax;
  Materia aux;
  for(i=0;i<CANT-1;i++)
    {
    posMax=i;
    for(j=i+1;j<CANT;j++){
      if(v_mat_ordenar[j].cant_alum_insc > v_mat_ordenar[posMax].cant_alum_insc){
        posMax=j;///SE HALLA LA POSICIÓN DEL MÁXIMO EN EL VECTOR
      }
    }
      ///SE REALIZAN LOS INTERCAMBIOS PARA ORDENAR LOS 3 ARRAYS
      if(v_mat_ordenar[i].num_materia!=0)
        {///para que ignore los valores no ingresados
        aux=v_mat_ordenar[i];
        v_mat_ordenar[i]=v_mat_ordenar[posMax];
        v_mat_ordenar[posMax]=aux;
        }
    }
  mostrarMaterias(v_mat_ordenar);

}


void copiar(Materia *v_mat,Materia *v_mat_ordenar)
{
    for(int i=0; i<CANT;i++)
    {
        v_mat_ordenar[i]=v_mat[i];
    }
}


void mostrarMaterias(Materia *v_mat)
{
  int i;
  for(i=0;i<CANT;i++)
  {
  if(v_mat[i].num_materia!=0)
  {
    cout<<"NUMERO DE MATERIA: "<<v_mat[i].num_materia<<"\t";
    cout<<"NOMBRE MATERIA: " << v_mat[i].nombre_materia <<endl;
    cout<<"CANTIDAD DE ALUMNOS: "<<v_mat[i].cant_alum_insc<<"\t CANTIDAD DE PROFESORES: "<<v_mat[i].cant_profe<<endl;
    system("pause");
   }
  }
}

#endif // FUNCIONES_H_INCLUDED
