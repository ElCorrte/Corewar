/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:37:30 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/23 18:14:12 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	ft_cat_str(char **str, int i)
{
	int	n;

	n = -1;
	while ((*str)[i] && **str)
		((*str)[++n]) = ((*str)[++i]);
}

static int		if_n(char **str, char **line)
{
	int	i;

	i = 0;
	while (**str != '\n')
	{
		(*str)++;
		i++;
	}
	*str -= i;
	*line = ft_strsub(*str, 0, (size_t)i);
	ft_cat_str(str, i);
	return (1);
}

static char		**mult(const int fd, t_mult **current)
{
	t_mult	*c;

	c = *current;
	while (c != NULL)
	{
		if ((c->fd) == fd)
			return (&(c->str));
		c = c->next;
	}
	c = (t_mult *)malloc(sizeof(t_mult));
	c->str = ft_strnew(0);
	c->fd = fd;
	c->next = (*current);
	(*current) = c;
	return (&(c->str));
}

static int		i_know(const int fd, char **buff, char **line, char **str)
{
	char		*tmp;
	ssize_t		t;

	while (((t = read(fd, *buff, BUFF_SIZE)) > 0) || (**str))
	{
		tmp = *str;
		*str = (*str == NULL) ? (ft_strdup(*buff)) : (ft_strjoin(*str, *buff));
		free(tmp);
		ft_strclr(*buff);
		if (ft_strchr(*str, '\n'))
		{
			ft_strdel(buff);
			return (if_n(&(*str), line));
		}
		if ((**str) && !(t))
		{
			ft_strdel(buff);
			*line = ft_strsub(*str, 0, ft_strlen(*str));
			ft_strdel(str);
			return (1);
		}
	}
	if (!(t) && (ft_strlen(*str) == 0))
		return (0);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			*buff;
	static t_mult	*current;
	char			**str;
	int				i;

	if ((BUFF_SIZE <= 0) || (fd == (-1)))
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if ((read(fd, buff, 0)) == (-1))
		return (-1);
	str = mult(fd, &current);
	if (*str == NULL)
	{
		ft_strdel(&buff);
		return (0);
	}
	i = i_know(fd, &buff, line, str);
	return (i);
}
