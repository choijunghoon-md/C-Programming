#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Insert(int idx, int list[], int searchnum)	 
{

	memmove(list + idx + 1, list + idx, sizeof(int) * (6 - idx));
	list[idx] = searchnum;
}

void main(void)
{
	int list[7] = { 1,4,9,15,30,0,0 };
	Insert(3, list, 10);

	for (int i = 0; i < 7; i++) {
		printf("%d ", list[i]);
	}
}