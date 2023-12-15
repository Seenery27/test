#include "utility.h"




void money(float *m){
  srand(time(NULL));
  float numero = 2000 + rand() % 2000;  // Genera un numero(aleatorio) entre 2000 y 4000
  *m = numero;
}

// Este funciona se asigna los valores por la lista de artículos que tenemos, 
void inicializar(TArticulo articulos[NUMARTS]) {
  int a;
  printf("articulo: ");
  scanf("%d", &a);

  if (a < 1 || a > NUMARTS-1) {
    printf("No existe este articulo.\n");
  } else {
      printf("REF: %d \n", articulos[a].codigo);
      printf("DESC: %s \n", articulos[a].descripcion);
      printf("PRECIO: %.2f \n", articulos[a].precio);
      printf("STOCK: %d \n\n", articulos[a].stock);
  }

}
  

void menu(int *A){
    
  printf("Menu\n\n");
  printf("Pulsa un numero para elegir\n");
  printf("1- Visualizar la lista de objetos\n");
  printf("2- Comprar articulos\n");
  printf("3- Salir\n");
  printf("4- Sacar el ticket\n");
  scanf("%d",A);

}


void comprar(float *m, TArticulo articulos[NUMARTS]){
  int code;
  printf("Introduce el codigo de artículo que quieres comprar: ");
  scanf("%d",&code);
  if (*m - articulos[code].precio < 0) {
    printf("\nNo puedes comprar este articulo.");
  } else {
      if (code == articulos[code].codigo) {
        if (articulos[code].stock != 0) {
          *m-=articulos[code].precio;
          articulos[code].stock--;
          articulos[code].cantidad_comprada++;
          printf("Añadiste el %s a tu carrito\n", articulos[code].descripcion);
          printf("Tienes %.2f euros restantes\n\n",*m);
      } else {
        printf("No tenemos este articulo en stock, disculpe por las molestias.\n\n");
      }
    }
  }
}



void reembolso(float *m, TArticulo articulos[NUMARTS]){
  int code;
  printf("Introduce el codigo de artículo que quieres reembolsar: ");
  scanf("%d",&code);
  if ( articulos[code].stock_inicial - articulos[code].stock == 0) {
    printf("\nNo puedes reembolsar este articulo.");
  } else {
      if (code == articulos[code].codigo) {
        if (articulos[code].stock != 0) {
          *m+=articulos[code].precio;
          articulos[code].stock++;
          articulos[code].cantidad_comprada--;
          printf("Añadiste el %s a tu carrito\n", articulos[code].descripcion);
          printf("Tienes %.2f euros restantes\n\n",*m);
      } else {
        printf("No tenemos este articulo en stock, disculpe por las molestias.\n\n");
      }
    }
  }
}


void ticket(TArticulo articulos[NUMARTS]) {
  float cantidadTotal = 0;
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
  printf("Total: %.2f\n", cantidadTotal);
}