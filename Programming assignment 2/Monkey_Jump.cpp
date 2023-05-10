#include<iostream>
#define ll long long
using namespace std;

//Initialise the count array
ll countS[100001]={};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //Accepting inputs
    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    //Traversing the array from end and
    //Calculating the jumps for each index and
    //Storing it in the countS array.
    for(ll i=n-1; i>=1; i--)
    {
        for(ll j=i-1; j>=0; j--)
        {
            if(a[j]>a[i])
                break;
            else
                countS[i]++;
        }
    }

    //Print the result
    for(ll i=0; i<n; i++)
    {
        cout<<countS[i]<<" ";
    }
    cout<<'\n';
    
    return 0;
}