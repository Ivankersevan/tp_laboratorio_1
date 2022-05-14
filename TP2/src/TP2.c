/*
 ============================================================================
 Name        : TP2
 Author      : Ivan Kersevan
 Version     : 1.0
 Description : Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
				no puede tener más de 2000 pasajeros.

datos: passenger: int id
char name [51]
char lastname[51]
float price
char flycode[10]
int typePassenger
int statusflight
int is empty

El sistema deberá tener el siguiente menú de opcioneses:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. listaado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. listaado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
1-NOTA: Se deberá realizar el menú de opcioneses y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
Para la realización de este programa, se utilizará una biblioteca llamada “ArrayPassenger” que
facilitará el manejo de la listaa de pasajeros y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
int main(void)
{
	setbuf(stdout,NULL);



	Passenger lista[LIMITE];

	int opciones;
	int error;
	float total;
	float promedio;
	int decision;
	int cantidad;
	int bandera = 0;

	initPassengers(lista,LIMITE);


	do
	{
		printf("\nIngrese una opcion: ");
		printf("\n1) ALTAS");
		printf("\n2) MODIFICAR");
		printf("\n3) BAJA\n");
		printf("\n4) Informar Resultados:");
		printf("\n5) Alta Forzada:");
		printf("\n6) Salir\n");

		scanf("%d",&opciones);

		switch(opciones)
		{
		case 1:
			ingresarPasajero(lista,LIMITE);
			bandera = 1;
			break;
		case 2:
			if(bandera == 1)
			{
				error=modificarPasajeroE(lista,LIMITE);
				if(error == 0)
				{
					printf("\nNo se a encontro el id");
				}
				else
				{
					printf("\nModificacion exitosa");
				}
			}
			else
			{
				printf("\nNesecita ingresar primero un pasajero");
			}
			break;
		case 3:
			if(bandera == 1)
			{
				error=eliminarPasajero(lista,LIMITE);
				if(error == 0)
				{
					printf("\nNo se a encontrado el id ingresado");
				}
				else
				{
					printf("\nSe a eliminado con exito");
				}
			}
			else
			{
				printf("\nNesecita ingresar primero un pasajero");
		    }
			break;
		case 4:
			if(bandera == 1)
			{
				pedirEntero(&decision,"\nIngrese la lista que quiera"
						"\n1): Ordenar por apellido"
						"\n2): Lista de precios y promedios; Precios que superan el promedio"
						"\n3): Ordenar por codigo"
						,"\nNo se ingreso un numero valido",1,3);
				switch(decision)
				{
				case 1:
					ordenarApellido(lista,LIMITE);
					error=printPassengers(lista,LIMITE);
					break;
				case 2:
					printf("\nEl total de precios es: ");
					total=totalPrecio(lista,LIMITE);
					printf("%2.f",total);

					printf("\nEl promedio de precios es: ");
					promedio=promedioPrecios(lista,LIMITE);
					printf("%2.f",promedio);

					printf("\nLa cantidad de pasajeros que superan el precio promedio es: ");
					cantidad=cantPasajeros(lista,LIMITE);
					printf("%d",cantidad);

					break;
				case 3:
					ordenarCodigo(lista,LIMITE);
					error=printPassengers(lista,LIMITE);
					break;
				default:
					printf("\nIngrese una opcion valida");
					break;
				}
			}
			else
			{
				printf("\nNesecita ingresar primero un pasajero");
			}

			break;
		case 5:
			hardcodeo(lista,TAMHARD);
			printPassengers(lista,TAMHARD);
			printf("\nCarga forzada activada...");

			break;
		case 6:
			printf("\nSaliendo del programa...");
			break;
		default:
			printf("\nERROR, Elegi una opcion correcta");
			break;

		}
	}while(opciones!=6);


	return 0;
}
