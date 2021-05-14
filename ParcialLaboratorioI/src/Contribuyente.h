/*
 * Contribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: Jorge
 */
typedef struct{
	int idContribuyente; //Comienza en 1000
	int idRecaudacion;
	int cuilContribuyente;
	char nombre[20];
	char apellido[20];
	int isEmpty;
}Contribuyente;

typedef struct{
	int idRecaudacion;
	char mes[20];
	int tipo;
	int importe;
	int isEmpty;
}Recaudacion;

int inicializarContribuyentes(Contribuyente array[], int len);
int buscarLibre(Contribuyente array[], int len, int* posicion);
int contribuyente_alta(Contribuyente array[], int len, int* contadorID);
int contribuyente_modificar(Contribuyente list[], int len,int id);
int contribuyente_baja(Contribuyente array[], int len);
void contribuyente_imprimir(Contribuyente array[], int len);
int recaudacion_alta(Recaudacion array[], int len, int* contadorIDRecaudacion);
void recaudacion_imprimir(Recaudacion array[], int len);

