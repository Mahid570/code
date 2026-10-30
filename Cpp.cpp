
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> freq(26, 0);
    vector<pair<char,int>> v;

    for(char c : s) {
        freq[c-'a']++;

        if(v.empty() || v.back().first != c)
            v.push_back({c, 1});
        else
            v.back().second++;
    }

    int mx = *max_element(freq.begin(), freq.end());

    if(v.size() > 3) {
        cout << "NO\n";
        return;
    }

    if(v.size() <= 2) {
        cout << "YES\n";
        return;
    }

    int mid = n / 2;
    int pos = v[0].second;

    if(mid >= pos + v[1].second) {
        cout << "NO\n";
        return;
    }

    char c = v[1].first;
    int cnt = freq[c-'a'];

    if(cnt != mx) {
        cout << "NO\n";
        return;
    }

    if(n % 2 == 1) {
        cout << (2 * cnt > n ? "YES\n" : "NO\n");
    }
    else {
        if(s[mid-1] != c || s[mid] != c) {
            cout << "NO\n";
            return;
        }

        cout << (2 * cnt >= n ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
