#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

using ll = long long;

int main (){
    int N;
    cin>>N;
    ll ans=0;
    bool isvalid[N+1];
    fill(isvalid,isvalid+N+1,true);
    for(int p=2;p*p<=N;p++){
        for(int i=0;i*p*p<=N;i++){
            isvalid[i*p*p]=false;
        }
    }
    vector<int> valid;
    for(int i=0;i<=N;i++){
        if(isvalid[i]) valid.push_back(i);
    }
    for(auto i:valid){
        for(int j=1;j*j<=N/i;j++){
            int k=sqrt(N/i)-j;
            ans+=k;
        }
    }
    cout<<ans<<endl;
    return 0;
}
