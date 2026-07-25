#include<iostream>
#include<vector>

using ll = long long ;
using namespace std ;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ; cin >> t ;
    while(t-- > 0){
        int n ; cin >> n ;
        vector<int>six ;
        vector<int>three ;
        vector<int>two ;
        vector<int>arr ;
        for(int i=0;i<n;i++){
            int a ;
            cin >> a ;
            if(a%6==0) six.push_back(a) ;
            else if(a%2==0) two.push_back(a) ;
            else if(a%3==0) three.push_back(a) ;
            else arr.push_back(a) ;
        }
        for(int x : six) cout << x << " " ;
        for(int x : two) cout << x << " " ;
        for(int x : arr) cout << x << " " ;
        for(int x : three) cout << x << " " ;
        cout << '\n' ;
    } 

    return 0 ;

}