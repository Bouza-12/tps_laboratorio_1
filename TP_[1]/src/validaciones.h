/*
 * validaciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Alejandro Javier Garcia Bouzada
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int validarEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo, int reintentos); // valida que el numero ingresado sea entero y esté dentro del rango solicitado
int validarNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo, int reintentos);
unsigned int verificarLetra(void);

#endif /* VALIDACIONES_H_ */
