import random

def main():
    print(100000)
    a = []
    for i in range(100000):
        a.append(str(random.randrange(1, 1 << 30)))
    print(' '.join(a))

if __name__ == '__main__':
    main()
