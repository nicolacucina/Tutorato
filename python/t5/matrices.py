"""
Write a function that prompts the user to enter two positive integers. 
The program should warn the user if the input is invalid (i.e., the input is not a positive integer)
and keep asking until a valid input is entered. 
Next, the program prints the two numbers.
"""

def get_positive_integer():
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

"""
Write a function that prompts the user to enter a matrix of size n x m, where n and m are the first and the last integers entered before. 
Next, the program saves the matrix into a file. 
Note: the first two lines of the file should contain the number of rows and columns of the matrix.
"""

def input_matrix(n, m):
    matrix = []
    for i in range(n):
        matrix.append([])
        for j in range(m):
            number = int(input('Insert element:'))
            matrix[i].append(number)
    return matrix

def save_matrix(n, m, matrix):
    outputfile = open("matrix.txt", "a")
    outputfile.write(str(n) + '\n')
    outputfile.write(str(m) + '\n')
    for i in range(n):
        for j in range(m):
            outputfile.write(str(matrix[i][j]) + '\n')
    outputfile.close()

"""
Write a function that, given a matrix as input, computes its transpose. 
(Recall that the transpose of a matrix is an operator which flips a matrix over its diagonal;
 that is, it switches the row and column indices.)
"""
def transpose_matrix(matrix):
    transpose = []
    n = len(matrix)
    m = len(matrix[0])
    for i in range(m):
        transpose.append([])
        for j in range(n):
            transpose[i].append(matrix[j][i])
    print(transpose)
    return transpose
"""
Write a program that reads the matrix saved into the previous file (exercise 1.B), 
computes its transpose, and finally prints the transposed matrix.
"""
def read_matrix(filename):
    inputfile = open(filename, "r")
    n = int(inputfile.readline())
    m = int(inputfile.readline())
    matrix = []
    for i in range(n):
        matrix.append([])
        for j in range(m):
            s = inputfile.readline()
            matrix[i].append(int(s))
    return matrix

def main():
    number1 = get_positive_integer()
    number2 = get_positive_integer()
    print('Numbers:', number1, number2)
    matrix = input_matrix(number1, number2)
    # save_matrix(number1, number2, matrix)
    matrix1 = read_matrix("matrix.txt")
    print(matrix1)
    matrix2 = transpose_matrix(matrix1)

main()
