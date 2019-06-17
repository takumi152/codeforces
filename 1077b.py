
def main():
    buf = input()
    n = int(buf)
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    disturbed = []
    for i in range(1, n-1):
        if a[i-1] == 1 and a[i] == 0 and a[i+1] == 1:
            disturbed.append(i)
    k = 0
    remaining = list(disturbed)
    for i in disturbed:
        if not i in remaining:
            continue
        remaining.remove(i)
        if i + 2 in remaining:
            remaining.remove(i + 2)
        k += 1
    print(k)

if __name__ == '__main__':
    main()
