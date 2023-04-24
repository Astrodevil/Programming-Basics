def bubbleSort(lst):
    n = len(lst)
 
    for i in range(n-1):
 
        for j in range(0, n-i-1):
 
           
            if lst[j] > lst[j + 1] :
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
 
lst = [64, 34, 25, 12, 22, 11, 90]
 
bubbleSort(lst)
