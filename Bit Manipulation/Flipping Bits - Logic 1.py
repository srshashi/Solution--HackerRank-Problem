#!/bin/python3

## Hackerrank
## Domains:: Algorithns:: Bit Manipulation: Flipping Bits
## Logic #1

## See: https://stackoverflow.com/questions/20766813/how-to-convert-signed-to-unsigned-integer-in-python
## Basically Logic #2, but Python does not have built-in unsigned types

i = int(input())
while i:
    t = int(input())
    t = (~t) & ((1<<32)-1)
    print(t)
    i = i-1
