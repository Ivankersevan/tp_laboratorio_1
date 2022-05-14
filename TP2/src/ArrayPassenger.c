#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

int initPassengers( Passenger lista[], int size)
{
	int i;
	int estado;

	estado = -1;
	if(size == LIMITE)
	{
		estado=0;
		for(i=0;i<size; i++)
		{
			lista[i].isEmpty = Empty;
		}
	}
	return estado;
}

int addPassengers(Passenger lista[], int size, int id, char name[],char lastname[],float price,int typePassenger, char flycode [],int statusflight)
{

	int retorno= -1;
	int indice;
	if(lista != NULL && size > 0)
	{
		indice=buscarlibre(lista,size);
		if(indice != -1)
		{

			lista[indice].id = id;
			strcpy(lista[indice].name,name);
			strcpy(lista[indice].lastname,lastname);
			lista[indice].price = price;
			strcpy(lista[indice].flycode,flycode);
			lista[indice].typePassenger = typePassenger;
			lista[indice].statusflight = statusflight;
			lista[indice].isEmpty = Full;
			retorno = 0;

		}
	}

	return retorno;
}

int findPassengersById( Passenger lista[], int size ,int id)
{
	int respuesta=0;

	for(int i = 0;i<size;i++)
	{
		if(lista[i].id == id)
		{
			respuesta=id;
			break;
		}
	}
	return respuesta;
}

int removePassenger( Passenger lista[], int size ,int id)
{
	int respuesta=0;
	for(int i = 0;i<size;i++)
		{
			if(lista[i].id == id)
			{
				lista[i].isEmpty = Empty;
				respuesta=1;
				break;
			}
		}
	return respuesta;
}

int printPassengers(Passenger lista[], int size)
{
	int respuesta = 0;
	printf("\nID:    NOMBRE:     APELLIDO:      PRECIO:      CODIGO:      TIPO:     ESTADO:\n");
	for(int i=0;i<size;i++)
	{
		if(lista[i].isEmpty == Full && lista != NULL)
		{
			mostrar(&lista[i]);
		}
	}
    respuesta = 1;
	return respuesta;
}

int sortPassenger(Passenger lista[],int size,int order)
{
	order= ordenarApellido(lista,size);
		return 0;
}


int sortPassengersByCode( Passenger lista[], int size ,int order)
{
	order=ordenarCodigo(lista,size);
	return 0;
}
