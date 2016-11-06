def main():

    n = int(input())
    for i in range(n):
        C, R, S = input().split()
        R = int(R)
        SR = "".join([c*R for c in S])
        print(C, SR)

if __name__ == "__main__":
    main()
