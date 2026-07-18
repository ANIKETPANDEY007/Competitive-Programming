#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long ;
using namespace std ;

int main(){
    int n , x ; 
    cin >> n >> x ;
    vector<ll>h(n) , s(n);
    vector<ll>dp(x+1,0) ;
    for(int i=0;i<n;i++){
        cin >> h[i] ;
    }
    for(int i=0;i<n;i++){
        cin >> s[i] ;
    }
    for(int i=0;i<n;i++){
        for(int j=x;j>=h[i];j--){
            dp[j] = max(dp[j],dp[j-h[i]]+s[i]) ;
        }  
    }
    cout << dp[x] << '\n';
}