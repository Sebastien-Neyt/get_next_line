/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:18:02 by sneyt             #+#    #+#             */
/*   Updated: 2022/05/10 09:15:25 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int	fd)
{
	static t_list   *stash;
    char            *line;

    stash = NULL;
    if ( BUFFER_SIZE <= 0 || fd < 0 || read(fd, &line, 0) < 0)
        return (NULL);
    line = NULL;
    // 1. read from fd and add to linked list
    read_and_stash(fd, &stash);
    if (stash == NULL)
        return (NULL);
    // 2. extract stash to line
    extract_line(stash, &line);
    // 3. clean up the stash
    clean_stash(&stash);
    if (line[0] =='\0')
    {
        free_stash(stash);
        stash = NULL;
        free(line);
        return (NULL);
    }
    return (line);
}

// uses read() to add characters to the stash

void	read_and_stash(int fd, t_list **stash)
{
    char    *buff;
    int     succes;

    succes = 1;    
    while(succes != 0 && !found_newline(*stash))
    {
        buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (buff == NULL)
            return;
        succes = (int)read(fd, buff, BUFFER_SIZE);
        if ((*stash == NULL && succes == 0) || succes == -1)
        {
            free(buff);
            return;
        }
        buff[succes] = '\0';
        add_to_stash(stash, buff, succes);
        free(buff);
    }
}

// Adds the content of our buffer to the end of our stash

void	add_to_stash(t_list **stash, char *buff, int succes)
{
    int i;
    t_list  *last;
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->content = malloc(sizeof(char) * (succes + 1));
    if (new_node->content == NULL)
        return;
    i = 0;
    while (buff[i] && i < succes)
    {
        new_node->content[i] = buff[i];
        i++;
    }
    new_node->content[i] = '\0';
    if (*stash == NULL)
    {
        *stash = new_node;
        return;
    }
    last = ft_lst_get_last(*stash);
    last->next = new_node;
}

//extract all characters from our stash and stores then in our line.
//stopping after the first \n ir encounters or EOF?

void	extract_line(t_list *stash, char **line)
{
    int i;
    int j;

    if (stash == NULL)
        return;
    generate_line(line, stash);
    if (*line == NULL)
        return;
    j = 0;
    while (stash)
    {
        i = 0;
        while (stash ->content[i])
        {
            if (stash->content[i] == '\n')
            {
                (*line)[j++] = stash->content[i];
                break;
            }
            (*line)[j++] = stash->content[i];
        }
        stash = stash->next;
    }
    (*line)[j] = '\0';
}

// After extracting the line that was read, we don't need those characters anymore.
// this function clears the stash so only the characters that have not been returned at 
// the end of the get_next_line() remain in our static stash

void	clean_stash(t_list **stash)
{
    t_list  *last;
    t_list  *clean_node;
    int i;
    int j;

    if (stash == NULL)
        return;
    clean_node = malloc(sizeof(t_list));
    if (clean_node == NULL)
        return;
    clean_node->next = NULL;
    last = ft_lst_get_last(*stash);
    i = 0;
    while (last->content[i] && last->content[i] != '\n')
        i++;
    if (last->content && last->content[i] == '\n')
        i++;
    clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
    if (clean_node->content == NULL)
        return;
    j = 0;
    while (last->content[i])
        clean_node->content[j++] = last->content[i++];
    clean_node->content[j] = '\0';
    free_stash(*stash);
    *stash = clean_node;
}
