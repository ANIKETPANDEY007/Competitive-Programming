#include<iostream>
#include<vector>
#include<cstring>


using namespace std ;

int main(){
    int n ; cin >> n ;
    vector<int>coins(n) ;
    for(int i=0;i<n;i++){
        cin >> coins[i] ;
    }
    int max_sum = 0 ;
    for(int x: coins ) max_sum += x ;
    vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false));
    dp[0][0] = true;

    for(int i=1;i<=n;i++){ // i -> no. of coins .
        for(int curr_sum = 0;curr_sum<=max_sum;curr_sum++){
            // curr_sum -> current sum . 
            // Basically we are checking if using i number of coins could construct curr_sum . 
            dp[i][curr_sum] = dp[i-1][curr_sum] ; // If i-1 could construct curr_sum and i no. number of coins could also construct curr_sum . 
            int prev_sum = curr_sum - coins[i-1] ;
            if(prev_sum >=0 && dp[i-1][prev_sum]) {
                dp[i][curr_sum] = true ; 

                // Basically the condition is saying that if the prevSum can be acheived using i-1 coins and prevSum >= 0 then after the adding the current coin it is also possible to construct currSum .

                //Ex -> If i=1 curr=5 basically we are checking dp[0][1] means we need 1 coins to construct 5 but from 0 coins it is not possible to get 1(5-4(prev coin)) so that's false and it's doesn't gonna change the value . 
            }
        }
    }

    vector<int>total ;
    for(int sum=1 ; sum <= max_sum ;sum++ ){
        if(dp[n][sum]) total.push_back(sum) ;
    }

    cout << total.size() << "\n" ;

    for(int sum : total){
        cout << sum << " " ;
    }
    cout << "\n" ;

}