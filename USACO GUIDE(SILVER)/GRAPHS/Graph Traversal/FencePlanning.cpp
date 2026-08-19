#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std ;

void dfs(int i , vector<vector<int>>& adj , vector<bool>& vis , vector<int>& x , vector<int>& y , int& minx , int& miny , int& maxx , int& maxy){

    for(int j : adj[i]){
        vis[i] = true ;
        if(!vis[j]){
            minx = min(x[j],minx) ;
            maxx = max(maxx,x[j]) ;
            miny = min(y[j],miny) ;
            maxy = max(maxy,y[j]) ;
            dfs(j,adj,vis,x,y,minx,miny,maxx,maxy) ;
        } 
    }
}

int main(){
    freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
    int n , m ;
    cin >> n >> m ;
    vector<int>x(n+1) , y(n+1) ;

    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i] ;
    } 

    // Adjoint creation . 
    vector<vector<int>>adj(n+1) ;
    for(int i=1;i<=m;i++){
        int a , b ; cin >> a >> b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    int ans = 0 ;
    int perimeter = INT_MAX ;
    vector<bool>vis(n+1) ;
    for(int i=1 ; i<=n ;i++){
        int minx = x[i] ;
        int miny = y[i] ;
        int maxx = x[i] ;
        int maxy = y[i] ;

        if(!vis[i]){
            dfs(i,adj,vis,x,y,minx,miny,maxx,maxy) ;
            perimeter = min(perimeter , (2*(maxx - minx))+(2*(maxy-miny))) ;
        } 
    }

    cout << perimeter << "\n" ;
}