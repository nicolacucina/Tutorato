def compute_inverse(matrix):
    a = matrix[0][0]
    b = matrix[0][1]
    c = matrix[1][0]
    d = matrix[1][1]

    det = a * d - b * c
    if det == 0:
        print("The matrix is not invertible")
        return None
    else:
        inverse = [[d, -b], [-c, a]]
        for i in range(2):
            for j in range(2):
                inverse[i][j] = inverse[i][j] / det
        return inverse

def enter_strings():
    strings = []
    continue_input = True
    while continue_input:
        s = input("Enter a string: ")
        if s == "" or s == "\n":
            continue_input = False
        else:
            strings.append(s)
    
    for s in strings:
        print(s)
    return strings

def recursive_longest_string(strings, max_length):
    """
        max_length = ""
        for i in range(len(strings)):
            if len(strings[i]) > len(max_length):
                max_length = strings[i]
    """
    if len(strings) == 0:
        return max_length
    else:
        if len(strings[0]) > len(max_length):
            max_length = strings[0]
        return recursive_longest_string(strings[1:], max_length)

# def longest_string(strings):
#     max_length = ""
#     for s in strings:
#         if len(s) > len(max_length):
#             max_length = s
#     return max_length

def main():
    matrix = [[1, 3], [2, -2]]
    inverse = compute_inverse(matrix)
    print(inverse)

    outputfile = open("inverse.txt", "w")
    outputfile.write(str(2) + '\n')
    outputfile.write(str(2) + '\n')
    outputfile.write('\n')
    for i in range(2):
        for j in range(2):
            outputfile.write(str(inverse[i][j]) + '\n')
    outputfile.close()

    strings = enter_strings()
    longest_string2 = recursive_longest_string(strings, "")
    print("The longest string is:", longest_string2)
    longest_string1 = longest_string(strings)
    print("The longest string is:", longest_string1)

main()