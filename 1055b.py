
def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    m = int(buflist[1])
    l = int(buflist[2])
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    # preprocessing
    need_cut = []
    for i in a:
        if i > l:
            need_cut.append(True)
        else:
            need_cut.append(False)
    cut_count = 0
    segmented = False
    for i in need_cut:
        if not segmented and i:
            cut_count += 1
            segmented = True
        elif segmented and not i:
            segmented = False
    for i in range(m):
        buf = input()
        buflist = buf.split()
        q = int(buflist[0])
        if q == 0:
            print(cut_count)
        elif q == 1:
            p = int(buflist[1]) - 1 # zero indexing
            d = int(buflist[2])
            a[p] += d
            if p == 0:
                if not need_cut[p] and a[p] > l:
                    need_cut[p] = True
                    if n == 1: # corner case
                        cut_count += 1
                    elif not need_cut[p+1]:
                        cut_count += 1
            elif p == n - 1:
                if not need_cut[p] and a[p] > l:
                    need_cut[p] = True
                    if not need_cut[p-1]:
                        cut_count += 1
            else:
                if not need_cut[p] and a[p] > l:
                    need_cut[p] = True
                    if not need_cut[p-1] and not need_cut[p+1]:
                        cut_count += 1
                    elif need_cut[p-1] and need_cut[p+1]:
                        cut_count -= 1

if __name__ == '__main__':
    main()
