a,b = map(int,input().split())
base = 10**1000
sign = (a<0) ^ (b<0)
print(((-1)**sign)*(abs(a)//abs(b)))