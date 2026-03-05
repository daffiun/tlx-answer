#include <bits/stdc++.h>

using namespace std;

int bfs(string asal, string tujuan, int k, int kombinasi) {
    unordered_map<string, int> dist; 
    queue<string> curr;

    curr.push(asal);
    dist[asal] = 0; 

    while(!curr.empty()) {
        string sekarang = curr.front();
        curr.pop();

        if (sekarang == tujuan) {
            return dist[sekarang];
        }

        for(int i = 0; i < kombinasi; i++) {
            string tetangga = sekarang;

            reverse(tetangga.begin() + i, tetangga.begin() + i + k);
            
            if (dist.find(tetangga) == dist.end()) {
                dist[tetangga] = dist[sekarang] + 1;
                curr.push(tetangga);
            }
        }
    }
    return -1; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;

    int tampung, kombinasi;
    string awal, akhir;
    for(int i = 0; i < n; i++) {
        cin >> tampung;
        awal += to_string(tampung);
        akhir += to_string(i + 1);
    }

    cin >> k;
    kombinasi = n - k + 1;

    cout << bfs(awal, akhir, k, kombinasi);    
}