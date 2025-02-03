#include <iostream>
#include <vector>

using namespace std;

void binarySearch(const vector<int>& arr, double x) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (m--) {
        double query;
        cin >> query;
        binarySearch(arr, query);
    }

    return 0;
}