#include "main.h"

/**
 * handler - handling ctrl-c signal
 *
 * @sig: number of the signal
 */
void handler(int sig __attribute__((unused)))
{
	write(1, "\n$ ", 4);
	signal(SIGINT, handler);
}
