#include "main.h"

/**
 * ctrlc_new_handler - prints ^C with a new line
 *@num: todavia nno se que es 
 * Return: Always 0
 */
void ctrlc_new_handler(int num __attribute__((unused)))
{
	printf("^C\n");
}
/**
 * register_new_signals - modify the signal handler
 * Return: Always 0
 */
void register_new_signals()
{
	if (signal(SIGINT, ctrlc_new_handler) == SIG_ERR)
	{
		/** When the ctrl c doesn't work, it prints */
		printf("\$");
		exit(1);
	}
}
/** ctrl d causa un golpe de salida y cierra la terminal */
/**
 * ctrld_new_handler - exists shell 
 *@num: todavia nno se que es 
 * Return: Always 0
 */
void ctrld_new_handler(int num __attribute__((unused)))
{
	printf("^C\n");
}
/**
 * register_new_signals - modify the signal handler
 * Return: Always 0
 */
void register_new_signals()
{
	if (signal(SIGINT, ctrlc_new_handler) == SIG_ERR)
	{
		/** When the ctrl c doesn't work, it prints */
		printf("\$");
		exit(1);
	}
}