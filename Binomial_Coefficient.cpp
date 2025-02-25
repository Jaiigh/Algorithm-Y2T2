#include <iostream>
#include <vector>

using namespace std;

long long binomialCoefficient(int n, int k)
{
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
        {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << binomialCoefficient(n, k) << endl;
    return 0;
}