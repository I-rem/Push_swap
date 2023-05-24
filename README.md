# Push_swap
Because Swap_push isn’t as natural

## Summary:
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

## Introduction

You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

Your goal is to write 2 programs in C:

• The first, named **checker** which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays **OK** if integers are sorted. Otherwise, it will display **KO**.

• The second one called **push_swap** which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts integer arguments received.

## General Instructions

• The first executable file must be named checker and the second push_swap.

• You must submit a Makefile. That Makefile needs to compile the project and must contain the usual rules. It can only recompile the program if necessary.

• If you are clever, you will use your library for this project, submit also your folder libft including its own Makefile at the root of your repository. Your Makefile will have to compile the library, and then compile your project.

• Global variables are forbidden.

• You have to handle errors in a sensitive manner. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).

• Neither program can have any memory leaks.

• Within your mandatory part you are allowed to use the following functions:

`write` `read` `malloc` `free` `exit`

## Evaluation

### Mandatory part

For the duration of the defence, no segfault, nor other unexpected termination of the program should happen.

#### Author file

Check that the author file is at the root of the repository and formatted as explained.

#### Memory leaks

Pay attention to the amount of memory used by push_swap (using the command top for example). Ensure that no anomalies happen and allocated memory is properly freed.

#### Checker program - Error management

No points will be awarded for this section if at least one check fails.

- Run checker with non numeric parameters. The program must display **"Error"**
- Run checker with a duplicate numeric parameter. The program must display **"Error"**
- Run checker with only numeric parameters including one greater than MAXINT. The program must display **"Error"**
- Run checker without any parameters. The program must display anything and give the prompt back.
- Run checker with valid parameters, and write an action that doesn't exist during the instruction phase. The program must display **"Error"**
- Ruc checker with valid parameters, and write an action with one or several spaces before and/or after the action during the instruction phase. The program must display **"Error"**.

#### Checker program - False tests

Execute the following 2 tests. If at least one fails, no points will be awarded
for this section.

Don't forget to press CTRL+D to stop reading during the infruction phase.

- Run checker with the following command `$>./checker 0 9 1 8 2
7 3 6 4 5` then write the following valid action list
`"[sa, pb, rrr]"`. Checker should display **"KO"**.

- Run checker with a valid list as parameter of your choice then write a valid instruction list that doesn't order the integers.
Checker should display **"KO"**. You'll have to specifically check that the program wasn't developed to only answer correctly
on the test included in this scale. You should repeat this test couple of times with several permutations before you validate it.

#### Checker program - Right tests

In this section, we'll evaluate the checker's ability to manage
a liss of instructions that sort the list. Execute the following 2 tests. If at least one fails, no points will be awarded for this section.

Don't forget to press CTRL+D to stop reading during the instruction phase.

- Run checker with the following command `$>./checker 0 1 2`
then press CTRL+D without writing any instruction. The
program should display **"OK"**.

- Run checker with the following command `$>./checker 0 9 1
8 2` then write the following valid action list `[pb, ra, pb, rq, sq, ra, pa, pa]`. The program should display **"OK"**.

- Run checker with a valid list as parameter of your choice then write a valid instruction list that order the integers.
Checker must display **"OK"**. Repeat this test couple of times with several permutations before you validate it.

#### Push_swap - Identity test

In this section, we'll evaluate push_swap's behavior when
given a list, which has already been sorted. Execute the
following 3 tests. If at least one fails, no points will be
awarded for this section.

- Run the following command `$>./push_swap 42`. The program
should display nothing (O instruction).

- Run the following command `"$>./push_swap 0 1 2 3".` The
program should display nothing (O instruction).

- Run the following command `$>./push_swap 0123456
7 8 9`. The program should display nothing (0 instruction).

#### Push_swap - Simple version

If the following test fails, no points will be awarded
for this section. Move to the next one.

- Run `$>ARG="2 1 0"; ./push_swap $ARG | ./checker $ARG"`.
Check that the checker program displays **OK** and that

the size of the list of instructions from push_swap is

2 OR 3. Otherwise the test fails.

#### Another simple version

Execute the following 2 tests. If at least one fails,
no points will be awarded for this section. Move to
the next one.

- Run `$>ARG="1 52 4 3"; ./push_swap $ARG | ./checker
$ARG`. Check that the checker program displays "OK" and that the size of the list of instructions from
push_swap isn't more than 12. Kudos if the size of
the list of instructions is 8.

- Run `$>ARG="<5 random values>"; ./push_swap $ARG |
./ checker $ARG` and replace the placeholder by 5 random
valid values. Check that the checker program displays
"OK" and that the size of the list of instructions
from push_swap isn't more than 12. Otherwise this test
fails. You'll have to specifically check that the program
wasn't developed to only answer correctly on the test
included in this scale. You should repeat this test
couple of times with several permutations before you
validate it.

#### Push_swap - Middle version

If the following test fails, no points will be awarded
for this section. Move to the next one.

- Run `$>ARG="<100 random values>"; ./push_swap $ARG |
./ checker $ARG`. and replace the placeholder by 100 random
valid values. Check that the checker program displays
"OK" and then give a grade based on the size of the list
of instructions:

- Less than 700: 5
- Less than 900: 4
- Less than 1100: 3
- Less than 1300: 2
- Less than 1500: 1

You should repeat this test couple of times with several permutations before you validate it.

Rate it from O (failed) through 5 (excellent)

#### Push_swap - Advanced version

If the following test fails, no points will be awarded
for this section.

- Run `$>ARG="<500 random values>"; ./push_swap $ARG |
./ checker $ARG` and replace the placeholder by 500
random valid values. Check that the checker program displays **"OK"**
and then give a grade based on the size of the list
of instructions:

- Less than 5500: 5
- Less than 7000: 4
- Less than 8500: 3
- Less than 10000: 2
- Less than 11500: 1

Otherwise this test fails.

You should repeat this test couple of times with several permutations before you validate it.

Rate it from O (failed) through 5 (excellent)

