import random

def RandomArray(size):
    random_array = []
    for a in range (size):
        random_array.append(random.randint(-1, 100))       
    return (random_array)

# Bubble sort
def BubbleSort(array,start, end):
    for i in range(start,end-1,+1): 
        for j in range(start,end):
            if array[j] > array[j+1]:
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
    sorted_array = []
    for a in range(start,end,+1):
        sorted_array.append(array[a])
    return (sorted_array)

class Student:
    public:
        