#include<iostream>
#include<vector>

using namespace std ;

void dfs(int i , vector<vector<int>>& adj , vector<bool>& vis , vector<bool>& open){

    for(int j : adj[i]){
        if(!vis[j] && open[j]){
            vis[j] = true ;
            dfs(j,adj,vis,open) ;
        }
    }
}

int main(){
    // freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    int n , m ;
    cin >> n >> m ;

    vector<vector<int>>path(m+1) ;
    for(int i=1;i<=m;i++){
        int a , b ;
        cin >> a >> b ;
        path[i].push_back(a) ;
        path[i].push_back(b) ;
    }
    
    // Creating a adjacency List .
    vector<vector<int>>adj(n+1) ;

    for(int i=1;i<=m;i++){
        int a = path[i][0] ;
        int b = path[i][1] ;

        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    vector<bool>open(n+1,true) ;

    for(int i=1;i<=n;i++){
        vector<bool>vis(n+1,false) ;
        int a ; cin >> a ;

        int start = -1 ;

        for(int j=1;j<=n;j++){
            if(open[j]){
                start = j ;
                break ;
            }    
        }
        vis[start] = true ;
        dfs(start,adj,vis,open) ;

        bool ok = true ;

        for(int j=1;j<=n;j++){
            if(open[j] && !vis[j]){
                ok = false ;
                break ;
            }
        }
        open[a] = false ;
        if(ok) cout << "YES" << '\n' ;
        else cout << "NO" << '\n' ;
    }

    return 0 ;

}