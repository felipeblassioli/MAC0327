def main():
	from sys import stdin
	from itertools import islice, takewhile
	from collections import deque

	tkns = iter(map(int,stdin.read().split()))
	m = tkns.next()

	nums = deque()
	max_nums = deque() 
	for n in takewhile(lambda x: x != -1, tkns):
		nums.append(n)
		while len(max_nums) > 0 and max_nums[-1] < n:
			max_nums.pop()
		max_nums.append(n)
		if len(nums) == m:
			i = nums.popleft()
			print max_nums[0]
			if max_nums[0] == i:
				max_nums.popleft()

main()
