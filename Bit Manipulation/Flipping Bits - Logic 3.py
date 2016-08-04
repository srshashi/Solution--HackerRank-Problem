
#!/bin/python3

## Hackerrank
## Domains:: Algorithns:: Bit Manipulation: Flipping Bits
## Logic #3

n = int(input())
while n:
    t = int(input())
    t = t^((1<<32) -1)    
    print(t)
    n=n-1
