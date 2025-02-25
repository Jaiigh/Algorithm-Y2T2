#include <iostream>

using namespace std;

int N, tmp, min1 = 101, min1_i = -1, sum = 0;
int s[101];

int main()
{
    cin >> N;

    for (int i = 0; i <= N; i++)
    {
        cin >> tmp;
        s[i] = tmp;

        if (tmp < min1)
        {
            min1 = tmp;
            min1_i = i;
        }
    }

    int j = min1_i + 2;
    while (j <= N)
    {
        sum += min1 * s[j - 1] * s[j];
        j++;
    }
    int k = min1_i - 2;
    while (k >= 0)
    {
        sum += min1 * s[k + 1] * s[k];
        k--;
    }
    if (min1_i != 0 && min1_i != N)
        sum += s[0] * min1 * s[N];
    cout << sum << endl;
    return 0;
}
