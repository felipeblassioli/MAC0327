# Using minmax algorithm: not using depth to really do a perfect player
from collections import namedtuple

Game = namedtuple('Game', ['board', 'current_turn'])
winning_positions = [
    (0,1,2), (3,4,5), (6,7,8),
    (0,4,8), (2,4,6),
    (0,3,6), (1,4,7), (2,5,8)
]  

def check_winner(board):
    for positions in winning_positions:
        s = sum(map(lambda p: board[p], positions))
        if s == 3 or s == -3:
            return s
    return 0

def possible_games(game):
    board, p = game
    _p = p * -1
    for i in xrange(9):
        if board[i] == 0:
            _board = [ x for x in board ]
            _board[i] = p
            g =  Game(_board, _p)
            yield g
    
def minmax(game):
    s = check_winner(game.board)
    if s in [3,-3]: 
        return s
    elif sum(map(lambda p: 1 if p == 0 else 0, game.board)) == 0: 
        return 0
    
    scores = [ minmax( g ) for g in possible_games(game) ]
    if game.current_turn == 1:
        return max(scores)
    else:
        return min(scores)

import sys
from itertools import islice, chain
def _val_map(p):
    if p == 'X': return 1
    elif p == 'O': return -1
    else: return 0

board = map(_val_map,islice(chain(*sys.stdin.read().strip().split()),9))
s = minmax(Game(board,1))
if s > 0:
    print 'Crosses win'
elif s < 0:
    print 'Ouths win'
else:
    print 'Draw'

