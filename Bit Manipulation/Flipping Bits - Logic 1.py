#!/bin/python3

## Hackerrank
## Domains:: Algorithns:: Bit Manipulation: Flipping Bits
## Logic #1

i = int(input())
while i:
    t = int(input())
    t = (~t) & ((1<<32)-1)
    print(t)
    i = i-1
