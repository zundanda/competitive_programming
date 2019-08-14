#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
constexpr ll longinf=__LONG_LONG_MAX__;

//x:正の整数に対し
//if xが十進法で二桁以上 then f[x]=f[xの各桁の総乗]+1
//else f[x]=0
//とfを定める
//f[x]=yを満たすxの最小値を高速に求めるプログラム(ただしx<=3*10^17まで)
//計算量はO((logx)^4*loglogx)くらい、たぶん

vector<ll> candidate; //f[x]=hogeを満たすxの最小値の候補
vector<ll> candidate2; //f[x]=hogeを満たすxの最小値の候補2

ll total_power_inv(ll n,int i2,int i3,int i5,int i7){ //各桁の総乗が2^i2*3^i3*5^i5*7^i7を満たす数のうち最小のものを返す
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

ll total_power(ll n){ //nの各桁の総乗を返す
    ll ret=1;
    while(n>0){
        ll pos=n%10;
        ret*=pos;
        n/=10;
    }
    return ret;
}

void calc(ll n,ll pos,ll i2,ll i3,ll i5, ll i7){
    if(pos>=n||pos<0){
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
    calc(n,1,0,0,0,0); //nまでの候補となる数字を計算
    sort(candidate.begin(),candidate.end());
    sort(candidate2.begin(),candidate2.end());
    map<ll,int> f;
    vector<ll> minimum_x(20,longinf); //f[x]=hogeとなるxの最小値がminimum_x[hoge] longinfで初期化
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
