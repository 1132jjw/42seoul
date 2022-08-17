/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:58:04 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/19 21:41:25 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_header.h"

int		input_num_check(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (!(str[cnt] >= '0' && str[cnt] <= '9'))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		cnt++;
	}
	if (str[0] == '0' && cnt != 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (cnt == 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}

void	dict_arr_free(t_dict *dict)
{
	int i;

	i = 0;
	while (i < g_dict_len)
	{
		free(dict[i].key);
		free(dict[i++].value);
	}
	free(dict);
}

int		start(int argc, char **argv, int *fd)
{
	if (argc > 3 || argc < 2)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	if (argc == 2)
	{
		*fd = open("numbers.dict", O_RDONLY);
		if (input_num_check(argv[1]) == -1)
			return (-1);
	}
	else
	{
		*fd = open(argv[1], O_RDONLY);
		if (input_num_check(argv[2]) == -1)
			return (-1);
	}
	if (*fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	return (0);
}

void	print_g_answer(void)
{
	g_answer[ft_strlen(g_answer) - 1] = '\0';
	ft_putstr(g_answer);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		pow_1000[1000];
	t_dict		*dict_arr;

	if (start(argc, argv, &fd) == -1)
		return (0);
	if (argc == 2)
		dict_arr = parse(fd, "numbers.dict");
	else if (argc == 3)
		dict_arr = parse(fd, argv[1]);
	else
		dict_arr = 0;
	close(fd);
	ft_sort(dict_arr);
	argc == 2 ? ft_read_argument(argv[1], pow_1000, dict_arr) \
	: ft_read_argument(argv[2], pow_1000, dict_arr);
	if (g_error == 1)
	{
		write(1, "Dict Error", 11);
		dict_arr_free(dict_arr);
		return (0);
	}
	print_g_answer();
	dict_arr_free(dict_arr);
	return (0);
}
