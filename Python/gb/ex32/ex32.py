l = []
n = int(input())
for i in range(n):
    new_element = int(input())
    l.append(new_element)
min = int(input())
max = int(input())
for x in l:
    if min <= x and max >= x:
        print(x)