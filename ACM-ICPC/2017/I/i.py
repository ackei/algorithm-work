grid = [[0]*9 for _ in range(9)]
row_eq = []
col_eq = []

coord_to_box = {}
box_to_coord = [[] for _ in range(9)]

for i in range(9):
    for j in range(9):
        box_num = 3*(i//3) + j
        coord_to_box[(i,j)] = box_num
        box_to_coord[box_num].append((i,j))

def check_row(i,j):
    poss = set(range(1,10))
    for num in grid[i]:
        poss.discard(num)
    return poss

def check_col(i,j):
    poss = set(range(1,10))
    for k in range(9):
        poss.discard(grid[k][j])
    return poss

def check_box(i,j):
    poss = set(range(1,10))
    box_num = coord_to_box[(i,j)]
    coords = box_to_cord[box_num]
    for coord in coords:
        x, y = coord
        poss.discard(grid[x][y])
    return poss

def check_eq(i,j):
    poss = set(range(1,10))
    if i % 3 != 0:
        col_op = 2 * (i // 3) + (i % 3) - 1
        symb = col_eq[j][op]


def check_all(i,j):
    pass

def backtrack(i,j):


P = int(input())
for _ in range(P):
    K = int(input())
    row_eq = []
    col_eq = []
    for i in range(15):
        symbs = input()
        if i % 2 == 0:
            row_eq.append(symbs)
        else:
            col_eq.append(symbs)

