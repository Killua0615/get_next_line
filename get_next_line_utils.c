/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:57:22 by nateshim          #+#    #+#             */
/*   Updated: 2024/11/17 19:43:56 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((ft_strlen(str) + 1));
	if (!ptr)
		return (ptr);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static void	copy_strings(char *dest, char *src, size_t *index)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[*index] = src[i];
		(*index)++;
		i++;
	}
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	len1;
	size_t	len2;
	size_t	index;
	char	*joined;

	if (!str1)
		str1 = ft_strdup("");
	if (!str1 || !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	index = 0;
	copy_strings(joined, str1, &index);
	copy_strings(joined, str2, &index);
	joined[index] = '\0';
	free(str1);
	return (joined);
}
