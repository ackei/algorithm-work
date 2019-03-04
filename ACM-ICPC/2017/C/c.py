from copy import deepcopy

rdiff = [-1,-1,-1,0,0,1,1,1]
cdiff = [-1, 0, 1,-1,1,-1,0,1]

def construct_candidates(grid, group, group_cands, i, j):
    R = len(grid)
    C = len(grid[0])
    g = group[i][j]
    cands = group_cands[g].copy()
    for k in range(8):
        new_i = i + rdiff[k]
        new_j = j + cdiff[k]
        if 0 <= new_i < R and 0 <= new_j < C:
            elt = grid[new_i][new_j]
            if elt in cands:
                cands.remove(elt)
    return cands

def backtrack(grid, group, group_cands, i, j):
    R = len(grid)
    C = len(grid[0])
    if j >= C:
        i = i+1
        j = 0
    if i >= R:
        return deepcopy(grid)
    if grid[i][j] != 0:
        return backtrack(grid, group, group_cands, i, j+1)
    candidates = construct_candidates(grid, group, group_cands, i, j)
    for candidate in candidates:
        tmp = grid[i][j]
        g = group[i][j]
        group_cands[g].remove(candidate)
        grid[i][j] = candidate
        answer = backtrack(grid, group, group_cands, i, j+1)
        grid[i][j] = tmp
        group_cands[g].add(candidate)
        if answer:
            return answer

def print_grid(grid):
    for row in grid:
        print(' '.join([str(s) for s in row]))


P = int(input())
for _ in range(P):
    K, R, C = [int(i) for i in input().split()]
    grid = []
    for row_num in range(R):
        row = input().split()
        for i in range(C):
            if row[i] == '-':
                row[i] = 0
            else:
                row[i] = int(row[i])
        grid.append(row)
    G = int(input())
    group = [[0 for _ in range(C)] for _ in range(R)]
    group_cands = []
    for i in range(G):
        g = input().split()
        group_size = int(g[0])
        group_cands.append(set([i+1 for i in range(group_size)]))
        for point in g[1:]:
            r = int(point[1]) - 1
            c = int(point[3]) - 1
            group[r][c] = i
    for i in range(R):
        for j in range(C):
            val = grid[i][j]
            if val != 0:
                g = group[i][j]
                group_cands[g].remove(grid[i][j])
    print(K)
    grid = backtrack(grid, group, group_cands, 0, 0)
    print_grid(grid)

