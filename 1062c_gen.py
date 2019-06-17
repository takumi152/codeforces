import random

def main():
    n = 100000
    q = 100000
    print(n, q)
    x = ""
    for i in range(n):
        x += str(random.randint(0, 1))
    print(x)
    for i in range(q):
        a = random.randint(1, n)
        b = random.randint(1, n)
        if a < b:
            print(a, b)
        else:
            print(b, a)

if __name__ == '__main__':
    main()
