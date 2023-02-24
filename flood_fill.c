/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:05:49 by mirnavar          #+#    #+#             */
/*   Updated: 2023/02/24 14:44:27 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10000001",
		"10010101",
		"10110001",
		"11101111",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	int	i;
	int j;
	char inicio;

	i = 0;
	j = 0;
	inicio = tab[begin.y][begin.x];
	printf("%s\n", &inicio);
	while (i < size.y)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (j < size.x && tab[i][j] == inicio && (tab[i+1][j] == inicio || tab[i][j+1] == inicio || tab[i][j-1] == 'F' || tab[i-1][j] == 'F')) 
				tab[i][j] = 'F';
			j++;
		}
		i++;
	}
}

