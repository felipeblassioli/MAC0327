import itertools

g = [0,0,0,0]
for i in xrange(4):
    for j, c in enumerate(raw_input().strip()):
        g[i] |= ((c == 'W') << 3-j)

m = [ int(raw_input().strip(),2) for i in xrange(3) ]
g = g[0] << 12 | g[1] << 8 | g[2] << 4 | g[3]

def mask(pos):
    shift = lambda x,d: x << d if d >= 0 else x >> (-d)
    if pos % 4 == 3:
        msk = [ x & ~1 for x in m ]
    elif pos % 4 == 0:
        msk = [ x & ~( 1 << 2) for x in m ]
    else:
        msk = [ x for x in m ]

    r = 0
    if pos > 3:
        r |= shift(msk[0], 18-pos)
    r |= shift(msk[1], 14-pos)
    if pos < 12:
        r |= shift(msk[2], 10-pos)
    return r

masks = {i: mask(i) for i in xrange(16)}
a = range(16)
has_solution = False
for level in xrange(17): 
    for positions in itertools.combinations(a,level): 
        game = g
        for pos in positions:
            game ^= masks[pos]

        if game == 65535 or game == 0:
            has_solution = True
            break
    if has_solution:
        break

if has_solution:
    print level
else:
    print 'Impossible'
