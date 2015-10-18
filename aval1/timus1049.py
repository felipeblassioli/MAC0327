# http://acm.timus.ru/help.aspx?topic=python
# Look at the section of "The number of divisors" and "Trial Division"
# https://www.topcoder.com/community/data-science/data-science-tutorials/prime-numbers-factorization-and-euler-function/

MAX = 10001
powers = [ 0 for i in xrange(MAX) ]

for n in ( int(input()) for i in xrange(10) ):
	j = 2
	while n != 1:
		while n % j == 0:
			powers[j] += 1
			n //= j
		j += 1

ans = 1
for i in xrange(2,MAX):
	ans = (ans * (powers[i] + 1)) % 10

print ans
