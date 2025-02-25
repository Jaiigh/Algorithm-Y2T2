#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    vector<int> B(n + 1, 0);

    B[1] = A[1];

    if (n >= 2)
        B[2] = A[1] + A[2];
    if (n >= 3)
        B[3] = max(B[1], B[2]) + A[3];

    for (int i = 4; i <= n; i++)
    {
        B[i] = A[i] + max({B[i - 1], B[i - 2], B[i - 3]})
    }

    cout << B[n] << endl;
    return 0;
}