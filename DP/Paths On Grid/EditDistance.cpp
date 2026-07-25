#include<iostream>
#include<string>
#include<vector>

using namespace std ;

int main(){
    string str1 , str2 ;
    cin >> str1 >> str2 ;
    int n = str1.size() ;
    int m = str2.size() ;
    vector<vector<int>>dp(n+1,vector<int>(m+1)) ;
    // dp[i][j] -> here i denotes the minimum number of edits to convert the first i character of the first string to the first j characters of the second string . 

    // Base case when the string is empty . 
    
}