#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> k >> n;
    vector<int> a(n + 1), c(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    for (int i = k; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            a[i] += ((c[j] * a[i - j]) % 32717);
            a[i] = a[i] % 32717;
        }
    }
    cout << a[n];
}