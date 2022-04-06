/*
 ============================================================================
 Name        : TP1.c
 Author      : Ivan Kersevan
 Version     : 1.0
 Description : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
			   para ofrecerlos a sus clientes.
			   Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
			   El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Funciones.h"

#define BITCOIN 4606954.55

int main(void) {
	setbuf(stdout,NULL);

	//Variables
	int opcion,salir,km,diferencia,aux,habilitar = 0;
	float precioLatam = 0,precioAerolineas = 0;
	char opcionAerolinea;
	float precioAerolineasDebito,precioAerolineasCredito,precioAerolineasBitcoin,precioAerolineasUnitario;
	float precioLatamDebito,precioLatamCredito,precioLatamBitcoin,precioLatamUnitario;

	km=0;
	salir=1;
	//Aca empieza el menu *******************************
	while(salir==1)
	{
		printf("\n\n"
			   "1-Ingresar Kilómetros: %d Km\n"
			   "2-Ingresar Precio de Vuelos: (Latam = $%.2f; Aerolineas = $%.2f)\n"
			   "3-Calcular todos los costos: \n"
			   "4-Informar Resultados \n"
			   "5-Carga forzada de datos \n"
			   "6-Salir \n",km,precioLatam,precioAerolineas);

		printf("\nIngrese una opcion: ");
		__fpurge(stdin);
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				km = ingresarKm();
				break;
			case 2:
				__fpurge(stdin);
				printf("\nA que aerolinea quiere ingresar precio? (Latam 'l' o Aerolineas 'a'): ");
				scanf("%c",&opcionAerolinea);
				opcionAerolinea=validarCaracterDos(opcionAerolinea,"ERROR, Ingrese Latam 'l' o Aerolineas 'a': ",'l','a');
				if(opcionAerolinea=='l')
				{
					precioLatam=ingresarPrecio();
					aux=solicitudOtraOpcion("Quiere ingresar el precio de Aerolineas?, ponga 's' para si: ");
					if(aux!=0)
					{
						precioAerolineas=aux;
					}
				}
				else
				{
					precioAerolineas=ingresarPrecio();
					aux=solicitudOtraOpcion("Quiere ingresar el precio de Latam?, ponga 's' para si: ");
					if(aux!=0)
					{
						precioLatam=aux;
					}
				}
				break;
			case 3:
				if(precioAerolineas>0 || precioLatam>0)
				{
				precioAerolineasDebito=precioTarjetaDebito(precioAerolineas, 10);
				precioAerolineasCredito=precioTarjetaCredito(precioAerolineas, 25);
				precioAerolineasBitcoin=precioBitcoin(precioAerolineas, BITCOIN);
				precioAerolineasUnitario=precioUnitario(precioAerolineas, km);

				precioLatamDebito=precioTarjetaDebito(precioLatam, 10);
				precioLatamCredito=precioTarjetaCredito(precioLatam, 25);
				precioLatamBitcoin=precioBitcoin(precioLatam, BITCOIN);
				precioLatamUnitario=precioUnitario(precioLatam, km);

				diferencia=precioDiferencia(precioAerolineas, precioLatam);

				habilitar=1;
				}
				else
				{
					printf("\n\n\nPrimero debe ingresar un precio y Km!!!");
				}
				break;
			case 4:
				if(habilitar==1)
				{
				printf("\nKMs Ingresados: %d km\n",km);
				mostrarResultados(precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, "Aerolineas");
				mostrarResultados(precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, "Latam");
				mostrarDiferencia(diferencia);
				salir=0;
				}
				else
				{
					printf("\n\n\nPrimero debe ingresar un precio y Km!!!");
				}
				break;
			case 5:
				printf("\n\n**************"
						"\n"
						"Carga Forzada de datos:"
						"\n\n"
						"KMs Ingresados: %d km\n",km);
				mostrarResultados(precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, "Aerolineas");
				mostrarResultados(precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, "Latam");
				mostrarDiferencia(diferencia);
				salir=0;
				break;
			case 6:
				salir=0;
				break;
			default:
				while(opcion>6 || opcion<1)
				{
				printf("\nERROR, Seleccione una opcion valida: ");
				__fpurge(stdin);
				scanf("%d",&opcion);
				}
				break;
		}
		if(opcion==6)
			{
				salir=0;
			}
	}
	printf("\nFin del programa");//Mensaje de salida

	return 0;
}
