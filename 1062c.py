# C++17 implemention -> 1062c.cpp
# Input generator -> 1062c_gen.py

MOD = 1000000007

def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    q = int(buflist[1])
    buf = input()
    x = buf
    sum_list = [0] # sentinel / one indexing
    for i, deliciousness in enumerate(x):
        sum_list.append(int(deliciousness) + sum_list[i])
    enjoyment_list = [0]
    for i in range(n):
        enjoyment_list.append((enjoyment_list[i] * 2 + 1) % MOD)
    # buffer input to avoid TLE
    query_list = []
    for i in range(q):
        buf = input()
        buflist = buf.split()
        l = int(buflist[0]) # one indexing
        r = int(buflist[1]) # one indexing
        query_list.append((l, r))
    for i, query in enumerate(query_list):
        l = query[0]
        r = query[1]
        banhmi_count = r - l + 1
        delicious_count = sum_list[r] - sum_list[l - 1]
        non_delicious_count = banhmi_count - delicious_count
        enjoyment = 0
        # main part
        if delicious_count == 0:
            enjoyment = 0
        else:
            enjoyment += enjoyment_list[delicious_count]
            enjoyment += (enjoyment_list[banhmi_count] - enjoyment_list[delicious_count] - enjoyment_list[non_delicious_count])
            enjoyment = enjoyment % MOD
        print(enjoyment)

if __name__ == '__main__':
    main()
