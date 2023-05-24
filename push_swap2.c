#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void push(t_stack *stack, int value) {
    if (stack->size >= MAX_STACK_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(1);
    }
    stack->data[stack->size++] = value;
}

int pop(t_stack *stack) {
    if (stack->size <= 0) {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(1);
    }
    return stack->data[--stack->size];
}

void swap(t_stack *stack) {
    if (stack->size >= 2) {
        int temp = stack->data[stack->size - 1];
        stack->data[stack->size - 1] = stack->data[stack->size - 2];
        stack->data[stack->size - 2] = temp;
    }
}

void rotate(t_stack *stack) {
    if (stack->size >= 2) {
        int temp = stack->data[stack->size - 1];
        for (int i = stack->size - 1; i > 0; i--) {
            stack->data[i] = stack->data[i - 1];
        }
        stack->data[0] = temp;
    }
}

void reverse_rotate(t_stack *stack) {
    if (stack->size >= 2) {
        int temp = stack->data[0];
        for (int i = 0; i < stack->size - 1; i++) {
            stack->data[i] = stack->data[i + 1];
        }
        stack->data[stack->size - 1] = temp;
    }
}

int is_empty(t_stack *stack) {
    return stack->size == 0;
}

int get_pivot(int *array, int size) {
    int pivot_index = size / 2;
    return array[pivot_index];
}

void quick_sort(int *array, int size)
{
    if (size <= 1)
        return;

    int pivot = get_pivot(array, size);
    int left_size = 0, right_size = 0;

    // partition the array around the pivot
    for (int i = 0; i < size; i++)
    {
        if (array[i] < pivot)
            left_size++;
        else if (array[i] > pivot)
            right_size++;
    }

    int *left_array = malloc(left_size * sizeof(int));
    int *right_array = malloc(right_size * sizeof(int));

    int j = 0, k = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < pivot)
            left_array[j++] = array[i];
        else if (array[i] > pivot)
            right_array[k++] = array[i];
    }

    // recursively sort the left and right arrays
    quick_sort(left_array, left_size);
    quick_sort(right_array, right_size);

    // merge the sorted arrays back into the original array
    int index = 0;
    for (int i = 0; i < left_size; i++)
        array[index++] = left_array[i];
    array[index++] = pivot;
    for (int i = 0; i < right_size; i++)
        array[index++] = right_array[i];

    free(left_array);
    free(right_array);
}


int is_sorted(t_stack *stack) {
    for (int i = 1; i < stack->size; i++) {
        if (stack->data[i] < stack->data[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void print_stack(t_stack *stack) {
    for (int i = 0; i < stack->size; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void push_swap(t_stack *a, t_stack *b) {
    if (is_sorted(a)) {
        return;
    }

    if (a->size <= 3) {
        // Sort small stacks manually
        if (a->size == 2) {
            if (a->data[0] > a->data[1]) {
                swap(a);
                printf("sa\n");
            }
        } else if (a->size == 3) {
            if (a->data[0] > a->data[1] && a->data[0] < a->data[2]) {
                swap(a);
                printf("sa\n");
            } else if (a->data[0] > a->data[1] && a->data[1] > a->data[2]) {
                swap(a);
                reverse_rotate(a);
                printf("sa\nrra\n");
            } else if (a->data[0] < a->data[1] && a->data[0] > a->data[2]) {
                rotate(a);
                printf("ra\n");
            } else if (a->data[0] < a->data[1] && a->data[1] > a->data[2] && a->data[0] < a->data[2]) {
                reverse_rotate(a);
                printf("rra\n");
            } else if (a->data[0] > a->data[1] && a->data[1] < a->data[2] && a->data[0] < a->data[2]) {
                swap(a);
                rotate(a);
                printf("sa\nra\n");
            }
        }
    } else {
        // Sort larger stacks using quicksort
        int *array = malloc(a->size * sizeof(int));
        for (int i = 0; i < a->size; i++) {
            array[i] = a->data[i];
        }

        quick_sort(array, a->size);

        int pivot_index = a->size / 2;
        int pivot = array[pivot_index];

        int i = 0;
        while (a->data[0] != pivot) {
            if (a->data[0] < pivot) {
                push(b, pop(a));
                printf("pb\n");
            } else {
                rotate(a);
                printf("ra\n");
            }
        }

        int j = 0;
        while (!is_empty(b)) {
            if (b->data[0] < pivot) {
                push(a, pop(b));
                printf("pa\n");
                if (i > 0) {
                    rotate(a);
                    printf("ra\n");
                }
                i++;
            } else {
                push(b, pop(b));
                printf("rb\n");
                if (j > 0) {
                    rotate(b);
                    printf("rb\n");
                }
                j++;
            }
        }

        free(array);

        // Recursively sort remaining elements
        push_swap(a, b);
    }
}

int main(int argc, char *argv[]) {
    t_stack stack_a;
    t_stack stack_b;
    stack_a.size = 0;
    stack_b.size = 0;

    // Read command-line arguments and push them to stack a
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push(&stack_a, value);
    }

    push_swap(&stack_a, &stack_b);

    return 0;
}
