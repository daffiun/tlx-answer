#include <bits/stdc++.h>

using namespace std;
void dfs(int asal, vector<int> adj[], bool visited[]) {
   visited[asal] = true;
   for(int tujuan : adj[asal]){
      if( !visited[tujuan]) {
         dfs(tujuan, adj, visited);
      }
   }   
}


int main() {
   int N, M;
   cin >> N >> M;

   vector<int> adj[N+1];
   int asal, tujuan;
   for(int i = 0; i < M; i++) {
      cin >> asal >> tujuan;
      adj[asal].push_back(tujuan);
      adj[tujuan].push_back(asal);
   }

   bool visited[N + 1] = {false};
   int component = 0;

   for(int i = 1; i <= N; i++ ){
      if(!visited[i]) {
         dfs(i,adj, visited);
         component++;
      }
   }

   cout << component << endl;
}