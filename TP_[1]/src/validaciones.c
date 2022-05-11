/*
 * validaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Alejandro Javier Garcia Bouzada
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

/// valido si el numero entero es el esperado
/// @param pResultado puntero donde aloja el valor si es varificado
/// @param mensaje muestra un string
/// @param mensajeError mustra un string en caso de ingresar un valor no esperado
/// @param minimo minimo valor esperado inclusive
/// @param maximo maximo valor esperado inclusive
/// @param reintentos valor de cantidad de veces maxima que se ejecuta el ciclo
/// @return 0 si el valor es verificado o -1 si se acaban los intentos
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

/// valido si el numero flotante es el esperado
/// @param pResultado puntero donde aloja el valor si es varificado
/// @param mensaje muestra un string
/// @param mensajeError mustra un string en caso de ingresar un valor no esperado
/// @param minimo minimo valor esperado inclusive
/// @param maximo maximo valor esperado inclusive
/// @param reintentos valor de cantidad de veces maxima que se ejecuta el ciclo
/// @return 0 si el valor es verificado o -1 si se acaban los intentos
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


/// Verifica si un char es el esperada
/// @return devulevle 1 para S y 0 para N
unsigned int verificarLetra(void){
	char letra;
	printf("\nEst%c seguro que desea salir(S/N): ?",160);
	scanf("%c",&letra);
	letra = toupper(letra); //debo pasar la letra a mayúscula para la comprobación
	//se repite el ciclo mientras no se ingrese la letra a verificar
	while(!((letra=='S')||(letra=='N'))){
		printf("\nHa ingresado opci%cn no v%clida. Ingrese S para salir o N para volver al menu: ",162,160);
		fflush(stdin);
		scanf("%c",&letra);
		letra = toupper(letra);
	}
	return (letra=='S'); //si la letra es S devuelce 1, si es N devuelve 0
}

