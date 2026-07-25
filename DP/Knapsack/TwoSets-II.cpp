#include<iostream>
#include<vector>

using namespace std ;

int main() {
    int n ; cin >> n ;
    int mod = 1e9 + 7 ;

    int sum = n*(n+1)/2 ;

    if(sum%2==1){
        cout << 0 << endl ;
        return 0 ;
    } 

    // Each subset sum needs to be half .
    sum /= 2 ;

    // dp[i][j] = the numbers of ways to make the sum j from the numbers 1 to i .
    vector<vector<int>>dp(n,vector<int>(sum+1,0)) ;

    //Base case -> There is one way to get sum 0 using 0 .
    dp[0][0] = 1 ;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j] += dp[i-1][j] ;

            // previous sum including the current element .
            int prev = j-i ;

            if(prev>=0) dp[i][j] += dp[i-1][prev] ;

            dp[i][j] %= mod ;
        }
    }
    cout << dp[n-1][sum] << "\n" ;
}