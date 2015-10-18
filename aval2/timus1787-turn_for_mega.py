k,n = [ int(i) for i in raw_input().strip().split(' ') ]

total = 0
for c in [ int(i) for i in raw_input().strip().split(' ') ]:
	total = max((total+c) - k, 0)
print total
