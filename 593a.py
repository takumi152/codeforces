import string

def main():
    buf = input()
    n = int(buf)
    w = []
    for i in range(n):
        buf = input()
        w.append(str(buf))
    char_count_list = []
    for i, word in enumerate(w):
        char_dict = {}
        for char in word:
            if char in char_dict:
                char_dict[char] += 1
            else:
                char_dict[char] = 1
        char_count_list.append(char_dict)
    max_char_length = 0
    for i, c1 in enumerate(string.ascii_lowercase):
        for c2 in string.ascii_lowercase[i+1:]:
            char_length = 0
            for char_dict in char_count_list:
                if len(char_dict) > 2:
                    continue
                elif len(char_dict) == 2:
                    if c1 in char_dict and c2 in char_dict:
                        char_length += char_dict[c1] + char_dict[c2]
                elif len(char_dict) == 1:
                    if c1 in char_dict:
                        char_length += char_dict[c1]
                    elif c2 in char_dict:
                        char_length += char_dict[c2]
            if char_length > max_char_length:
                max_char_length = char_length
    print(max_char_length)

if __name__ == '__main__':
    main()
