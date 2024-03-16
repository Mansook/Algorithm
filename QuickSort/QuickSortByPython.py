a=[5,7,9,0,1,3,6,8,2,4]

def QuickSort(le, ri):
    if(le==ri):
        return
    pivot=a[(le+ri)//2]
    l,r=le,ri
    while(l<r):
        while(a[l]<pivot):
            l+=1
        while(pivot<a[r]):
            r-=1
        temp=a[r]
        a[r]=a[l]
        a[l]=temp
    if le+1==ri:
        return
    QuickSort(le,l-1)
    QuickSort(l,ri)

QuickSort(0,9)
print(a)