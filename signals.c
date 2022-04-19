#include "shell.h"
/**
 * new_signal_handler - identifies the input signal (creo)
 *
 */
void new_signal_handler(int pid __attribute__((unused)))
{
	// prompconte signo
	if (write(STDOUT_FILENO, "\n$ ", 3) == EOF)
		exit(EXIT_FAILURE);
}

