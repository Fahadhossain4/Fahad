#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int maxBlank = 0;
        int currentBlank = 0;
        
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            
            if (a == 0) {
                currentBlank++;
                maxBlank = max(maxBlank, currentBlank);
            } else {
                currentBlank = 0;
            }
        }
        
        cout << maxBlank << endl;
    }
    
    return 0;
}
