
def main():
    buf = input()
    l = int(buf)
    buf = input()
    n = buf
    for i in range(l//2, l):
        left = None
        right = None
        if n[i] != '0':
            left = i
        if n[-i] != '0':
            right = i
        if left and right:
            li = int(n[0:i]) + int(n[i:l])
            ri = int(n[0:l-i]) + int(n[l-i:l])
            print(min(li, ri))
            return
        elif left:
            print(int(n[0:i]) + int(n[i:l]))
            return
        elif right:
            print(int(n[0:l-i]) + int(n[l-i:l]))
            return

if __name__ == '__main__':
    main()
