import random

def main():
    n = 200000
    print(n)
    p = ""
    for i in range(n):
        p += str(random.randint(1, 10000000))
        if i != n - 1:
            p += " "
    print(p)

if __name__ == '__main__':
    main()
