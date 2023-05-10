#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define int long long

 
// Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
int Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
 
    // while there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] > k*arr[j]) {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1); 
        }
        else {
            aux[k++] = arr[i++];     // NOTE
        }
    }
 
    // copy remaining elements
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
 
    /* no need to copy the second half (since the remaining items
       are already in their correct position in the temporary array) */
 
    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
    // printf("%lld\n", inversionCount);
 
    return inversionCount;
}

int CountS[100000];
 
// Sort array `arr[low…high]` using auxiliary array `aux`
int MergeSort(int arr[], int aux[], int low, int high)
{
    // base case
    if (high <= low) {        // if run size <= 1
        return 0;
    }
 
    // find midpoint
    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;
 
    // recursively split runs into two halves until run size <= 1,
    // then merges them and return up the call chain
 
    // split/merge left half
    MergeSort(arr, aux, low, mid);
 
    // split/merge right half
    MergeSort(arr, aux, mid + 1, high);
 
    // merge the two half runs
    inversionCount += Merge(arr, aux, low, mid, high);

    CountS[low] = inversionCount;

    return inversionCount;
}

int count2[100000];

void naivefn(int arr[], int n, int k) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i+1; j < n; j++) 
        {
            if (arr[i]>(k*arr[j])) 
            {
                count2[i]++;
            }
        }
    }
}
 
int main()
{
    // int arr[] = { 1, 9, 6, 4, 5 };
 
    // int N = sizeof(arr)/sizeof(arr[0]);

    // int N,k;
    // scanf("%lld %lld",&N,&k);
    // int arr[N]; 
    // int aux[N];
    // for (int i = 0; i < N; i++) {
    //     scanf("%lld",&arr[i]);
    //     aux[i] = arr[i];
    //     CountS[i] = 0;
    // }

    // MergeSort(arr, aux, 0, N - 1);
 
    // get the inversion count by performing merge sort on arr
    // printf("The inversion count is %d", MergeSort(arr, aux, 0, N - 1));
    // for(int i=0; i<N; i++)
    // {
    //     printf("%lld ", CountS[i]/2);
    // }
    // printf("\n");
 
    while(1)
    {
        srand(time(NULL)*time(NULL));
        int N,k;
        N = rand()%100+1;
        k = rand()%100+1;
        int arr[N];
        int aux[N];
        for (int i = 0; i < N; i++) {
            arr[i] = rand()%100+1;
            aux[i] = arr[i];
            CountS[i] = 0;
            count2[i] = 0;
        }
        printf("%lld %lld\n",N,k);
        for(int i=0; i<N; i++)
        {
            printf("%lld ", arr[i]);
        }
        printf("\n");

        naivefn(arr,N,k);
        MergeSort(arr, aux, 0, N - 1);

        int flag=0;
        for(int i=0; i<N; i++)
        {
            if(count2[i] != (CountS[i]))
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("Right\n");
        }
        else
        {
            printf("Wrong\n");
            printf("Expected: \n");
            for(int i=0; i<N; i++)
            {
                printf("%lld ", count2[i]);
            }
            printf("\n");
            printf("Result: \n");
            for(int i=0; i<N; i++)
            {
                printf("%lld ", (CountS[i]));
            }
            printf("\n");
            break;
        }
        printf("\n");
    }
    return 0;
}