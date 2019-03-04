P = int(input())
for _ in range(P):
    K, M, x = input().split()
    K = int(K)
    M = int(M)
    x = float(x)
    min_diff = 1
    min_frac = (1,1)
    for den in range(M//2,M+1):
        num = round(x * den)
        diff = abs(x-num/den)
        if diff < min_diff:
            min_diff = diff
            min_frac = (num,den)
    print("{} {}/{}".format(K,min_frac[0],min_frac[1]))

