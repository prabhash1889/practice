#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void solve() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    unordered_map<int, int> idmp;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        idmp[X[i]] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
    }
    vector<int>pov;
    
    for (int i = 0; i < N; i++) {
        int pvt = X[i];
        vector<pii> L;
        
        for (int j = 0; j < N; j++) {
            L.emplace_back(abs(X[j] - pvt), X[j]);
        }
        
        sort(L.begin(), L.end());
        vector<int> c_Y;
        
        for (const auto &p : L) {
            c_Y.push_back(p.second);
        }
        
        if (c_Y == Y) {
           pov.push_back(idmp[pvt]);
        }
    }
    
    if (pov.empty()) {
        cout << -1 << "\n";
    } else {
        cout <<pov[0] << "\n"; // Output any valid pvt index
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}