#!/bin/python3

## Hackerrank
## Domains:: Algorithns:: Bit Manipulation: Lonely Integer

# Head ends here
def lonelyinteger(b):
    answer = int(b[0])
    for i in range(1, len(b)):
        b[i] = int(b[i])
        answer = answer^b[i]
    return answer

# Tail starts here
if __name__ == '__main__':
    a = int(input())
    b = input().strip().split(" ")
    print(lonelyinteger(b))
