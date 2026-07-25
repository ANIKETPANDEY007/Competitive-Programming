#include<iostream>
#include<vector> 

using ll = long long ;
using namespace std ;
int main(){
    int mod = 1e9 + 7 ;
    int n , m ; 
    cin >> n >> m ;
    vector<int>v(n+1) ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0)) ;
    // dp[i][j] = number of ways to fill the first i elements of the array such that a[i] = j ;

    if(v[1]==0){
        for(int i=1;i<=m;i++) dp[1][i] = 1 ;
    }else{
        dp[1][v[1]] = 1 ;
    }

    for(int i=2;i<=n;i++){
        int val = v[i] ;
        for(int j=1;j<=m;j++){
            if(val != 0 && val != j){
                continue ;
            } 

            dp[i][j] = dp[i-1][j] ;
            if(j-1>=1) dp[i][j] += dp[i-1][j-1] ;
            if(j+1<=m) dp[i][j] += dp[i-1][j+1] ; 
            dp[i][j] %= mod ;
        }
    }
    ll ans = 0 ;
    for(int i=1;i<=m;i++){
        ans += dp[n][i] ;
        ans %= mod ;
    }
    cout << ans << '\n' ;
}