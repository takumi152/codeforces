
def main():
    buf = input()
    buflist = buf.split()
    x = int(buflist[0])
    y = int(buflist[1])
    z = int(buflist[2])
    coc = (x // z) + (y // z)
    x %= z
    y %= z
    if x + y < z:
        print(coc, 0) # no extra
        return
    else:
        give = min(z - x, z - y)
        print(coc+1, give)
        return

if __name__ == '__main__':
    main()
