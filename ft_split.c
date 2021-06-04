/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:16:09 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/02 14:26:22 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**malloc_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

int	str_count(char *str, char c)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != 0)
			result++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (result);
}

int	str_line_len(char *str, char c)
{
	int	count;

	count = 0;
	while (str[count] != c && str[count] != 0)
		count++;
	return (count);
}

char	**write_lines(char **result, char const *s, int count_strs, char c)
{
	int	n;
	int	str_pos;
	int	c_pos;

	n = 0;
	str_pos = 0;
	c_pos = 0;
	while (n < count_strs)
	{
		while (s[str_pos] == c)
			str_pos++;
		result[n] = (char *)malloc(str_line_len((char *)s + str_pos, c) + 1);
		if (result == 0)
			return ((char **)malloc_free(result));
		while (s[str_pos] != c && s[str_pos] != 0)
			result[n][c_pos++] = s[str_pos++];
		result[n][c_pos] = 0;
		c_pos = 0;
		str_pos++;
		n++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count_strs;

	if (!s)
		return (0);
	count_strs = str_count((char *)s, c);
	result = (char **)malloc((count_strs + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	if (count_strs == 0)
	{
		result[0] = 0;
		return (result);
	}
	result = write_lines(result, s, count_strs, c);
	result[count_strs] = 0;
	return (result);
}
