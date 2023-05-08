#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int *data;
    int size;
} t_stack;

void sa(t_stack *a)
{
    if (a->size >= 2)
    {
        int tmp = a->data[0];
        a->data[0] = a->data[1];
        a->data[1] = tmp;
    }
}

void pa(t_stack *a, t_stack *b)
{
    if (b->size >= 1)
    {
        for (int i = a->size; i > 0; i--)
            a->data[i] = a->data[i - 1];
        a->data[0] = b->data[0];
        a->size++;
        for (int i = 0; i < b->size - 1; i++)
            b->data[i] = b->data[i + 1];
        b->size--;
    }
}

void pb(t_stack *a, t_stack *b)
{
    if (a->size >= 1)
    {
        for (int i = b->size; i > 0; i--)
            b->data[i] = b->data[i - 1];
        b->data[0] = a->data[0];
        b->size++;
        for (int i = 0; i < a->size - 1; i++)
            a->data[i] = a->data[i + 1];
        a->size--;
    }
}

void ra(t_stack *a)
{
    if (a->size >= 2)
    {
        int tmp = a->data[0];
        for (int i = 0; i < a->size - 1; i++)
            a->data[i] = a->data[i + 1];
        a->data[a->size - 1] = tmp;
    }
}

void rra(t_stack *a)
{
    if (a->size >= 2)
    {
        int tmp = a->data[a->size - 1];
        for (int i = a->size - 1; i > 0; i--)
            a->data[i] = a->data[i - 1];
        a->data[0] = tmp;
    }
}

int get_pivot(int *array, int size)
{
    // select a pivot element (e.g. the middle element)
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
    {{
    if (array[i] < pivot)
    {
        left_array[j] = array[i];
        j++;
    }
    else if (array[i] > pivot)
    {
        right_array[k] = array[i];
        k++;
    }
}

// sort the left and right partitions recursively
quick_sort(left_array, left_size);
quick_sort(right_array, right_size);

// merge the sorted partitions back into the original array
j = 0, k = 0;
for (int i = 0; i < size; i++)
{
    if (j < left_size && (k >= right_size || left_array[j] < right_array[k]))
    {
        array[i] = left_array[j];
        j++;
    }
    else
    {
        array[i] = right_array[k];
        k++;
    }
}

free(left_array);
free(right_array);
}

int main(int argc, char **argv)
{
t_stack a = {NULL};
t_stack b = {NULL};// Parse integer arguments and push onto stack a
for (int i = 1; i < argc; i++)
{
    int value = atoi(argv[i]);
    push(&a, value);
}

// Read instructions from standard input
char *line;
while (get_next_line(STDIN_FILENO, &line) > 0)
{
    // Execute instruction
    if (strcmp(line, "sa") == 0)
    {
        sa(&a);
    }
    else if (strcmp(line, "sb") == 0)
    {
        sa(&b);
    }
    else if (strcmp(line, "ss") == 0)
    {
        sa(&a);
        sa(&b);
    }
    else if (strcmp(line, "pa") == 0)
    {
        pa(&a, &b);
    }
    else if (strcmp(line, "pb") == 0)
    {
        pb(&a, &b);
    }
    else if (strcmp(line, "ra") == 0)
    {
        ra(&a);
    }
    else if (strcmp(line, "rb") == 0)
    {
        ra(&b);
    }
    else if (strcmp(line, "rr") == 0)
    {
        ra(&a);
        ra(&b);
    }
    else if (strcmp(line, "rra") == 0)
    {
        rra(&a);
    }
    else if (strcmp(line, "rrb") == 0)
    {
        rra(&b);
    }
    else if (strcmp(line, "rrr") == 0)
    {
        rra(&a);
        rra(&b);
    }

    free(line);
}

// Sort stack a using quicksort
quick_sort(a.data, a.size);

// Print sorted stack a
for (int i = 0; i < a.size; i++)
{
    printf("%d\n", a.data[i]);
}

// Free memory
free(a.data);
free(b.data);

return 0;
}
