#include<iostream>
#include<string>

using namespace std ;

int main(){
    int t ; 
    cin >> t ;
    while(t--){
        int n ; cin >> n ;
        string s1 , s2 ;
        cin >> s1 >> s2 ;
        int os1=0 , es1=0 , os2=0 , es2=0 ;
        
        for(int i=1;i<=n;i++){
            if(s1[i-1]=='1' && i%2!=0) os1++ ;
            else if(s1[i-1]=='0' && i%2==0) es1++ ;

            if(s2[i-1]=='1' && i%2!=0) os2++ ;
            else if(s2[i-1]=='0' && i%2==0) es2++ ;
        }

        if(os1==os2 && es1==es2) cout << "Yes\n" ;
        else cout << "No\n" ;
    }
}