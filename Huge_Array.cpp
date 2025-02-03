#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); std::cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<pair<int,int>> v(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        pair<int, int> p = make_pair(A, B);
        v[i] = p;
    }

    sort(v.begin(), v.end());

    vector<int> table(N);
    table[0] = v[0].second;
    for (int i = 1; i < N; i++) {
        table[i] = v[i].second + table[i - 1];
    }

    while (Q--) {
        int index;
        cin >> index;
        cout << v[(lower_bound(table.begin(), table.end(), index) - table.begin())].first << "\n";
    }
}