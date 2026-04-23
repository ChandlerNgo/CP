num = int(input())
found = False
while not found:
    cards = (num*((3*num) + 1))//2
    if cards % 4 == 0:
        print(num)
        found = True
    
    num += 1