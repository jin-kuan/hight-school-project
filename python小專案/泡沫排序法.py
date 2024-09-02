size = 8
array = [16, 25, 39, 27, 12, 8, 45, 63]

for i in range(size - 1):
    for j in range(size - 1 - i):
        if array[j] > array[j + 1]:
            array[j], array[j + 1]=array[j+1], array[j]
print(array)

    








