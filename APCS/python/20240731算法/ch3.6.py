def sq(x,pre=2):
    step = 1
    r =step
    while step>= 10 ** -pre:
        while r * r <x:
            r+=step
            if r * r == x:
                return r
        r -= step
        step/=10
    return r
while True:
    n = int(input("N"))
    print(f"{n}平方根{sq(n):.2f}")
    
