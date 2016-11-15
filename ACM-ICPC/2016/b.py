DIGITS = "0123456789ACDEFHJKLMNPRTVWX"
char2digit = {c: i for i, c in enumerate(DIGITS)}
confusing = {
    "B": "8", "G": "C", "I": "1", "O": "0", "Q": "0", "S": 5, "U": "V", "Y": "V", "Z": "2"
}

coeffs = [2, 4, 5, 7, 8, 10, 11, 13]

def times(p):
    return p[0]*p[1]

def replace_confusing(ucn):
    for i in range(len(ucn)):
        if ucn[i] in confusing:
            ucn[i] = confusing[ucn[i]]
    return ucn

def main():
    P = int(input())
    for gbg in range(P):
        K, ucn_d = input().split()
        ucn, icd = ucn_d[:-1], ucn_d[-1]
        ucn = replace_confusing(ucn)
        cd = sum(map(times, zip(coeffs, [char2digit[c] for c in ucn]))) % 27
        if cd != char2digit[icd]:
            print(K, "Invalid")
            continue
        acc = 0
        pwr = 1
        for i in reversed(range(8)):
            acc += char2digit[ucn[i]]*pwr
            pwr *= 27
        print(K, acc)

if __name__ == "__main__":
    main()
