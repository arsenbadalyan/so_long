#include "so_long.h"

void	catch_exception(int errno, char *addn)
{
	char	*error;

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

void	handle_error(int exit_code, char *type)
{
	if (!ft_strcmp(type, WRONG_EXTENTION))
		ft_putstr_fd("Please write correct file type: {map_name}.ber\n", 2);
	else if (!ft_strcmp(type, WRONG_ARGUMENTS))
		ft_putstr_fd("Too few arguments!\n", 2);
	else if (!ft_strcmp(type, WRONG_MAP_CONF))
		ft_putstr_fd("Please fill map correctly!\n", 2);
	else if (!ft_strcmp(type, WRONG_WALL_CONF))
		ft_putstr_fd("Please set correct wall configuration!\n", 2);
	else if (!ft_strcmp(type, WRONG_PE_CONF))
	{
		ft_putstr_fd("Please check if you set correct flags: \
		[1, 0, P (one), E (one), C (at least one), V]\n", 2);
	}
	else if (!ft_strcmp(type, WRONG_WAY_CONF))
	{
		ft_putstr_fd("Please make sure that you set correct \
		way for player to get all coins and exit from game!\n", 2);
	}
	else
	{
		ft_putstr_fd("Something went wrong. Please check map \
		configuration.\n", 2);
	}
	if (exit_code)
		exit(exit_code);
}
