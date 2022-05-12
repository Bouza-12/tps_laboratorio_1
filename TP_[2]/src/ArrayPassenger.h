/*
 * ArrayPassenger.h
 *
 *  Created on: 5 may. 2022
 *      Author: bouza
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menus.h"
#include "validaciones.h"

#define EMPTY 0
#define OCCUPED 1
#define DOWN -1

#define ACTIVO 1
#define DEMORADO 2
#define CANCELADO 3

//esctructuras
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

typedef struct
{
	char flycode[10];
	int statusFlight;
}eStatusFlight;



// FUNCIONES DECLARACION
/** \brief To indicate that all position in the array are empty,-
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initPassengers(Passenger list[], int len);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);
int printPassenger(Passenger* list, int length);
int sortPassengers(Passenger* list, int len, int order);

int showActiveFlights(Passenger* list, int len);

void modifyPassenger(Passenger list[], int len, int);

float pricePromedio(Passenger list[],int len);
void showAboveProm(Passenger list[],int len, float promedio);

#endif /* ARRAYPASSENGER_H_ */
