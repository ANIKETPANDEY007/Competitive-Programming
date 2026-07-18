#include <iostream>
using namespace std;

int main() 
{
    long long n ; cin >> n ;
    const int mod = 1e9 + 7 ;
    long long dp[1000001] = {0} ;
    dp[0] = 1 ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0) dp[i] = (dp[i] + dp[i-j])%mod ;
        }
    }
    cout << dp[n] << '\n' ;

}