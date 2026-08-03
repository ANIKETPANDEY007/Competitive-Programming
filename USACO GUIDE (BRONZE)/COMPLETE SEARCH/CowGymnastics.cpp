#include<iostream>
#include<vector>

using namespace std ;

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n , k ; // n -> number of cows . 
    // k -> number of sessions . 
    cin >> k >> n ;
    vector<vector<int>>pos(k+1 , vector<int>(n+1)) ;
    for(int s=1;s<=k;s++){
        for(int r=1;r<=n;r++){
            int cow ;
            cin >> cow ;
            pos[s][cow] = r ;
            // position of the cow in the session[s] .
        }
    }
    int ans = 0 ;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){

            if(a==b) continue ;
            bool ok = true ;

            for(int s=1;s<=k;s++){
                if(pos[s][a] > pos[s][b] ){
                    ok = false ;
                    break ;
                }
            }
            if(ok) ans++ ;
        }
    }
    cout << ans << '\n' ;
}