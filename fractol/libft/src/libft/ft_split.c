/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:00:11 by jichompo          #+#    #+#             */
/*   Updated: 2024/05/24 01:43:26 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **result)
{
	int	index;

	index = 0;
	while (result[index])
	{
		free(result[index]);
		index++;
	}
	free(result);
}

static	size_t	count_words(char const *s, char c)
{
	size_t	index;
	size_t	words;

	index = 0;
	words = 0;
	while (s[index])
	{
		if ((s[index + 1] == c || s[index + 1] == '\0') && s[index] != c)
			words++;
		index++;
	}
	return (words);
}

static	char	**write_result(char const *s, char c, char	**result)
{
	size_t	start;
	size_t	index;
	size_t	word;

	start = 0;
	index = 0;
	word = 0;
	while (s[index])
	{
		if ((s[index + 1] == c || s[index + 1] == '\0') && s[index] != c)
		{
			result[word] = ft_substr(s, start, index - start + 1);
			if (!result[word])
			{
				ft_free(result);
				return (0);
			}
			word++;
		}
		if (s[index] == c && (s[index + 1] != c || s[index + 1] != '\0'))
			start = index + 1;
		index++;
	}
	result[word] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (0);
	result = write_result(s, c, result);
	return (result);
}
