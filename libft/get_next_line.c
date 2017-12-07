/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:14:17 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/07 16:53:56 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_data(t_fd_list *current, char **line)
{
	size_t				l_len;
	size_t				a_len;
	char				*temp;

	l_len = ft_wordlen(current->content, '\n');
	if (!(*line = ft_strsub(current->content, 0, l_len)))
		return (-1);
	a_len = ft_strlen(current->content);
	if (!(temp = ft_strsub(current->content, l_len + 1, a_len - l_len - 1)))
		return (-1);
	free(current->content);
	current->content = temp;
	return (1);
}

static int	join_buff(t_fd_list *current, char *buff)
{
	char				*temp;

	if (!(temp = ft_strjoin(current->content, buff)))
		return (0);
	free(current->content);
	current->content = temp;
	return (1);
}

static int	read_more(int fd, t_fd_list *current, char **line)
{
	int					read_result;
	char				buff[BUFF_SIZE + 1];

	while ((read_result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_result] = '\0';
		if (!(join_buff(current, buff)))
			return (-1);
		if (ft_strchr(current->content, '\n'))
			return (get_data(current, line));
	}
	if (read_result == 0 && current->content[0])
	{
		if (!(join_buff(current, "\n")))
			return (-1);
		return (get_data(current, line));
	}
	return (read_result);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_list	*fd_list;
	t_fd_list			*current;

	current = fd_list;
	while (current && current->fd != fd)
		current = current->next;
	if (!current)
	{
		if (!(current = (t_fd_list *)malloc(sizeof(t_fd_list))))
			return (-1);
		current->fd = fd;
		current->content = ft_strnew(0);
		current->next = fd_list;
		fd_list = current;
	}
	else if (ft_strchr(current->content, '\n'))
		return (get_data(current, line));
	return (read_more(fd, current, line));
}
