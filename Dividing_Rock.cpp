#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1997;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> dp(k + 1, 0), prev(k + 1, 0);
    prev[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[1] = 1;
        for (int j = min(i, k); j >= 2; j--)
        {
            dp[j] = (prev[j - 1] + (j * prev[j]) % MOD) % MOD;
        }
    }
}