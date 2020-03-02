#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

t_stack *stack_init(unsigned int max_size);
int stack_push(t_stack *stack, void *data);
void *stack_pop(t_stack *stack);

int main(void)
{
	t_stack *stack = stack_init(5);
	stack_push(stack, "aa");
	stack_push(stack, "b");
	stack_push(stack, "ccc");
	stack_push(stack, "ddddd");
	stack_push(stack, "ee");
	stack_push(stack, "f");

	for (int i = 0; i < 6; i++)
	{
		printf("%s\n", (char *)stack_pop(stack));
	}

	return (0);
}

t_stack *stack_init(unsigned int max_size)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->max_size = max_size;
	stack->top_index = -1;
	stack->data = (void **)malloc(sizeof(void *) * max_size);
	if (stack->data == 0)
	{
		free(stack);
		return (0);
	}
	return (stack);
}

int stack_push(t_stack *stack, void *data)
{
	if (stack == 0 || stack->data == 0 || stack->top_index + 1 >= stack->max_size)
		return (0);
	stack->top_index++;
	stack->data[stack->top_index] = data;
	return (1);
}

void *stack_pop(t_stack *stack)
{
	void *result;

	if (stack == 0 || stack->data == 0 || stack->top_index < 0)
		return (0);
	result = stack->data[stack->top_index];
	stack->data[stack->top_index] = 0;
	stack->top_index--;
	return (result);
}
