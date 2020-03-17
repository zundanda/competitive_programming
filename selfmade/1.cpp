#include<iostream>
#include<math.h>
using namespace std;

using ll = long long;

int main (){
    int N;
    cin>>N;
    bool square_free[N+1]; 
    fill(square_free,square_free+N+1,true);
    for(int p=2;p*p<=N;p++){
        for(int i=1;i*p*p<=N;i++){
            square_free[i*p*p]=false; //平方因子を持つ整数をfalseにする.
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        if(square_free[i]){//平方因子を持たない整数iに対し
            int m=sqrt(N/i); 
            ans+=((m*(m-1))/2); //sqrt(i)(j+k)<=sqrt(N)を満たす(j,k)の個数を数える.
        }
    }
    cout<<ans<<endl;
    return 0;
}
