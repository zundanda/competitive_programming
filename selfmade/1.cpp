#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

using ll = long long;

int main (){
    int N;
    cin>>N;
    bool square_free[N+1]; //square_freeなものはtrueになる.
    fill(square_free,square_free+N+1,true);
    for(int p=2;p*p<=N;p++){
        for(int i=1;i*p*p<=N;i++){
            square_free[i*p*p]=false;
        }
    }
    ll ans=0;
    for(int i=1;i<=N;i++){
        if(square_free[i]){
            for(int j=1;i*j*j<=N;j++){
                int k=sqrt(N/i)-j; //sqrt(i)(j+k)<=sqrt(N)を満たすkの個数.
                ans+=k;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
