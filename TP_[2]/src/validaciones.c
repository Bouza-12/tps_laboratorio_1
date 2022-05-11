/*
 * validaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Alejandro Javier Garcia Bouzada
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// valido si el numero entero es el esperado
/// @param pResultado puntero donde aloja el valor si es varificado
/// @param mensaje muestra un string
/// @param mensajeError mustra un string en caso de ingresar un valor no esperado
/// @param minimo minimo valor esperado inclusive
/// @param maximo maximo valor esperado inclusive
/// @return 0 si el valor es verificado o -1 si se acaban los intentos
int validarEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo){
	int retorno =-1;
	int bufferInt;
	if(minimo<=maximo){  //comprobación de parametros ingresados
		printf("%s",mensaje);
		scanf("%d",&bufferInt);
		fflush(stdin);
		do{
			if(bufferInt>=minimo && bufferInt<=maximo){
				*pResultado = bufferInt;
				retorno =0;
			}
			else{
				printf("%s",mensajeError);
				scanf("%d",&bufferInt);
				fflush(stdin);
			}
		}while(retorno!=0);
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

/// @param pResultado puntero de donde guardar la letra ingresada
/// @param mensaje para que el usuario sepa que debe ingresar
/// @param mensajeError si ingreso algo que no debia muestra este mensaje explicando mejor
/// @param minimo letra minima a ingresar
/// @param maximo letra maxima a ingresar
/// @return devuelve 0 si se ingreso un caracter esperado
int validarRangoChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
	int retorno =-1;
	char bufferChar;
	if(minimo<=maximo){  //comprobación de parametros ingresados
		printf("%s",mensaje);
		scanf("%c",&bufferChar);
		fflush(stdin);
		bufferChar = toupper(bufferChar);
		do{
			if(bufferChar>=minimo && bufferChar<=maximo){
				*pResultado = bufferChar;
				retorno =0;
			}
			else{
				printf("%s",mensajeError);
				scanf("%c",&bufferChar);
				fflush(stdin);
			}
		}while(retorno!=0);
	}
	return retorno;
}

/// Verifica si un char es el esperada
/// @return devulevle 1 para S y 0 para N
unsigned int verificarSalida(char* mensaje, char* mensajeError)
{
	char letra;
	printf(mensaje);
	scanf("%c",&letra);
	fflush(stdin);
	letra = toupper(letra); //debo pasar la letra a mayúscula para la comprobación
	//se repite el ciclo mientras no se ingrese la letra a verificar
	while(!((letra=='S')||(letra=='N'))){
		printf(mensajeError);
		scanf("%c",&letra);
		fflush(stdin);
		letra = toupper(letra);
	}
	return (letra=='S'); //si la letra es S devuelce 1, si es N devuelve 0
}

/// @param vector vector con numeros flotantes a ordenar
/// @param len largo del vector
/// @return devuelve 0 si fue posible ordenarlo o -1 si no fue posible
int OrdenarNumerosFloatAscendente(float vector[],int len)
{
	int retorno=1;
	float auxInt;
	if(vector!=NULL){
		for(int i=0;i<len-1;i++){//1
			for(int j=i+1;j<len;j++){//2
				if(vector[i]>vector[j]){//3
					auxInt=vector[i];//4
					vector[i]=vector[j];
					vector[j]=auxInt;//5
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

/// @param vector vector con numeros enteros a ordenar
/// @param len len largo del vector
/// @return devuelve 0 si fue posible ordenarlo o -1 si no fue posible
int OrdenarNumerosAscendente(int vector[],int len)
{
	int retorno=1;
	int auxInt;
	if(vector!=NULL){
		for(int i=0;i<len-1;i++){//1
			for(int j=i+1;j<len;j++){//2
				if(vector[i]>vector[j]){//3
					auxInt=vector[i];//4
					vector[i]=vector[j];
					vector[j]=auxInt;//5
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

/// brief orden los un vector con string
/// @param vector vector con numeros enteros a ordenar
/// @param len largo del vector
/// @return devuelve 0 si fue posible ordenarlo o -1 si no fue posible
int OrdenarNumerosCharAscendente(char vector[],int len)
{
	int retorno=1;
	char auxInt;
	if(vector!=NULL){
		for(int i=0;i<len-1;i++){//1
			for(int j=i+1;j<len;j++){//2
				if(vector[i]>vector[j]){//3
					auxInt=vector[i];//4
					vector[i]=vector[j];
					vector[j]=auxInt;//5
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

/// @param vector con numeros enteros a ordenar
/// @param len largo del vector
/// @return devuelve 0 si fue posible ordenarlo o -1 si no fue posible
int OrdenarNumerosDescendente(int vector[],int len)
{
	int retorno=1;
	int auxInt;
	if(vector!=NULL){
		for(int i=0;i<len-1;i++){//1
			for(int j=i+1;j<len;j++){//2
				if(vector[i]<vector[j]){//3
					auxInt=vector[i];//4
					vector[i]=vector[j];
					vector[j]=auxInt;//5
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

/// @param vector con numeros enteros a ordenar
/// @param len largo del vector
/// @return devuelve 0 si fue posible ordenarlo o -1 si no fue posible
int OrdenarNumerosFloatDescendente(float vector[],int len)
{
	int retorno=1;
	float auxInt;
	if(vector!=NULL){
		for(int i=0;i<len-1;i++){//1
			for(int j=i+1;j<len;j++){//2
				if(vector[i]<vector[j]){//3
					auxInt=vector[i];//4
					vector[i]=vector[j];
					vector[j]=auxInt;//5
					retorno=0;
				}
			}
		}
	}
	return retorno;
}
