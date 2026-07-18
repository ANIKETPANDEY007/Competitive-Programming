#include<iostream>
#include<vector>
#include<climits>

using ll = long long ;
using namespace std ;

int mod = 1e9 + 7 ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , x ;
    cin >> n >> x ;

    vector<int>coins(n),dp(x+1) ;
    for(int i=0;i<n;i++){ cin>>coins[i] ;} 
    dp[0] = 1 ;

    for(int i=1;i<=x;i++){
        for(int j : coins){
            if(i-j>=0){
                dp[i] += dp[i-j] ;
                if(dp[i]>=mod) dp[i] -= mod ;
            } 
        }
    }

    cout << dp[x] << '\n' ;
}