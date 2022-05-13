/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:58 by mreymond          #+#    #+#             */
/*   Updated: 2022/05/13 14:38:00 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		write(1, "Error: argument\n", 16);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	int		width;
	int		height;
	char	background;

	chech_args(argc, argv);
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32)
		return (1);
	}
	if (fscanf(file, "%d %d %c\n", &width, &height, &background)) != 3)
	{
		write(1, "Error: Operation file corrupted\n", 32)
		return (1);
	}
	return (0);
}
