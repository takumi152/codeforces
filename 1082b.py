import math

def main():
    buf = input()
    n = int(buf)
    buf = input()
    row = buf
    beauty = []
    count = 0
    for i in row:
        if i == 'G':
            count += 1
        else:
            beauty.append(count)
            count = 0
    beauty.append(count)
    if len(beauty) == 1:
        print(beauty[0])
        return
    max_adj_beauty = 0
    isolated = True
    for i in range(len(beauty) - 1):
        if beauty[i] + beauty[i+1] > max_adj_beauty:
            max_adj_beauty = beauty[i] + beauty[i+1]
            if beauty[i] == 0 or beauty[i+1] == 0:
                isolated = True
            else:
                isolated = False
    more_than_one_count = 0
    for i in range(len(beauty)):
        if beauty[i] > 0:
            more_than_one_count += 1
    if more_than_one_count > 2 or (isolated and more_than_one_count > 1):
        max_adj_beauty += 1
    print(max_adj_beauty)

if __name__ == '__main__':
    main()
