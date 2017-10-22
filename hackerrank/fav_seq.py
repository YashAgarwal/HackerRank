def combine(l, s):

    bufs = []
    bufl = []

    len1 = len(l)
    len2 = len(s)

    if len1 == 0:
        return s

    elif len2 == 0:
        return l
    
    elif len1 < len2:
        #swap
        temp = l
        l = s
        s = temp 

    for index, val in enumerate(s):
        if val in l:
            if len(bufl) == 0:
                bufs.append(index)
                bufl.append(l.index(val))

            elif index > bufl[-1]: 
                bufs.append(index)
                bufl.append(l.index(val))
    
    if len(bufs) == 0:
        return merge(l,s)           
    
    l_temp = []

    subs = s[0:bufs[1]]
    subl = l[0:bufl[1]]
        
    l_temp += merge(subl, subs)

    for i in range(len(subs)+1):
        

    for index, pos in enumerate(bufs):
        subs = []
        subl = []
        
        if index == len(bufs) - 1:
            subs = s[pos:]
            subl = l[bufl[index]:]
        
        else:
            subs = s[pos:bufs[index+1]]
            subl = l[bufl[index]:bufl[index+1]]
            
        l_temp += merge(subl, subs)

    return l_temp

def merge(str1, str2):

    if len(str1) == 0:
        return str2

    elif len(str2) == 0:
        return str1

    i = str2[0]    
    
    if i in str1:
        return merge(str1, str2[1:])

    flag = 0
    pos = 0
            
    for index,j in enumerate(str1):
        if i < j:
            return str1[:index] + [i] + merge(str1[index:],str2[1:])

    return str1 + str2

L = [2,4]
M = [4,3]

print merge(L, M)

"""
M = raw_input()
M = int(M)

l = []

for i in range(M):
    
    K = raw_input()
    K = int(K)
    
    if K is not 0:
    
        s = []

        f = raw_input().strip().split(' ')
        
        for k in f:

            s.append(int(k))

        len1 = len(l)
        len2 = len(s)
        
        if len1 == 0:

            l = s

        elif len1 > len2:
            
            l = combine(l,s)

        else:
            
            l = combine(s,l)

        print l   

ans = ""

for index, i in enumerate(l):

    if index == len(l) -1:                  
        ans += str(i)

    else:
        ans += str(i) + " "

print ans
"""    