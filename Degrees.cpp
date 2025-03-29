#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n, 0);

    int max_deg = 0;
    int s;

    for (int i = 0; i < n; i++)
    {
        s = 0;
        int curr;

        for (int j = 0; j < n; j++)
        {
            cin >> curr;
            s += curr;
        }
        v[s]++;
        max_deg = max(max_deg, s);
    }

    for (int i = 0; i <= max_deg; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}