#include<iostream>
#include<vector>
#define ll long long

using namespace std ;

signed main(){
    ll n , x ;
    cin >> n >> x ;

    int s1 = n/2 ;
    int s2 = n-n/2 ;

    vector<ll>t1(s1) , t2(s2) ;
    for(int i=0;i<s1;i++) cin >> t1[i] ;
    for(int i=0;i<s2;i++) cin >> t2[i] ;

    vector<int>sum1 , sum2 ;

    for(int i=0;i<(1LL<<s1) ; i++){
        ll sum = 0 ;
        for(ll j=0 ; j<s1 ; j++){
            if(((1LL << j) & i)!=0){
                sum += t1[j] ;
            }
        }
        sum1.push_back(sum) ;
    }

    for(int i=0;i<(1LL<<s2);i++){
        ll sum = 0 ;
        for(ll j=0 ; j<s2 ; j++){
            if(((1LL<<j) & i)!=0){
                sum += t2[j] ;
            }
        }
        sum2.push_back(sum) ;
    }

    ll ans = 0 ;

    sort(sum1.begin(),sum1.end()) ;
    sort(sum2.begin(),sum2.end()) ;

    for(int i=0 ; i<sum1.size() ; i++){
        int l = lower_bound(sum2.begin() , sum2.end(),x-sum1[i]) - sum2.begin() ;
        int r = upper_bound(sum2.begin() , sum2.end(),x-sum1[i]) - sum2.begin()- 1 ;

        if(l<=r) ans += (r-l+1) ;
    }

    cout << ans << endl ;

}