/*
 * Contribuyente.c
 *
 *  Created on: 13 may. 2021
 *      Author: Jorge
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuyente.h"

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

			array[posicion].isEmpty = 0;

			printf("\nContribuyente guardado.");

			retorno=0;
		}
	}

	return retorno;
}

int contribuyente_modificar(Contribuyente array[], int len, int id)
{
	int i;
	char respuesta='s';
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
				printf("Desea Modificar los datos? s/n\n");
				scanf("%c", &respuesta);

				if(respuesta == 's' || respuesta == 'S')
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
					if(respuesta == 'n' || respuesta == 'N')
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

//BAJA

int contribuyente_baja(Contribuyente array[], int len)
{
	int i;
	int identificacion;
	char respuesta = 's';
	int retorno;
	printf("Ingrese el ID del contribuyente que desea dar de baja: ");
	scanf("%d", &identificacion);
	fflush(stdin);

	for(i=0;i<len;i++)
		{
			if(identificacion == array[i].idContribuyente)
			{
				printf("\nEl contribuyente con el ID %d será dado de baja. Desea continuar? s/n \n", identificacion);
				scanf("%c", &respuesta);

				if(respuesta == 's' || respuesta == 'S'){
					printf("El contribuyente con el ID %d fue eliminado.\n", identificacion);
					array[i].isEmpty = 1;
					retorno = 1;
				}


		    	if(respuesta == 'n' || respuesta == 'N')
					{
						printf("Operación cancelada.\n");
						retorno = -1;
					}
				}
			if(identificacion != array[i].idContribuyente)
			{
			printf("Contribuyente no encontrado.");
			retorno = -1;
			break;
			}
		}

		return retorno;
}

//LISTAR CONTRIBUYENTES

void contribuyente_imprimir(Contribuyente array[], int len)
{
	int i;
	printf("\n|||CONTRIBUYENTES UTN|||\n");

	for(i=0; i < len; i++)
	{
		if(array[i].isEmpty == 0)
		{
			printf("\nID: %d", array[i].idContribuyente);
			printf("\nNombre: %s", array[i].nombre);
			printf("\nApellido: %s", array[i].apellido);
			printf("\nCuil: %d \n", array[i].cuilContribuyente);
		}

	}
}


