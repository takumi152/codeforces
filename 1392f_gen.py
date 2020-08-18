import random

def main():
    n = 1000000
    a = [10 ** 12 - (n - i + 1) for i in range(n)]
    print(n)
    print(' '.join([str(x) for x in a]))

if __name__ == '__main__':
    main()
