//Este fichero es para enlacer los ficheros de main.c y utility.c.
//Contiene los librarios, estructuras, prototipos, y los macros.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_CAD 30
#define NUMARTS 8


typedef char TCadena[MAX_CAD];
typedef struct {
    int codigo;
    TCadena descripcion;
    float precio;
    int stock;
    int stock_inicial;
    int cantidad_comprada;
} TArticulo;

void menu();
void buscar(TArticulo articulos[NUMARTS]);
void comprar(float *m, TArticulo articulos[NUMARTS]);
void reembolso(float *m, TArticulo articulos[NUMARTS]);
void money(float *m);
void ticket(TArticulo articulos[NUMARTS]);
void clear();
void pulsaEnter();
void canjear_Descuento(float *cantidadTotal_temporal);

