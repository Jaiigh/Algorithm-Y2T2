#include <iostream>
#include <vector>

using namespace std;

void combi(int n, vector<int> &sol, int len, int k) {
    if (len < n) {
        sol[len] = 0;
        combi(n, sol, len + 1, k);
        sol[len] = 1;
        combi(n, sol, len + 1, k);
    } else {
        int consecOne = 0;
        bool isPrint = false;
        
        for (int i = 0; i < n; i++) {
            if (sol[i] == 1) {
                consecOne++;
            } else {
                consecOne = 0;
            }

            if (consecOne >= k) {
                isPrint = true;
                break;
            }
        }

        if (isPrint) {
            for (int i = 0; i < n; i++) {
                cout << sol[i];
            }
            cout << endl;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sol(n);
    combi(n, sol, 0, k);
}