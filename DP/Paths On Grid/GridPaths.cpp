#include<iostream>
#include<vector>
using namespace std ;

int mod = 1e9 + 7 ;

int main(){
    int n ; cin >> n ;
    vector<vector<char>>grid(n,vector<char>(n)) ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j] ;
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,0)) ;
    if (grid[0][0] == '*') {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '*'){
                dp[i][j] = 0 ;
                continue ;
            } 
            if (i == 0 && j == 0) continue;
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n-1][n-1] ;
}