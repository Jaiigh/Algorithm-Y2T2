#include <iostream>
#include <vector>

using namespace std;

bool hasTripleSum(const vector<int>& A, int q) {
    int n = A.size();
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            long long sum = (long long)A[i] + A[j] + A[k];
            if (sum == q) {
                return true;
            } else if (sum < q) {
                j++;
            } else {
                k--;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);


    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    for (int i = 0; i < m; i++) {
        if (hasTripleSum(A, queries[i])) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}