/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:51:22 by maru              #+#    #+#             */
/*   Updated: 2022/05/29 17:58:52 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char *s1, char const *s2);

char	*get_next_line(int fd);

char	*read_line(int fd, char *line);

char	*get_whats_left(char *line);

char	*get_filtered_line(char *line);

#endif