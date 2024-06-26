arr = [7,4,7,0,8,3,-9,2]

n = len(arr)
for i in range(1,n):
    key  =arr[i]
    j=i-1
    while j>=0 and(arr[j]>key):
        arr[j+1] =arr[j]
        j-=1
        print(arr)
        print("\n")
    arr[j+1 ] = key

