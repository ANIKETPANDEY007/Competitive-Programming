#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std ;

int main(){
    int t ; cin >> t ;
    while(t-- > 0){
        int n ; cin >> n ;
        string a, b ;
        cin >> a >> b ;

        bool ok = true ;
        long long sum = 0 ;
        for(int k=0; k<2 ;k++){

            vector<int> v1, v2 ;
            for(int i=k ;i<n;i+=2){
                if (a[i] == '1')
                    v1.push_back(i);

                if (b[i] == '1')
                    v2.push_back(i);
            }
            if(v1.size()!=v2.size()){
                ok = false ;
                break ;
            } 
            for(int i=0;i<v1.size();i++) sum += abs(v1[i]-v2[i]) ;
        }

        if(!ok) cout << -1 << '\n' ;
        else cout << sum/2 << '\n' ;
        
    }
    return 0 ;
}