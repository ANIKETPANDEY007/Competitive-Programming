#include<iostream>
#include<vector>
#include<algorithm>
#define f first 
#define s second 

using namespace std ;
int INF = 1e9 + 1 ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    cin >> n ;
    vector<pair<char,int>> v(n+1) ;
    for(int i=1;i<=n;i++){
        char c ; int p ;
        cin >> c >> p ;
        v[i] = {c,p} ;
    }
    int lies = INF ;
    // We have to count the minimum number of lies 
    for(int i=1;i<=n;i++){
        int count = 0 ;
        int x = v[i].s ;
        for(int j=1;j<=n;j++){
            if(v[j].f == 'G'){
                if(x < v[j].s) count++ ;
            }else{
                if(x > v[j].s) count++ ;
            }
             
        }
        lies = min(count,lies) ;
    }
    cout << lies << '\n' ;
    return 0 ;
}