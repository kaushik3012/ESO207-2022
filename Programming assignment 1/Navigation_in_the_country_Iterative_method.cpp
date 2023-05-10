#include<iostream>

using namespace std;

unsigned long pow(long x, long n)
{
    if(n==0)
        return 1;
    
    unsigned long temp;
    temp = pow(x, long(n)/2 );
    temp = ((temp%1000000007)*(temp%1000000007))%1000000007;

    if(n%2==1)
        temp = (temp*x)%1000000007;
    
    return temp;
}

// unsigned long pow(long x, long n)
// {
//     unsigned long res=1;
//     while(n)
//     {
//         if (n%2==1)
//             res = ((res%1000000007)*(x%1000000007))%1000000007;
//         x = ((x%1000000007)*(x%1000000007))%1000000007;
//         n = n/2;
//     }
//     return res;
// }

unsigned long AWays(long n)
{
    unsigned long sum=0;
    for(long i=1; i<=n; i++)
    {
        if(i%2==0)
        {
            sum -= pow(2, n-i);
            if(i==n)
                sum += 1;
        }
        else
        {
            sum += pow(2, n-i);
            if(i==n)
                sum -= 1;                
        }
    }
    return sum;
}

int main()
{
    long n;
    cin>>n;

    cout<<pow(2,n)<<endl;

    unsigned long res = (unsigned long)(AWays(n))%(1000000007);
    cout<<res<<'\n';
    return 0;
}




// unsigned long AWays(long n)
// {
//     if(n%2==0)
//         return (unsigned long)(((long)(pow(2,n)+2))/(long)(3));

//     return (unsigned long)(((long)(pow(2,n)-2))/(long)(3));
// }

