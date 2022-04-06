/*
 * funciones.c
 *
 *  Created on: 6 abr. 2022
 *      Author: bouza
 */


// funciones

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
float calcularPrecioDebito(float precioVuelo, int descuento){
	float resultado, porcentajeDescuento, precioDescontado;
	porcentajeDescuento = (float) descuento/100;
	precioDescontado = precioVuelo * porcentajeDescuento;
	resultado= precioVuelo-precioDescontado;
	return resultado;
}

float calcularPrecioCredito(float precioVuelo, int interes){
	float resultado, porcentajeInteres, precioInteres;
	porcentajeInteres = (float) interes/100;
	precioInteres = precioVuelo * porcentajeInteres;
	resultado= precioVuelo+precioInteres;
	return resultado;
}

float calcularPrecioPorKilometro(float precioVuelo, int kilometros){
	float resultado;
	resultado = precioVuelo / (float) kilometros;
	return resultado;
}

float calcularPrecioBitcoin(float precioVuelo){
	const float btc = 4606954.55;
	float resultado;
	resultado = precioVuelo / btc;
	return resultado;
}

void mostrarDiferencia(float precioAerolineas,float precioLatam){
	float diferencia;
	if (precioAerolineas > precioLatam){
		diferencia = restaDosFloat(precioAerolineas, precioLatam);
		printf("La diferencia de precio es: $ %2.f",diferencia);
	}
	else{
		if(precioAerolineas < precioLatam){
			diferencia = restaDosFloat(precioLatam, precioAerolineas);
			printf("La diferencia de precio es: $ %2.f",diferencia);
		}
		else{
			printf("No hay diferencia de precio.");
		}
	}
}

float restaDosFloat(float num1, float num2){
	float res;
	res = num1 - num2 ;
	return res;
}

int validarEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo, int reintentos){
	int retorno =-1;
	int bufferInt;
	if(minimo<=maximo && reintentos >=0){  //comprobación de parametros ingresados
		printf("%s",mensaje);
		scanf("%d",&bufferInt);
		fflush(stdin);
		do{
			if(bufferInt>=minimo && bufferInt<=maximo){
				*pResultado = bufferInt;
				retorno =0;
				reintentos = -1;
			}
			else{
				printf("%s",mensajeError);
				scanf("%d",&bufferInt);
				fflush(stdin);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int validarNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo, int reintentos){
	int retorno =-1;
	float bufferFloat;
	if(minimo<=maximo && reintentos >=0){
		printf("%s",mensaje);
		scanf("%f",&bufferFloat);
		fflush(stdin);
		do{
			if(bufferFloat>=minimo && bufferFloat<=maximo){
				*pResultado = bufferFloat;
				retorno =0;
				reintentos = -1;
			}
			else{
				printf("%s",mensajeError);
				scanf("%f",&bufferFloat);
				fflush(stdin);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

unsigned int verificarLetra(void){
	char letra;
	printf("\nEst%c seguro que desea salir(S/N): ?",160);
	scanf("%c",&letra);
	letra = toupper(letra);
	while(!((letra=='S')||(letra=='N'))){
		printf("\nHa ingresado opci%cn no v%clida. Ingrese S para salir o N para volver al menu: ",162,160);
		fflush(stdin);
		scanf("%c",&letra);
		letra = toupper(letra);
	}
	return (letra=='S'); //si la letra es S devuelce 1, si es N devuelve 0
}
