
def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    k = int(buflist[1])
    buf = input()
    buflist = buf.split()
    s = list(map(int, buflist))
    appearance = {}
    for i in s:
        if not i in appearance:
            appearance.update({i : 1})
        else:
            appearance[i] += 1
    idx = [k for k, _ in dict(sorted(appearance.items(), key=lambda x:x[1])).items()][::-1]
    orig_count = [v for _, v in dict(sorted(appearance.items(), key=lambda x:x[1])).items()][::-1]
    count = list(orig_count)
    pos = 0
    factor = []
    for i in idx:
        factor.append(0)
    t = []
    while len(t) < k:
        factor[pos] += 1
        count[pos] = orig_count[pos] // factor[pos]
        if count[pos] != 0:
            t.append(idx[pos])
        if len(idx) == 1 or pos == len(idx) - 1:
            continue
        if pos == 0:
            if count[pos] < count[pos+1]:
                pos += 1
        else:
            if count[pos] >= count[]
    p = ""
    for i, e in enumerate(t):
        p += str(e)
        if i != len(t) - 1:
            p += " "
    print(p)

if __name__ == '__main__':
    main()
