#!/usr/bin/python3
'''
Interview we search the minimal operations
'''


def minOperations(n):
    '''
    calculates the fewest number of operations needed to result
    in exactly n H characters in the file.
    '''
    if type(n) is not int or n <= 1:
        return 0

    H = 2
    result = 0

    while H <= n:
        if n % H == 0:
            '''is the n divisable by H'''
            n = n / H
            result += H
        else:
            H += 1

    return result
    