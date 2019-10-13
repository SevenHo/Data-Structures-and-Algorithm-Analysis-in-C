#include <stdio.h>
#include <stdlib.h>

/**
 * 查找主元素的候选者
 */
int main_element(int[], int);

int main(void)
{   
    int length = 9;
    int array[] = {1,1,0,0,0,0,1,1,2};
    int count = 0;
    int result = main_element(array, length);
    for (int i = 0; i < length ; i++)
    {
        if(array[i] == result){
            count++;
        }
    }
    if(count > length/2){
        printf("\nthe main element is %d", result);
    }else{
        printf("\nno main element ");
    }

    return 0;
}

int main_element(int array[], int length)
{
    if (length == 1)
    {
        return array[0];
    }
    else if (length == 0)
    {
        return -1;
    }
    else
    {
        int count = 0;
        int size = length;
        int temp_ele = -1;

        if (length % 2 != 0)
        {
            size--;
        }
        for (int i = 0; i < size; i += 2)
        {
            if (array[i] == array[i + 1])
            {
                array[count] = array[i];
                count++;
                // printf("\ncount is %d",count);
            }
        }
        temp_ele = main_element(array, count);
        if (size != length && temp_ele == -1)
        {
            return array[size];
        }
        else
        {
            return temp_ele;
        }
    }
}