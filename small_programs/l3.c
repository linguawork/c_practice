
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define bool _Bool

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

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int l;
	int r;
    int sum;

	char * res;
	*returnSize = 2;
 
    quicksort(nums, 0, numsSize - 1);
 
    /* Now look for the two candidates in the sorted
       array*/
    l = 0;
    r = numsSize - 1;
    while (l < r) {
        if (nums[l] + nums[r] == sum)
		{

			// printf("[%d, %d]\n", l, r);
			res = (char *)malloc(sizeof(char *)* (2 + 1));
            res[0] = nums[l];
            res[1] = nums[r];
            res[2] = '\0';
            printf("[%s]", res);
            free(res);
            return (1);
		}
        else if (nums[l] + nums[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
	// res = "nothing found";
    return(0);
}

int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 16;
    int arr_size = 6;
	char *res;
	int returnsize = 2;
 
    res = twoSum(A, arr_size, n, &returnsize);
	if (strcmp(res, "nothing found") != 0)
		printf ("%s", res);
        // printf("Array has two elements with given sum");
    else
        printf("Array doesn't have two elements with given sum");
 
    // getchar();
	free(res);
    return 0;
}