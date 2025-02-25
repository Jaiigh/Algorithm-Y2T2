#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCustomers(vector<int> &c)
{
    int n = c.size();
    if (n == 1)
        return c[0];
    if (n == 2)
        return max(c[0], c[1]);

    vector<int> dp(n);
    dp[0] = c[0];
    dp[1] = max(c[0], c[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + c[i]);
    }

    return dp[n - 1];
}

int main()
{
    int N;
    cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
}