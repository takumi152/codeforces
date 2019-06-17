
def main():
    buf = input()
    n = int(buf)
    buf = input()
    buflist = buf.split()
    f = list(map(int, buflist))
    f = list(map(lambda x: x-1, f)) # zero indexing
    s = []
    for i in range(n):
        s.append(i)
    s = [z for _, z in sorted(zip(f, s), key=lambda pair: pair[0])]
    f = list(sorted(f))
    t = 0
    for i in range(len(s)-1):
        t += abs(s[i] - s[i+1])
    print(t)

if __name__ == "__main__":
    main()
