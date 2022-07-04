from cs50 import get_int
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
for row in range(1 , height + 1):
    for space in range(0 , height - row):
        print(" " , end="")
    for dash in range(0 , row):
        print("#", end="")
    print(end="  ")
    for dash in range(0 , row):
        print("#", end="")
    print()
