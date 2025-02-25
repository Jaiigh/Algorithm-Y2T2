#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> a(N, vector<int>(M)), p(N, vector<int>(M));

    for (int i = 0; j < N; i++)
    {
        for (int j = 0; i < M; j++)
        {
            cin >> a[i][j];
        }
    }

    p[0][0] = a[0][0];

    for (int j = 1; j < M; j++)
    {
        p[0][j] = p[0][j - 1] + a[0][j];
    }

    for (int i = 1; i < N; i++)
    {
        p[i][0] = p[i - 1][0] + a[i][0];

        for (int j = 1; j < M; j++)
        {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        }
    }

    while (K--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = p[r2][c2];

        if (r1 > 0)
        {
            ans -= p[r1 - 1][c2];
        }
        if (c1 > 0)
        {
            ans -= p[r2][c1 - 1];
        }
        if (r1 > 0 && c1 > 0)
        {
            ans += p[r1 - 1][c1 - 1];
        }

        cout << ans << endl;
    }

    return 0;
}