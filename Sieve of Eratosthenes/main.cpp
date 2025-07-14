#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void makeZeros(int n, vector<char> &arr)
{
    for (int i = n * n; i < arr.size(); i += n)
    {
        arr[i] = 0;
    }
}
void check(int n, vector<char> &arr)
{
    if (arr[n] == 0)
        return;
    bool var = checkPrime(n);
    if (var)
    {
        makeZeros(n, arr);
        arr[n] = 1;
    }
}

int Count(vector<char> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i])
            count++;
    }
    return count;
}

int countPrimes(int n)
{
    if (n < 2)
        return 0;
    vector<char> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        check(i, primes);
    }
    return Count(primes);
}

int main()
{
    cout << "The method used here is Sieve of Eratosthenes" << endl;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int primes = countPrimes(n);

    cout << "There are " << primes << " prime numbers from 0 to " << n << endl;
    return 0;
}
