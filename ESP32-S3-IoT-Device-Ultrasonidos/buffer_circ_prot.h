/**
 @file buffer_circ_prot.h
*/

#ifndef BUFFER_CIRC_H
#define BUFFER_CIRC_H

#include "src/quirc/quirc.h"
#define BUFSIZE 10
#define true 1
#define false 0

#define T_espera 1000

typedef struct Buffer 
{
	struct quirc_data datos[BUFSIZE];
	int bufIN = 0;
  int bufOUT = 0;
  int contador = 0;
  portMUX_TYPE taskMux = portMUX_INITIALIZER_UNLOCKED;
} Buffer_Circ;

//Función para saber si el Buffer está vacío
bool isEmpty(Buffer_Circ* buff);

//Función para saber si el Buffer está lleno
bool isFull(Buffer_Circ* buff);

//Funcion para obtener elemento del Buffer
int get_item(struct quirc_data * X, Buffer_Circ* buff );

//Función para introducir elemento en el Buffer
int put_item(struct quirc_data  X , Buffer_Circ* buff );

//Función para saber cuántos elementos tiene el Buffer
int number(Buffer_Circ* buff);

//Función para listar el contenido del Buffer
int listBuffer(Buffer_Circ* buff);

#endif 

/*** End of file ****/