/*
 ============================================================================
 Name        : ParcialLaboratorioI.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

Se necesita administrar la recaudacion de impuestos de los contribuyentes, y para ello
se deberá realizar un programa de acuerdo a lo siguiente:
Contará con el siguiente menú:


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Contribuyente.h"

#define LEN 2


int main(void) {

	setbuf(stdout, NULL);

	Contribuyente array[LEN];

	int opcion = 0;
	int auxContadorContribuyente=1000;
	int respuesta;
	int auxId = 0;


	inicializarContribuyentes(array, LEN); //Inicializo los arrays en 1 (o sea disponibles para usar)

	do
		{
		respuesta = utn_getNumero(&opcion, "\n\n||||MENU CONTRIBUYENTES||||\n\n1 - ALTA \n2 - MODIFICAR \n3 - BAJA\n4 - RECAUDACIÓN\n5 - REFINANCIAR RECAUDACION\n6 - SALDAR RECAUDACIÓN\n7 - IMPRIMIR CONTRIBUYENTES\n8 - IMPRIMIR RECAUDACION\n9 - SALIR\n\n\n", "Opción no válida", 1, 9, 2);

		if(respuesta == 0)
		{
			switch(opcion)
			{
			case 1: //ALTA CONTRIBUYENTE
				contribuyente_alta(array, LEN, &auxContadorContribuyente);
				break;
			case 2:	//MODIFICAR CONTRIBUYENTE
				contribuyente_modificar(array, LEN, auxId);
				break;
			case 3: //BAJAR CONTRIBUYENTE
				contribuyente_baja(array, LEN);
				break;
			case 4: //RECAUDACION
				break;
			case 5: //REFINANCIAR RECAUDACIÓN
			    break;
			case 6: //SALDAR RECAUDACIÓN
				break;
			case 7: //IMPRIMIR CONTRIBUYENTES
				contribuyente_imprimir(array, LEN);
				break;
			case 8: //IMPRIMIR RECAUDACIÓN
				break;
			case 9:
				printf("Saliste del sistema.");
				//Agregar desea salir del sistema?
				exit(0);
				break;
			}
		}

		}while(opcion != 9);

	return 0;
}


