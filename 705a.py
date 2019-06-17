
def main():
    buf = input()
    n = int(buf)
    feeling = ""
    for i in range(n):
        if i % 2 == 0:
            feeling += "I hate "
        else:
            feeling += ("I love ")
        if i == n - 1:
            feeling += ("it")
        else:
            feeling += ("that ")
    print(feeling)

if __name__ == "__main__":
    main()
