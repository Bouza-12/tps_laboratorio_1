/*
 * funciones.c
 *
 *  Created on: 6 abr. 2022
 *      Author: Alejandro Javier Garcia Bouzada
 */


// funciones

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "operaciones.h"


/**
 * Se usa para calcular el precio con descuento al consultar el pago con debito. calucla el porcentaje y lo aplica al precio original.
 * @param precioVuelo precioVUelo variable del precio original
 * @param descuento variable entera de un porcentaje a aplicar (ex. 10 para 10% / 20 para 20%)
 * @return devuelve el valor resultado
 */
float calcularPrecioDebito(float precioVuelo, int descuento)
{
	float resultado, porcentajeDescuento, precioDescontado;
	porcentajeDescuento = (float) descuento/100; //Debo tratar al entero como float
	precioDescontado = precioVuelo * porcentajeDescuento; //calculo cual es el precio del descuento
	resultado= precioVuelo-precioDescontado; //Resto el decuento al precio original
	return resultado;
}

/// Sirve para pasar el precio del pasaje con el interes al consultar por pagos con tarjeta de credito. calcula el porcentaje y lo suma al precio original
/// @param precioVuelo varable con el precio origianl
/// @param interes varaible entera de porcentaje a aplicar (ex. 10 para 10% / 20 para 20%)
/// @return devuelve el resultado con el interés aplicado
float calcularPrecioCredito(float precioVuelo, int interes){
	float resultado, porcentajeInteres, precioInteres;
	porcentajeInteres = (float) interes/100; //Debo tratar al entero como float
	precioInteres = precioVuelo * porcentajeInteres; //calculo cual es el precio del interes a sumar
	resultado= precioVuelo+precioInteres; // sumo el precio original con el interes.
	return resultado;
}


/// calculo y devuelvo el valor del precio del pasaje por cada kilometro
/// @param precioVuelo varable con el precio origianl
/// @param kilometros variable numerica de la distancia total
/// @return el resultado de la cuenta
float calcularPrecioPorKilometro(float precioVuelo, float kilometros){
	float resultado;
	resultado = precioVuelo / kilometros;
	return resultado;
}

/// cuanta para averiguar el valor del pasaje en bitcoin
/// @param precioVuelo  varable con el precio origianl
/// @return devuelvo el precio en BTC
float calcularPrecioBitcoin(float precioVuelo){
	const float btc = 4765858.73;
	float resultado;
	resultado = precioVuelo / btc;
	return resultado;
}

/// muestra la resta de los pasajes y diferencia cual es el mayor para evitar numeros negativos y si no hay doferencia entre estos
/// @param precioAerolineas float indicando un precio a comparar
/// @param precioLatam float indicando otro precio a comparar
void mostrarDiferencia(float precioAerolineas,float precioLatam){
	float diferencia;
	//Debo averiguar cual es el mayor para que la resta no sea un numero negativo. O mostrar un mensaje especial en caso de que sean iguales.
	if (precioAerolineas > precioLatam)
	{
		diferencia = restaDosFloat(precioAerolineas, precioLatam);
		printf("\nLa diferencia de precio es: $ %2.f\n",diferencia);
	}
	else
	{
		if(precioAerolineas < precioLatam)
		{
			diferencia = restaDosFloat(precioLatam, precioAerolineas);
			printf("La diferencia de precio es: $ %2.f\n",diferencia);
		}
		else
		{
			printf("No hay diferencia de precio.\n");
		}
	}
}

