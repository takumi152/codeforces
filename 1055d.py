
def main():
    buf = input()
    n = int(buf)
    w = []
    for i in range(n):
        buf = input()
        w.append(buf)
    x = []
    for i in range(n):
        buf = input()
        x.append(buf)
    diff = []
    first = []
    last = []
    for i, _ in enumerate(w):
        count = 0
        delta = 0
        f = 0
        l = 0
        for j, _ in enumerate(w[i]):
            if delta >= 1:
                delta += 1
            if w[i][j] != x[i][j]:
                if delta == 0:
                    delta = 1
                    f = j
                count = delta
                l = j + 1
        diff.append(count)
        first.append(f)
        last.append(l)
    w = [z for _, z in sorted(zip(diff,w), key=lambda pair: pair[0])][::-1]
    x = [z for _, z in sorted(zip(diff,x), key=lambda pair: pair[0])][::-1]
    first =[z for _, z in sorted(zip(diff,first), key=lambda pair: pair[0])][::-1]
    last = [z for _, z in sorted(zip(diff,last), key=lambda pair: pair[0])][::-1]
    diff = sorted(diff)[::-1]
    s = w[0][first[0]:last[0]]
    t = x[0][first[0]:last[0]]
    for i, word in enumerate(w):
        rep_word = word.replace(s, t, 1)
        if rep_word != x[i]:
            print("NO")
            return
    print("YES")
    print(s)
    print(t)

if __name__ == '__main__':
    main()
