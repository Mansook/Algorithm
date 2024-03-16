a=[5,7,9,0,1,3,6,8,2,4]

def MergeSort(le,ri):
    if(le+1==ri):
        return
    mid=(le+ri)//2
    MergeSort(le,mid)
    MergeSort(mid,ri)

    l,r=le,mid
    temp=[]
    while(1):
        if l==mid and r==ri:
            break
        elif l==mid:
            temp.append(a[r])
            r+=1
        elif r==ri:
            temp.append(a[l])
            l+=1
        else:
            if a[l]<a[r]:
                temp.append(a[l])
                l+=1
            else:
                temp.append(a[r])
                r+=1
    
    for i in temp:
        a[le]=i
        le+=1

MergeSort(0,10)
print(a)