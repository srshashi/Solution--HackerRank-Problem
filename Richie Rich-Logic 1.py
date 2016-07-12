#!/bin/python3

## Hackerrank
## May-world Codesprint 2016: Richie Rich
## Moderate Level
## Logic #1

## Format to print properly
def string(s):
    c = ''
    for each in s:
        c = c+str(each)
    return c

## Check if string is palindrome
def isPalindrome(s):
    j = 0
    while j < n//2 :
        if s[j] != s[n-j-1]:
            return False
        j=j+1
    return True

## To make the palindrome bigger
def bigger(s, check):
    global k
    i = 0
    while k > 0 and i < n//2 :
        if s[i] != '9' and s[n-1-i] != '9':
            # if we have already traverse through char at i & n-1-i once so we need to do only by one
            if check[i] == 1:
                k = k-1
            # if not, two cases arise
                # 1. if k = 1 and check[i] = 0, in this case we can't change, so we skip using continue
                # 2. if k > 1 then we can change the char
            elif k > 1 :
                k = k-2
            else:
                i = i+1
                continue
            s[i] = s[n-1-i] = '9'
        i = i+1
    if n%2 != 0 :
        if k > 0:
            s[n//2] = '9'

## This function makes the string into palindrome, if possible in given k
def palindrome(s, check):
    global k
    t = n//2 - 1
    while k > 0 and t >= 0:
        c1 = s[n-t-1]
        c2 = s[t]

        if c1 < c2:
            s[n-t-1] = s[t]
        elif c2 < c1:
            s[t] = s[n-t-1]

        if c1 != c2:
            k = k-1
            check[t] = 1
        t = t-1

## take input here, store each digit in as an array element
n, k = input().strip().split(' ')
n = int(n)
k = int(k)
s = list(input())

## to keep track if a char is traversed or not
## We need to keep track of only half of element
## initially all char are unchecked, so every element is 0
check = list()

for i in range(n//2):
    check.append(0)

palindrome(s, check)
bigger(s, check)
if isPalindrome(s):
    print(string(s))
else:
    print(-1)
