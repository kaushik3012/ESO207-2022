#include<iostream>
#define ll long long
using namespace std;

//Utility Function to find maximum of two numbers
ll max(ll a, ll b)
{
    return a > b ? a : b;
}

//Function to get optimal index of teacher in the array
ll searchTeacher(int *arr, ll n, ll m)
{
    //Calculate the middle index of the array
    ll mid = (n-1)/2; 
    if(arr[mid]==1)
        return mid;

    ll i,k;
    if(n%2==0)
    {
        i=mid;
        k=mid+1;
    }
    else
    {
        i=mid-1;
        k=mid+1;
    }

    //Traverse the array from the middle index to the left and right simultaneously
    for(; i>=0 && k<n; i--, k++)
    {
        //Return index if element at the index is 1
        if(i==0 || arr[i]==1)
            return i;
        if(k==n-1 || arr[k]==1)
            return k;
    }
    return -1;
}


//Function to find the smallest subarray with sum M+1
ll smallestSubWithSum(int arr[], ll n, ll x)
{
    // Initialize current sum and minimum length
    ll curr_sum = 0, min_len = n + 1;
    int temp[min_len];
 
    // Initialize starting and ending indexes
    ll start = 0, end = 0;
    while (end < n) 
    {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
 
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n)
        {
            // Update minimum length if needed
            if (end - start < min_len)
            {
                min_len = end - start;
                for(ll r=0; r<min_len; r++)
                    temp[r] = arr[start+r];
            }
 
            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    
    //Searching the optimal index where the teacher will stay
    ll idx = searchTeacher(temp, min_len, x);

    //Returning Maximum distance of the farthest ends
    return max(idx, min_len-1-idx);
}

// Main Function
int main()
{
    //Accepting inputs
    ll n,m;
    cin>>n>>m;

    int a[n];
    for(ll i=0;i<n;i++)
    {
        int t;
        cin>>t;
        a[i]=1-t;     //Inverting the binary state of each element while storing
    }

    //Calculating the required distance and printing it
    cout<<smallestSubWithSum(a,n,m)<<'\n';

    return 0;
}