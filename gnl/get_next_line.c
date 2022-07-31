/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:24:37 by flazerak          #+#    #+#             */
/*   Updated: 2022/01/12 17:24:37 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *save)
{
	int		nb_read;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == 0)
			break ;
		if (nb_read < 0)
		{
			free (buff);
			return (NULL);
		}
		buff[nb_read] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save || !save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_malloc(char *save, int i)
{
	char	*s;

	s = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_cut(char *save)
{
	int		i;
	int		j;
	char	*s;

	if (BUFFER_SIZE == 1)
	{
		free (save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	s = ft_malloc(save, i);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(save, '\n'))
		save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = ft_cut(save);
	return (line);
}
