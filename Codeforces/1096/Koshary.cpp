#include<iostream>
using namespace std ;

int main(){
    int t ; cin >> t ;
    while(t-- > 0){
        int x , y ;
        cin >> x >> y ;
        if(x%2!=0 && y%2 != 0){
            cout << "NO" << '\n' ;
        }else{
            cout << "YES" << '\n' ;
        }
    }
}