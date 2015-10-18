from collections import deque, defaultdict

m = input()
products = defaultdict(int, { d[2]: int(d[0]) for d in [ raw_input().strip().split(' ') for _ in xrange(m) ]})
n = input()
customers = deque([ (int(d[0]), d[2]) for d in [ raw_input().strip().split(' ') for _ in xrange(n) ] ])

time = 0
while len(customers) > 0:
    qty, p = customers.popleft()
    if qty <= products[p]:
        products[p] -= qty
    elif products[p] == 0:
        pass
    elif len(customers) > 0:
        next_customer = customers.popleft()
        customers.appendleft((products[p], p))
        customers.appendleft(next_customer)
    else:
        customers.appendleft((products[p], p))
        time += 1
        break
    time += 1

print time
