/*
 * ArrayPassenger.c
 *
 *  Created on: 5 may. 2022
 *      Author: bouza
 */

#include "ArrayPassenger.h"


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
			list[i].statusFlight = ACTIVO;
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

/** \brief Remove a Passenger by Id (put isEmpty Flag in -1 to not overwrite)
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
	int sure=-1;
	if(list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCCUPED && list[i].id == id)
			{
				sure =verificarSalida("\nEsta seguro que desea dar de BAJA el pasajero? S|N: ", "\nERROR!!! Debe ingresar un caracter valido 'S' para SI o 'N' para NO: ");
				if(sure==1)
				{
					list[i].isEmpty = DOWN;
					retorno = 0;
				}
				else
				{
					printf("No se dio de BAJA al pasajero");
				}
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
		printf("\n  ID         NOMBRE       APELLIDO    PRECIO        CODIGO  TIPO DE PASS\n");
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
					if((strcmp(list[i].lastName,list[j].lastName)>0) && (list[i].isEmpty==OCCUPED && list[j].isEmpty == OCCUPED))
					{
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].isEmpty==OCCUPED && list[j].isEmpty == OCCUPED))
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
					if((strcmp(list[i].lastName,list[j].lastName)<0) && (list[i].isEmpty==OCCUPED && list[j].isEmpty == OCCUPED))
					{
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].isEmpty==OCCUPED && list[j].isEmpty == OCCUPED))
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

void modifyPassenger(Passenger list[], int len,int idmax)
{
	int modifValidada;
	int idModify;
	int positionModify;
	int optionModify;
	int validarChangePrice;
	int validarChangetTipo;
	float changePriceAux;
	int changeTipoAux;

	printPassenger(list, len);


	modifValidada = validarEntero(&idModify, "\nIngrese el ID del pasajero a MODIFICAR: ", "\nError!!! Debe ingresar un ID valido: ", 1000, idmax);
	if(modifValidada==0)
	{
		positionModify = findPassengerById(list, len, idModify);
		if(list[positionModify].isEmpty==OCCUPED && list[positionModify].id==idModify)
		{
			optionModify = menuOptionInt("\n¿Que desea modificar?\n1. NOMBRE\n2. APELLIDO\n3. PRECIO\n4. TIPO DE PASAJERO\n5. CODIGO DE VUELO\n6. SALIR", 1, 6);
			switch(optionModify)
			{
				case 1:
					cargarNombre(list[positionModify].name, 51, "Ingrese el NOMBRE del Pasajero: ");
					break;
				case 2:
					cargarNombre(list[positionModify].lastName, 51, "Ingrese el APELLIDO del Pasajero: ");
					break;
				case 3:
					validarChangePrice = validarNumeroFlotante(&changePriceAux, "\nIngrese el nuevo PRECIO del pasaje: ", "\nError!!! debe ingresar un PRECIO  valido: ", 1, 9999999999, 5);
					if(validarChangePrice==0)
					{
						list[positionModify].price = changePriceAux;
					}
					else
					{
						printf("No se pudo realizar el cambio de precio.");

					}
					break;
				case 4:
					validarChangetTipo = validarEntero(&changeTipoAux, "\nIngrese el Tipo de Pasajero: ", "\nError!!! Debe ingresar un tipo de pasajero valido: ", 1, 3);
					if(validarChangetTipo==0)
					{
						list[positionModify].typePassenger = changeTipoAux;
						printf("\nSe hizo el cambio con exito.");
					}
					else
					{
						printf("No se realizaron los cambios.");
					}
					break;
				case 5:
					printf("Ingrese el nuevo codigo de vuelo: ");
					scanf("%s", list[positionModify].flyCode);
					break;
				case 6:
					verificarSalida("Salir sin modificar? S|N ", "Debe ingresar S o N");
					break;
			}
		}
	}
}

/// Mustra los vuelos de estado ACTIVO por orden alfabetico
/// @param list: lista de Passenger
/// @param len: largo maximo de la lista
/// @return: devuelve 0 si hubo exito en mostrar la lista / -1 si no pudo mostrar
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
				if((strcmp(list[i].flyCode,list[j].flyCode)>0) && (list[i].isEmpty==OCCUPED && list[j].isEmpty == OCCUPED))
				{
					listAux = list[i];
					list[i]=list[j];
					list[j]=listAux;
				}
				else
				{
					if((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].isEmpty==OCCUPED && list[j].isEmpty == OCCUPED))
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
		for(k=0;k<len;k++)
		{
			if(list[k].isEmpty==OCCUPED && list[k].statusFlight==ACTIVO)
			{
				printf("\n --- %s --- %s, %s",list[k].flyCode,list[k].lastName,list[k].name);
			}
		}
	}


	return retorno;
}

/// suma los precios de una lista de Passenger, los muestra y devuelve el promedio
/// @param list: lista de Passenger
/// @param len: largo de la lista
/// @return: el float del promedio.
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

/// Mustra de una lista de passenger los que superan el promedio de precio
/// @param list: lista de Passenger
/// @param len: largo de la lista
/// @param promedio: variable para mostrar los que superen este numero.
void showAboveProm(Passenger list[],int len, float promedio)
{
	if(list!=NULL)
	{
		printf("\nLos pasajes por encima del promedio son: ");
		printf("\n  ID         NOMBRE       APELLIDO    PRECIO    CODIGO  TIPO DE PASS");
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty ==OCCUPED && list[i].price>=promedio)
			{
				printf("\n%5d %15s %15s %.2f %12s %4d %4d",list[i].id
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
