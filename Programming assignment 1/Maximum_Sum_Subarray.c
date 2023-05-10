#include<stdio.h>

//Giving the long long datatype a new name
typedef long long int LINT;

//Function to Find the Maximum sum of all subarrays
LINT maxsumsub(LINT *arr, LINT n)
{
    //Declaring a new array with equal to size of original array
    LINT sum[n];
    sum[0] = arr[0];
    for(LINT i=1; i<n; i++)
    {
        //  Adding the previous sum to the array element only when the previous sum is positive 
        //  else initialise the current sum only with the array element
        if(sum[i-1]>0)
            sum[i]=sum[i-1]+arr[i];
        else
            sum[i]=arr[i];
    }

    //Finding the maximum element in the sum array
    LINT max=sum[0];
    for(LINT i=1; i<n; i++)
        if(max<sum[i])
            max=sum[i];
    
    return max;
}

int main()
{
    //Scanning for inputs
    LINT n;
    scanf("%lld\n",&n);

    LINT arr[n];
    for(LINT i=0; i<n; i++)
        scanf("%lld ",arr+i);
    scanf("\n");

    //Calling the maxsumsub function and printing the Maximum sum of subarrays
    printf("%lld\n", maxsumsub(arr, n));
    
    return 0;
}