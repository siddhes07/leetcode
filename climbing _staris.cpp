#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n <= 2)
        return n;

    int prev2 = 1; // ways to reach step 1
    int prev1 = 2; // ways to reach step 2
    int current;

    for (int i = 3; i <= n; i++)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Number of distinct ways: " << climbStairs(n) << endl;

    return 0;
}