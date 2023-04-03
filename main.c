/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:41:32 by tturto            #+#    #+#             */
/*   Updated: 2022/01/06 08:43:18 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		ret;

	argc = 2;	
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		printf("%s\n", str);
		free(str);
	}
	close(fd);
	return (0);
}
