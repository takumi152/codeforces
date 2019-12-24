import math

def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    r = int(buflist[1])
    # ((r+R)cos(180/n))^2 + (R)^2 = (r+R)^2
    R = 1
    delta = abs(((r + R) * math.cos(math.radians(180/n))) ** 2 + R ** 2 - (r + R) ** 2)
    left = 0.0
    right = 1e6
    while delta > 1e-8:
        delta_left = abs(((r + left) * math.cos(math.radians(180/n))) ** 2 + left ** 2 - (r + left) ** 2)
        delta_right = abs(((r + right) * math.cos(math.radians(180/n))) ** 2 + right ** 2 - (r + right) ** 2)
        if delta_left < delta_right:
            right = right - (right - left) / 100
            R = left
        else:
            left = left + (right - left) / 100
            R = right
        delta = min(delta_left, delta_right)
    print(R)


if __name__ == '__main__':
    main()
