/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:27:10 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/16 11:27:11 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include "libft.h"

typedef struct		s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

t_btree				*ft_btreenew(void const *content, size_t content_size);
void				ft_btreedelone(t_btree **abtree, void (*del)(void *, size_t));
void				ft_btree_insert(t_btree *root, void *content, size_t size,
										int (*cmp)(void *cont1, void *cont2));
int					ft_btree_find(t_btree *root, void *key,
									int (*cmp)(void *cont1, void *cont2));
void				ft_btree_preorder_print(t_btree *root, void (*p)(void *));

#endif