#include <iostream>
#include <string>

using namespace std;

bool areSimilar(string a, string b) {
    if (a == b) {
        return true;
    }

    if (a.length() % 2 != 0) {
        return false;
    }

    int mid = a.length() / 2;

    string a1 = a.substr(0, mid);
    string a2 = a.substr(mid);
    string b1 = b.substr(0, mid);
    string b2 = b.substr(mid);

    return (areSimilar(a1, b1) && areSimilar(a2, b2) || areSimilar(a1, b2) && areSimilar(a2, b1));
}

int main() {
    string a, b;
    cin >> a >> b;

    if (areSimilar(a, b)) {
        cout << "YES" << "\n";
    } else { 
        cout << "NO" << "\n";
    }

    return 0;
}