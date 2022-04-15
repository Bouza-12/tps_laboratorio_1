/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Alejandro Javier Garcia Bouzada
 Description : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y
  	  	  	   Aerolíneas Argentinas para ofrecerlos a sus clientes.
			   Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
			   El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "validaciones.h"

int main(void) {

	float kilometros;
	//int esEntero;
	int esFloat;
	float precioAerolinias;
	float precioLatam;
	float precioDevitoA;
	float precioDebitoL;
	float precioCreditoA;
	float precioCreditoL;
	float precioBtcA;
	float precioBtcL;
	float precioUnitarioA;
	float precioUnitarioL;
	int opcion;
	int salir =0;
	int flagIngresoDatos = 0;

	setbuf(stdout,NULL);

	kilometros = 0;
	precioAerolinias = 0;
	precioLatam = 0;
	//entro al menu y no salgo hasta que se ingrese la opción correcta
	do{
		//menu de opciones
		printf("================================"
				"\n1. Ingresar kil%cmetros: %2.f"
				"\n2. Ingresa Precio de Vuelos: "
				"\n   - Precio vuelo Aerolineas: %2.f"
				"\n   - Precio vuelo Latam: %2.f"
				"\n3. Calcular todos los costos: "
				"\n4. Informar Resultados: "
				"\n5. Carga forzada de datos"
				"\n6. Salir"
				"\n================================\n",162,kilometros,precioAerolinias,precioLatam);
		scanf("%d",&opcion);
		fflush(stdin);
		switch(opcion)
		{
			case 1:
				esFloat = validarNumeroFlotante(&kilometros, "1. Ingresar kilometros: ", "Error debe ingresar un numero entero entre 1 y 40000: \n", 1, 40000, 4);
				//entra si el numero NO es validado y muestra un mensaje y devuelve al menu
				if(esFloat !=0)
				{
					printf("Error!!! Demasiados intentos\n");
				}
				break;
			case 2:
				printf("\n2.Ingresa Precio de Vuelos:");
				esFloat = validarNumeroFlotante(&precioAerolinias, "\n - Precio vuelo Aerolineas: ", "debe ingresar un numero valido mayor a 0: \n", 0, 99999999,4);
				//entra si el numero NO es validado y muestra un mensaje y continúa con la proxima carga
				if(esFloat!=0)
				{
					printf("Error demasiados intentos fallidos\n.");
					break;
				}
				esFloat = validarNumeroFlotante(&precioLatam, "\n - Precio vuelo Latam: ", "debe ingresar un número valido mayor a 0: \n", 0, 99999999,4);
				//entra si el numero NO es validado y muestra un mensaje y vuelve al menú
				if(esFloat!=0)
				{
					printf("Error demasiados intentos fallidos.\n");
					break;
				}
				break;
			case 3:
				if(kilometros !=0 && precioAerolinias !=0 && precioLatam != 0) //corroboro que se haya ingresado todos los datos necesarios
				{
					printf("\nSe realizaron los c%clculos de costos: \n",160);
					precioDevitoA = calcularPrecioDebito(precioAerolinias, 10);
					precioDebitoL = calcularPrecioDebito(precioLatam, 10);
					precioCreditoA = calcularPrecioCredito(precioAerolinias, 25);
					precioCreditoL = calcularPrecioCredito(precioLatam, 25);
					precioBtcA = calcularPrecioBitcoin(precioAerolinias);
					precioBtcL = calcularPrecioBitcoin(precioLatam);
					precioUnitarioA = calcularPrecioPorKilometro(precioAerolinias, kilometros);
					precioUnitarioL = calcularPrecioPorKilometro(precioLatam, kilometros);
					flagIngresoDatos = 1;
				}
				else //si no se ingresaron muestra el mensaje y vuelve al menu
				{
					printf("No se pueden realizar los c%clcuolos. Faltan completar datos.\n",160);
				}
				break;
			case 4:
				//me aseguro que hayan ingresado datos y se hayan realizado los cálculos con la opción 3
				if(kilometros !=0 && precioAerolinias !=0 && precioLatam != 0 && flagIngresoDatos !=0 )
				{
					printf("KMs Ingresados: %2.f km\n",kilometros);
					printf("\nPrecio Aerolineas: %2.f"
							"\na) Precio con tarjeta de debito: $%2.f"
							"\nb) Precio con tarjeta de credito: $%2.f"
							"\nc) Precio pagando con bitcoin: $%f BTC"
							"\nd) Mostrar precio unitario: $%2.f\n", precioAerolinias, precioDevitoA, precioCreditoA, precioBtcA, precioUnitarioA);
					printf("\nPrecio Latam: %2.f"
							"\na) Precio con tarjeta de debito: $%2.f"
							"\nb) Precio con tarjeta de credito: $%2.f"
							"\nc) Precio pagando con bitcoin: $%f BTC"
							"\nd) Mostrar precio unitario: $%2.f\n",precioLatam,precioDebitoL,precioCreditoL,precioBtcL,precioUnitarioL);
					mostrarDiferencia(precioAerolinias, precioLatam);
				}
				else // si no se ingresaron datos o se realizaron los calculos muestra el mensaje y vuelve al menu
					printf("No se realizaron los c%clculos todav%ca porque falta ingresar datos.\n",160,161);
				break;
			case 5:
				//Ejercicio de carga forzada de datos, hardcodeo datos, hago las cuentas y muestro el resultado
				kilometros = 7090;
				precioAerolinias = 162965;
				precioLatam = 159339;

				precioDevitoA = calcularPrecioDebito(precioAerolinias, 10);
				precioDebitoL = calcularPrecioDebito(precioLatam, 10);
				precioCreditoA = calcularPrecioCredito(precioAerolinias, 25);
				precioCreditoL = calcularPrecioCredito(precioLatam, 25);
				precioBtcA = calcularPrecioBitcoin(precioAerolinias);
				precioBtcL = calcularPrecioBitcoin(precioLatam);
				precioUnitarioA = calcularPrecioPorKilometro(precioAerolinias, kilometros);
				precioUnitarioL = calcularPrecioPorKilometro(precioLatam, kilometros);
				printf("KMs Ingresados: %2.f km\n",kilometros);
				printf("\nPrecio Aerolineas: %2.f"
						"\na) Precio con tarjeta de debito: $%2.f"
						"\nb) Precio con tarjeta de credito: $%2.f"
						"\nc) Precio pagando con bitcoin: $%f BTC"
						"\nd) Mostrar precio unitario: $%2.f\n", precioAerolinias, precioDevitoA, precioCreditoA, precioBtcA, precioUnitarioA);
				printf("\nPrecio Latam: %2.f"
						"\na) Precio con tarjeta de debito: $%2.f"
						"\nb) Precio con tarjeta de credito: $%2.f"
						"\nc) Precio pagando con bitcoin: $%f BTC"
						"\nd) Mostrar precio unitario: $%2.f\n",precioLatam,precioDebitoL,precioCreditoL,precioBtcL,precioUnitarioL);
				mostrarDiferencia(precioAerolinias, precioLatam);
				break;
			case 6:
				//para salir se debe hace una comprobación para saber que no fue un accidente.
				salir = verificarLetra();
				break;
			default:
				//en caso de no ingresar una opción de menu válida, se debe reintentar
				printf("Ingrese una opci%cn v%clida\n",162,160);
				break;
		}
		//necesario para poder ver mensajes antes de borrar la consola
		system("pause");
		//borra la consola para no tener sobrecarga visual
		system("cls");
	}while(salir==0);
	printf("FIN DEL PROGRAMA");
	return 0;
}


