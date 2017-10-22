# Enter your code here. Read input from STDIN. Print output to STDOUT

"""
T = int(raw_input().strip())

for t in range(T):
    
    P = [1]
    Nmax = [2]
    X = 4
    
    N = int(raw_input().strip())
    
    while True:

        if N <= Nmax[X-4]:
            break

        else:
            #increment X
            X += 1

            #Calculate P[X]
            P.append(0)
            i = 1
            while X - i*i - 4 >= 0:
                P[X-4] += P[X - i*i - 4]
                i += 1
            
            #find Nmax
            Nmax.append(0)
            Nmax[X-4] = Nmax[X-5] + P[X-4]

    print X
"""

T = int(raw_input().strip())

for N in range(T):
    
    P = [1]
    Nmax = [2]
    X = 4

    while True:

        if N <= Nmax[X-4]:
            break

        else:
            #increment X
            X += 1

            #Calculate P[X]
            P.append(0)
            i = 1
            while X - i*i - 4 >= 0:
                P[X-4] += P[X - i*i - 4]
                i += 1
            
            #if X >= 9:
            #    P[X-4] += 1

            #find Nmax
            Nmax.append(0)
            Nmax[X-4] = Nmax[X-5] + P[X-4]
            
            if X >= 9:
                Nmax[X-4] += 1
            
            

    print str(N) + ":" + str(X)