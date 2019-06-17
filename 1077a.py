
def main():
    buf = input()
    t = int(buf)
    query_list = []
    for i in range(t):
        buf = input()
        buflist = buf.split()
        query_list.append(list(map(int, buflist))) # a, b, k
    for query in query_list:
        distance = query[0] * (query[2] // 2) - query[1] * (query[2] // 2)
        if query[2] % 2 == 1:
            distance += query[0]
        print(distance)

if __name__ == '__main__':
    main()
