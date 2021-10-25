// решение на хеш таблицах:
// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/

// https://leetcode.com/problems/two-sum/solution/

#include <stdio.h>
#define bool int
 
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
 
bool hasArrayTwoCandidates(int A[], int arr_size, int sum)
{
    int l;
	int r;
 
    quicksort(A, 0, arr_size - 1);
 
    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum)
		{
			printf("[%d, %d]\n", l, r);
            return 1;
		}
        else if (A[l] + A[r] < sum)
            l++;
        else
            r--;
    }
    return 0;
}

int main()
{
    int A[] = { 2, 7, 11, 15 };
    int n = 9;
    int arr_size = 3;
 
    if (hasArrayTwoCandidates(A, arr_size, n))
		return(1);
    else
        printf("Array doesn't have two elements with given sum");
    return 0;
}