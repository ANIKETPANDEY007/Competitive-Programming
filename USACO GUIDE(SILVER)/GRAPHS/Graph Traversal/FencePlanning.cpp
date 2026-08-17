#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

void dfs(int i , vector<vector<int>>& adj , vector<bool>& vis){

    for(int j : adj[i]){
        if(!vis[i]) dfs(j,adj,vis) ;
    }
}

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int>x(n+1) , y(n+1) ;

    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i] ;
    } 

    // Adjoint creation . 
    vector<vector<int>>adj(m+1) ;
    for(int i=1;i<=m;i++){
        int a , b ; cin >> a >> b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }


    int ans = 0 ;
    for(int i=1 ; i<=n ;i++){
        vector<bool>vis(n+1) ;
    }


}