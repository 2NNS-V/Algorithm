import sys

while True :
    line = sys.stdin.readline().rstrip('\n')
    if not line: break
    low, upper, digit, empty =0,0,0,0

    for i in line:
        if i.islower():
            low += 1
        elif i.isupper():
            upper += 1
        elif i.isdigit():
            digit += 1
        elif i.isspace():
            empty += 1
    print(low, upper, digit, empty)