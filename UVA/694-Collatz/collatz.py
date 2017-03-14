import sys

def collatz_terms(A, limit):
    num_terms = 0
    while A != 1 and A <= limit:
        if A % 2 == 0:
            A /= 2
        else:
            A = 3 * A + 1
        num_terms += 1
    if A == 1:
        num_terms += 1
    return num_terms

case = 1
for line in sys.stdin:
    A, limit = [int(n) for n in line.split()]
    if A < 0 and limit < 0:
        break
    print("Case {}: A = {}, limit = {}, number of terms = "
          "{}".format(case,A,limit,collatz_terms(A,limit)))
    case += 1

