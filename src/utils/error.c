#include "so_long.h"

void catch_exception(int errno, char *addn)
{
	char *error;
	
	error = strerror(errno);
	ft_putstr_fd("so_long: ", 2);
	ft_putstr_fd(error, 2);
	if (addn)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(addn, 2);
	}
	ft_putstr_fd("\n", 2);
	if (errno < 128)
		exit(errno);
}

void handle_error(int exit_code, char *type)
{
	if(!ft_strcmp(type, WRONG_EXTENTION))
		ft_putstr_fd("Please write correct file type: {map_name}.ber\n", 2);
	else if(!ft_strcmp(type, WRONG_ARGUMENTS))
		ft_putstr_fd("Too few arguments!\n", 2);
	else
		ft_putstr_fd("Unexpected error.\n", 2);
	exit(exit_code);
}