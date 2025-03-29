#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int> &s, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 2; len <= N; len++)
    {
        for (int i = 0; i <= N - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + s[i] * s[k + 1] * s[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][N - 1];
}

int main()
{
    int N;
    cin >> N;

    vector<int> s(N + 1);
    for (int i = 0; i <= N; i++)
    {
        cin >> s[i];
    }

    cout << matrixChainMultiplication(s, N) << endl;
    return 0;
}