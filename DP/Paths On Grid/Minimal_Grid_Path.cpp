#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ; cin >> n ;
    vector<vector<char>>grid(n,vector<char>(n)) ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j] ;
        }
    }

    vector<vector<string>>dp(n,vector<string>(n)) ;
    dp[0][0] = string(1,grid[0][0]) ;
    for (int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            if(i>0 && j>0){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) ;
                dp[i][j] += grid[i][j] ;
            }else if(i>0){
                dp[i][j] = dp[i-1][j] + grid[i][j] ;
            }else if(j>0){
                dp[i][j] =  dp[i][j-1] + grid[i][j] ;
            }
        }
    }

    cout << dp[n-1][n-1] ;
}