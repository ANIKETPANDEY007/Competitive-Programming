#include<iostream>
#include<vector>

using namespace std ;

int main(){
    int t ; cin >> t ;
    while(t-- > 0){
        int n ;
        cin >> n ;
        vector<int> v(2*n) ;
        vector<bool> b(n,false) ;
        for(int i=0;i<2*n;i++){
            cin >> v[i] ;
            b[v[i]] = true ;
        }
    }
}