#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

int main(){
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin >> n ;
    vector<int>right(n+1) ;
    vector<int>left(n+1) ;

    for(int i=1;i<=n;i++) cin >> right[i] ;
    for(int i=1;i<=n;i++) cin >> left[i] ;
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,0)) ;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
            if(abs(left[i]-right[j])<=4){
                dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + 1) ;
            }
        }
    }
    cout << dp[n][n] << '\n' ;
}