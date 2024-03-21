a=[1,2,3,5,7,8,9,11,14,15,16,20,24,33,35,44]

def BinearySearch(target):
    le=0
    ri=len(a)-1
    while(le<=ri):
        mid=(le+ri)//2
        if(target==a[mid]):
            return True
        elif(target>a[mid]):
            le=mid+1
        else:
            ri=mid-1
    return False

print(BinearySearch(21))


