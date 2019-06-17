
def main():
    buf = input()
    n = int(buf)
    a = []
    p = []
    for i in range(n):
        buf = input()
        buflist = buf.split()
        a.append(int(buflist[0]))
        p.append(int(buflist[1]))
    cost = 0
    min_price = float("inf")
    for i in range(n):
        if p[i] < min_price:
            min_price = p[i]
        cost += a[i] * min_price
    print(cost)    

if __name__ == '__main__':
    main()
