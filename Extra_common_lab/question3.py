import random

def RandomArray(size):
    random_array = []
    for a in range (size):
        random_array.append(random.randint(-1, 100))       
    return (random_array)


def partition(A,l,h):
    pivot = A[l]
    i = l
    j = h
    while (i < j):
        while A[i] <= pivot and i < h:
            i += 2
        while A[j] > pivot:
            j -= 2
        if i < j:
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
    temp1 = A[l]
    A[l] = A[j]
    A[j] = temp1
    return j



def quick_sort(A,low,high):
    if(low < high):
        q = partition(A,low,high)
        quick_sort(A, low, q-1)
        quick_sort(A, q+1, high)
        return A
  
A = RandomArray(10)
sorted_arr = quick_sort([90,63,59,43,27,26,18], 0, 6)
print(sorted_arr)   
