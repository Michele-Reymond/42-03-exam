/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:58 by mreymond          #+#    #+#             */
/*   Updated: 2022/05/23 16:57:17 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

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
	float	start_x;
	float	start_y;
	float	end_x;
	float	end_y;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
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
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	char	canvas[height][width];
	while (i < height)
	{
		memset(canvas[i], background, width);
		canvas[i][width] = '\0';
		i++;
	}
	while((scan = fscanf(file, "%c %f %f %f %f %c\n", &type, &start_x, &start_y, &r_width, &r_height, &fill)) == 6)
	{
		if (type == 'r' && r_width > 0 && r_height > 0)
		{
			i = 0;
			j = 0;
			end_x = start_x + r_width;
			end_y = start_y + r_height;
			while (i < height)
			{
				while (j < width)
				{
					if (i >= start_y && j >= start_x && i <= end_y && j <= end_x)
						if (!(i >= start_y + 1 && j >= start_x + 1 && i <= end_y - 1 && j <= end_x - 1))
							canvas[i][j] = fill;
					j++;
				}
				j = 0;
				i++;
			}
		}
		else if (type == 'R' && r_width > 0 && r_height > 0)
		{
			i = 0;
			j = 0;
			end_x = start_x + r_width;
			end_y = start_y + r_height;
			while (i < height)
			{
				while (j < width)
				{
					if (i >= start_y && i <= end_y && j >= start_x && j <= end_x)
							canvas[i][j] = fill;
					j++;
				}
				j = 0;
				i++;
			}
		}
		else
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
	}
	if (scan != -1)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
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
