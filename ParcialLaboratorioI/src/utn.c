/*
 * utn.c
 *
 *  Created on: 6 may. 2021
 *      Author: Jorge
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//GET NUMERO

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <=maximo)
			{
			*pResultado = bufferInt;
			retorno = 0;
			break;
			}
			else
			{
			printf("%s", mensajeError);
			reintentos--;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

//GET FLOTANTE

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
		int retorno = -1;
		float bufferFloat;


		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s", mensaje);
				scanf("%f", &bufferFloat);
				if(bufferFloat >= minimo && bufferFloat <=maximo)
				{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
				}
				else
				{
				printf("%s", mensajeError);
				reintentos--;
				}
			}while(reintentos >= 0);
		}

		return retorno;

}



//GET CARACTER

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
		int retorno = -1;
		char bufferChar;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%c", &bufferChar);
				if(bufferChar >= minimo && bufferChar <=maximo)
				{
				*pResultado = bufferChar;
				retorno = 0;
				break;
				}
				else
				{
				printf("%s", mensajeError);
				reintentos--;
				}
			}while(reintentos >= 0);
		}

		return retorno;
}

//Verifico si el valor recibido es numerico. El parametro es el string con la cadena a ser analizada. Retorna 1
//si es numerico y 0 si no lo es

int esNumerico(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
		return 0;
		i++;
	}
	return 1;
}

//Verifico si el valor recibido contiene solo letras. El parametro es el string con la cadena a ser analizada.
//Retorna 1 si contiene solo ' ' y letras y 0 si no lo es

int esSoloLetras(char str[])
{
	int i=0;
	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		return 0;
		i++;
	}
	return 1;
}

//Verifico si el valor recibido contiene solo letras y numeros (alfanumerico). El parametro es el string con la
//cadena a ser analizada. Retorna 1 si contiene solo espacio o letras y numeros y 0 si no lo es

int esAlfaNumerico(char str[])
{
	int i=0;
	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] > 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
		return 0;
		i++;
	}
	return 1;
}

//Verifico si el valor recibido contiene solo numeros, + y -. El parametro es el array con la cadena a ser analizada.
//Retorna 1 si contiene solo numeros, espacios y un guion.

int esTelefono(char str[])
{
	int i=0;
	int contadorGuiones = 0;
	while(str[i] != '\0')
		{
			if((str[i] != ' ') && (str[i] < '0' || str[i] > '9'))
			return 0;
			if(str[i] == '-')
			contadorGuiones++;
			i++;
		}
	if(contadorGuiones == 1)
		return 1;
	return 0;
}


//Get string: Solicita un texto al usuario y lo devuelve. El parametro mensaje es el mensaje a ser mostrado, el input
//Array donde se cargará el texto ingresado, retorna un void

void getString(char mensaje[], char input[])
{
printf(mensaje);
scanf("%s", input);
}

//Get string letras: VALIDA SI LO QUE INGRESO EL USUARIO SON SOLO LETRAS
//Solicita un texto al usuario y lo devuelve. El parametro mensaje es el mensaje a ser mostrado, el input
//Array donde se cargará el texto ingresado, retorna 1 si el texto contiene solo letras

int getStringLetras(char mensaje[], char input[])
{
	char aux[256];
	getString(mensaje, aux);
	if(esSoloLetras(aux))
	{
		strcpy(input, aux);
		return 1;
	}
	return 0;
}


//Get string numeros: VALIDA SI LO QUE INGRESO EL USUARIO SON SOLO NUMEROS

int getStringNumeros(char mensaje[], char input[])
{
	char aux[256];
	getString(mensaje, aux);
	if(esNumerico(aux))
	{
		strcpy(input, aux);
		return 1;
	}
	return 0;
}


