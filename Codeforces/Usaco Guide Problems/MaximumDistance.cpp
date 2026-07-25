#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std ;

int main(){
    int n ; cin >> n ;
    vector<int>x(n) ;
    vector<int>y(n) ;
    for(int i=0;i<n;i++){
        cin >> x[i] ;
    }
    for(int i=0;i<n;i++){
        cin >> y[i] ;
    }
    int maxSum = INT_MIN ;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i==j) continue ;
            int x1 = x[i] - x[j] ;
            int y1 = y[i] - y[j] ;
            int sum = x1*x1 + y1*y1 ;
            maxSum = max(sum,maxSum) ;
        }
    }
    cout << maxSum << '\n' ;
}