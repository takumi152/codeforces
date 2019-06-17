import math

def main():
    buf = input()
    buflist = buf.split()
    la = int(buflist[0])
    ra = int(buflist[1]) + 1 # exclusive range
    ta = int(buflist[2])
    buf = input()
    buflist = buf.split()
    lb = int(buflist[0])
    rb = int(buflist[1]) + 1 # exclusive range
    tb = int(buflist[2])
    gcd = math.gcd(ta, tb)
    if gcd == 1: # coprime
        print(min(abs(ra - la), abs(rb - lb)))
    else:
        if gcd < math.sqrt(max(ta, tb)):
            la_m = lb
            ra_m = la_m + (ra - la)
            num_left = min(abs(ra_m - la_m), abs(rb - lb))
            while abs(la_m - la) % gcd != 0:
                la_m -= 1
                ra_m -= 1
                num_left = min(num_left, min(abs(max(0, ra_m - la_m)), abs(max(0, ra_m - lb)), abs(max(0, rb - la_m)), abs(max(0, rb - lb))))
            la_m = lb
            ra_m = la_m + (ra - la)
            num_right = min(abs(ra_m - la_m), abs(rb - lb))
            while abs(la_m - la) % gcd != 0:
                la_m += 1
                ra_m += 1
                num_right = min(num_left, min(abs(max(0, ra_m - la_m)), abs(max(0, ra_m - lb)), abs(max(0, rb - la_m)), abs(max(0, rb - lb))))
            print(max(num_left, num_right))
        else:
            if ta < tb:
                la_m = la
                ra_m = ra
                num = 0
                for i in range(max(ta, tb) // gcd):
                    num = max(num, min(abs(max(0, ra_m - la_m)), abs(max(0, ra_m - lb)), abs(max(0, rb - la_m)), abs(max(0, rb - lb))))
                    la_m += gcd
                    ra_m += gcd
                print(num)
            else:
                lb_m = lb
                rb_m = rb
                num = 0
                for i in range(max(ta, tb) // gcd):
                    num = max(num, min(abs(max(0, ra - la)), abs(max(0, ra - lb_m)), abs(max(0, rb_m - la)), abs(max(0, rb_m - lb_m))))
                    lb_m += gcd
                    rb_m += gcd
                print(num)


if __name__ == '__main__':
    main()
