/*
　　　∫ ∫ ∫
　　　ノヽ
　　（＿　 ）
　（＿　　　 ）
（＿＿＿＿＿＿ ）
　ヽ(´･ω･)ﾉ　
　　 |　 /
　　 UU
*/
#pragma region macro
#include <bits/stdc++.h>
typedef long long int64;
using namespace std;
using P = pair<int64, int64>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const int64 INF = 1LL << 62;
const int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
#define bn '\n'
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T,typename S>
ostream& operator<<(ostream& os, pair<T,S> const&P){
    os << P.first;
    os << " ";
    os << P.second;
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> &S){
    auto it=S.begin();
    while(it!=S.end()){
        os << *it;
        os << " ";
        it++;
    }
    os << "\n";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T> &q){
    for(auto it=q.begin();it<q.end();it++){
        os<<*it;
        os<<" ";
    }
     os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;


struct Eratosthenes{
    int N;
    vector<int> data;
    Eratosthenes(int N):N(N){
        data.assign(N+1,-1);
        for(int64 i=2;i*i<=N;i++){
            if(data[i]!=-1) continue;
            for (int j=i; j<=N; j+=i){
                data[j] = i;
            }
        }
    }

    int64 prime_factorization(int X){
        map<int,int> pri;
        while (data[X]!=-1){
            int prime = data[X];
            pri[prime] += 1;
            X /= prime;
        }
        if(X!=1) pri[X] += 1;
        int64 res = 1;
        for(auto it=pri.begin(); it!=pri.end(); it++) res *= ((*it).second+1);

        return res;
    }


};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    Eratosthenes Era(N);
    int64 ans = INF;
    vector<pair<int,int>>  ans_vec;
    for(int i=1;i<N;i++){
        int j = N-i;
        auto pri_i = Era.prime_factorization(i);
        auto pri_j = Era.prime_factorization(j);
    
        if(chmin(ans,abs((i-pri_i)-(j-pri_j)))) {
            ans_vec.erase(ALL(ans_vec));
        }
        if(ans>=abs((i-pri_i)-(j-pri_j))) ans_vec.emplace_back(i,j);
    }

    for(auto a:ans_vec) cout << a << bn;
}