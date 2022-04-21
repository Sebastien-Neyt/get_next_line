/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:18:02 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/21 09:57:37 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

buffer in stack
buffer_size + 1

/* FUNCTION 1
 * get next line function wich takes the fd. (int fd)
 * static variable
 * condition that checks if fd, BUFFER_SIZE and read works
 * we set our static variable equal to the resulf of the read_file
 * if this static variable 
 * 
 * 
 *
 * FUNCTION 2
 * create function that reads into our buffer. (char *buffer, fd)
 * checks if buffer exists. If it doesn't we ft_calloc(1, 1) it.
 * We have a new variable buffer2. we malloc the size of BUFFER_SIZE + 1
 * we use another variable wich is = 1.
 * loop -> variable > 0;
 * byte_read = read(fd, buffer, BUFFER_SIZE)
 * if byte_read == -1 we want to free buffer and retrun null
 * buffer2[byte_read] = 0; ( this is to prevent the end from leaking)
 * buffer = func3(buffer, buffer2)
 * condition that stops when \n is found. (strchr(buffer, \n) - break;
 * free buffer2
 * return result.
 *
 * FUNCTION 3
 * function that joins buffer, buffer2 inside a temp.
 * then frees buffer and returns temp.
 
