import math
import decimal

def main():
    buf = input()
    buflist = buf.split()
    a = int(buflist[0])
    b = int(buflist[1])
    c = int(buflist[2])
    buf = input()
    buflist = buf.split()
    start = (int(buflist[0]), int(buflist[1]))
    end = (int(buflist[2]), int(buflist[3]))
    corner1 = (start[0], end[1])
    corner2 = (end[0], start[1])
    shortest = calc_distance(start, corner1) + calc_distance(corner1, end)
    sc1 = is_crossing(a, b, c, start, corner1)
    sc2 = is_crossing(a, b, c, start, corner2)
    ec1 = is_crossing(a, b, c, end, corner1)
    ec2 = is_crossing(a, b, c, end, corner2)
    if sc1 and ec1:
        x = find_crossing_with_y(a, b, c, corner1[1])
        y = find_crossing_with_x(a, b, c, corner1[0])
        dist = calc_distance(start, (corner1[0], y)) + calc_distance((corner1[0], y), (x, corner1[1])) + calc_distance((x, corner1[1]), end)
        if dist < shortest:
            shortest = dist
    if sc2 and ec2:
        x = find_crossing_with_y(a, b, c, corner2[1])
        y = find_crossing_with_x(a, b, c, corner2[0])
        dist = calc_distance(start, (x, corner2[1])) + calc_distance((x, corner2[1]), (corner2[0], y)) + calc_distance((corner2[0], y), end)
        if dist < shortest:
            shortest = dist
    if sc1 and ec2:
        y1 = find_crossing_with_x(a, b, c, corner1[0])
        y2 = find_crossing_with_x(a, b, c, corner2[0])
        dist = calc_distance(start, (corner1[0], y1)) + calc_distance((corner1[0], y1), (corner2[0], y2)) + calc_distance((corner2[0], y2), end)
        if dist < shortest:
            shortest = dist
    if sc2 and ec1:
        x1 = find_crossing_with_y(a, b, c, corner1[1])
        x2 = find_crossing_with_y(a, b, c, corner2[1])
        dist = calc_distance(start, (x2, corner2[1])) + calc_distance((x2, corner2[1]), (x1, corner1[1])) + calc_distance((x1, corner1[1]), end)
        if dist < shortest:
            shortest = dist
    print(decimal.Decimal(shortest))

def calc_distance(p1, p2):
    return math.sqrt(abs(p1[0] - p2[0]) * abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) * abs(p1[1] - p2[1]))

def is_crossing(a, b, c, p1, p2):
    c1 = a * p1[0] + b * p1[1] + c
    c2 = a * p2[0] + b * p2[1] + c
    return c1 * c2 <= 0

def find_crossing_with_x(a, b, c, x):
    return (-a * x - c) / b

def find_crossing_with_y(a, b, c, y):
    return (-b * y - c) / a

if __name__ == '__main__':
    main()
