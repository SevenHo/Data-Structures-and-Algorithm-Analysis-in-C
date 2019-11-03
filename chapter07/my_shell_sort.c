#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ElementType int

typedef struct
{
	int capacity;
	int size;
	ElementType *arr;
} ArrayList;

ArrayList *create_array_list(int size)
{
	ArrayList *list = malloc(sizeof(ArrayList));
	list->arr = malloc(sizeof(ElementType) * size);
	list->capacity = size;
	list->size = 0;
	return list;
}

ArrayList *resize(ArrayList *arr)
{
	int newcapacity = arr->capacity * 2;
	ElementType *newarr = (ElementType *)malloc(sizeof(ElementType) * newcapacity);
	for (int i = 0; i < arr->size; i++)
	{
		newarr[i] = arr->arr[i];
	}
	arr->capacity = newcapacity;
	free(arr->arr);
	arr->arr = newarr;
	return arr;
}

void put(ElementType x, ArrayList *arr)
{
	if (arr->size < arr->capacity)
		arr->arr[arr->size++] = x;
	else
	{
		arr = resize(arr);
		put(x, arr);
	}
}

ArrayList *get_sedgewick(int len)
{
	ArrayList *arr = create_array_list(len / 2);
	int i = 0;
	int tmp;
	while (1)
	{
		/* 9*4^i - 9*2^i + 1 */
		/* 4^i - 3*2^i + 1 */
		tmp = (int)(9 * pow(4, i) - 9 * pow(2, i) + 1);
		if (tmp < len)
			put(tmp, arr);
		else
			break;

		tmp = (int)(pow(4, i+2) - 3 * pow(2, i+2) + 1);
		if (tmp < len)
			put(tmp, arr);
		else
			break;
		i++;
	}

	return arr;
}

void shell_sort(ElementType arr[], int len)
{
	/* 9*4^i - 9*2^i + 1 */
	/* 4^i - 3*2^i + 1 */
	// int Sedgewick[] = {1,5,19,41,109,209,505};
	ArrayList *list = get_sedgewick(len);
	for (int i = list->size - 1; i >= 0; i--)
	{
		int increment = list->arr[i];
		for (int p = increment; p < len; p++)
		{
			ElementType tmp = arr[p];
			int j ;
			for (j = p; j >= increment; j -= increment)
			{
				if (arr[j - increment] > tmp)
				{
					arr[j] = arr[j - increment];
				}else{
					break;
				}
			}
			arr[j] = tmp;
		}
	}
}

int main(void)
{
	ElementType	arr[] = {12,5,23,10,0,9,8,6,5,3,4,1,2};
	shell_sort(arr,13);
	for (int i = 0; i < 13; i++)
	{
		printf("%2d, " , arr[i]);
	}
	
}