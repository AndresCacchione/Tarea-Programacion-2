#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

///prototipos de funciones

void cargarDatosMaterias(int numeroMaterias[CANT],char nombreMaterias[20][30], int cantidadInscriptos[20], int cantidadProfes[20]);

void cargarDatosIngresos(bool [], float [], int [CANT][31]);
///(bool *, float *, int [CANT][31])
///(bool [20], float [20], int [CANT][31])

void estadisticas(int [], bool [], float [], int [CANT][31], int *, int *, char (*)[30]);

void ponerFalse(bool [], int);
void ponerCeroVecF(float [],int);
void ponerCeroMatriz(int [CANT][31], int , int);

void puntoA(bool *, char [CANT][30]);
void puntoB(float *);
  int calcularMaximo(float *, int);
void puntoC(int [CANT][31]);
void puntoD(int *,int *);
void puntoE();
void puntoF(int numMateria[], int cantAlus[20], int cantProfes[20], char nombreMaterias[][30]);
void mostrarMaterias(int cantAlus[20], int cantProfes[20], char nombreMaterias[][30], int *nMat);


#endif // PROTOTIPOS_H_INCLUDED
