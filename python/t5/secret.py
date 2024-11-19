"""
Write a program that, given two lower case strings called msg and secret,
determines if all the characters of secret are found inside of msg. If they are,
the program displays msg where all the characters of secret are replaced by
their upper case version.
"""

def find_secret(msg,secret):
    # print(secret in msg) does not help
    index = 0
    found = False
    for i in range(len(msg)):
        if msg[i] == secret[index]:
            index += 1
        if index == len(secret):
            found = True
            break
    return found

def replace_secret(msg,secret):
    new_msg = ''
    index = 0
    for i in range(len(msg)):
        if index < len(secret) and msg[i] == secret[index]:
            new_msg += msg[i].upper()
            index += 1
        else:
            new_msg += msg[i]
    print(new_msg)

def main():
    msg = input('Insert lower case message:').lower()
    secret = input('Insert lower case secret:').lower()
    print('Found:', find_secret(msg,secret))
    replace_secret(msg,secret)

main()