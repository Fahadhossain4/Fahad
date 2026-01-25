#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Anna wins if a >= b OR a > c
        if (a >= b || a > c) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    
    return 0;
}
