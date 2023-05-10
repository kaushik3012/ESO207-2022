#include<iostream>

using namespace std;

//Declare prototype of functions to use in resursion
long AWays(int);
long BWays(int);
long CWays(int);


//Function to recursively calculate the number of ways B comes at the nth day.
long BWays(int n)
{
    //B(0) = 0
    if(n==0)
        return 0;

    // B(n) = C(n-1) + A(n-1)
    return CWays(n-1) + AWays(n-1);
}

//Function to recursively calculate the number of ways C comes at the nth day.
long CWays(int n)
{
    //C(0) = 0
    if(n==0)
        return 0;

    // C(n) = B(n-1) + A(n-1)
    return BWays(n-1) + AWays(n-1);
}

//Function to recursively calculate the number of ways A comes at the nth day.
long AWays(int n)
{
    //A(0) = 1
    if(n==0)
        return 1;
    
    // A(n) = B(n-1) + C(n-1)
    return BWays(n-1) + CWays(n-1);
}

int main()
{
    int n;
    cin>>n;     //Accepting input

    long res = ((long)(AWays(n)))%(1000000007);     //Finding A(n) modulo 10^9+7

    cout<<res<<'\n';      //Printing Result
    return 0;
}