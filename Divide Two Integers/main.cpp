#include <bits/stdc++.h>
using namespace std;

int removal(int numerator, int denominator)
{
    int i;
    for (i = 0; i < numerator; i++)
    {
        int p1 = pow(2, i);
        int p2 = denominator * p1;
        if (numerator < p2)
        {
            i--;
            break;
        }
    }
    return pow(2, i);
}
bool sign(int numerator, int denominator)
{
    if ((numerator > 0 && denominator < 0) ||
        (numerator < 0 && denominator > 0))
        return false;
    else
        return true;
}
int divide(int dividend, int divisor)
{
    bool signOfAns = sign(dividend, divisor);
    int numerator = abs(dividend), denominator = abs(divisor);
    if (numerator == denominator)
    {
        if (signOfAns)
            return 1;
        else
            return -1;
    }
    int answer = 0, power;
    while (numerator > denominator)
    {
        power = removal(numerator, denominator);
        answer += power;
        numerator -= denominator * power;
    }
    if (signOfAns)
        return answer;
    else
        return -answer;
}

int main()
{
    int n1 = 22, n2 = 3;
    cout << divide(n1, n2) << endl;
    return 0;
}