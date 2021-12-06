/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:15:16 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/06 16:01:10 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char	*ft_strjoin(char	*s1, char	*s2);
char	*get_next_line(int fd);
char	*ft_strchr(const char	*str, int c);
size_t	ft_strlen(const char *str);
void	ft_strncpy(char *dest, char *src, int size);

#endif
