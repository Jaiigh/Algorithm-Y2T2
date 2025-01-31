#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void genBarcode(int A, int B, vector<string>& results, string current = "", int ones = 0, int zeros = 0) {
    if (current.length() == B) {
        if (ones == A) {
            results.push_back(current);
        }
        return;
    }

    if (ones < A) {
        genBarcode(A, B, results, current + "1", ones + 1, zeros);
    }

    if (zeros < B - A) {
        genBarcode(A, B, results, current + "0", ones, zeros + 1);
    }
}

int main() {
    int A, B;
    cin >> A >> B;

    vector<string> results;

    genBarcode(A, B, results);

    sort(results.begin(), results.end());

    for (const string& barcode : results) {
        cout << barcode << "\n";
    }

    return 0;
}