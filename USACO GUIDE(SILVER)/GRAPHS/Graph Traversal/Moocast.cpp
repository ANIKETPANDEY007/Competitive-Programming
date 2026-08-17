#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std ;

void dfs(int i , vector<vector<int>>& adj,vector<int>& vis){
    vis[i] = true ;

    for(int j : adj[i]){
        if(!vis[j]){
            dfs(j,adj,vis) ;
        }
    }
}

int main(){
    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    int n ;
    cin >> n ;
    vector<int>x(n+1) , y(n+1) , p(n+1) ;

    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i] >> p[i] ;
    }

    vector<vector<int>>adj(n+1) ;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            int dx = x[i] - x[j] ;
            int dy = y[i] - y[j] ;
            int dist = dx*dx + dy*dy ;
            if(dist<=(p[i]*p[i])) adj[i].push_back(j) ;
        }
    }

    int ans = 0 ;

    for(int i=1;i<=n;i++){
        vector<int>vis(n+1,false) ;

        dfs(i,adj,vis) ;

        int count = 0 ;
        for(int j=1;j<=n;j++){
            if(vis[j]) count++ ;
        }

        ans = max(count,ans) ;
    }

    cout << ans << '\n' ;
    return 0 ;
}