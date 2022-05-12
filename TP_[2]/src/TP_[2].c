/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Alejandro Garcia Bozuada
 Version     :
 Description : Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo.
 	 	 	   Se sabe que no puede tener más de 2000 pasajeros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "validaciones.h"
#include "ArrayPassenger.h"
#include "menus.h"
//defines
#define MAX_PASSENGER 2000
#define TURISTA 1
#define EJECUTIVA 2
#define PRIMERA 3

#define EMPTY 0
#define OCCUPED 1
#define DOWN -1

static int idIncremental = 1000;
static int ePassenger_getID();
/// Funcion para encontrar un id unico sin depender de posiciones
/// @return devuelve el id generado
static int ePassenger_getID() {
	return idIncremental++;
}

//void cargaForzada(Passenger list[],int len);





//MAIN
int main(void)
{
	setbuf(stdout,NULL);
	//VARIABLES
	Passenger listPassengers[MAX_PASSENGER];

	int optionMenu, optionInform;
	int flagEnd=0, contadorPassenger=0, bajaValidada;
	int addSuccess;
	int typePassenger;
	char name[51], lastName[51], flycode[10];
	float price, promedioPrices;
	int validarFloat, validarInt, validarActivos;
	int idBaja, idAlta, bajaEfectiva;

	initPassengers(listPassengers, MAX_PASSENGER);

//	cargaForzada(listPassengers, MAX_PASSENGER);
//	contadorPassenger =4;
	do
	{
		optionMenu = menuOptionInt("\nMENU PRINCIPAL:\n1. ALTA DE PASAJERO\n2. MODIFICAR UN PASAJERO\n3. BAJA DE UN PASAJERO\n4. LISTA DE INFORME\n5. SALIR", 1 , 5);
		switch(optionMenu)
		{
			case 1: //ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
//				      número de Id. El resto de los campos se le pedirá al usuario.
				cargarNombre(name, 51, "Ingrese el NOMBRE del pasajero: ");
				cargarNombre(lastName, 51, "Ingrese el APELLIDO del pasajero: ");

				validarFloat = validarNumeroFlotante(&price, "Ingrese el PRECIO del pasaje: ", "Error!!! Debe ingresar un PRECIO valido: ", 1, 999999999 , 5);
				if(validarFloat!=0)
				{
					printf("No se pudo ingresar el precio!!!");
					break;
				}
				validarInt = validarEntero(&typePassenger, "Ingrese el TIPO DE PASAJERO\n1 - Clase TURISTA\n2 - Clase EJECUTIVA\n3 - PRIMERA CLASE\n", "Error!!! Debe seleccionar una opcion correcta: ", 1, 3);
				if(validarInt!=0)
				{
					printf("No se pudo ingresar el Tipo de Pasajero!!!");
					break;
				}
				printf("Ingrese el CODIGO DE VUELO: ");
				scanf("%s",flycode);
				fflush(stdin);
				idAlta = ePassenger_getID();
				addSuccess = addPassenger(listPassengers, MAX_PASSENGER, idAlta, name, lastName, price, typePassenger, flycode);
				if(addSuccess!=0)
				{
					printf("Ocurrio un error al cargar el pasajero, intentelo de nuevo.");
				}
				else
				{
					contadorPassenger++;
					printf("Se dio de alta con exito!");
				}
				break;
			case 2: //MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
//				   	  o Precio o Tipo de pasajero o Código de vuelo
				if(contadorPassenger>0)
				{
					modifyPassenger(listPassengers, MAX_PASSENGER,idIncremental);
				}
				else
				{
					printf("Todavía no se ingresaron pasajeros.\n");
				}
				break;
			case 3: //BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

				if(contadorPassenger>0)
				{
					printPassenger(listPassengers, MAX_PASSENGER);
					bajaValidada = validarEntero(&idBaja, "\nIngrese el ID del pasajero a dar de baja: ", "\nError!!! Debe ingresar un ID valido: ", 1000, 1000+contadorPassenger);
					if(bajaValidada==0)
					{
						bajaEfectiva = removePassenger(listPassengers, MAX_PASSENGER, idBaja);
						if(bajaEfectiva==0)
						{
							printf("Se dio de baja el pasajero.\n");
							contadorPassenger--;
						}
						else
						{
							printf("No se pudo dar la baja.\n");
						}
					}
					else
					{
						printf("No se pudo dar la baja.\n");
					}
				}
				else
				{
					printf("Todavía no se ingresaron pasajeros.\n");
				}
				break;
			case 4: //INFORMAR:
					//1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
					//2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
					//promedio.
					//3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
				//Verifico que haya al menos un pasajero cargado
				if(contadorPassenger>0)
				{
					//Muestro menu de informes
					optionInform = menuOptionInt("\n1. Lista de pasajero ordenados.\n2. Total y promedio de precios de los pasaje. Cuantos superan el precio\n3. Listado de pasajero segun codigo de vuelo y estado activo", 1, 3);
					switch (optionInform)
					{
						case 1:
							//Ordeno pasageros por Apellido ascendente y si tienen el mismo apellido por mayor tipo de pasajero
							sortPassengers(listPassengers, MAX_PASSENGER, 1);
							printPassenger(listPassengers, MAX_PASSENGER);
							break;
						case 2:
							//Asigno el promedio a la variable, tambien muesto el promedio y el acumulado
							promedioPrices = pricePromedio(listPassengers, MAX_PASSENGER);
							//Muestro superiores al promedio
							showAboveProm(listPassengers, MAX_PASSENGER, promedioPrices);
							break;
						case 3:
							validarActivos = showActiveFlights(listPassengers, MAX_PASSENGER);
							if(validarActivos==0)
							{
								printf("\n Vuelos Activos OK");
							}
							else
							{
								printf("No se pudieron mostrar los vuelos ACTIVOS.");
							}
							break;
						default:
							printf("Ocurrio un error y no se puedo informar.");
							break;
					}

				}
				else
				{
					printf("Todavía no se ingresaron pasajeros.\n");
				}
				break;
			case 5: //Exit
				flagEnd = verificarSalida("\nDesea salir del programa? S|N ", "\Error!!! Debe ingresar un caracter valido S|N: ");

				break;
			default:
				printf("No ingreso una opcion de menu valida.\n");
				break;
		}

	}while(flagEnd==0);


	system("pause");
	return EXIT_SUCCESS;
}

//FUNCIONES







//submenu MODIFICAR: se ingrese id. nombre - apellido - precio - codigo de vuelo - tipo -

//submenu informar: lista por apellido y tipo - total precio, promedio pasajes y cuantos arriba del promedio
// - listar pasajeros con codigo de vuelo y activos.



//void cargaForzada(Passenger list[],int len)
//{
//	Passenger carga[]={
//			{1000,"Alejandro","Garcia",250000,"ARS1234TUR",1,0,OCCUPED},
//			{1001,"Gabriel", "Salvador",325000,"ARS1234EJE",2,0,OCCUPED},
//			{1002,"Camila", "Leyes",433000.25,"EUR9874PCL",3,0,OCCUPED},
//			{1003,"Rosa","Diaz",275000,"EUR9876",1,0,OCCUPED}
//	};
//	list= carga;
//}
