#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define LIMITE 2000
#define TAMHARD 5
#define Empty 0
#define Full 1




typedef struct{
		int id;
		char name [51];
		char lastname[51];
		float price;
		char flycode[10];
		int typePassenger;
		int statusflight;
		int isEmpty;
	}Passenger;

/// @param lista
/// @param size
/// @return
int initPassengers( Passenger lista[], int size);
/// @param lista
/// @param size
/// @param id
/// @param name
/// @param lastname
/// @param price
/// @param typePassenger
/// @param flycode
/// @param statusflight
/// @return
int addPassengers( Passenger lista[], int size, int id, char name[],char lastname[],float price,int typePassenger, char flycode [],int statusflight);
/// @param lista
/// @param size
/// @param id
/// @return
int findPassengersById( Passenger lista[], int size ,int id);
/// @param lista
/// @param size
/// @param id
/// @return
int removePassenger( Passenger lista[], int size ,int id);
/// @param lista
/// @param size
/// @param order
/// @return
int sortPassengers( Passenger lista[], int size ,int order);
/// @param lista
/// @param size
/// @return
int printPassengers( Passenger lista[], int size);
/// @param lista
/// @param size
/// @param order
/// @return
int sortPassengerByCode( Passenger lista[], int size ,int order);



/// @param lista
/// @param size
/// @return
int hardcodeo(Passenger lista[],int size);
/// @param cadena
/// @param mensaje
/// @param mensajeError
/// @param max
/// @return
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);
/// @param flotante
/// @param mensaje
/// @param mensajeError
/// @param min
/// @param max
/// @return
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
/// @param lista
/// @param size
/// @return
int ordenarApellido(Passenger lista[],int size);
/// @param lista
/// @param size
/// @return
int ordenarCodigo(Passenger lista[],int size);
/// @param lista
/// @param size
/// @return
int totalPrecio(Passenger lista[],int size);
/// @param lista
/// @param size
/// @return
int promedioPrecios(Passenger lista[],int size);
/// @param lista
/// @param size
/// @return
int cantPasajeros(Passenger lista[],int size);
/// @param lista
/// @param size
/// @return
int ingresarPasajero(Passenger lista[], int size);
/// @param lista
/// @param size
/// @return
int buscarlibre(Passenger lista[], int size);
/// @param lista
/// @param size
/// @return
int modificarPasajeroE(Passenger lista[], int size);
/// @param entero
/// @param mensaje
/// @param mensajeError
/// @param min
/// @param max
/// @return
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
/// @param lista
/// @param size
/// @return
int eliminarPasajero(Passenger lista[], int size);
/// @param pasajero
void mostrar(Passenger* pasajero);
/// @param list
/// @param len
/// @param id
void modificarPasajero( Passenger list[], int len ,int id);ero( Passenger lista[], int size ,int id);

