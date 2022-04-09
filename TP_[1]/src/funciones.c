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

/*Se usa para calcular el precio con descuento al consultar el pago con debito
* param precioVUelo variable del precio original
* param descuento variable entera de un porcentaje a aplicar (ex. 10 para 10% / 20 para 20%)
*/
float calcularPrecioDebito(float precioVuelo, int descuento)
{
	float resultado, porcentajeDescuento, precioDescontado;
	porcentajeDescuento = (float) descuento/100;
	precioDescontado = precioVuelo * porcentajeDescuento;
	resultado= precioVuelo-precioDescontado;
	return resultado;
}
/* Devuelve el precio del pasaje con el interes al consultar por pagos con tarjeta de credito.
 * param precioVUelo varable con el precio origianl
 * param interes. varaible entera de porcentaje a aplicar (ex. 10 para 10% / 20 para 20%)
 */
float calcularPrecioCredito(float precioVuelo, int interes){
	float resultado, porcentajeInteres, precioInteres;
	porcentajeInteres = (float) interes/100;
	precioInteres = precioVuelo * porcentajeInteres;
	resultado= precioVuelo+precioInteres;
	return resultado;
}
/* Devuelvo el precio por cada kilometro
 * param precioVuelo varable con el precio origianl
 * param kilometros. variable numerica de la distancia total
 */
float calcularPrecioPorKilometro(float precioVuelo, int kilometros){
	float resultado;
	resultado = precioVuelo / (float) kilometros;
	return resultado;
}
/*cuanta para averiguar el valor del pasaje en bitcoin
 * param precioVuelo varable con el precio origianl
 */

float calcularPrecioBitcoin(float precioVuelo){
	const float btc = 4765858.73;
	float resultado;
	resultado = precioVuelo / btc;
	return resultado;
}
/*muestra la resta de los pasajes y diferencia cual es el mayor para evitar numeros negativos y si no hay doferencia entre estos
 * param precioAerolineas. float indicando un precio a comparar
 * param precio Latam. float indicando otro precio a comparar
 */
void mostrarDiferencia(float precioAerolineas,float precioLatam){
	float diferencia;
	if (precioAerolineas > precioLatam){
		diferencia = restaDosFloat(precioAerolineas, precioLatam);
		printf("La diferencia de precio es: $ %2.f\n",diferencia);
	}
	else{
		if(precioAerolineas < precioLatam){
			diferencia = restaDosFloat(precioLatam, precioAerolineas);
			printf("La diferencia de precio es: $ %2.f\n",diferencia);
		}
		else{
			printf("No hay diferencia de precio.\n");
		}
	}
}
/* resta de 2 variables float que devuelve el resultado float
 * param num 1 numero float
 * param num2 otro numero float
 */

float restaDosFloat(float num1, float num2){
	float res;
	res = num1 - num2 ;
	return res;
}

/*valido, pido el ingreso de un numero
 * param pResultado. puntero donde aloja el valor si es varificado
 * param mensaje. muestra un string
 * param mensajeError. mustra un string en caso de ingresar un valor no esperado
 * param minimo. minimo valor esperado inclusive
 * param maximo. maximo valor esperado inclusive
 * param reintentos. valor de cantidad de veces maxima que se ejecuta el ciclo
 */
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

/*valido, pido el ingreso de un numero
 * param pResultado. puntero donde aloja el valor si es varificado
 * param mensaje. muestra un string
 * param mensajeError. mustra un string en caso de ingresar un valor no esperado
 * param minimo. minimo valor esperado inclusive
 * param maximo. maximo valor esperado inclusive
 * param reintentos. valor de cantidad de veces maxima que se ejecuta el ciclo
 */
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

/* Verifica si la letra ingresada es valida entre 2 esperadas
 *  devuelve 1 si es verdadero 'S' u 0 si es falso 'N'
 */
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
