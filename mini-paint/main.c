/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:58 by mreymond          #+#    #+#             */
/*   Updated: 2022/05/13 17:35:13 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_args(int argc)
{
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	int		width;
	int		height;
	char	background;
	char	*arg;
	char 	type;
	float	x;
	float	y;
	float	radius;
	char	color;

	
	arg = argv[1];
	if (check_args(argc))
		return (1);
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (fscanf(file, "%d %d %c\n", &width, &height, &background) != 3)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (width <= 0 || height <= 0 || width > 300 || height > 300)
		return (1);
	return (0);
}
