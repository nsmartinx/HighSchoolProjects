j = input()
a = input()

sizes = []
for i in range(int(j)):
    sizes.append(input())

correctJerseys = 0

for i in range(int(a)):
    line = input()
    number = int(line[2:]) - 1
    curSize = line[0]
    if sizes[number] != "T":
        if curSize == "S" or curSize == sizes[number] or (curSize == "M" and sizes[number] == "L"):
                correctJerseys += 1
                sizes[number] = "T"
print(correctJerseys)
