/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:54:48 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/12 15:54:11 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str != NULL && *str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strndup(char *s1, ssize_t s1_len)
{
	char	*cpy_s1;
	ssize_t		i;

	cpy_s1 = malloc(sizeof(char) * (s1_len + 1));
	if (cpy_s1 == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		cpy_s1[i] = s1[i];
		i++;
	}
	cpy_s1[i] = '\0';
	return (cpy_s1);
}

char	*ft_strjoin(char *save, char *buff)
{
	char	*connected_s;
	size_t		i;
	size_t		j;

	if (save == NULL && buff == NULL)
		return (NULL);
	connected_s = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buff) + 1));
	if (connected_s == NULL)
		return (NULL);
	i = 0;
	while (save && save[i])
	{
		connected_s[i] = save[i];
		i++;
	}
	j = 0;
	while (buff && buff[j])
	{
		connected_s[i] = buff[j];
		i++;
		j++;
	}
	connected_s[i] = '\0';
	free(save);
	return (connected_s);
}
