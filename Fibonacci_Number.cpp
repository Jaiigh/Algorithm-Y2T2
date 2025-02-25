#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int N)
{
    if (N == 1)
        return 1;
    if (N == 2)
        return 1;

    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[N];
}

int main()
{
    int N;
    cin >> N;
    cout << fibonacci(N) << endl;
    return 0;
}