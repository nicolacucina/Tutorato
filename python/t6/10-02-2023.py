def reverse_order(list):
    # return lst[::-1]
    outputlist = []
    for i in range(len(list)):
        outputlist.append(list[len(list) - 1 - i])
    return outputlist

def enter_list():
    lst = []
    # continue_input = True
    # while continue_input:
    continue_input = "y"
    while continue_input == "y":
        s = input("Enter a string: ")
        # if s == "" or s == "\n":
        #     continue_input = False
        # else:
        #     lst.append(int(s))
        lst.append(s)
        continue_input = input("Do you want to continue? (y/n): ")
    return lst

def enter_integer():
    valid = False
    while not valid:
        try:
            number = int(input('Insert a positive integer:'))
            if number > 0:
                valid = True
            else:
                print('The number must be positive.')
        except ValueError:
            print('Invalid input. Please insert a positive integer.')
    return number

def enter_integers(n):
    lst = []
    for i in range(n):
        temp = enter_integer()
        lst.append(temp)
    return lst

def recursive_find_zero(lst):
    """
        if len(lst) == 1:
            if lst[0] == 0:
                return True
            else:
                return False
        else:
            result = recursive_find_zero(lst[1:])
            return (result or lst[0] == 0)

        contains_zero = False
        for i in range(len(lst)):
            if lst[i] == 0:
                contains_zero = True
                break
    """
    if len(lst) == 1:
        return lst[0] == 0
    else:
        return lst[0] == 0 or recursive_find_zero(lst[1:])

def main():
    lst = enter_list()
    print(lst)
    reversed_list = reverse_order(lst)
    print(reversed_list)

main()