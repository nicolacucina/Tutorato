"""
Vowels and Consonants
Write a function using the following prototype:
    insert_characters(s1)
The function recevies the string s1 as a parameter. The output of the func-
tion is a string s2 where:
• a ”@” is inserted after each vowel
• a ”*” is inserted after each consonant
Then, write a program that invokes the written function. If the string ”hello
world” is given as input, the expected output is ”h*e@l*l*o@ w*o@r*l*d*”.
"""

def insert_characters(s1):
    vowels = 'aeiouAEIOU'
    s2 = ''
    for i in range(len(s1)):
        if s1[i] in vowels:
            s2 += s1[i] + '@'
        else:
            s2 += s1[i] + '*'
    return s2

def main():
    s1 = input('Insert string:')
    print(insert_characters(s1))

main()