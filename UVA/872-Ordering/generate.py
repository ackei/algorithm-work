import string
import random
import itertools

def main():

    T = random.randint(1, 5)
    print(T, end="\n\n")
    identifiers = list(string.ascii_uppercase)
    for _ in range(T):
        random.shuffle(identifiers)
        nVar = random.randint(2, 10)
        print(' '.join(identifiers[:nVar]))
        relations = random.sample(
            [(x, y) for x in range(nVar) for y in range(x+1, nVar)],
            random.randint(0, nVar*(nVar-1)/2)
        )
        for x, y in relations:
            print(identifiers[x], '<', identifiers[y], sep='', end=' ')
        print("\n")

if __name__ == '__main__':
    main()
