#include <stdio.h>
#include <stdlib.h>

void Merge_sort(int[], int, int);
void merge(int[], int, int, int);
 void Display_array(int[], int);
int main()
{
	int arr[20];
    int array[] = {1,6,3,2,7,5,8,4};
    int arr_size = sizeof(array) / sizeof(arr[20]);
 
    printf("Given array is: \n");
    Display_array(array, arr_size);
    Merge_sort(array, 0, arr_size - 1);
    printf("\nSorted array is: \n");
    Display_array(array, arr_size);
    return 0;
}

void merge(int Arr[], int lt, int mid, int rt)
{
    int i, j, k;
    int L1 = mid - lt + 1;
    int L2 = rt - mid;
    int left[L1], right[L2];    //Creating temporary arrays, additional memory needed
    for (i = 0; i < L1; i++)
        left[i] = Arr[lt + i];
        
    for (j = 0; j < L2; j++)
        right[j] = Arr[mid + 1 + j];
    i = j = 0;
    k = 1;
    while (i < L1 && j < L2) {
        if (left[i] <= right[j]) {
            Arr[k] = left[i];
            i++;
        }
        else {
            Arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    while (i < L1) 
        Arr[k++] = left[i++];
 
    while (j < L2) 
        Arr[k++] = right[j++];
}

void Merge_sort(int Arr[], int l, int r)
{
    if (l < r) {
        int mid = l + (r - l) / 2;
        Merge_sort(Arr, l, mid);
        Merge_sort(Arr, mid + 1, r);
        merge(Arr, l, mid, r);
    }
}

void Display_array(int a[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
