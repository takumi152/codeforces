
def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    s = int(buflist[1]) - 1 # zero indexing
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    buf = input()
    buflist = buf.split()
    b = list(map(int, buflist))
    start = 0
    if not a[0]:
        print("NO")
        return
    if not a[s] and not b[s]:
        print("NO")
        return
    if a[s]:
        print("YES")
        return
    for i in range(s+1, n):
        if a[i] and b[i]:
            print("YES")
            return
    print("NO")
    return

if __name__ == '__main__':
    main()
