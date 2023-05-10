#include<iostream>

//Giving the long long datatype a new name
typedef long long int LINT;

using namespace std;

//Assigning the value 10&9+7 to the mod variable for easier calculation
const LINT MOD=1e9+7;

//Function for Matrix Multiplication
void matmul(LINT a[3][3],LINT b[3][3])
{
    //Calculating product of matrices
    LINT p[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            p[i][j]=0;
            for(int k=0;k<3;k++)
            {
                p[i][j]=p[i][j]+(a[i][k]*b[k][j]);
                p[i][j] = p[i][j]%MOD;
            }
        }
    }

    //Storing the product in array 'a' for easy access
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j]=p[i][j];
}

//Function to calculate power of matrix i.e. A^n
void matpow(LINT arr[3][3], LINT n)
{
    LINT res[3][3] = {{1,0,0},{0,1,0},{0,0,1}}; //Initialising identity matrix

    //Calculating power of matrix using O(logn) Time Complexity algorithm
    while(n)
    {
        if(n%2==1)
            matmul(res,arr);
        matmul(arr,arr);
        n=n/2;
    }

    //Storing result in array 'a' for easy access
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            arr[i][j]=res[i][j];
}

//Function to return the No of Ways the journey ends with A
//using the matrix exponentiation method
LINT AWays(LINT n)
{
    LINT arr[3][3] = {{0,1,1},{1,0,1},{1,1,0}};
    matpow(arr,n);

    //Returning only the first element of matrix arr^n
    //because the final result is matrix multiplication of arr^n with [1,0,0]^T
    return arr[0][0];
}

int main()
{
    LINT n;
    cin>>n;     //Accepting Input

    //Calling the function and storing the result
    LINT res = AWays(n)%(MOD);
    cout<<res<<'\n';    //Printing the Result
    return 0;
}

