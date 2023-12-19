#include "utility.h"



int main() {
  TArticulo articulos[NUMARTS];
  char *descripciones[] = {     //Este array tiene la lista de nombres para copiar a nuestro estructura
    "NULL",              //"NULL" existe porque el caracteristico "codigo" es igual a la posición de la lista, así que cuando una función que pide al usuario a ingresar el código del artículo, no empieza de cero.
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

  for (int i = 1;i<NUMARTS;i++ ) {                            //Este bucle es para inicializar las estructuras y asignar los valores arriba.
    strcpy(articulos[i].descripcion, descripciones[i]);
    articulos[i].codigo = i;
    articulos[i].precio = precios[i];
    articulos[i].stock = stocks[i];
    articulos[i].stock_inicial = stock_inicial[i];
    articulos[i].cantidad_comprada = cant_comp[i];

  }
  int op;  // Este variable es para elegir los casos en el condicional de switch.
  float m = 0; // Este variable contiene la cantidad de dinero que tiene el usuario.
  money(&m);  //Este función se asigna un valor aleatorio entre 2000-4000 y está asignado al variable m.
  

  do {
    menu(&op);    // Ejecuta una función que va a imprimir opciones y se pide el usuario a elegir una opción con variable op

    switch(op) {
      case 1:    //Si el usario quiere buscar por un artículo
        printf("¡Buenos días! Aquí tenemos una lista de articulos para comprar:\n");
        buscar(articulos);
        printf("Pulsa enter para continuar.");
        pulsaEnter();
        clear();
        break;

      case 2:      //Si el usario quiere comprar un artículo
        printf("Tienes %.2f euros.\n", m);        
        comprar(&m, articulos);
        printf("Pulsa enter para continuar.");
        pulsaEnter();
        clear();

        break;
      case 3:     //Si el usario quiere devolver un artículo
        printf("Tienes %.2f euros.\n", m);        
        reembolso(&m, articulos);
        printf("Pulsa enter para continuar.");
        pulsaEnter();
        clear();

        break;
      case 4:     //Si el usuario quiere salir y terminar el bucle
        printf("Saliendo...\n");
        break;

      case 5:     //Si el usuario quiere imprimir el ticket
        ticket(articulos);
        printf("Pulsa enter para continuar.");
        pulsaEnter();
        clear();
        break;

      default:    //Si algo inespecificado está puesto
        color(31);
        printf("Opción no valida. Intenta de nuevo.\n\n");
        color(37);
        printf("Pulsa enter para continuar.\n");
        pulsaEnter();
        clear();
        break;


    } 
  } while (op != 4);

  return 0;
}
