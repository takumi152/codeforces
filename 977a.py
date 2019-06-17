
def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    k = int(buflist[1])
    for i in range(k):
        if n % 10 != 0:
            n -= 1
        else:
            n //= 10
    print(n)

if __name__ == "__main__":
    main()
