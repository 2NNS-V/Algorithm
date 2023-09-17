import sys

s = sys.stdin.readline()

print(s)
for i in s:
    if i.isupper(): 
        print(chr[ord(i)+13], end='')
    else: print(i)