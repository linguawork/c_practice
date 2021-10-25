// решение:
// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/

#include <stdio.h>
#define bool int
 
void quicksort(int list[], int low, int high) // по сути подаем вместо листа: массив
// low - самое нижнее значение и high - самое высокое
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
 
    /* Sort the elements */
    quicksort(A, 0, arr_size - 1);
 
    /* Now look for the two candidates in the sorted
       array*/
    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum)
		{
			printf("[%d, %d]\n", l, r);
			// printf("the printf returns %d\n", (printf("[%d, %d]\n", l, r)));
            return 1;
            // return(printf("[%d, %d]\n", l, r));
		}
        else if (A[l] + A[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
    return 0;
}

/* Driver program to test above function */
int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 16;
    int arr_size = 6;
	// int flag;
 
    if (hasArrayTwoCandidates(A, arr_size, n))
		return(1);
        // printf("Array has two elements with given sum");
    else
        printf("Array doesn't have two elements with given sum");
 
    // getchar();
    return 0;
}