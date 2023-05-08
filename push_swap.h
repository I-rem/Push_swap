typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

void push(t_stack *stack, int value);
int pop(t_stack *stack);
int peek(t_stack *stack);
int is_sorted(t_stack *stack);
