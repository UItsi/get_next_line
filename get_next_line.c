/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:05:05 by tturto            #+#    #+#             */
/*   Updated: 2022/01/06 09:02:13 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_rowcontent(char *arr)
{
	int		len;
	char	*row;
	int		i;

	len = 0;
	while (arr[len] != '\0')
		len++;
	row = (char *)malloc(sizeof(char) * len + 1);
	if (!row)
		return (NULL);
	i = 0;
	while (arr[i] != '\0')
	{
		row[i] = arr[i];
		i++;
	}
	row[i] = '\0';
	return (row);
}

static int	ft_strrow(int fd, char **line, char **arr)
{
	char	*temp;
	int		rowlen;

	rowlen = 0;
	while (arr[fd][rowlen] != '\n' && arr[fd][rowlen] != '\0')
		rowlen++;
	if (arr[fd][rowlen] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, rowlen);
		temp = ft_rowcontent(arr[fd] + rowlen + 1);
		free(arr[fd]);
		arr[fd] = temp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else
	{
		*line = ft_rowcontent(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

static void	ft_buf_to_arr(char **arr, int fd, char *buf)
{
	char		*temp;

	temp = NULL;
	if (!arr[fd])
		arr[fd] = ft_strnew(1);
	temp = ft_strjoin(arr[fd], buf);
	free(arr[fd]);
	arr[fd] = temp;
}

int	get_next_line(const int fd, char **line)
{
	int			file;
	char		buf[BUFF_SIZE + 1];
	static char	*arr[1];

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while (line)
	{
		file = read(fd, buf, BUFF_SIZE);
		if (file == -1)
			return (-1);
		if (file > 0)
		{
			buf[file] = '\0';
			ft_buf_to_arr(arr, fd, buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
		else
			break ;
	}
	if (arr[fd] == '\0')
		return (0);
	return (ft_strrow(fd, line, arr));
}
