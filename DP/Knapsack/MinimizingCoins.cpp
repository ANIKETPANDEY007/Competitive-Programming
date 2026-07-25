#include<iostream>
#include<vector>
#include<climits>
using ll = long long ;
using namespace std ;

ll dp[1000001] ;

int main(){
    int n , amount ;
    cin >> n >> amount ;
    vector<int>coins(n) ;
    for(int i=0;i<n;i++){
        cin >> coins[i] ;
    }
    for(int i=0;i<=amount;i++) dp[i] = INT_MAX ;

    dp[0] = 0 ;
    for(int i=1;i<=n;i++){
        for(int j=coins[i-1];j<=amount;j++){
            dp[j] = min(dp[j],dp[j-coins[i-1]]+1) ; 
            // Current taken coin , To get the previous weight the number of coins takes taken + 1(for the current coin ) . 
        }
    }

    cout << (dp[amount] == INT_MAX ? -1 : dp[amount]) << '\n' ;
    
}