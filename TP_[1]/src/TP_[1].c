/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
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
//funciones - prototipos


int main(void) {
	setbuf(stdout,NULL);

	int kilometros, esEntero, esFloat;
	float precioAerolinias, precioLatam, precioDevitoA,precioDebitoL,precioCreditoA, precioCreditoL;
	float precioBtcA, precioBtcL, precioUnitarioA, precioUnitarioL;
	int opcion, flagCalculos=0;
	int salir =0;

	kilometros = 7090;
	precioAerolinias = 162965;
	precioLatam = 159339;

	do{
		//menu
		printf("\n================================"
				"\n1. Ingresar kil%cmetros: %d"
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
		switch(opcion){
			case 1:
				esEntero = validarEntero(&kilometros, "1. Ingresar kilometros: ", "Error debe ingresar un numero entero entre 1 y 40000", 1, 40000, 4);
				if(esEntero !=0){
					printf("Error!!! Demasiados intentos\n");
				}
				break;
			case 2:
				printf("\n2.Ingresa Precio de Vuelos:");
				esFloat = validarNumeroFlotante(&precioAerolinias, "\n - Precio vuelo Aerolineas: ", "debe ingresar un número valido mayor a 0", 0, 99999999,4);
				if(esFloat!=0){
					printf("Error demasiados intentos fallidos\n.");
					break;
				}
				esFloat = validarNumeroFlotante(&precioLatam, "\n - Precio vuelo Latam: ", "debe ingresar un número valido mayor a 0", 0, 99999999,4);
				if(esFloat!=0){
					printf("Error demasiados intentos fallidos.\n");
					break;
				}
				break;
			case 3:
				printf("\nSe realizaron los c%clculos de costos: ",160);
				precioDevitoA = calcularPrecioDebito(precioAerolinias, 10);
				precioDebitoL = calcularPrecioDebito(precioLatam, 10);
				precioCreditoA = calcularPrecioCredito(precioAerolinias, 25);
				precioCreditoL = calcularPrecioCredito(precioLatam, 25);
				precioBtcA = calcularPrecioBitcoin(precioAerolinias);
				precioBtcL = calcularPrecioBitcoin(precioLatam);
				precioUnitarioA = calcularPrecioPorKilometro(precioAerolinias, kilometros);
				precioUnitarioL = calcularPrecioPorKilometro(precioLatam, kilometros);
				flagCalculos = 1;
				break;
			case 4:
				if(flagCalculos ==1){
					printf("KMs Ingresados: %d km\n",kilometros);
					printf("\nPrecio Aerolineas: %2.f"
							"\na) Precio con tarjeta de debito: $%2.f"
							"\nb) Precio con tarjeta de credito: $%2.f"
							"\nc) Precio pagando con bitcoin: $%f"
							"\nd) Mostrar precio unitario: $%2.f\n", precioAerolinias, precioDevitoA, precioCreditoA, precioBtcA, precioUnitarioA);
					printf("\nPrecio Latam: %2.f"
							"\na) Precio con tarjeta de debito: $%2.f"
							"\nb) Precio con tarjeta de credito: $%2.f"
							"\nc) Precio pagando con bitcoin: $%f"
							"\nd) Mostrar precio unitario: $%2.f\n",precioLatam,precioDebitoL,precioCreditoL,precioBtcL,precioUnitarioL);
					mostrarDiferencia(precioAerolinias, precioLatam);
				}
				else
					printf("No se realizaron los cálculos todavía porque no se ingresron los datos aún.");
				break;
			case 5:
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
				printf("KMs Ingresados: %d km\n",kilometros);
				printf("\nPrecio Aerolineas: %2.f"
						"\na) Precio con tarjeta de debito: $%2.f"
						"\nb) Precio con tarjeta de credito: $%2.f"
						"\nc) Precio pagando con bitcoin: $%2.f"
						"\nd) Mostrar precio unitario: $%2.f\n", precioAerolinias, precioDevitoA, precioCreditoA, precioBtcA, precioUnitarioA);
				printf("\nPrecio Latam: %2.f"
						"\na) Precio con tarjeta de debito: $%2.f"
						"\nb) Precio con tarjeta de credito: $%2.f"
						"\nc) Precio pagando con bitcoin: $%2.f"
						"\nd) Mostrar precio unitario: $%2.f\n",precioLatam,precioDebitoL,precioCreditoL,precioBtcL,precioUnitarioL);
				mostrarDiferencia(precioAerolinias, precioLatam);
				break;
			case 6:
				salir = verificarLetra();
				break;
		}
		system("\npause");
		system("cls");
	}while(salir==0);
	printf("FIN DEL PROGRAMA");
	return 0;
}


