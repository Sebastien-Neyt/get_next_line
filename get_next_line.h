/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:18:08 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/20 12:18:10 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
    char            *content;
    struct s_list   *next;
}   t_list;


char    *get_next_line(int fd);
void    read_and_stash(int fd, t_list **stash);
void    add_to_stash(t_list **stash, char *buff, int succes);
void    extract_line(t_list *stash, char **line);
void    clean_stash(t_list **stash);

int     found_newline(t_list *stash);
t_list  *ft_lst_get_last(t_list *stash);
void    generate_line(char **line, t_list *stash);
void    free_stash(t_list *stash);
int     ft_strlen(const char *str);

#endif
