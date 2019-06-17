import random

def main():
    print(100000)
    s = ''
    for i in range(100000):
        s += str(random.randint(0, 9))
    print(s)

if __name__ == '__main__':
    main()
