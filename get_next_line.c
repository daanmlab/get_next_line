/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:56:43 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/16 15:41:40 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

void	buffer_fix(char *nl_pointer, char *buffer)
{
	if (nl_pointer[1] == '\0')
		clean_buffer(buffer);
	else
		ft_strcpy(buffer, nl_pointer + 1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	char		*nl_pointer;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		clean_buffer(buffer);
		return (NULL);
	}
	result = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		nl_pointer = ft_strchr(buffer, '\n');
		result = ft_strjoin(result, buffer);
		if (nl_pointer)
		{
			buffer_fix(nl_pointer, buffer);
			break ;
		}
		else
			clean_buffer(buffer);
	}
	return (result);
}

// #include <fcntl.h>
// int main(void)
// {
//     int fd;
//     char *result;

//     fd = open("multiple_line_w_nl.txt", O_RDONLY);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     return (0);
// }
