/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:57:00 by nateshim          #+#    #+#             */
/*   Updated: 2024/11/15 12:49:12 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int fd;
	char *r;
	int i;

	printf("start program\n");
	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error: I can't open file\n");
		return (1);
	}
	printf("file is open: fd=%d\n===\n", fd);
	while (i++ < 1300)
	{
		r = get_next_line(fd);
		if (r == NULL)
			break ;
		printf("%s", r);
		free(r);
	}
	close(fd);
	return (0);
}