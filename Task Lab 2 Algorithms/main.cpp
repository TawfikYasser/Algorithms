#include <iostream>

using namespace std;

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] +
            F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] +
            F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] +
            F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] +
            F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n)
{
    int i;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };

    // n - 1 times multiply the
    // matrix to {{1,0},{0,1}}
    for(i = 2; i <= n; i++)
        multiply(F, M);
}

//Function for Fibonacci using 'Powering Method'
int poweringMethodFibonacci(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };

    if (n == 0)
        return 0;

    power(F, n - 1);

    return F[0][0];
}


//Function for Fibonacci using 'Recursion'

int recursiveFibonacci(int n)
{
    if (n <= 1)
        return n;
    return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
}

//Function for Fibonacci using 'Dynamic Programming'
int dynamicProgrammingFibonacci(int n)
{
    int f[n + 2];
    int i;
    f[0] = 0;
    f[1] = 1;
    for(i = 2; i <= n; i++)
    {
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
    }

int main()
{
    int n = 99;

    //Fibonacci using 'Recursion'
    cout<<"Fibonacci using 'Recursion'"<<endl;
    cout << recursiveFibonacci(n)<<endl;

    //Fibonacci using 'Dynamic Programming'
    cout<<"Fibonacci using 'Dynamic Programming'"<<endl;
    cout<<dynamicProgrammingFibonacci(n)<<endl;

    //Fibonacci using 'Powering Method'
    cout<<"Fibonacci using 'Powering Method'"<<endl;
    cout<<poweringMethodFibonacci(n)<<endl;
    return 0;
}
