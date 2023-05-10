#include <stdio.h>
#include <string.h>
#include <math.h>
#include<time.h>
#include <stdlib.h>

long sub1(long *arr, long n)
{
    //Declaring a new array with equal to size of original array
    long s[n];
    s[0] = arr[0];
    for(long i=1; i<n; i++)
    {
        //  Adding the previous sum to the array element only when the previous sum is positive 
        //  else initialise the current sum only with the array element
        if(s[i-1]>0)
            s[i]=s[i-1]+arr[i];
        else
            s[i]=arr[i];
    }

    //Finding the maximum element in the sum array
    long max=s[0];
    for(long i=1; i<n; i++)
        if(max<s[i])
            max=s[i];
    
    return max;
}

long sub2(long *A, long N) {
    // long int N,sum=0,maxi=0;
    // scanf("%ld",&N);
    // long int A[N];
    // for(int i=0;i<N;i++)
    // {
    //     scanf("%ld",&A[i]);
    // }

    long maxi=0,sum=0;

    for(long j=0;j<N;j++)
    {
        if(A[j] > (A[j]+sum))
            sum = A[j];
        else {
            sum = A[j]+sum;
        }
        
        if(maxi < (sum))
            maxi=sum;
        
    }

    return maxi;
    // printf("%ld",maxi);
    // /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    // return 0;
}

int main()
{
    while(1)
    {
        srand(time(0));
        long int N,sum=0,maxi=0;
        N = 1+(rand()%(long(1e5)));
        long int A[N];
        for(long i=0;i<N;i++)
        {
            A[i] = (rand()%(long(2e6))) - long(1e6);
            printf("%ld ", A[i]);
        }
        printf("\n");
        long s1 = sub1(A, N);
        long s2 = sub2(A,N);

        if(s1!=s2)
        {
            printf("Incorrect!\n");
            printf("s1 = %ld\n", s1);
            printf("s2 = %ld\n", s2);
            break;
        }
        else
            printf("Correct!\n\n");

    }
    return 0;
}