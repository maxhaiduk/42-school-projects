/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:43:54 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/12/04 11:19:20 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>

# include "../libft/libft.h"

t_list	*read_file(char *filename);

#endif
