

#include "utility.h"



int main() {
  TArticulo articulos[NUMARTS];
  char *descripciones[] = {     //Este array tiene la lista de nombres para copiar a nuestro estructura
    "NULL",
    "Ratón InSys",
    "Teclado InSys",
    "Pantalla AlHua",
    "iPhone 15",
    "iPad",
    "Samsung Tablet S6",
    "Portatil"
  };

  float precios[] = {0, 5.99, 9.99, 50.99, 499.99, 549.99, 229.99, 1459.99};    //Este array tiene la lista de precios para copiar a nuestro estructura.
  float stocks[] = {0, 2, 22, 20, 20, 20, 20, 20};
  int stock_inicial[] = {0, 2, 22, 20, 20, 20, 20, 20};
  int cant_comp[] = {0,0,0,0,0,0,0,0};

  for (int i = 1;i<NUMARTS;i++ ) {
    strcpy(articulos[i].descripcion, descripciones[i]);
    articulos[i].codigo = i;
    articulos[i].precio = precios[i];
    articulos[i].stock = stocks[i];
    articulos[i].cantidad_comprada = cant_comp[i];

  }
  int op;
  float m = 0;
  money(&m);
  

  do {
    menu(&op);

    switch(op) {
      case 1:
        printf("¡Buenos días! Aquí tenemos una lista de articulos para comprar:\n");
        inicializar(articulos);
        break;

      case 2:
        printf("Tienes %.2f euros.\n", m);        
        comprar(&m, articulos);

        break;

      case 3:
        printf("Saliendo...\n");
        break;

      case 4:
        ticket(articulos);
        break;

      default:
        printf("Opción no valida. Intenta de nuevo.\n\n");
        break;


    } 
  } while (op != 3);

  return 0;
}