/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:47:54 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/08 15:47:56 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_memory(char **ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

static char	**ft_splitfnorm(size_t size, size_t len, char *str, char **r)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i])
			break ;
		i++;
	}
	while (size--)
	{
		r[j] = ft_strdup(str + i++);
		if (!(r[j]))
			return (free_memory(r, j));
		j++;
		while (i < len)
		{
			if (!(str[i - 1]) && str[i])
				break ;
			i++;
		}
	}
	return (r);
}

static size_t	ft_strcountnull(char *str, char c, size_t len)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (i < len)
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || !str[i + 1])
				size++;
		}
		else
			str[i] = '\0';
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	len;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	size = ft_strcountnull(str, c, len);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
	{
		free(str);
		return (NULL);
	}
	result = ft_splitfnorm(size, len, str, result);
	free(str);
	if (!result)
		return (NULL);
	result[size] = NULL;
	return (result);
}

// static char	**free_array(char **ptr, int i)
// {
// 	while (i > 0)
// 	{
// 		i--;
// 		free(ptr[i]);
// 	}
// 	free(ptr);
// 	return (0);
// }

// static int	count_words(char const *string, char c)
// {
// 	int	count;
// 	int	inword;

// 	count = 0;
// 	inword = 0;
// 	while (*string != '\0')
// 	{
// 		if (*string == c)
// 			inword = 0;
// 		else if (inword == 0)
// 		{
// 			inword = 1;
// 			count++;
// 		}
// 		string++;
// 	}
// 	return (count);
// }

// static char	*putword(char *word, char const *s, int i, int word_len)
// {
// 	while (word_len > 0)
// 	{
// 		*word = s[i - word_len];
// 		word++;
// 		word_len--;
// 	}
// 	*word = '\0';
// 	return (word);
// }

// static char	**ft_split_words(char const *s, char c, char **s2, 
//												int num_words)
// {
// 	int	i;
// 	int	word;
// 	int	word_len;

// 	i = 0;
// 	word = 0;
// 	word_len = 0;
// 	while (word < num_words)
// 	{
// 		while (s[i] != '\0' && s[i] == c)
// 			i++;
// 		while (s[i] != '\0' && s[i] != c)
// 		{
// 			i++;
// 			word_len++;
// 		}
// 		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
// 		if (s2 == NULL)
// 			return (free_array(s2, word));
// 		putword(s2[word], s, i, word_len);
// 		word_len = 0;
// 		word++;
// 	}
// 	s2[word] = 0;
// 	return (s2);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char			**s2;
// 	unsigned int	num_words;

// 	if (s == NULL)
// 		return (0);
// 	num_words = count_words(s, c);
// 	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
// 	if (s2 == NULL)
// 		return (0);
// 	s2 = ft_split_words(s, c, s2, num_words);
// 	return (s2);
// }