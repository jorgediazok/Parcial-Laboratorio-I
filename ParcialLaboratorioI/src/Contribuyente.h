/*
 * Contribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: Jorge
 */
typedef struct{
	int idContribuyente; //Comienza en 1000
	int cuilContribuyente;
	char nombre[20];
	char apellido[20];
	int isEmpty;
}Contribuyente;

int inicializarContribuyentes(Contribuyente array[], int len);
int buscarLibre(Contribuyente array[], int len, int* posicion);
int contribuyente_alta(Contribuyente array[], int len, int* contadorID);
int contribuyente_modificar(Contribuyente list[], int len,int id);
int contribuyente_baja(Contribuyente array[], int len);
void contribuyente_imprimir(Contribuyente array[], int len);

