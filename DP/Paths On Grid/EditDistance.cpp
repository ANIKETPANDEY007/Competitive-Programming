#include<iostream>
#include<climits>
#include<string>
#include<vector>

using namespace std ;

int main(){
    string str1 , str2 ;
    cin >> str1 >> str2 ;
    int n = str1.size() ;
    int m = str2.size() ;
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX)) ;
    // dp[i][j] -> here i denotes the minimum number of edits to convert the first i character of the first string to the first j characters of the second string . 

    // Base case when the string is empty . 
    dp[0][0] = 0 ;

    for(int i=0;i<=n;i++){
    // At i=0 -> Basically the string 1 is empty and we are comparing it with string2 so at each j we after comparing we have to insert an element j that's why we are adding 1 . 

    // At j = 0 -> Similarly the same concept while we are adding it as there are no elements on the string 2 .

        for(int j=0;j<=m;j++){
            if(i!=0) dp[i][j] = min(dp[i-1][j]+1,dp[i][j]) ;

            if(j!=0) dp[i][j] = min(dp[i][j],dp[i][j-1]+1) ;

            if(i!=0 && j!=0) {
                int new_sum = dp[i-1][j-1] + ( str1[i-1] != str2[j-1]) ;
                dp[i][j] = min(new_sum , dp[i][j]) ;
            }
        }
    }

    cout << dp[n][m] ;
    
}