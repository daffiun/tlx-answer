#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<string, string> spesies;
    string child, parent;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> parent >> child;
        spesies[child] = parent;
    }

    string a, b;
    cin >> a >> b;
    
    vector<string> path;
    
    string cur = b;
    while(true) {
        path.push_back(cur);

        if(cur == a) {
            reverse(path.begin(), path.end());
            for(auto &s : path) {
                cout << s << endl;
               
            } 
            return 0;
        }
        if(!spesies.count(cur)) break;

        cur = spesies[cur];
    }

    path.clear();

    cur = a;
    while(true) {
        path.push_back(cur);

        if(cur == b) {
            reverse(path.begin(), path.end());
            for(auto &s : path) {
                cout << s << endl;
                
            }
            return 0;
        }
        if(!spesies.count(cur)) break;

        cur = spesies[cur];
    }

    cout << "TIDAK MUNGKIN" << endl;
}