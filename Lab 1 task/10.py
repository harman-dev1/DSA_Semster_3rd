def srted_neg_positive(arr):
    positive_array = []
    negative_array = []
    # separting Both negative and positive array's
    for a in range(len(arr)-1,-1,-1):
        if arr[a] > 0:
            positive_array.append(arr[a])
        else:
            negative_array.append(arr[a])
    # sorting arrays separte
    for i in range(len(positive_array)-1,0,-1):
        for j in range(i):
            if positive_array[j] > positive_array[j+1]:
                temp = positive_array[j]
                positive_array[j] = positive_array[j+1]
                positive_array[j+1] = temp
            
    for i in range(len(negative_array)-1,0,-1):
        for j in range(i):
            if negative_array[j] > negative_array[j+1]:
                temp = negative_array[j]
                negative_array[j] = negative_array[j+1]
                negative_array[j+1] = temp
    
    merge_array = []
    i = 0
    while i < len(negative_array) or i < len(positive_array):
        if i < len(negative_array):
            merge_array.append(negative_array[i])
        if i <  len(positive_array):
            merge_array.append(positive_array[i])
        i += 1
        
        
    return merge_array
        
    



arr = [10, -1, 9, 20, -3, -8, 22, 9, 7]
merge_array = srted_neg_positive(arr)
print(merge_array)