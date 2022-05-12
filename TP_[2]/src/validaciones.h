/*
 * validaciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Alejandro Javier Garcia Bouzada
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int validarEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);
int validarNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo, int reintentos);
int validarRangoChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);


unsigned int verificarSalida(char*, char*);

int OrdenarNumerosAscendente(int vector[],int len);
int OrdenarNumerosFloatAscendente(float vector[],int len);
int OrdenarNumerosDescendente(int vector[],int len);
int OrdenarNumerosFloatDescendente(float vector[],int len);
int OrdenarNumerosCharAscendente(char vector[],int len);

void cargarNombre(char vector[], int len, char *mensaje);

#endif /* VALIDACIONES_H_ */
