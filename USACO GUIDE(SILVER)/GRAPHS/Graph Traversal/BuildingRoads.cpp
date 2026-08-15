#include<iostream>
#include<vector>

using namespace std ;

void dfs(int i,vector<vector<int>>& adj , vector<bool>& vis ){
    vis[i] = true ;
    for(int j : adj[i]){
        if(!vis[j]){
            dfs(j,adj,vis) ;
        } 
    }
} 

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>>road(m+1,vector<int>(2)) ;
    for(int i=1 ;i<=m;i++){
        int a , b ;
        cin >> a >> b ;
        road[i][0] = a;
        road[i][1] = b;
    }
    // Now we got the edges for the graph now we have to form an adjacency list . 

    // Forming an adjacency list . 
    vector<vector<int>>adj(n+1) ;

    for(int i=1;i<=m;i++){
        adj[road[i][0]].push_back(road[i][1]) ;
        adj[road[i][1]].push_back(road[i][0]) ;
    }

    vector<bool>vis(n+1,false) ;
    vector<int>ans ;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis) ;
            ans.push_back(i) ;
        } 
    }
    cout << ans.size()-1 << '\n' ;

    if((ans.size()-1) != 0) {
        for(int i=1;i<ans.size();i++){
            cout << ans[i-1] << " " << ans[i] << '\n' ;
        }
    }
    
}