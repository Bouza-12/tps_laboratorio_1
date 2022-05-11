/*
 * ArrayPassenger.c
 *
 *  Created on: 5 may. 2022
 *      Author: bouza
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"




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


#define EMPTY 0
#define OCCUPED 1
#define DOWN -1

#define ACTIVO 1
#define DEMORADO 2
#define CANCELADO 3



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initPassengers(Passenger list[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		list[i].isEmpty=EMPTY;
	}
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int lenght of the list
* \param id int id for the new passenger
* \param name[] char name of the passenger
* \param lastName[] char last name of the passenger
* \param price float
* \param typePassenger int
* \param flycode[] char alphanumeric valid
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int addPassenger(Passenger* list, int len, int id, char* name,char* lastName,float price,int typePassenger, char* flycode)
{
	int i, retorno=-1;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty ==0)
		{
			list[i].id = id;
			strcpy(list[i].name,name);
			strcpy(list[i].lastName,lastName);
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].flyCode,flycode);
			list[i].isEmpty = OCCUPED;
			retorno =0;
			break;
		}
	}
	return retorno;
}

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno=-1;
	if(list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCCUPED && list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	if(list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCCUPED && list[i].id == id)
			{
				//se puede agregar el preguntas si esta seguro
				list[i].isEmpty = DOWN;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger list[], int length)
{
	if(list!=NULL)
		{
		printf("  ID         NOMBRE       APELLIDO    PRECIO    CODIGO  TIPO DE PASS");
			for(int i=0;i<length;i++)
			{
				if(list[i].isEmpty ==OCCUPED)
				{
					printf("%5d %15s %15s %.2f %12s %10d %4d\n",list[i].id
												 ,list[i].name
												 ,list[i].lastName
												 ,list[i].price
												 ,list[i].flyCode
												 ,list[i].typePassenger
												 ,list[i].statusFlight);
				}
			}
		}
return 0;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order)
{
	int retorno =-1;
	int i,j;
	Passenger listAux;

	printf("\n Orden Establecido: %d\n",order);

	if(list!= NULL && len>0)
	{
		retorno=0;
		if(order==1)
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName)>0) && (list[i].isEmpty==EMPTY && list[j].isEmpty == EMPTY))
					{
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].isEmpty==EMPTY && list[j].isEmpty == EMPTY))
						{
							if(list[i].typePassenger>list[j].typePassenger)
							{
								listAux = list[i];
								list[i]=list[j];
								list[j]=listAux;
							}
						}
					}
				}
			}
		}
		else
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName)<0) && (list[i].isEmpty==EMPTY && list[j].isEmpty == EMPTY))
					{
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].isEmpty==EMPTY && list[j].isEmpty == EMPTY))
						{
							if(list[i].typePassenger>list[j].typePassenger)
							{
								listAux = list[i];
								list[i]=list[j];
								list[j]=listAux;
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}

void modifyPassenger(Passenger list[], int len,)
{
	int modifValidada;
	int idModify;
	int optionModify;
	int validarChangePrice;
	int validarChangetTipo;
	float changePriceAux;

	modifValidada = validarEntero(&idModify, "\nIngrese el ID del pasajero a MODIFICAR: ", "\nError!!! Debe ingresar un ID valido: ", 1000, idstatico);
	if(modifValidada==0)
	{
		if(list!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty==OCCUPED && list[i].id==idModify)
				{
					optionModify = menuOptionInt("\n¿Que desea modificar?\n1. NOMBRE\n2. APELLIDO\n3. PRECIO\n4. TIPO DE PASAJERO\n5. CODIGO DE VUELO\nElija una opcion: ", 1, 5);
					switch(optionModify)
					{
						case 1:
							cargarNombre(list[i].name, 51, "Ingrese el NOMBRE del Pasajero");
							break;
						case 2:
							cargarNombre(list[i].lastName, 51, "Ingrese el APELLIDO del Pasajero");
							break;
						case 3:
							validarChangePrice = validarNumeroFlotante(&changePriceAux, "\nIngrese el nuevo PRECIO del pasaje: ", "\nError!!! debe ingresar un PRECIO  valido: ", 1, 9999999999, 5);
							if(validarChangePrice==0)
							{
								list[i].price = changePriceAux;
							}
							else
							{
								printf("No se pudo realizar el cambio de precio.");

							}
							break;
						case 4:

							break;
						case 5:
							printf("Ingrese el nuevo codigo de vuelo: ");
							scanf("%s", list[i].flyCode);
							break;
					}
					break;
				}
				break;
			}
		}

	}
	else
	{
		printf("No se reconoce el ID, no se puede moificar ningun dato.\n");
	}

}

int showActiveFlights(Passenger* list, int len)
{
	int retorno =-1;
	int i,j,k;
	Passenger listAux;

	printf("\nLos vuelos ACTIVOS son los siguientes: ");

	if(list!= NULL && len>0)
	{
		retorno=0;
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if((strcmp(list[i].flyCode,list[j].flyCode)>0) && (list[i].isEmpty==EMPTY && list[j].isEmpty == EMPTY))
				{
					listAux = list[i];
					list[i]=list[j];
					list[j]=listAux;
				}
				else
				{
					if((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].isEmpty==EMPTY && list[j].isEmpty == EMPTY))
					{
						if(list[i].statusFlight>list[j].statusFlight)
						{
							listAux = list[i];
							list[i]=list[j];
							list[j]=listAux;
						}
					}
				}
			}
		}
		for(k=0;i<len;k++)
		{
			if(list[i].isEmpty==OCCUPED && list[i].statusFlight==ACTIVO)
			{
				printf("\n --- %s ---",list[i].flyCode);
			}
		}
	}


	return retorno;
}

float pricePromedio(Passenger list[],int len)
{
	float acumuladorPrice=0, contadorPrice=0, promedio;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==OCCUPED)
		{
			acumuladorPrice += list[i].price;
			contadorPrice++;
		}
	}
	promedio = acumuladorPrice / contadorPrice;
	printf("\nLa suma total de los PRECIOS de los pasajes es: %2.f\nEl promedio de PRECIO de los vuelos es: %2.f\n",acumuladorPrice,promedio);
	return promedio;
}

void showAboveProm(Passenger list[],int len, float promedio)
{
	if(list!=NULL)
	{
		printf("\nLos pasajes por encima del promedio son: ");
		printf("  ID         NOMBRE       APELLIDO    PRECIO    CODIGO  TIPO DE PASS");
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty ==OCCUPED && list[i].price>=promedio)
			{
				printf("%5d %15s %15s %.2f %12s %4d %4d\n",list[i].id
											 ,list[i].name
											 ,list[i].lastName
											 ,list[i].price
											 ,list[i].flyCode
											 ,list[i].typePassenger
											 ,list[i].statusFlight);
			}
		}
	}
}
