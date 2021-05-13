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

typedef struct{
	int idContribuyente; //Comienza en 1000
	int cuilContribuyente;
	char apellido[20];
	int isEmpty;
}Contribuyente;


#define LEN 2

int inicializarContribuyentes(Contribuyente array[], int len);
int buscarLibre(Contribuyente array[], int len, int* posicion);
int contribuyente_alta(Contribuyente array[], int len, int* contadorID);


int main(void) {

	setbuf(stdout, NULL);

	Contribuyente array[LEN];

	int opcion = 0;
	int auxContadorContribuyente=1000;
	int respuesta;

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
				break;
			case 3: //BAJAR CONTRIBUYENTE
				break;
			case 4: //RECAUDACION
				break;
			case 5: //REFINANCIAR RECAUDACIÓN
			    break;
			case 6: //SALDAR RECAUDACIÓN
				break;
			case 7: //IMPRIMIR CONTRIBUYENTES
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


//INICIALIZAR CONTRIBUYENTES
int inicializarContribuyentes(Contribuyente array[], int len)
{

	int i;
	int retorno = -1;

		if(array != NULL && len > 0)
		{
			for(i=0; i < len; i++)
			{
				array[i].isEmpty = 1; //Pone cada campo is empty array en 1, o sea está disponible/libre
			}

			retorno = 1;
		}

		return retorno;

}

int buscarLibre(Contribuyente array[], int len, int* posicion)
{
	int retorno = -1;

		if(array != NULL && len > 0 && posicion != NULL)
		{
			int i;
			for(i=0; i < len; i++)
			{
				if(array[i].isEmpty == 1)
				{
					retorno = 0;
					*posicion = i;
					break;
				}
			}
		}
		return retorno;
}

//Alta

int contribuyente_alta(Contribuyente array[], int len, int* contadorID)
{
	int retorno = -1;
	int posicion;
	if(array != NULL && len > 0 && contadorID != NULL)
	{
		if(buscarLibre(array, len, &posicion)==-1)
		{
			printf("\nNo hay lugares vacíos");
		}
		else
		{
			(*contadorID)++;
			array[posicion].idContribuyente=*contadorID;
			printf("Ingrese N° de Cuil: \n");

			scanf("%d", &array[posicion].cuilContribuyente);
			printf("Ingrese Apellido: \n");
			scanf("%s", array[posicion].apellido);

			printf("Contribuyente guardado.");

			retorno=0;
		}
	}

	return retorno;
}





