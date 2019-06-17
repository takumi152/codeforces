import math

def main():
    buf = input()
    s = buf
    row = math.ceil(len(s) / 20)
    column = math.ceil(len(s) / row)
    space = row * column - len(s)
    print(row, column)
    pos_l = 0
    pos_r = 0
    for i in range(row):
        name = ""
        pos_l = pos_r
        pos_r += column
        if space > 0:
            pos_r -= 1
            space -= 1
            name += "*"
        name += s[pos_l:pos_r]
        print(name)

if __name__ == '__main__':
    main()
