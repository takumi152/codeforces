
def main():
    buf = input()
    s = ""
    for _, c in enumerate(buf):
        if c == '[' or c == ']' or c == ':' or c == '|':
            s += c
    
    if len(s) < 4:
        print(-1) # impossible
        return

    idx_brl = None # [
    idx_col = None # :
    idx_cor = None # :
    idx_brr = None # ]

    for i, c in enumerate(s):
        if c == '[' and idx_brl == None:
            idx_brl = i
        if c == ']':
            idx_brr = i+1
    if idx_brl == None or idx_brr == None:
        print(-1) # impossible
        return
    if idx_brl >= idx_brr:
        print(-1) # impossible
        return

    for i in range(idx_brl, idx_brr):
        if s[i] == ':':
            if idx_col == None:
                idx_col = i
            idx_cor = i+1
    if idx_col == None or idx_cor == None:
        print(-1) # impossible
        return
    if idx_col >= idx_cor-1:
        print(-1) # impossible
        return

    accordion_length = 4
    for i in range(idx_col, idx_cor):
        if s[i] == '|':
            accordion_length += 1
    print(accordion_length)

if __name__ == '__main__':
    main()
