"""
Farfallino alphabet

Write a function using the following prototype:
    farfallino(s1, s2)
The function recevies two strings s1 and s2. s2 must be modified as follows:
• an ”f” is placed after each lower case vowel, along with the lower case
vowel itself
• an ”F” is placed after each upper case vowel, along with the upper case
vowel itself
"""

def farfallino(s1, s2):
    vowels = 'aeiou'
    uppervowels= 'AEIOU'
    for i in range(len(s1)):
        if s1[i] in vowels:
            s2 += s1[i] + 'f' + s1[i]
        elif s1[i] in uppervowels:
            s2 += s1[i] + 'F' + s1[i]
        else:
            s2 += s1[i]
    return s2

def main():
    s1 = input('Insert string:')
    s2 = ''
    # s2[0] = s1[0] non consentito
    print(farfallino(s1, s2))

def other_main():
    s1 = open('file.txt', 'r').read()
    print("Input file:", s1)
    s2 = ''
    
    result = farfallino(s1, s2)
    print(result)

    outputfile = open('output.txt', 'a')
    outputfile.write(result)
    outputfile.close()

def other_other_main():
    inputfile = open('file.txt', 'r')
    has_more_lines = True
    while has_more_lines:
        s1 = inputfile.readline()
        if s1 == '':
            has_more_lines = False
        else:
            print("Input file:", s1)
            s2 = ''
            result = farfallino(s1, s2)
            print(result)

            outputfile = open('output.txt', 'a')
            outputfile.write(result)
            outputfile.close()

main()
other_main()
