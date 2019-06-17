import random

def main():
    print(1000, 1000)
    for i in range(1000):
        s = ''
        for j in range(1000):
            s += chr(random.randint(0x61, 0x7a))
        print(s)

if __name__ == '__main__':
    main()
