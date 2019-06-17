# WIP

def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    c = int(buflist[1])
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    pos_list = {}
    for i, num in enumerate(a):
        if not num in pos_list:
            pos_list.update({num : [i]})
        else:
            pos_list[num].append(i)
    print(pos_list)

if __name__ == '__main__':
    main()
