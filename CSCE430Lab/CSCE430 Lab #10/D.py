# number = int(input())
import math
for number in range(1,30):
    nums = 9

    for i in range(1,number):
        nums *= 10
        nums /= (i+1)
        nums = math.floor(nums)
    print(nums)