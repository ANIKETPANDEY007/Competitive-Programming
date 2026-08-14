#include<iostream>
#include<vector>

using namespace std ;

    void dfs(int i , vector<vector<int>>& adj , vector<bool>& vis){
        int n = adj.size() ;
        vis[i] = true ;
        for(int ele : adj[i] ){
            if(!vis[ele]){
                vis[ele] = true ;
                dfs(ele,adj,vis) ;
            }
        }

    };

int main(){
    int n ; cin >> n ;
    vector<int>p(n+1) ;
    for(int i=1;i<=n;i++){
        cin >> p[i] ;
    }
    vector<vector<int>>adj(n+1) ;

    for(int i=1;i<=n;i++){
        adj[i].push_back(p[i]) ;
        adj[p[i]].push_back(i) ;
    }

    vector<bool> vis(n+1 , false) ;

    int components = 0 ;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis) ; 
            components++ ;
        }
    }
    cout << components << '\n' ;
}