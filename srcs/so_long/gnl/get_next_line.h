/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:16:10 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/23 15:00:32 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*get_next_line_sl(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2, int i);
size_t	ft_strlen_gnl(const char *s);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_calloc_gnl(size_t size);

#endif
