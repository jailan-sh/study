#include "main.h"

/**
 */

int main(int argc, char *argv[])
{
	if (argc == 1 && isatty(STDIN_FILENO))
		interactive();

	else if (argc >= 1 && !isatty(STDIN_FILENO))
		noninteractive(argc, argv);
	return (0);
}
