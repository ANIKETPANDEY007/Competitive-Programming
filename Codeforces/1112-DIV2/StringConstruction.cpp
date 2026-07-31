#include<iostream>
#include<string>

using namespace std ;

int main(){
    int t ; cin >> t ;
    while(t-- > 0){
        int n , k ;
        cin >> n >> k ;
        string s = "" ;

        int c0 = 0 ;
        int c1 = 1 ; 
        if(k+1==n || k>((n+1)/2)) {
            cout << -1 << '\n' ;
            continue ;
        }else{
            int c0 = n/2-k/2 ;
            int c1 = n - n/2 - (k-k/2);
            for(int i=)
            cout << s << '\n' ;
        }
    }
}