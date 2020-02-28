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
template <typename T>
ostream& operator<<(ostream& os, vector<T> &V){
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
    os << "(";
    os << P.first;
    os << " , ";
    os << P.second;
    os << ")";
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
//fixed<<setprecision(10)<<ans<<endl;

random_device seed_gen; 
mt19937_64 engine(seed_gen());
const uint64_t random_base = engine()%100000+1000;
template <typename T> 
struct RollingHash{
    const uint64_t mod = (1ull << 61) - 1;
    const uint64_t base = random_base;
    const uint64_t MASK31 = (1ull << 31) - 1;
    const uint64_t MASK30 = (1ull << 30) - 1;
    vector<uint64_t> pows, hash;
    RollingHash(const T& S)
        : pows(S.size()+1,1), hash(S.size()+1,0) {
        size_t N = S.size();
        for(int i=0; i<N; i++){
            hash[i+1] = CalcMod( Mul(hash[i], base) + S[i] );
            pows[i+1] = CalcMod( Mul(pows[i], base));
        }
    }

    uint64_t Mul(uint64_t a, uint64_t b){
        uint64_t au = a>>31 , ad = a & MASK31; //上位30bitと下位31bit
        uint64_t bu = b>>31 , bd = b & MASK31; //上位30bitと下位31bit

        uint64_t mid = ad*bu + au*bd, midu = mid>>30, midd = mid&MASK30;
        return au*bu*2 + midu + (midd<<31) + ad*bd;
    }

    uint64_t CalcMod(uint64_t val){
        val = (val&mod) + (val>>61);
        if (val >= mod) val-=mod;
        return val;
    }

    uint64_t get_hash(int l, int r){
        if (r<l){
            cerr << "r<l:" << make_pair(l,r) << endl;
        }
        unsigned long long a = hash[r], b =CalcMod( Mul(hash[l] , pows[r-l]));
        while (a<b) a+= mod;
        uint64_t res = CalcMod(a-b);
        return res;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();

    RollingHash<string> RH(S);
    auto a = RH.get_hash(1,11);
    map<unsigned long long, int> cnt;
    REP(l,N){
        for(int r=l+1; r<=min(N,l+11); r++){
            cnt[RH.get_hash(l,r)]++;
        }
    }
    int M;
    cin >> M;

    int ans=0;
    REP(i,M){
        string s; cin >> s;
        RollingHash<string> rh(s);
        ans += cnt[rh.get_hash(0,s.size())];
    }


    cout << ans << endl;
}