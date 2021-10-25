#include <stdio.h>
#include <stdlib.h>

void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}

// int intcmp(void *a, void *b)
// {
//     return(*((int *)a) - *((int *)b));
// }

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)* *returnSize);
    // qsort(nums, numsSize, sizeof(int), &intcmp);
    quicksort(nums, 0, numsSize - 1);   
    
    for (int i = 0; i < numsSize; i++ )
        printf("%d\n", nums[i]);

    return(nums);
}

int main()
{
    int A[] = { 2, 7, 11, 15 };
    int n = 9;
    int arr_size = 4;

    int *result;
    int *returnsize;
    returnsize = 2;
    result = twoSum(A, arr_size, n, returnsize);
    printf("%d", *result);
	// int flag;
 
    // if (hasArrayTwoCandidates(A, arr_size, n))
	// 	return(1);
    //     // printf("Array has two elements with given sum");
    // else
    //     printf("Array doesn't have two elements with given sum");
 
    // // getchar();
    return 0;
}