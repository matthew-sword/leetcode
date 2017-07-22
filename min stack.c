#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int* stack;
    int* min_stack;
    int top;
    int min_top;
    int max_size;
} MinStack;

//初始化栈
MinStack* minStackCreate(int maxSize);

//入栈
void minStackPush(MinStack* obj, int x);

//出栈
void minStackPop(MinStack* obj);
//top
int minStackTop(MinStack* obj);

//获得最小值
int minStackGetMin(MinStack* obj);

//free
void minStackFree(MinStack* obj);

int main()
{
    //MinStack* mark = (MinStack*)malloc(sizeof(MinStack));

    //minStackCreate(mark);

    return 0;
}

MinStack* minStackCreate(int maxSize)
{
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));

    obj->max_size = maxSize;

    obj->stack = (int*)malloc(sizeof(int)*maxSize);
    obj->min_stack = (int*)malloc(sizeof(int)*maxSize);

    memset(obj->stack, 0, sizeof(int)*maxSize);
    memset(obj->min_stack, 0, sizeof(int)*maxSize);

    obj->top = -1;
    obj->min_top = -1;

    return obj;

    /*stack->max_size = INIT_SIZE;

    stack->stack = (int*)malloc(sizeof(int)*INIT_SIZE);
    memset(stack->stack, 0, INIT_SIZE);
    stack->top = -1;

    stack->min_stack = (int*)malloc(sizeof(int)*INIT_SIZE);
    memset(stack->min_stack, 0, INIT_SIZE);
    stack->min_top = -1;*/

}

void minStackPush(MinStack* obj, int x)
{
    /*if (obj->top+1 >= obj->max_size || obj->min_top+1 >= obj->max_size)
    {
        obj->stack = (int*)realloc(obj->stack,sizeof(int)*stack->max_size*2);
        obj->min_stack = (int*)realloc(stack->min_stack,sizeof(int)*stack->max_size*2);
        stack->max_size *= 2;
    }*/

    obj->top++;
    obj->stack[obj->top] = x;

    if (obj->top == 0 || obj->stack[obj->min_stack[obj->min_top]] > x)
    {
        obj->min_top++;
        obj->min_stack[obj->min_top] = obj->top;
    }
}

void MinStackPop(MinStack* obj)
{
    if (obj->top == -1)
    {
        printf("stack is empty\n");
        return ;
    }

    if (obj->top == obj->min_stack[obj->min_top])
    {
        obj->top --;
        obj->min_top --;
    }
    else
        obj->top --;
}

int MinStackTop(MinStack* obj)
{
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj)
{
    return obj->stack[obj->min_stack[obj->min_top]];
}

void minStackFree(MinStack* obj)
{
    free(obj->stack);
    free(obj->min_stack);
    free(obj);
}