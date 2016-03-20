import random
import itertools

def main():

    n = random.randint(10, 20)
    m = random.randint(0, n)

    print(n, m)
    edges = list(itertools.combinations(range(n), 2))
    for x, y in random.sample(edges, random.randint(n // 2, min(10*n, len(edges)))):
        print(x, y)

    print(-1, -1)
    print(0, 0)

if __name__ == '__main__':
    main()
