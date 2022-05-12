/*
 * menus.c
 *
 *  Created on: 11 may. 2022
 *      Author: bouza
 */

#include "menus.h"

/// Funcion para hacer un menu de opciones Order List
/// @param mensaje: menu a mostrar
/// @param minimo: primer numero de la lista
/// @param maximo: numero maximo de la lista
/// @return devuelve 0 si se pudo elegir una opcion correcta / -1 en caso de error
int menuOptionInt(char* mensaje, int minimo, int maximo)
{
	int option, correcto, retorno;
	printf("%s",mensaje);
	correcto = validarEntero(&option, "\nElija una opcion: ", "\nNo inrgeso una opcion vailda: ", minimo, maximo);
	if(correcto==0)
	{
		retorno=option;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}
