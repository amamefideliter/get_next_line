/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:01:37 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/24 17:32:11 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->content);
		free(current);
		current = next_node;
	}
}

void	ft_add_new(t_list **lst, void *content)
{
	t_list	*copy;
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free_list(*lst);
		return ;
	}
	new_node->content = content;
	new_node->next = NULL;
	copy = *lst;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	while (copy && copy->next)
	{
		copy = copy->next;
	}
	last_node = copy;
	last_node->next = new_node;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;
	void		*res;

	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (const char *)src;
	res = cdest;
	while (n--)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}
