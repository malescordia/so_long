/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:52:58 by gude-cas          #+#    #+#             */
/*   Updated: 2023/05/15 16:05:19 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*new_content(char *content);
char	*extract_line(char *content);
char	*update_content(char *content, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);

#endif
