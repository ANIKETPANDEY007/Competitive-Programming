#include<iostream>
#include<string>
#include <algorithm>

using namespace std ;

int main(){
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        string s ; cin >> s ;
        int len = 1 ; 
        // Here len counts the number of continuous groups . 

        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) len++ ;
        }

        int red = 0 ;
        // Here red is the maximum number of groups we can eleminate .
        // Or the number of the reduction possible of the group .  

        for(int i=1;i<n-1;i++){
            if(s[i]!=s[i-1] && s[i]!=s[i+1]){
                if(s[i-1] == s[i+1]) red = max(red,2) ;
                else red = max(red,1) ;
            }
        }

        cout << len - red << '\n' ;

    }
}