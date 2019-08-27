
def main():
    buf = input()
    q = int(buf)
    l = []
    r = []
    d = []
    for i in range(q):
        buf = input()
        buflist = buf.split()
        l.append(int(buflist[0]))
        r.append(int(buflist[1]))
        d.append(int(buflist[2]))
    for i in range(q):
        if d[i] < l[i]:
            print(d[i])
        else:
            print(d[i] * ((r[i] // d[i]) + 1))

if __name__ == '__main__':
    main()
