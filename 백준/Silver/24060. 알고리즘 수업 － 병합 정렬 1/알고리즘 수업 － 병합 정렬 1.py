import copy
tmp = list()
count = 0
def main():
    n, k = map( int, input().split() ) 
    lst = list( map(int, input().split() ) )
    global tmp
    global count
    tmp = copy.deepcopy(lst)
    mergeSort(lst, 0, n-1, k)
    if count < k:
        print(-1)

def mergeSort(lst, p, r, k):
    if p < r:
        q = (p+r)//2
        mergeSort(lst, p, q, k)
        mergeSort(lst, q+1, r, k)
        merge(lst, p, q, r, k)

def merge( lst, p, q, r, k):
    global tmp
    global count
    i = p
    j = q+1
    t = 0

    while i <= q and j <= r:
        if lst[i] <= lst[j]:
            tmp[t] = lst[i]
            t, i = t+1, i+1
        else:
            tmp[t] = lst[j]
            t,j = t+1, j+1
            
        count += 1
        if count is k:
            print(tmp[t-1])
            
    while i <= q:
        tmp[t] = lst[i]
        t, i = t+1, i+1
        count += 1
        if count is k:
            print(tmp[t-1])
            
    while j <= r:
        tmp[t] = lst[j]
        t, j = t+1, j+1
        count += 1
        if count is k:
            print(tmp[t-1])
            
    i, t = p, 0
    while i <= r:
        lst[i] = tmp[t]
        i, t = i +1, t+1
        
main()
    