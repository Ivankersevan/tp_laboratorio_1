#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include <stdio_ext.h>




int ingresarPasajero(Passenger lista[], int size)
{

	int error;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int typePassenger;
	char flycode[10];
	int statusflight;

	id=buscarlibre(lista,size);
	id++;
	pedirCadena(nombre,"\nIngrese su nombre: ","\nNo se a ingresado un nombre valido,reingrese su nombre nuevamente: ",50);
	pedirCadena(apellido,"\nIngrese su apellido: ","\nNo se a ingresado un apellido valido,reingrese su apellido nuevamente: ",50);
	pedirFlotante(&precio,"\nIngrese el precio: ","\nNo se a ingresado un numero valido nuevamente: ",1,100000000000000);
	pedirEntero(&typePassenger,"\nIngrese el tipo de pasajero ( 1) First Class,2) clase Economica,3) clase Ejecutiva)","\nNo se a ingresado un numero valido: ",1,3);
	pedirCadena(flycode,"\nIngrese el codigo de vuelo: ","\nNo se a ingresado un codigo de vuelo valido, reingrese su codigo: ",10);
	pedirEntero(&statusflight,"\nIngrese el estado de vuelo: ( 1) a tiempo,2) retrasado,3) sin actividad)","\nNo se a ingresado un numero valido, intente nuevamente: ",1,3);

	error=addPassengers(lista,size,id,nombre,apellido,precio,typePassenger,flycode,statusflight);



		if(error == -1)
		{
			printf("\nOcurrio un error en la carga");
		}
		else
		{
			printf("\nCarga exitosa!!!");
		}




return error;
}

int buscarlibre(Passenger lista[], int size)
{


	int i;
	int index;

	index = -1;



	for(i=0;i<size; i++)
	{
		if(lista[i].isEmpty == Empty)
		{
			index=i;
			break;
		}
	}
	return index;
}

int modificarPasajeroE(Passenger lista[], int size)
{
	int respuesta;
	int id;

	pedirEntero(&id,"\nIngrese el id del pasajero a modificar: ","\nNo se a ingresado un numero valido",1,2000);

	respuesta = findPassengersById(lista,size,id);

	if(respuesta != 0)
	{
		modificarPasajero(lista,size,respuesta);
	}

return respuesta;
}

void modificarPasajero( Passenger lista[], int size ,int id)
{
	Passenger pasajero;
	int opcion;
	char name [51];
	char lastname[51];
	float precio;
	int typePassenger;
	char flycode[10];

	do
	{
		printf("\nQue desea modificar?");
		printf("1) Nombre");
		printf("2) Apellido");
		printf("3) Precio");
		printf("4) Tipo de pasajero");
		printf("5) Codigo de vuelo");
		printf("6) Nada");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			pedirCadena(name,"\nIngrese su nombre: ","\nNo se a ingresado un nombre valido, intente nuevamente",50);
			strcpy(pasajero.name,name);
			break;

		case 2:
			pedirCadena(lastname,"\nIngrese su apellido: ","\nNo se a ingresado un apellido valido,intente nuevamente",50);
			strcpy(pasajero.lastname,lastname);
			break;

		case 3:
			pedirFlotante(&precio,"\nIngrese un precio: ","\nNo se a ingresado un numero valido,intente nuevamente",1,100000000000000);
			pasajero.price = precio;
			break;

		case 4:
			pedirEntero(&typePassenger,"\nIngrese el tipo de pasajero: ( 1) primera clase,2) clase ejecutiva,3) clase economica)","\nNo se a ingresado un numero valido,intente nuevamente",1,3);
			pasajero.typePassenger = typePassenger;
			break;

		case 5:
			pedirCadena(flycode,"\nIngrese el codigo de vuelo: ","\nNo se a ingresado un codigo de vuelo valido,intente nuevamente",10);
			strcpy(pasajero.flycode,flycode);
			break;

		case 6:
			printf("\nSaliendo de modificacion...");
			break;

		default:
			printf("\nIngrese una opcion valida");
			break;
		}
		lista[id]=pasajero;
	}while(opcion != 6);
}


int hardcodeo(Passenger lista[],int size)
{
	int retorno = -1;
	if(lista != NULL && size > 0)
	{
		Passenger aux [] =
		{
				{1021,"Ivan","Kersevan",10000,"LATAM6524",2,4,Full},
				{1022,"Diego","Maradona",12350,"AEROLI6542",1,3,Full},
				{1033,"Mariana","Fernandez",9500,"AEROLI6987",3,1,Full},
				{1034,"Ricardo","Fort",17000,"TAM4855",1,1,Full},
				{1055,"Mirta","Legrand",6400,"TAM9725",3,2,Full}
		};


		for(int i=0;i<size;i++)
		{
			lista[i]=aux[i];
		}
		retorno=0;
	}
	return retorno;
}
int ordenarApellido(Passenger lista[],int size)
{
	Passenger aux;
	int orden;



		int retorno = -1;
		pedirEntero(&orden,"\nIngrese el orden en que desee ordenar la lista: ( 1) Descendiente 2) Ascendente)","\nNo se a ingresado un numero valido,intente nuevamente",1,2);
		if(orden == 1)
		{

			if(lista != NULL && size>0)
			{
			for(int i = 0;i<size-1;i++)
			{
				for(int j = i + 1;j<size;j++)
				{
					if(stricmp(lista[i].lastname,lista[i+1].lastname) > 0)
					{
						aux=lista[i];
						lista[i] = lista[j];
						lista[j] = aux;
					}
				}
			}
			retorno=0;

		}
		else
		{
			if(lista != NULL && size>0)
			{
					for(int i = 0;i<size-1;i++)
					{
						for(int j = i + 1;j<size;j++)
						{
							if(stricmp(lista[i].lastname,lista[i+1].lastname) < 0)
							{
								aux=lista[i];
								lista[i] = lista[j];
								lista[j] = aux;
							}
						}
					}
			}

		retorno=0;
		}

		}
			return retorno;

}

int eliminarPasajero(Passenger lista[], int size)
{
	int respuesta;
	int id;

	pedirEntero(&id,"\nIngrese el id del pasajero a modificar: ","\nNo se a ingresado un numero valido,intente nuevamente",1,2000);


	respuesta = removePassenger(lista,size,id);


	return respuesta;
}

void mostrar(Passenger* pasajero)
{



	if(pasajero->isEmpty == Full)
	{
		printf("\n %d %8s %8s $%8.2f %8s %8d %8d \n",pasajero->id,pasajero->name,pasajero->lastname,pasajero->price,pasajero->flycode,pasajero->typePassenger,pasajero->statusflight);
	}


}

int ordenarCodigo(Passenger lista[],int size)
{


	Passenger aux;
	int orden;
			int retorno = -1;

			pedirEntero(&orden,"\nIngrese el orden en que desee ordenar la lista: ( 1) Descendiente 2) Ascendente)","\nNo se a ingresado un numero valido,ingrese nuevamente",1,2);
			if(orden == 1)
			{

				if(lista != NULL && size>0)
				{
					for(int i = 0;i<size-1;i++)
						{
							for(int j = i + 1;j<size;j++)
							{
								if(stricmp(lista[i].flycode,lista[i+1].flycode) > 0)
								{
									if(lista[i].statusflight == Full)
									{
										aux=lista[i];
										lista[i] = lista[j];
										lista[j] = aux;
									}
								}
							}
						 }

					retorno=0;
				}
			}
			if(orden == 2)
			{
				if(lista != NULL && size>0)
				{
					for(int i = 0;i<size-1;i++)
						{
							for(int j = i + 1;j<size;j++)
							{
								if(stricmp(lista[i].flycode,lista[i+1].flycode) < 0)
								{
									if(lista[i].statusflight == Full)
									{
										aux=lista[i];
										lista[i] = lista[j];
										lista[j] = aux;
									}
								}
							}
						}


					retorno=0;
				}
			}




		return retorno;

}

int totalPrecio(Passenger lista[],int size)
{
	float suma=0;

	for(int i = 0;i<size;i++)
	{
		if(lista[i].isEmpty == Full)
		{
			suma+=lista[i].price;
		}
	}
	return suma;
}



int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
    int retorno = -1;
    char buffer[256];
    int tam;



    if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", buffer);
        tam = strlen(buffer);

        while(tam > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%[^\n]", buffer);
            tam = strlen(buffer);
        }

        strcpy(cadena, buffer);
        retorno = 0;
    }


    return retorno;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{

    int retorno = -1;
    float numeroIngresado;


    if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%f", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", &numeroIngresado);
        }

        *flotante = numeroIngresado;
        retorno = 0;
    }


    return retorno;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{

    int retorno = -1;
    int numeroIngresado;

    if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {

        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *entero = numeroIngresado;
        retorno = 0;
    }


    return retorno;
}

int promedioPrecios(Passenger lista[],int size)
{
	int contador = 0;
	float promedio;
	float total;
	for(int i=0;i<size;i++)
	{
		if(lista[i].isEmpty == Full)
		{
			contador++;
		}
	}
	total=totalPrecio(lista,size);

	promedio=total/contador;

	return promedio;
}


int cantPasajeros(Passenger lista[],int size)
{
	float promedio;
	int contador=0;
	promedio=promedioPrecios(lista,size);
	for(int i=0;i<size;i++)
	{
		if(lista[i].isEmpty == Full)
		{
			if(lista[i].price > promedio)
			{
				contador++;
			}
		}
	}
	return contador;
}

