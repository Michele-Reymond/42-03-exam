/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:58 by mreymond          #+#    #+#             */
/*   Updated: 2022/05/16 17:53:05 by mreymond         ###   ########.fr       */
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
	int 	scan;
	int		i;
	int 	j;
	char	type;
	float	r_width;
	float	r_height;
	char	fill;
	float	point1[2];
	float	point2[2];

	i = 0;
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
	char	canvas[height][width];
	while (i < height)
	{
		memset(canvas[i], background, width);
		canvas[i][width] = '\0';
		i++;
	}
	while((scan = fscanf(file, "%c %f %f %f %f %c\n", &type, &point1[0], &point1[1], &r_width, &r_height, &fill)) == 6)
	{
		if (type == 'r')
		{
			i = 0;
			j = 0;
			point2[0] = point1[0] + r_width;
			point2[1] = point1[1] + r_height;
			while (i < height)
			{
				while (j < width)
				{
					if (point1[0] <= i && i <= point2[0])
						if (point1[1] <= j && j <= point2[1])
							canvas[i][j] = fill;
					j++;
				}
				j = 0;
				i++;
			}
		}
		else if (type == 'R')
		{
			i = 0;
			j = 0;
			point2[0] = point1[0] + r_width;
			point2[1] = point1[1] + r_height;
			while (i < height)
			{
				while (j < width)
				{
					if (point1[0] <= i && i <= point2[0])
						if (point1[1] <= j && j <= point2[1])
							canvas[i][j] = fill;
					j++;
				}
				j = 0;
				i++;
			}
		}
		else
			return (1);
	}
	if (scan != -1)
		return (1);
	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			write(1, &canvas[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
