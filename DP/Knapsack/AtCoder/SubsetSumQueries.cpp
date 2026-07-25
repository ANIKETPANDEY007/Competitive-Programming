#include<iostream>
#include<vector>

using namespace std ;

int main(){
    int mod = 998244353 ;
    int q , k ;
    cin >> q >> k ;
    vector<int>dp(k+1) ;
    dp[0] = 1 ;
    for(int i=0;i<q;i++){
        char type ;
        int x ;
        cin >> type >> x ;
        if(type=='+'){
            for(int j=k;j>=x;j--){
                (dp[j] += dp[j-x])%=mod ;
            }
        }else{
            for(int j=x;j<=k;j++){
                (dp[j] += mod - dp[j-x])%=mod ;
            }
        }
        cout << dp[k] << '\n' ;
    }
}