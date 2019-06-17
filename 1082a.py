import math

def main():
    buf = input()
    t = int(buf)
    n = []
    x = []
    y = []
    d = []
    for i in range(t):
        buf = input()
        buflist = buf.split()
        n.append(int(buflist[0]))
        x.append(int(buflist[1]))
        y.append(int(buflist[2]))
        d.append(int(buflist[3]))
    for i in range(t):
        min = int(1e18)+1
        if abs(x[i] - y[i]) % d[i] == 0:
            if abs((x[i] - y[i]) // d[i]) < min:
                min = abs((x[i] - y[i]) // d[i])
        if abs(y[i] - 1) % d[i] == 0:
            if abs(math.ceil((x[i] - 1) / d[i])) + abs((y[i] - 1) // d[i]) < min:
                min = abs(math.ceil((x[i] - 1) / d[i])) + abs((y[i] - 1) // d[i])
        if abs(y[i] - n[i]) % d[i] == 0:
            if abs(math.ceil((x[i] - n[i]) / d[i])) + abs((y[i] - n[i]) // d[i]) + 1 < min:
                min = abs(math.ceil((x[i] - n[i]) / d[i])) + abs((y[i] - n[i]) // d[i]) + 1
        if min > int(1e18):
            print(-1)
        else:
            print(min)

if __name__ == '__main__':
    main()
