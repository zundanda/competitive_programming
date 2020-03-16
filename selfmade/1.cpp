#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

using ll = long long;

int main (){
    int N;
    cin>>N;
    bool isvalid[N+1]; //ip^2の形でないものがisvalidでtrueになる.
    fill(isvalid,isvalid+N+1,true);
    for(int p=2;p*p<=N;p++){
        for(int i=0;i*p*p<=N;i++){
            isvalid[i*p*p]=false;
        }
    }
    ll ans=0;
    for(int i=0;i<=N;i++){
        if(isvalid[i]){
            for(int j=1;i*j*j<=N;j++){
                int k=sqrt(N/i)-j; //sqrt(i)(j+k)<=sqrt(N)を満たすkの個数を数える. 計算より1<=k<=sqrt(N/i)-jを満たす整数kの個数である.
                ans+=k;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
