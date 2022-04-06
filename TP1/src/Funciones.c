#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include <stdio_ext.h>

int ingresarKm(void)
{
	int kmDevuelto;
	printf("\nIngrese la cantida de KM: ");
	scanf("%d",&kmDevuelto);
	while(kmDevuelto<0)
	{
		printf("\nIngrese la cantida de KM mayor a 0 : ");
		scanf("%d",&kmDevuelto);
	}

	return kmDevuelto;
}

float ingresarPrecio(void)
{
	float precio;

	printf("\nIngrese un precio: ");
	scanf("%f",&precio);
	while(precio<0)
	{
		printf("\nIngrese un precio mayor a 0 : ");
		scanf("%f",&precio);
	}

	return precio;
}

float solicitudOtraOpcion(char mensaje [])
{
	float precio;
	char opcion;
	__fpurge(stdin);
	printf("\n%s",mensaje);
	scanf("%c",&opcion);
	if(opcion=='s')
	{
	precio=ingresarPrecio();
	return precio;
	}
	return 0;
}

char validarCaracterDos(char caracter,char error [],char opcion1,char opcion2)
{
int caracterDevuelto;

while(caracter!=opcion1 && caracter!=opcion2)
{
	__fpurge(stdin);
	printf("\n%s",error);
	scanf("%c",&caracter);
}

caracterDevuelto=caracter;

return caracterDevuelto;

}

float precioTarjetaDebito(float precio,int descuento)
{
	float precioDevuelto,aux;
	aux=100-descuento;
	precioDevuelto=precio*aux/100;
	return precioDevuelto;
}

float precioTarjetaCredito(float precio,int interes)
{
	float precioDevuelto,aux;
	aux=100+interes;
	precioDevuelto=precio*aux/100;
	return precioDevuelto;
}

float precioBitcoin(float precio,float precioBitcoin)
{
	float precioDevuelto;

	precioDevuelto=precio/precioBitcoin;
	return precioDevuelto;
}

float precioUnitario(float precio,int km)
{
	float precioDevuelto;

	precioDevuelto=precio/km;
	return precioDevuelto;
}
float precioDiferencia(float precio1,float precio2)
{
	float diferencia;

	if(precio2>precio1)
	{
		diferencia=precio2-precio1;
		return diferencia;
	}
	diferencia=precio1-precio2;
	return diferencia;
}

void mostrarResultados(float precioDebito,float precioCredito,float precioBitcoin,float precioUnitario,char nombre [])
{
	printf("\n%s:\n\n"
			"a)Precio con tarjeta de debito: $ %.2f\n"
			"b)Precio con tarjeta de credito: $ %.2f\n"
			"c)Precio pagando con bitcoin: %.2f BTC\n"
			"d)Mostrar precio unitario: $ %.2f\n",nombre,precioDebito,precioCredito,precioBitcoin,precioUnitario);
}

void mostrarDiferencia(float precioDiferencia)
{
	printf("\ne)La diferencia de precio es: $ %.2f\n",precioDiferencia);
}
