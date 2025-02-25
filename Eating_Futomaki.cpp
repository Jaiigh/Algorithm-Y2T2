#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }

    for (int sz = 4; sz <= n; sz += 2)
    {
        for (int l = 1, r = sz; r <= n; l++, r++)
        {
            dp[l][r] = max({
                dp[l + 2][r] + max(arr[l], arr[l + 1]), // Eat first two
                dp[l + 1][r - 1] + max(arr[l], arr[r]), // Eat first and last
                dp[l][r - 2] + max(arr[r], arr[r - 1])  // Eat last two
            });
        }
    }

    cout << dp[1][n] << "\n";
}