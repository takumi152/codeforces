n = 100
m = 500
l = 100
print(n, m, l)
a = []
for i in range(n):
    a.append(i+1)
print(" ".join(list(map(str, a))))
for i in range(m):
    if i < m // 2:
        if i % 2 == 0:
            print("0")
        else:
            print("1 "+str(i%n)+" "+str(i%n))
    else:
        if i % 2 == 0:
            print("0")
        else:
            print("1 "+str(i%(n+1))+" "+str(i%n+1))
