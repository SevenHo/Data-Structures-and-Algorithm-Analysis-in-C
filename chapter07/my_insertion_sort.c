#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ElementType int

void insertion_sort(ElementType arr[], int len)
{
	ElementType tmp ;
	for (int p = 1; p < len; p++)
	{
		tmp = arr[p];
		int i;
		for (i = p; i > 0 && arr[i-1] > tmp; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[i] = tmp;		
	}
	
}


int main(void)
{
	int arr[] = {12,1,4,0,9,8,7,6,5};
	insertion_sort(arr,9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d,   ",(int)(9*pow(4,i)-9*pow(2,i)+1));
		printf("%d   \n",(int)(pow(4,i+2)-3*pow(2,i+2)+1));
	}
	
	return 0;
}