/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* mensaje;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	config = leer_config();

	ip = config_get_string_value(config, "IP");

	puerto = config_get_string_value(config, "PUERTO");

	conexion = crear_conexion(ip,puerto);

	enviar_mensaje("soy un log desde el cliente al server",conexion);

	mensaje = recibir_mensaje(conexion);

	log_info(logger, mensaje,...);

	terminar_programa(conexion, logger, config);
}

//TODO
t_log* iniciar_logger(void)
{
	return log_create("tp0.log", "game_watch_client", true, 1);
}

//TODO
t_config* leer_config(void)
{
	return config_create("tp0.config");
}

//TODO
void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	log_destroy(logger);
	config_destroy(config);
	liberar_conexion(conexion);
}
