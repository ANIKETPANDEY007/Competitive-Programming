#include<iostream>
#include<string>
using namespace std ;

int main(){
    int t ; cin >> t ;
    while(t-- > 0){
        int n ; cin >> n ;
        string s ; cin >> s ;
        int c1 = 0 , c2 = 0 ;
        for(char ch : s){
            if(ch=='(') c1++ ;
            else c2++ ;
        }
        if(c1==c2) cout << "YES" << '\n' ;
        else cout << "NO" << '\n' ;
    }
}