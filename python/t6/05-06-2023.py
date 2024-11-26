def enter_integers():
    lst = []
    continue_input = True
    while continue_input:
        try:
            s = int(input("Enter an integer: "))
            if s == 0:
                continue_input = False
            else:
                if s > 0:
                    lst.append(int(s))
                else:
                    print("The number must be positive.")
        except ValueError:
            print("Invalid input. Please insert an integer.")
    
    for s in lst:
        print(s)
    return lst

def save_to_file(lst):
    outputfile = open("positive.txt", "w")
    for i in range(len(lst)):
        outputfile.write(str(lst[i]) + '\n')
    outputfile.close()

def read_from_file():
    lst = []
    inputfile = open("positive.txt", "r")
    for line in inputfile:
        lst.append(int(line))
    inputfile.close()
    return lst

def count_even(lst):
    """
        if len(lst) == 1:
            if lst[0] % 2 == 0
                count += 1
            return count
        else:
            if lst[0] % 2 == 0:
                count += 1
            return count_even(lst[1:], count)
    """
    count = 0
    for i in lst:
        if i % 2 == 0:
            count += 1
    return count

def main():
    lst = enter_integers()
    save_to_file(lst)
    lst = read_from_file()
    print(count_even(lst))

main()