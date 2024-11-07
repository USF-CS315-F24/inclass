import sys

print("v2.0 raw")

for line in sys.stdin:
    hexvals = [hex(ord(line[i]))[2:] for i in range(4)]
    hexstr = '0x' + ''.join(hexvals)
    print(hexstr)
