/*
 * menus.c
 *
 *  Created on: 11 may. 2022
 *      Author: bouza
 */


int menuOptionInt(char* mensaje, int minimo, int maximo)
{
	int option, correcto, retorno;
	printf(mensaje);
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
