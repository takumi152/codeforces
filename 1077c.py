
def main():
    buf = input()
    n = int(buf)
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    if n == 2:
        print(0)
        return
    for i, _ in enumerate(a):
        a[i] = [a[i], i + 1] # one indexing
    a = list(sorted(a, key = lambda x: x[0]))
    sum_list = []
    for i, num in enumerate(a):
        if not sum_list:
            sum_list.append(num[0])
        else:
            sum_list.append(sum_list[i - 1] + num[0])
    nice = []
    for i, _ in enumerate(a):
        if i == 0:
            if sum_list[len(a) - 2] - sum_list[i] == a[len(a) - 1][0]:
                nice.append(a[i][1])
        elif i == len(a) - 1:
            if sum_list[len(a) - 3] == a[len(a) - 2][0]:
                nice.append(a[i][1])
        else:
            if sum_list[i - 1] + sum_list[len(a) - 2] - sum_list[i] == a[len(a) - 1][0]:
                nice.append(a[i][1])
    print(len(nice))
    p = ""
    for i, e in enumerate(nice):
        p += str(e)
        if i != len(nice) - 1:
            p += " "
    print(p)

if __name__ == '__main__':
    main()
