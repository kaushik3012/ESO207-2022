#include <iostream>

//Giving the long long datatype a new name
typedef long long int LINT;

using namespace std;

//Assigning the value 10&9+7 to the mod variable for easier calculation
const LINT MOD=1e9+7;

//Function to calculate subtraction with modulo 10^9+7
LINT sub(LINT a, LINT b)
{
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
}

//Function to calculate Multiplication with modulo 10^9+7
LINT mul(LINT a, LINT b)
{
    return ((a%MOD) * (b%MOD))%MOD;
}

//Function to return the value of x^n using O(logn) Time Complexity
LINT pow(LINT x, LINT n)
{
    //Base Case: x^0 = 1
    if(n==0)
        return 1;
    
    LINT temp;
    temp = pow(x, n/2);    //Recursive Call to pow function
    temp = mul(temp,temp);

    if(n%2==1)
        temp = mul(temp,x);
    
    return temp;
}

int main()
{
    LINT n;
    cin>>n;     //Accept input

    //Calculating the No of ways using the iterative method
    // A(n) = (2^n-1) - (2^n-2) + ... + ((-1)^n.2)
    LINT prev=1LL;
    for(LINT i=1;i<=n;i++)
        prev=sub(pow(2,i-1),prev);
    cout<<prev;     //Print result

    return 0;
}