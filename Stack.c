#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Stack {
    unsigned top;
    unsigned size;
    int* arr;
};

struct Stack* create(unsigned size)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->arr = (int*)malloc(stack->size * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->size - 1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == (int)-1;
}

void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->arr[++stack->top] = item;
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return -1;
	return stack->arr[stack->top--];
}

int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->arr[stack->top];
}

int postfix_evaluator(const char** str_arr, int arr_size)
{
	struct Stack* stack = create(arr_size);
	for (int i = 0; i < arr_size; i++)
	{
		int first = 0;
		int second = 0;
		if (strcmp(str_arr[i], "+") == 0) // Değişiklik: strcmp kullanarak karşılaştırma yapın
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, first + second);
		}
		else if (strcmp(str_arr[i], "-") == 0) // Değişiklik: strcmp kullanarak karşılaştırma yapın
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, second - first);
		}
		else if (strcmp(str_arr[i], "*") == 0) // Değişiklik: strcmp kullanarak karşılaştırma yapın
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, first * second);
		}
		else if (strcmp(str_arr[i], "/") == 0) // Değişiklik: strcmp kullanarak karşılaştırma yapın
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, second / first);
		}
		else if (strcmp(str_arr[i], "==") == 0) // Değişiklik: strcmp kullanarak karşılaştırma yapın
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, first == second);
		}
		else
		{
			push(stack, atoi(str_arr[i]));
		}
	}
	return stack->arr[0];
}

int main()
{
	const char* postfix_expr[] = {"30", "10", "20", "+", "-"};
	int postfix_size = sizeof(postfix_expr) / sizeof(postfix_expr[0]);
	int result = postfix_evaluator(postfix_expr, postfix_size);
	printf("Result: %d\n", result);

	struct Stack* stack = create(100);
	push(stack, 30);
	push(stack, 10);
	push(stack, 20);
	printf("%d popped\n", pop(stack));
	printf("%d popped\n", pop(stack));
	(isEmpty(stack) == -1) ? printf("Empty") : printf("Not Empty");

	return 0;
}
