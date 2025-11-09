#include <iostream>
using namespace std;
#include <cmath>
#include <string>
int main() {
    string s = "1101";
    int n = s.size();
    int ans = 0;
    int idx = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans += pow(2, idx) * (s[i] - '0');
        idx++;
    }
    cout << ans << endl;
}