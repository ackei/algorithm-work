import re

def nextval(val):
    ival = int(val)
    rev = int("".join(list(reversed(val))))
    nval = ival + rev
    nval = int("".join(list(sorted(str(nval)))))
    result = str(nval)
    return str(nval)

def isCreeper(val):
    return re.match("^123{2,}4444$", val) or re.match("^556{2,}7777$", val)

def main():

    P = int(input())
    for _ in range(P):
        K, M, val = input().split()
        K, M = int(K), int(M)
        seen = set()
        for i in range(1, M):
            if isCreeper(val):
                print("{K} C {i}".format(**locals()))
                break
            if val in seen:
                print("{K} R {i}".format(**locals()))
                break
            seen.add(val)
            val = nextval(val)
        else:
            if val in seen:
                print("{K} R {M}".format(**locals()))
            else:
                print("{K} {val}".format(**locals()))


if __name__ == "__main__":
    main()
