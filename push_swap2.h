#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define MAX_STACK_SIZE 500

typedef struct {
    int data[MAX_STACK_SIZE];
    int size;
} t_stack;

void push(t_stack *stack, int value);
int pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
int is_empty(t_stack *stack);
int get_pivot(int *array, int size);
void quick_sort(int *array, int size);
void push_swap(t_stack *a, t_stack *b);
int is_sorted(t_stack *stack);
void print_stack(t_stack *stack);

#endif
