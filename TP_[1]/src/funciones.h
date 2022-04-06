/*
 * funcones.h
 *
 *  Created on: 6 abr. 2022
 *      Author: bouza
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>


int validarEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo, int reintentos); // valida que el numero ingresado sea entero y esté dentro del rango solicitado
int validarNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo, int reintentos);
unsigned int verificarLetra(void);

float restaDosFloat(float num1, float num2);

float calcularPrecioCredito(float precioVuelo, int interes);// calcula y muestra el precio con interes
float calcularPrecioBitcoin(float precioVuelo);
float calcularPrecioPorKilometro(float precioVuelo, int kilometros);
float calcularPrecioDebito(float precioVuelo, int descuento);//calcula y muestra el descuento con débito
void mostrarDiferencia(float precioAerolineas,float precioLatam);


#endif /* FUNCIONES_H_ */
