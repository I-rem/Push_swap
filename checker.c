int main(int argc, char **argv)
{
    t_stack a = {NULL};
    t_stack b = {NULL};

    // Parse integer arguments and push onto stack a
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
            // swap the first 2 elements at the top of stack a
            // Do nothing if there is only one or no elements
        }
        else if (strcmp(line, "sb") == 0)
        {
            // swap the first 2 elements at the top of stack b
            // Do nothing if there is only one or no elements
        }
        else if (strcmp(line, "ss") == 0)
        {
            // sa and sb at the same time
        }
        else if (strcmp(line, "pa") == 0)
        {
            // push the top element of stack b to the top of stack a
            // Do nothing if stack b is empty
        }
        else if (strcmp(line, "pb") == 0)
        {
            // push the top element of stack a to the top of stack b
            // Do nothing if stack a is empty
        }
        else if (strcmp(line, "ra") == 0)
        {
            // shift up all elements of stack a by 1
            // The first element becomes the last one
        }
        else if (strcmp(line, "rb") == 0)
        {
            // shift up all elements of stack b by 1
            // The first element becomes the last one
        }
        else if (strcmp(line, "rr") == 0)
        {
            // ra and rb at the same time
        }
        else if (strcmp(line, "rra") == 0)
        {
            // shift down all elements of stack a by 1
            // The last element becomes the first one
        }
        else if (strcmp(line, "rrb") == 0)
        {
            // shift down all elements of stack b by 1
            // The last element becomes the first one
         }
         else if (strcmp(line, "rrr") == 0)
          {
            // rra and rrb at the same time
            }
            else
            {
            fprintf(stderr, "Error: Invalid instruction: %s\n", line);
            free(line);
            clear_stack(&a);
            clear_stack(&b);
            return 1;
            }
        free(line);
}

  // Check if stack a is sorted and stack b is empty
  if (is_sorted(&a) && is_empty(&b))
  {
      printf("OK\n");
  }
  else
  {
      printf("KO\n");
  }

  clear_stack(&a);
  clear_stack(&b);

  return 0;
