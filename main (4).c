#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
Struct Stack
{
Unsigned capacity;
Int top;
Int *array;
};
Struct Stack* createStack(unsigned capacity)
{
Struct Stack* stack =
(struct Stack*) malloc(sizeof(struct Stack));
Stack -> capacity = capacity;
Stack -> top = -1;
Stack -> array =
(int*) malloc(stack -> capacity * sizeof(int));
Return stack;
}
Int isFull(struct Stack* stack)
{
Return (stack->top == stack->capacity – 1);
}
Int isEmpty(struct Stack* stack)
{
Return (stack->top == -1);
}
Void push(struct Stack *stack, int item)
{
If (isFull(stack))
return;
Stack -> array[++stack -> top] = item;
}
Int pop(struct Stack* stack)
{
If (isEmpty(stack))
Return INT_MIN;
Return stack -> array[stack -> top--];
}
Void moveDisk(char fromPeg, char toPeg, int disk)
{
printf(“Move the disk %d from \’%c\’ to \’%c\’\n”,
Disk, fromPeg, toPeg);
}
Void moveDisksBetweenTwoPoles(struct Stack *src,
Struct Stack *dest, char s, char d)
{
Int pole1TopDisk = pop(src);
Int pole2TopDisk = pop(dest);
If (pole1TopDisk == INT_MIN)
{
Push(src, pole2TopDisk);
moveDisk(d, s, pole2TopDisk);
}
Else if (pole2TopDisk == INT_MIN)
{
Push(dest, pole1TopDisk);
moveDisk(s, d, pole1TopDisk);
}
Else if (pole1TopDisk > pole2TopDisk)
{
Push(src, pole1TopDisk);
Push(src, pole2TopDisk);
moveDisk(d, s, pole2TopDisk);
}
Else
{
Push(dest, pole2TopDisk);
Push(dest, pole1TopDisk);
moveDisk(s, d, pole1TopDisk);
}
}
Void tohIterative(int num_of_disks, struct Stack
*src, struct Stack *aux,
Struct Stack *dest)
{
Int I, total_num_of_moves;
Char s = ‘S’, d = ‘D’, a = ‘A’;
If (num_of_disks % 2 == 0)
{
Char temp = d;
D = a;
A = temp;
}
Total_num_of_moves = pow(2, num_of_disks) – 1;
For (I = num_of_disks; I >= 1; i--)
Push(src, i)
For (I = 1; I <= total_num_of_moves; i++)
{
If (I % 3 == 1)
moveDisksBetweenTwoPoles(src, dest, s, d);
else if (I % 3 == 2)
moveDisksBetweenTwoPoles(src, aux, s, a);
else if (I % 3 == 0)
moveDisksBetweenTwoPoles(aux, dest, a, d);
}
}
Int main()
{
Unsigned num_of_disks = 3;
Struct Stack *src, *dest, *aux;
Src = createStack(num_of_disks);
Aux = createStack(num_of_disks);
Dest = createStack(num_of_disks);
tohIterative(num_of_disks, src, aux, dest);
return 0;
}