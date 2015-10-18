a,b,c,d = [ int(x) for x in raw_input().split(' ') ]

while a <= c:
	a+=b
	a = min(a,c)
	c-=d
print a
