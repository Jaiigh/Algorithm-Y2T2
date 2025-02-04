#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        int k, index = 0, ans = 0;
        cin >> k;

        while (A[index] != k) {
            if (A[index] > k) {
                ans++;
            }
            index++;
        }
        cout << ans << "\n";
    }
}