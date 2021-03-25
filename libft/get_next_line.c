/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:59:28 by alafranc          #+#    #+#             */
/*   Updated: 2021/03/24 15:55:26 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_first_line(char *file)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (file == NULL)
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	if (!(ft_nalloc(&buf, sizeof(char), ft_strlen(file) - i + 1)))
		return (NULL);
	while (file[i])
		buf[j++] = file[i++];
	buf[j] = '\0';
	free(file);
	return (buf);
}

static int	ft_read_gnl(int *b_read, int fd, char *buf)
{
	*b_read = read(fd, buf, BUFFER_SIZE);
	return (*b_read);
}

char	*fill_filebuf(int fd, char *filebuf, int *b_read, int *eof)
{
	char		buf[BUFFER_SIZE + 1];

	if (ft_strchr_gnl(filebuf, '\n') >= 0 || (fd == 0 && filebuf != NULL))
		return (filebuf);
	while (ft_read_gnl(b_read, fd, buf) > 0)
	{
		buf[*b_read] = '\0';
		filebuf = ft_strjoin_free(filebuf, buf);
		if (fd != 0 && ft_strchr_gnl(filebuf, '\n') != -1)
			break ;
	}
	if (*b_read == 0)
		*eof = 1;
	return (filebuf);
}

int	get_next_line(int fd, char **line)
{
	int			b_read;
	static char	*filebuf[4096];
	int			eof;

	eof = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || !line)
		return (-1);
	filebuf[fd] = fill_filebuf(fd, filebuf[fd], &b_read, &eof);
	*line = ft_substr_line(filebuf[fd]);
	filebuf[fd] = ft_remove_first_line(filebuf[fd]);
	if (filebuf[fd] == NULL || (eof && filebuf[fd][0] == '\0'))
		return (0);
	else
		return (1);
}
