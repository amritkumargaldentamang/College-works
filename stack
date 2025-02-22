//Implementation of stack as an ADT
#include<stdio.h>

#include<stdlib.h>

#define MAXSIZE 10 //Macro and a preprocessor(firstly processed
typedef struct stack
{
	int top;
	int items[MAXSIZE];
} STACK;

void createStack(STACK *st)//can also be initStack 
{
	st->top = -1;
	printf("Stack initialized sucessfully\n");
}
int isFull(STACK *st)
{
	if(st->top == MAXSIZE-1)
	{
		printf("Stack overflow, can't push\n");
		return 1;
	}
	return 0;
}
int isEmpty(STACK *st)
{
	if(st->top == -1)
	{
		printf("Stack empty, can't pop\n");
		return 1;
	}
	return 0;
}
void pop(STACK *st)
{
	int x;
	if(!isEmpty(st)){
		x = st->items[st->top];
		st->top -= 1;
		printf("Item %d popped from the stack\n",x);
	}	
}
int peek(STACK *st)
{	
	if(!isEmpty(st)){
		int topItem = st->items[st->top];
		return (topItem);
	}
}
void push(STACK *st, int x)
{
	if(!isFull(st)){
		///increment top
	st->top += 1;
	st->items[st->top] = x;
	printf("Item %d pushed into stack\n",x);
	}
	
}

void main()
{
	int item, choice;
	STACK *st = (STACK *)malloc(sizeof(STACK));
    if (st == NULL) {
        printf("Memory allocation failed.\n");
        exit(-1);
    }
	
	//menu driven application
	Start:
	printf("MENU\n1. Create Stack\n2. Push Item\n3. Pop item\n4. Peek\n5. Exit\nEnter your choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			createStack(st);
			system("pause");
			system("cls");
			break;
		case 2:
			printf("Enter the item to push:");
			scanf("%d",&item);
			push(st, item);
			system("pause");
			system("cls");
			break;
		case 3:
			pop(st);
			system("pause");
			system("cls");
			break;
		case 4:
			printf("The top item is: %d\n",peek(st));
			system("pause");
			system("cls");
			break;
		case 5:
			free(st);
			exit(0);
		default:
			printf("Invalid input.");
	}
	goto Start;
	
}
