#!/usr/bin/python3
''' Will solve lockbox to determine if all boxes can be opened '''


def canUnlockAll(boxes):
    ''' If all boxes can be opened then pass if not then fail '''
    avKeys = [0]
    # Will go through keys in boxes and add any new keys
    for x in avKeys:
        for key in boxes[x]:
            # Will add key to list if it is not in list
            if key not in avKeys and key < len(boxes):
                avKeys.append(key)

    x = 0
    while x < len(boxes):
        if x not in avKeys:
            return False
        x += 1

    return True
