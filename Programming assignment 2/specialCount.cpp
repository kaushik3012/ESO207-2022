#include<iostream>
#define ll long long
using namespace std;

void specialCount(ll arr[], ll n, ll k, ll countS[])
{
    for(ll i=0; i<n; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            if(arr[i]>k*arr[j]) 
                countS[i]++;
        }
    }
}

int main()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll countS[n];
    for(ll i=0;i<n;i++)
        countS[i]=0;

    specialCount(arr,n,k,countS);
    for(ll i=0;i<n;i++)
        cout<<countS[i]<<" ";
    cout<<endl;

    return 0;
}