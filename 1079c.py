import math

def main():
    buf = input()
    n = int(buf)
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    if n == 1:
        print(1)
        return
    elif n == 2:
        if a[0] < a[1]:
            print(1, 5)
        else:
            print(5, 1)
        return
    else:
        finger_list = []
        if a[0] < a[1]:
            finger_list.append(1)
        elif a[0] > a[1]:
            finger_list.append(5)
        else:
            finger_list.append(3)
        for i in range(n - 2):
            if a[i] < a[i + 1]:
                if a[i + 1] < a[i + 2]:
                    finger_list.append(finger_list[-1] + 1)
                    if finger_list[-1] >= 6:
                        print(-1)
                        return
                elif a[i + 1] > a[i + 2]:
                    finger_list.append(5)
                    if finger_list[-2] == finger_list[-1]:
                        print(-1)
                        return
                else:
                    finger_list.append(finger_list[-1] + 1)
                    if finger_list[-1] >= 6:
                        print(-1)
                        return
            elif a[i] > a[i + 1]:
                if a[i + 1] > a[i + 2]:
                    finger_list.append(finger_list[-1] - 1)
                    if finger_list[-1] <= 0:
                        print(-1)
                        return
                elif a[i + 1] < a[i + 2]:
                    finger_list.append(1)
                    if finger_list[-2] == finger_list[-1]:
                        print(-1)
                        return
                else:
                    finger_list.append(finger_list[-1] - 1)
                    if finger_list[-1] <= 0:
                        print(-1)
                        return
            else:
                if a[i + 1] < a[i + 2]:
                    if finger_list[-1] == 1:
                        finger_list.append(2)
                    else:
                        finger_list.append(1)
                elif a[i + 1] > a[i + 2]:
                    if finger_list[-1] == 5:
                        finger_list.append(4)
                    else:
                        finger_list.append(5)
                else:
                    if finger_list[-1] == 3:
                        finger_list.append(2)
                    else:
                        finger_list.append(3)
        if a[-2] < a[-1]:
            finger_list.append(finger_list[-1] + 1)
            if finger_list[-1] >= 6:
                print(-1)
                return
        elif a[-2] > a[-1]:
            finger_list.append(finger_list[-1] - 1)
            if finger_list[-1] <= 0:
                print(-1)
                return
        else:
            if finger_list[-1] == 3:
                finger_list.append(2)
            else:
                finger_list.append(3)
    p = ""
    for i, e in enumerate(finger_list):
        p += str(e)
        if i != len(finger_list) - 1:
            p += " "
    print(p)


if __name__ == '__main__':
    main()
