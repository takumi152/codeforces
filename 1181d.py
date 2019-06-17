import bisect

def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    m = int(buflist[1])
    q = int(buflist[2])
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    k = []
    for i in range(q):
        buf = input()
        k.append(int(buf) - n-1)
    held = []
    for i in range(m):
        held.append([0, i])
    for x in a:
        held[x][0] += 1
    held.sort()
    mod_table = []
    smallest = held[0][0]
    for x in held:
        if x[0] > smallest:
            mod_table.append()

if __name__ == '__main__':
    main()
