#include<iostream>
#include<vector>

using namespace std ;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin >> n >> m ;
    // A C G T 
    string s[n] , p[n] ;
    vector<bool>v(m,true) ;

    for(int i=0; i<n; i++) cin >> s[i] ;
    for(int j=0; j<n; j++) cin >> p[j] ;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(s[i][j]==p[k][j] && v[j]){
                    v[j] = false ;
                }
            }    
        }
    }
    int count = 0 ;

    for(int i=0;i<m;i++){
        if(v[i]) count++ ;
    }
    cout << count << '\n' ;

}