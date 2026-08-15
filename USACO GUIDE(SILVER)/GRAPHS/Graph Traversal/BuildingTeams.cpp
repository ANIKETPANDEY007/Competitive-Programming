#include<iostream>
#include<vector>

using namespace std ;

void dfs(int i , vector<vector<int>>& adj , vector<int>& team , bool& ans){

    for(int j : adj[i]){
        if(team[i]==team[j]){
            ans = false ;
            return ;
        }else if(team[j]==-1){
            team[j] = 3 - team[i] ;
            dfs(j, adj, team, ans);
        }
    }
}

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>>pupils(m+1) ;

    for(int i=1;i<=m;i++){
        int a , b ;
        cin >> a >> b ;
        pupils[i].push_back(a) ;
        pupils[i].push_back(b) ;
    }

    // Constructing the adjacency list .
    vector<vector<int>>adj(n+1) ;

    for(int i=1;i<=m;i++){
        int a = pupils[i][0] ;
        int b = pupils[i][1] ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ; 
    }

    vector<int>team(n+1,-1) ; 
    // Initially They were on no team (-1). 

    // We will traverse to the graph and will try to divide them into two groups . 

    bool ans = true ;
    for(int i=1;i<=n;i++){
        if(team[i]==-1 && ans){
            team[i] = 1 ;
            dfs(i,adj,team,ans) ;
        }
    }
    
    if(!ans){
        cout << "IMPOSSIBLE" << '\n' ;
        return 0 ;
    }

    for(int i=1;i<=n;i++){
        cout << team[i] << " " ;
    }

    return 0 ;

}