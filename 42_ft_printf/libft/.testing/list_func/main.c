/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/16 09:30:58 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../libft.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void	ft_lstdelcont(void *content, size_t content_size);
t_list	*mult2(t_list *node);
void	show_int(t_list *elem);

int	main(void)
{
/*
	t_lisst *head;
	char *str = "abcdefg0000";
	head = ft_lstnew(str, ft_strlen(str) + 1);
	printf("--- STRING ---\n%s\n%lu\n\n", head->content, head->content_size);

	t_list *head2;
	char *str2 = NULL;
    head2 = ft_lstnew(str2, 4);
    printf("--- NULL ---\n%s\n%lu\n\n", head2->content, head2->content_size);

	t_list *head3;
	int a = 42;
	head3 = ft_lstnew(&a, sizeof(a));
	printf("--- INT ---\n%i\n%lu\n\n", *((int *)head3->content), head3->content_size);
*/
	int i = 0;
	t_list *head4;
	t_list *temp;
	head4 = ft_lstnew(&i, sizeof(int));
	i++;
	while (i < 5)
	{
		temp = ft_lstnew(&i, sizeof(int));
		//ft_lstadd(&head4, temp);
		ft_lstadd_back(&head4, temp);
		i++;
	}
	/*
	while (head4)
	{
		ft_lstiter(head4, &show_int);
		printf("\tList length: %lu\n", ft_lstlen(head4));
		//ft_lstdel_back(&head4);
		//ft_lstdel_front(&head4);
	}
	*/
		//ft_lstdel_back(head4);
		//ft_lstiter(head4, &show_int);

	ft_lstiter(head4, &show_int);
	ft_putchar('\n');
	t_list *head_dup;
	head_dup = ft_lstmap(head4, &mult2);
	ft_lstiter(head_dup, &show_int);

    ft_putchar('\n');
    ft_lstiter(head4, &show_int);
    ft_putchar('\n');
	//ft_lstdelone(&head4, *ft_lstdelcont);
    //printf("--- DELONE ---\n%i\n%lu\n\n", *((int *)head4->content), head4->content_size);
	
    //ft_lstdel(&head3, &ft_lstdelcont);
    //printf("--- LSTDEL ---\n%i\n%lu\n\n", *((int *)head3->content), head3->content_size);
	

	

	return (0);
}

t_list *mult2(t_list *node)
{

	(*((int *)(node->content))) = 2 * (*((int *)(node->content)));
	return (node);
}

void show_int(t_list *elem)
{
	ft_putnbr(*((int *)(elem->content)));
	ft_putchar(' ');
}

void ft_lstdelcont(void *content, size_t content_size)
{
	if (content)
	{
		free(content);
		content = NULL;
		content_size = 0;
	}
}
