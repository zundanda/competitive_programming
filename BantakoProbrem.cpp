#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
constexpr ll longinf=__LONG_LONG_MAX__;

//Bantakoくんの問題

//x:正の整数に対し
//if xが十進法で二桁以上 then f[x]=f[xの各桁の総乗]+1
//else f[x]=0
//とfを定める
//f[x]=yを満たすxの最小値を高速に求めるプログラム(ただしx<=3*10^17まで)((yはこの範囲だと11までしか値を取らない！))

//方針はxの各桁の総和が2^i*3^j*5^k*7^lになることを使うもので、以下の1.2.を全探索
//1. 2^i*3^j*5^k*7^lの形の整数
//2. f[x]=f[2^i*3^j*5^k*7^l]+1の形になる整数xのうち最小のもの

//1<=i,j,k,l<=logxくらいで
//(xの各桁の総乗<x)を使ってメモ化をするためにsortしたり、飛び飛びの値を扱うためにmapを使うのでさらにlogがついて
//計算量はO((logx)^4*loglogx)くらい、たぶん。

vector<ll> candidate; //f[x]=hogeを満たすxの最小値の候補(x=2^i*3^j*5^k*7^lの形のもの)
vector<ll> candidate2; //f[x]=hogeを満たすxの最小値の候補2(f[x]=f[2^i*3^j*5^k*7^l]+1を満たすxの最小値)

ll total_power_inv(ll n,int i2,int i3,int i5,int i7){ //f[x]=f[2^i2*3^i3*5^i5*7^i7]+1を満たす数xのうち最小のものを返す
    ll ret=0;
    int i[10]={0,0,i2,i3,0,i5,0,i7,0,0};
    if(i[2]%3>=1&&i[3]%2==1){
        i[6]=1;
        --i[2];
        --i[3];
    }
    if(i[2]%3==2){
        i[4]=1;
        i[2]-=2;
    }
    i[8]=i[2]/3;
    i[9]=i[3]/2;
    i[2]-=(3*i[8]);
    i[3]-=(2*i[9]);
    for(int j=2;j<10;j++){
        for(int k=0;k<i[j];k++){
            ret*=10;
            ret+=j;
            if(ret>n){
                return -1;
            }
        }
    }
    return ret;
}

ll total_power(ll x){ //nの各桁の総乗を返す
    ll ret=1;
    while(x>0){
        ll pos=x%10;
        ret*=pos;
        x/=10;
    }
    return ret;
}

void calc(ll n,ll pos,ll i2,ll i3,ll i5, ll i7){
    if(pos>=n){
        return;
    }
    else{
        candidate.push_back(pos);
        ll pos2=total_power_inv(n,i2,i3,i5,i7);
        if(pos2>0) candidate2.push_back(pos2);
        if(pos%3!=0&&pos%5!=0&&pos%7!=0){
            calc(n,2*pos, i2+1, i3, i5, i7);
        }
        if(pos%5!=0&&pos%7!=0){
            calc(n,3*pos, i2, i3+1, i5, i7);
        }
        if(pos%7!=0){
            calc(n,5*pos, i2, i3, i5+1, i7);
        }
        calc(n,7*pos, i2, i3, i5, i7+1);
    }
}

int main(){
    ll n=3e17;
    calc(n,1,0,0,0,0); //nまでのf[x]=yを満たす最小値xの候補を計算してcandidate,candidate2に突っ込む
    sort(candidate.begin(),candidate.end());
    sort(candidate2.begin(),candidate2.end());
    map<ll,int> f;
    vector<ll> minimum_x(20,longinf); //f[x]=yとなるxの最小値がminimum_x[y] longinfで初期化(yのmaxは範囲内で11なので20くらい取っておく)
    for(auto x:candidate){
        if(x<10) f[x]=0;
        else f[x]=f[total_power(x)]+1;
        minimum_x[f[x]]=min(minimum_x[f[x]],x);
    }
    for(auto x:candidate2){
        if(x<10) f[x]=0;
        else f[x]=f[total_power(x)]+1;
        minimum_x[f[x]]=min(minimum_x[f[x]],x);
    }
    for(int y=0;y<20;y++){
        if(minimum_x[y]<longinf){ //初期化した値より小さかったら更新されているので出力
        cout<<"f["<<minimum_x[y]<<"] = "<<y<<endl;
        }
    }
    return 0;
}
