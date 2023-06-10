#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{ 
	int			content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
//void	ft_lstdelone(t_list *lst, void (*del)(void *));
//void	ft_lstclear(t_list **lst, void (*del)(void *));
void    little_sort(t_list *lst, t_list **lst_b, int argc);
void    swap(t_list **stack, char mode);
void    push(t_list **src_stack, t_list **dst_stack, char mode);
void    rotate(t_list **stack, char mode);
void    reverse_rotate(t_list **stack, char mode);
#endif

