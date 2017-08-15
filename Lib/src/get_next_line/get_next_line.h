/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:38:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/03/23 15:21:22 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define BUFF_SIZE 1

typedef struct			s_mult
{
	char				*str;
	int					fd;
	struct s_mult		*next;
}						t_mult;

int						get_next_line(const int fd, char **line);

#endif
