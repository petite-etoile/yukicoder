#
# 　　  ⋀_⋀　 
#　　  (･ω･)  
# .／ Ｕ ∽ Ｕ＼
#  │＊　合　＊│
#  │＊　格　＊│ 
#  │＊　祈　＊│ 
#  │＊　願　＊│ 
#  │＊　　　＊│ 
#      ￣
#
import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
inf=float('inf')
mod = 10**9+7
def pprint(*A): 
    for a in A:     print(*a,sep='\n')
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [I() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
class RollingHash:
    BASE = randint(1000,1000000)
    MOD = 2**61-1
    def __init__(self,S):
        self.hash = [0]*(len(S)+1)
        self.pows = [1]*(len(S)+1)
        for i,s in enumerate(S,start=1):
            self.hash[i] = (self.hash[i-1] * self.BASE + ord(s)) % self.MOD
            self.pows[i] = (self.pows[i-1] * self.BASE         ) % self.MOD
        
    #S[l:r]のハッシュを取得する
    def get_hash(self,l,r):
        if r-l<0:
            print("r<l",(r,l),file=sys.stderr)
        return (self.hash[r] - self.hash[l] * self.pows[r-l]) % self.MOD

def main():
    S=ST()
    RH = RollingHash(S)
    cnt = defaultdict(int)
    for l in range(len(S)):
        for r in range(l+1,l+11):
            if r>len(S):
                break
            cnt[RH.get_hash(l,r)] += 1

    M=I()
    ans = 0
    for _ in range(M):
        s = ST()
        h = RollingHash(s).get_hash(0,len(s))
        ans += cnt[h]
    print(ans)
if __name__ == '__main__':
    main()