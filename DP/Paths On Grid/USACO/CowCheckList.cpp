#include <iostream>
#include<climits>
#include<vector>

using namespace std;

using ll = long long ;
ll mod = 1e18 ;

struct Coord{
    public : 
        int x , y ; 
} ; 

ll dist(const Coord &a , const Coord &b){
    ll x = (a.x - b.x) ;
    ll y = (a.y - b.y) ;
    return (x*x) + (y*y) ;
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // example below, replace it with your solution
    int h,g;
    cin>> h >> g ;
    vector<Coord> hs(h+1) , gs(g+1) ; 
    for(int i=1;i<=h;i++){
        cin >> hs[i].x >> hs[i].y  ;
    }
    for(int i=1 ;i <= g ; i++){
        cin >> gs[i].x >> gs[i].y ;
    }

    // Here dp[i][j] represents the minimum increasing distance for the farmer John 
    // to visit i holsteins and first j Guernseys , 
    // given that John is at the postion k(0: ith Holstein , 1: ith Guernsey) .

    // Set value to very arbitarily integer to prevent overflow .
    vector<vector<vector<ll>>>dp(h+1,vector<vector<ll>>(g+1,vector<ll>(2,mod))) ;

    dp[1][0][0] = 0 ;
    for(int i=0;i<=h;i++){
        for(int j=0;j<=g;j++){
            if(i>1){
                dp[i][j][0] = min(dp[i][j][0] , dp[i-1][j][0] + dist(hs[i] , hs[i-1])) ; // hs[i-1] -> hs[i]
            }

            if(j>1){
                dp[i][j][1] = min(dp[i][j][1],dp[i][j-1][1] + dist(gs[j-1],gs[j])) ;
            }

            if(i>0 && j>0){
                dp[i][j][0] = min(dp[i][j][0] , dp[i-1][j][1] + dist(hs[i],gs[j])) ; // gs[i] -> hs[i] 

                dp[i][j][1] = min(dp[i][j][1] , dp[i][j-1][0] + dist(hs[i],gs[j])) ; // hs[i] -> gs[i] 
            }
        }
    }
    cout << dp[h][g][0] ;
}
