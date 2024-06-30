/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:23:51 by jichompo          #+#    #+#             */
/*   Updated: 2024/03/14 15:55:59 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

static char	*ft_find_newline(int fd, char *file_read)
{
	char	*buff;
	int		num_read;

	if (!file_read)
		file_read = ft_calloc(1, sizeof(char));
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (free(file_read), ((void *)0));
	num_read = 1;
	while (num_read > 0)
	{
		num_read = read(fd, buff, BUFFER_SIZE);
		if (num_read == 0)
			break ;
		if (num_read == -1)
			return (free(buff), free(file_read), ((void *)0));
		buff[num_read] = '\0';
		file_read = ft_free_strjoin(file_read, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (file_read);
}

static char	*ft_remove_remain(char *file_read)
{
	char	*result;
	int		index;

	index = 0;
	if (!file_read[index])
		return ((void *)0);
	while (file_read[index] && file_read[index] != '\n')
		index++;
	result = ft_calloc(index + 2, sizeof(char));
	if (!result)
		return ((void *)0);
	index = 0;
	while (file_read[index] && file_read[index] != '\n')
	{
		result[index] = file_read[index];
		index++;
	}
	if (file_read[index] && file_read[index] == '\n')
	{
		result[index] = file_read[index];
		index++;
	}
	return (result);
}

static char	*ft_get_remain(char *file_read)
{
	char	*result;
	int		index;
	int		result_index;

	index = 0;
	while (file_read[index] && file_read[index] != '\n')
		index++;
	if (!file_read[index])
		return (free(file_read), ((void *)0));
	result = ft_calloc(sizeof(char), ft_strlen(file_read) - index + 1);
	if (!result)
		return (free(file_read), ((void *)0));
	index++;
	result_index = 0;
	while (file_read[index])
	{
		result[result_index] = file_read[index];
		index++;
		result_index++;
	}
	free(file_read);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*file_read;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	file_read = ft_find_newline(fd, file_read);
	if (!file_read)
		return ((void *)0);
	current_line = ft_remove_remain(file_read);
	file_read = ft_get_remain(file_read);
	return (current_line);
}
