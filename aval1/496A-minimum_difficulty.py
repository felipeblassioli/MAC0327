n = input()
A = [ int(x) for x in raw_input().split(' ') ]

track_difficulty = max([ A[i+1] - A[i] for i in xrange(n-1)])
difficulties = [ max(A[i+1] - A[i-1], track_difficulty) for i in xrange(1,n-1) ]
print min(difficulties) if len(difficulties) > 0 else track_difficulty
