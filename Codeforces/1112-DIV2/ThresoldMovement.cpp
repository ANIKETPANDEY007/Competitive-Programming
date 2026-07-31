// Just think of a < k < b where a is the lower bound and b is the upper bound and we have to maintain this throughout the array . As the we traverse in the array moves towards i -> 1 to i -> n the value for the a we have to take the maximum (a will be in the ) and for the b we have to find the minimum lower bound . 



#include<iostream>
#include<vector>

using namespace std ;

int main(){
    int t ; cin >> t ;
    while(t-- > 0){
        int n ; cin >> n ;
        vector<int>v(n+1,0) ;
        for(int i=1;i<=n;i++){
            cin >> v[i] ;
        } 
        int low = INT_MAX , high = INT_MIN ;

        if(n%2 != 0){
            cout << "NO\n";
            continue ;
        }
        for(int i=1;i<=n;i++){
           if(i & 1){
                low = min(v[i],low) ;
           }else{
                high = max(v[i],high) ;
           }
        }
        if(low - high >= 2){
            cout << "YES\n" ;
        }else{
            cout << "NO\n" ; 
        }
    }
    return 0 ;
}