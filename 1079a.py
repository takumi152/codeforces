import math

def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    k = int(buflist[1])
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    appearance = {}
    for i in a:
        if not i in appearance:
            appearance.update({i : 1})
        else:
            appearance[i] += 1
    max_utensil = 0
    for _, v in appearance.items():
        if v > max_utensil:
            max_utensil = v
    dish_served = math.ceil(max_utensil / k)
    max_utensil = dish_served * k
    stolen = 0
    for _, v in appearance.items():
        stolen += max_utensil - v
    print(stolen)


if __name__ == '__main__':
    main()
