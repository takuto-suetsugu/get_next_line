/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:28:21 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/11 22:59:14 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_search_breakpoint(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_build_line(char *save)
{
	ssize_t len_break;
	char *new_line;

	len_break = 0;
	if (!save)
		return (0);
	while (save[len_break] && save[len_break] != '\n')
		len_break++;
	new_line = ft_strdup(save, len_break);
	return (new_line);
}

char	*ft_build_save(char *save)
{
	char		*new_save;
	ssize_t len_break;

	len_break = 0;
	if (!save)
		return(NULL);
	while (save[len_break] && save[len_break] != '\n')
		len_break++;
	if (!save[len_break])
	{
		free(save);
		return (0);
	}
	new_save = ft_strdup(save + len_break + 1, ft_strlen(save) - len_break);
	free(save);
	return (new_save);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		input_len;
	char		*buff;
	static char	*save;

	input_len = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || buff == NULL)
		return (-1);
	while (input_len != 0 && !ft_search_breakpoint(save))
	{
		input_len = read(fd, buff, BUFFER_SIZE);
		if (input_len == -1)
		{
			free(buff);
			return (-1);
		}
		buff[input_len] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = ft_build_line(save);
	save = ft_build_save(save);
	if (input_len != 0)
		return (1);
	return (0);
}
