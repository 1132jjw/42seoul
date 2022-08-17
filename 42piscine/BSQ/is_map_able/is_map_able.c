/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_able.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:00:28 by hyomkim           #+#    #+#             */
/*   Updated: 2020/07/22 09:22:06 by hyomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>	//	ddddd
#include <stdio.h>	//	ddddd
#include <stdlib.h>

int		is_line_num_match(char **map)
{
	int	line_num;
	int	real_num;

	line_num = 0;
	real_num = 0;
	while(*(*map + 3))
	{
		line_num *= 10;
		line_num += *((*map)++) - '0';
	}
	while(map[real_num])
		real_num++;
	if (line_num == real_num - 1)
		return (0);
	return (-1);
}

int		is_str_consist_only_of_base(char *str, char *base)
{
	int	b_i;
	int	s_i;

	s_i = 0;
	while (str[s_i])
	{
		b_i = 0;
		while (base[b_i])
		{
			if(str[s_i] == base[b_i])
				break ;
			b_i++;
		}
		if (base[b_i] == '\0')
			return (-1);
		s_i++;
	}
	return (0);
}

int		is_str_able_print_and_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] < ' ' && str[len] > '~')
			return (-1);
		len++;
	}
	return (len);
}

char	*is_base_able(char *str)
{
	char	*cp_base;
	int		i;
	int		i2;

	cp_base = (char*)malloc(sizeof(char) * 4);
	i = 0;
	while (str[i] != '\0')
		i++;
	i2 = 3;
	while (i2 >= 0)
		cp_base[i2--] = str[i--];
	cp_base[3] = '\0';
	if (is_str_able_print_and_strlen(cp_base) < 0)
		return (char*)(0);
	if (cp_base[0] == cp_base[1])
		return (char*)(0);
	if (cp_base[0] == cp_base[2])
		return (char*)(0);
	if (cp_base[1] == cp_base[2])
		return (char*)(0);
	return (cp_base);
}

int		is_map_able(char *map[])
{
	int		last_len;
	char	*base;
	int		answer;
	int		m_i;

	answer = 0;
	m_i = 0;
	if (!(base = is_base_able(map[m_i++])))
		return (-1);
	if (is_line_num_match(map) < 0)
		return (-2);
	while (map[m_i] && answer  >= 0)
	{
		if (last_len != is_str_able_print_and_strlen(map[m_i]) && m_i > 1)
			answer = -3;
		else if (is_str_consist_only_of_base(map[m_i], base) < 0)
			answer = -4;
		last_len = is_str_able_print_and_strlen(map[m_i++]);
	}
	free(base);
	base = (char*)0;
	if (answer <= -1)
		return (answer);
	return (0);
}

int main(void)	//	dddddddd
{
	char	**map;
	int	i;
	int answer;

	i = 0;
	map = (char**)malloc(6);
	while(i < 5)
		map[i++] = (char*)malloc(10);
	map[i] = (char*)0;
	i = 0;
	printf("\n************ printing map data *************\n\n");
	if(!(map[i++] = strdup("4012")))
		return (-1);
	printf("%s\n",map[i - 1]);
	while(i < 5)
	{
		if(!(map[i++] = strdup("002014012")))
			return (-1);
		printf("%s\n",map[i - 1]);
	}
	printf("\n********************************************\n\n");
	answer = is_map_able(map);
	switch (answer)
	{
		case 0 : 
			printf("Good map!!!");
			break ;
		case (-1) : 
			printf("'base' error!!!");
			break ;
		case (-2) : 
			printf("'number of lines' error!!!");
			break ;
		case (-3) : 
			printf("'Map data include nuable print char' error!!!");
			break ;
		case (-4) : 
			printf("'Map data does not match base' error!!!");
			break ;
	}
	printf("\n********************************************\n\n");
	return (0);
}
