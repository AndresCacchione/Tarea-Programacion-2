#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

///Estructura de Materia:
    struct Materia
    {
        int num_materia;
        char nombre_materia[30];
        int cant_alum_insc;
        int cant_profe;
    };

///Estructura de ingresos:

    struct Ingresos
    {
        int legajo;
        int dia_acceso;
        int mes_acceso;
        int num_materia;
        float cant_hs;
    };



///PARA RESOLVER PUNTOS

    struct EstructABC
    {
        bool accesos;
        float cantidadHoras;
        int dias[31];
    };

const int CANT=20;


///prototipos de funciones

void cargarDatosMaterias(struct Materia *);
void cargarDatosIngresos(struct EstructABC *, float *, Ingresos *, Materia *);
void estadisticas(struct Materia *, struct EstructABC *, float *, Ingresos *);
void puntoA(struct Materia *, struct EstructABC *);
void puntoB(struct EstructABC *);
int calcularMaximo(struct EstructABC *, int);
void puntoC(struct EstructABC *);
void puntoD(struct Materia *);
void puntoE(float *, int);
int calcularMinimoSinCero(float *, int);
Ingresos may_acceso(Ingresos *,Ingresos *);
void puntoF(Ingresos *);
void mostrarMaterias(struct Materia *);
void puntoG(struct Materia *);
void copiar(Materia *,Materia *);

#endif // PROTOTIPOS_H_INCLUDED
