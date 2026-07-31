#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using pi = pair<int,int> ;
#define f first 
#define s second 
#define sz(x) (int) x.size()

int INF = 1e9 + 7 ;
int MX = 1e3 + 1 ;

int sq(int a){
    return a*a ;
}
int dist(pi a , pi b){
    // Squared distance between two points .
    return sq(a.f - b.f) + sq(a.s - b.s) ;
}

map<char,int>md{{'N',0} , {'E',1} , {'S',2} , {'W',3}} ;

int dx[4] = {0,1,0,-1} ; // N , S has no effect on x dimension
int dy[4] = {1,0,-1,0} ;

// i = current step of John 
// j = current step of Bessie ;

int main(){

    // freopen("radio.in", "r", stdin);
    // freopen("radio.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m ;
    cin >> n >> m ;
    vector<pi>jl(n+1) ; // John location 
    vector<pi>bl(m+1) ; // Bessie location

    int a , b ; 
    cin >> a >> b ;
    jl[0] = {a,b} ;
    cin >> a >> b ;
    bl[0] = {a,b} ;

    string js , bs ; // John and Bessie movement string . 
    cin >> js >> bs ;

    for(int i=0;i<sz(js);i++){
        jl[i+1] = {jl[i].f + dx[md[js[i]]],jl[i].s + dy[md[js[i]]]} ;
    }
    for(int i=0;i<sz(bs);i++){
        bl[i+1] = {bl[i].f + dx[md[bs[i]]],bl[i].s + dy[md[bs[i]]]} ;
    }
    int dp[MX][MX] ;

    fill_n(dp[0],MX*MX,INF) ;
    dp[0][0] = 0 ;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            // John Moves one step .
            dp[i+1][j] = min(dp[i+1][j] , dp[i][j] + dist(jl[i+1],bl[j])) ;
            // Bessie moves one step . 
            dp[i][j+1] = min(dp[i][j+1] , dp[i][j] + dist(jl[i],bl[j+1])) ;
            // Both moves one step . 
            dp[i+1][j+1] = min(dp[i+1][j+1] , dp[i][j] + dist(jl[i+1],bl[j+1])) ;
        }
    }

    cout << dp[n][m] << '\n';


}