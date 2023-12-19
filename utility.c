#include "utility.h"  //Este fichero es para enlacer los ficheros de main.c y utility.c. Contiene todos los librarios que necesitaremos.

void clear() {
     printf("\033[2J"); 
}

void pulsaEnter() {
  while (getchar() != '\n');
}


void money(float *moneda){
  srand(time(NULL));
  float numero = 2000 + rand() % 2000;  // Genera un numero(aleatorio) entre 2000 y 4000
  *moneda = numero;
}

// Este funciona se busca por el código introducido y se devuelva la información relacionado con el código introducido.
void buscar(TArticulo articulos[NUMARTS]) {
  int a;
  printf("Ingrese el número de artículo (1-%d): ", NUMARTS-1);
  scanf("%d", &a);

  if (a < 0 || a >= NUMARTS) {
    color(31);
    printf("El artículo no existe.\n");
    color(37);
  } else {
    printf("REF: %d \n", articulos[a].codigo);
    printf("DESC: %s \n", articulos[a].descripcion);
    printf("PRECIO: %.2f \n", articulos[a].precio);
    printf("STOCK: %d \n\n", articulos[a].stock);
  }
  pulsaEnter();
}
  
void menu(int *opcion){
    
  printf("Menu\n\n");
  printf("Pulsa un numero para elegir\n");
  printf("1- Visualizar la lista de objetos\n");
  printf("2- Comprar articulos\n");
  printf("3- Reembolsar articulos\n");
  printf("4- Salir\n");
  printf("5- Sacar el ticket\n");
  scanf("%d",opcion);
}

void comprar(float *moneda, TArticulo articulos[NUMARTS]){
  int code;
  printf("Introduce el codigo de artículo que quieres comprar: ");
  scanf("%d",&code);
  if (code < 0 || code >= NUMARTS) {
    color(31);
    printf("El artículo no existe.\n");
    color(37);
  }
  else {  
    if (*moneda - articulos[code].precio < 0) {  
      printf("\nNo puedes comprar este articulo.\n");
    } 
    else { 
      if (articulos[code].stock != 0) {
        *moneda-=articulos[code].precio;
        articulos[code].stock--;
        articulos[code].cantidad_comprada++;
        printf("Añadiste el %s a tu carrito\n", articulos[code].descripcion);
        printf("Tienes %.2f euros restantes\n\n",*moneda);
      } 
      else {
        printf("No tenemos este articulo en stock, disculpe por las molestias.\n\n");
      }
    }
  }
  pulsaEnter();
}

void reembolso(float *moneda, TArticulo articulos[NUMARTS]){
  int code;
  printf("Introduce el codigo de artículo que quieres reembolsar: ");
  scanf("%d",&code);
    if (code < 0 || code >= NUMARTS) {
    color(31);
    printf("El artículo no existe.\n");
    color(37);
  }
  else {
    if ( articulos[code].stock_inicial - articulos[code].stock == 0) {
      printf("\nNo puedes reembolsar este articulo.");
    } 
    else {
      *moneda+=articulos[code].precio;
      articulos[code].stock++;
      articulos[code].cantidad_comprada--;
      printf("Quitaste el %s de tu carrito\n", articulos[code].descripcion);
      printf("Tienes %.2f euros restantes\n\n",*moneda);
    }
  }
  pulsaEnter();
}


void ticket(TArticulo articulos[NUMARTS]) {
  float cantidadTotal = 0;
  float cantidadTotal_temporal = 0;
  for(int i=1;i<NUMARTS;i++) {
    if (articulos[i].cantidad_comprada > 0) {
      cantidadTotal_temporal += articulos[i].cantidad_comprada*articulos[i].precio;
    }
  }

 canjear_Descuento(&cantidadTotal_temporal);

  printf("---------------------------------------------------------------------\n");
  printf("%-20s%-10s%-10s%-10s\n", "Descripción", "Cantidad", "Precio", "Total");
  printf("---------------------------------------------------------------------\n");
  for(int i=1;i<NUMARTS;i++) {
    if (articulos[i].cantidad_comprada > 0) {
      printf("%-20s%-10d%-10.2f%-15.2f\n", articulos[i].descripcion, articulos[i].cantidad_comprada, articulos[i].precio, articulos[i].cantidad_comprada*articulos[i].precio);
      cantidadTotal += articulos[i].cantidad_comprada*articulos[i].precio;
      printf("\n");
    }
  }
  printf("---------------------------------------------------------------------\n");

 if(cantidadTotal_temporal != 0){
    cantidadTotal = cantidadTotal_temporal;
    printf("Total con descuento: %.2f\n", cantidadTotal);
  }
  else {  
    printf("Total: %.2f\n", cantidadTotal);
  }

  pulsaEnter();
}

 
void canjear_Descuento(float *cantidadTotal_temporal)
{

	int descuento; // variable para elegir si quiere usar un descuento
  char codigo_descuento[5] ="eps"; // código de descuento
  char codigo_usuario[5]; // código que escribe el usuario
    
    	// tiene un código de descuento?
	printf("\nTienes un codigo de descuento? si=1 no=0\n");
	scanf("%d", &descuento);
	if (descuento == 0) // sin descuento
	{
		printf("No tienes un descuento, debes pagar el total. \n"); 
	}
	// con descuento
	if (descuento == 1) 
	{
		printf("Escribe el código de descuento:\n ");
		scanf("%5s" , codigo_usuario); 
 
		// check si el código es correcto con una comparacion
		if ( strcmp(codigo_descuento, codigo_usuario) == 0 ) 
		{
			 *cantidadTotal_temporal = *cantidadTotal_temporal * 0.90; // descuento del 10%
      color(32);
			printf("Tu descuento se proceso correctamente, Pagarás 10 porciento menos \n");
		  color(37);
    }
		else // escribes un código equivocado 
		{
      color(31);
			printf("El código introducido no es valido, pagarás precio el original  \n" );
      color(37);
		}
	}
}


void color(int color) {
  
     printf("\033[%dm",color); 
}

