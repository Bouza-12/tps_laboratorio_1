/*
 * funcones.h
 *
 *  Created on: 6 abr. 2022
 *      Author: Alejandro Javier Garcia Bouzada
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>



/// Sirve para pasar el precio del pasaje con el interes al consultar por pagos con tarjeta de credito. calcula el porcentaje y lo suma al precio original
/// @param precioVuelo varable con el precio origianl
/// @param interes varaible entera de porcentaje a aplicar (ex. 10 para 10% / 20 para 20%)
/// @return devuelve el resultado con el interés aplicado
float calcularPrecioCredito(float precioVuelo, int interes);// calcula y muestra el precio con interes

/// cuanta para averiguar el valor del pasaje en bitcoin
/// @param precioVuelo  varable con el precio origianl
/// @return devuelvo el precio en BTC
float calcularPrecioBitcoin(float precioVuelo);

/// calculo y devuelvo el valor del precio del pasaje por cada kilometro
/// @param precioVuelo varable con el precio origianl
/// @param kilometros variable numerica de la distancia total
/// @return el resultado de la cuenta
float calcularPrecioPorKilometro(float precioVuelo, float kilometros);

/**
 * Se usa para calcular el precio con descuento al consultar el pago con debito. calucla el porcentaje y lo aplica al precio original.
 * @param precioVuelo precioVUelo variable del precio original
 * @param descuento variable entera de un porcentaje a aplicar (ex. 10 para 10% / 20 para 20%)
 * @return devuelve el valor resultado
 */
float calcularPrecioDebito(float precioVuelo, int descuento);//calcula y muestra el descuento con débito

/// muestra la resta de los pasajes y diferencia cual es el mayor para evitar numeros negativos y si no hay doferencia entre estos
/// @param precioAerolineas float indicando un precio a comparar
/// @param precioLatam float indicando otro precio a comparar
void mostrarDiferencia(float precioAerolineas,float precioLatam);


#endif /* FUNCIONES_H_ */
