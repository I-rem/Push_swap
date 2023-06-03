#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node

typedef struct s_stack
{
    t_node *top;
} t_stack

void swap(t_stack *stack);
void push(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
#endif
