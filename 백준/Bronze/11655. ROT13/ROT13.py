import sys

s = sys.stdin.readline()

for i in s:
    if ord(i) + 13 > 90 and i >= 'A' and i <= 'Z': 
        print(chr(ord(i) - 13), end='')
    elif i >= 'a' and i <= 'z' and ord(i) + 13 > 122:
        print(chr(ord(i) - 13), end='')
    elif i.isspace() or i.isdigit(): print(i, end='')
    else: print(chr(ord(i) + 13), end='')