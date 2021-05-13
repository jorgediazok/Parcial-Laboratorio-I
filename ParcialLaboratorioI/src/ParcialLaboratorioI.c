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
	char nombre[20];
	char apellido[20];
	int isEmpty;
}Contribuyente;


#define LEN 2

int inicializarContribuyentes(Contribuyente array[], int len);
int buscarLibre(Contribuyente array[], int len, int* posicion);
int contribuyente_alta(Contribuyente array[], int len, int* contadorID);
int contribuyente_modificar(Contribuyente list[], int len,int id);


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

			printf("Ingrese N° ID: \n");
			scanf("%d", &array[posicion].idContribuyente);

			printf("Ingrese Nombre: \n");
			scanf("%s", array[posicion].nombre);
			fflush(stdin);


			printf("Ingrese Apellido: \n");
			scanf("%s", array[posicion].apellido);
			fflush(stdin);


			printf("Ingrese N° de Cuil: \n");
			scanf("%d", &array[posicion].cuilContribuyente);

			printf("\nContribuyente guardado.");

			retorno=0;
		}
	}

	return retorno;
}

int contribuyente_modificar(Contribuyente array[], int len, int id)
{
	int i;
	char answer='y';
	int identificacion;
	char auxNombre[20];
	char auxApellido[20];
	int auxCuil;
	int retorno = -1;

		printf("\nIngrese el ID del contribuyente a Modificar: \n");
		scanf("%d", &identificacion);
		fflush(stdin);

		for(i=0; i < len;i++)
		{

			if(identificacion == array[i].idContribuyente)
			{
				printf("El empleado con el ID %d es: ", array[i].idContribuyente);
				printf("%s ", array[i].nombre);
				printf("%s.", array[i].apellido);
				printf(" Su número de cuil es %d. \n", array[i].cuilContribuyente);
				printf("Desea Modificar los datos? y/n\n");
				scanf("%c", &answer);

				if(answer == 'y' || answer == 'Y')
					{
					fflush(stdin);
					printf("\nIngrese el nuevo nombre: \n");
					scanf("%s", auxNombre);
					fflush(stdin);
					printf("\nIngrese el nuevo apellido: \n");
					scanf("%s", auxApellido);
					fflush(stdin);
					printf("\nIngrese el nuevo número de cuil: \n");
					scanf("%d", &auxCuil);
					fflush(stdin);

					fflush(stdin);


					strcpy(array[i].nombre, auxNombre);
					strcpy(array[i].apellido, auxApellido);
					array[i].cuilContribuyente = auxCuil;

					printf("\nEmpleado correctamente modificado.");
					retorno = 1;

					break;
					}
				else
				{
					if(answer == 'n' || answer == 'N')
					{
					fflush(stdin);
					printf("\nOperación Cancelada.\n");
					retorno = -1;
					break;
					}
				}
			}
			else
			{
				printf("No se encontró el usuario.");
				retorno = -1;
				break;
			}
		}

		return retorno;
}




