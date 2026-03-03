#include <bits/stdc++.h>

using namespace std;


int ubah_x[] = {-1, 1, 0, 0};
int ubah_y[] = {0,0, -1, 1};

int bfs(int c, int r, vector<vector<char>> &petak, int awal_x, int awal_y, int kode) {

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<pair<int,int>> elemen_bfs;
    int luas = 0;
 
    elemen_bfs.push({awal_x, awal_y});
    visited[awal_x][awal_y] = true;
 
    while(!elemen_bfs.empty()) {
       pair<int, int> lokasi_skrng = elemen_bfs.front();
       elemen_bfs.pop();
       luas++;
 
       for(int i = 0; i < 4; i++) {
          int lokasi_x = lokasi_skrng.first + ubah_x[i];
          int lokasi_y = lokasi_skrng.second + ubah_y[i];
 
          if(lokasi_x >= 0 && lokasi_x < r &&
             lokasi_y >= 0 && lokasi_y < c &&
             !visited[lokasi_x][lokasi_y] &&
             petak[lokasi_x][lokasi_y] != '#') {
 
             if((kode == 'B' && petak[lokasi_x][lokasi_y] == 'K') ||
                (kode == 'K' && petak[lokasi_x][lokasi_y] == 'B')) {
                return -1;
             }
 
             visited[lokasi_x][lokasi_y] = true;
             elemen_bfs.push({lokasi_x, lokasi_y});
          }
       }
    }
 
    return luas;
}

int main() {
   int c, r;
   cin >> c >> r;

   vector<vector<char>> petak(r, vector<char>(c));
   int awal_bx, awal_by, awal_kx, awal_ky;
   
   queue<pair<int, int>> elemen_bfs;
   for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
         cin >> petak[i][j];
         if(petak[i][j] == 'B') {
            awal_bx = i;
            awal_by = j;
         } else if( petak[i][j] == 'K') {
            awal_kx = i;
            awal_ky = j;
         }
      }
   }

   int luas_bebek = bfs(c, r, petak, awal_bx, awal_by, 'B');
   if(luas_bebek == -1) {
      cout << "SERI" << endl;
      return 0;
   }

   int luas_kucing = bfs(c, r, petak, awal_kx, awal_ky, 'K');


   if(luas_bebek > luas_kucing) cout << "B " << luas_bebek - luas_kucing << endl; 
   else if(luas_kucing > luas_bebek) cout << "K " << luas_kucing - luas_bebek << endl;

   return 0;
}