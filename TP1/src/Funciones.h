#include <stdio.h>
#include <stdlib.h>

//MENU 1
int ingresarKm(void);
//MENU 2
float ingresarPrecio(void);
char validarCaracterDos(char caracter,char error [],char opcion1,char opcion2);
float solicitudOtraOpcion(char mensaje []);
//MENU 3
float precioTarjetaDebito(float precio,int descuento);
float precioTarjetaCredito(float precio,int interes);
float precioBitcoin(float precio,float precioBitcoin);
float precioUnitario(float precio,int km);
float precioDiferencia(float precio1,float precio2);
//MENU 4 Y 5
void mostrarResultados(float precioDebito,float precioCredito,float precioBitcoin,float precioUnitario,char nombre []);
void mostrarDiferencia(float precioDiferencia);

