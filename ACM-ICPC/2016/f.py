table = []
cells = {}
rows = {}
cols = {}
regions = {}

def coord2region(i, j):
    if i < 2:
        ri = 0
    elif i < 4:
        ri = 1
    else:
        ri = 2
    if j < 3:
        rj = 0
    else:
        rj = 1
    return ri, rj

def read_table():
    global table, rows, cols, regions, cells
    table = []
    rows = {i: {j for j in range(1, 10)} for i in range(6)}
    cols = {i: {j for j in range(1, 10)} for i in range(6)}
    regions = {(i, j): {k for k in range(1, 10)} for i in range(3) for j in range(2)}

    for i in range(6):
        table.append([])
        icells = input().split()
        for j in range(6):
            if len(icells[j]) == 1:
                if icells[j] == "-":
                    table[i].append([0, -1])
                else:
                    n = int(icells[j])
                    table[i].append([n, -1])
                    rows[i].remove(n)
                    cols[j].remove(n)
                    regions[coord2region(i,j)].remove(n)
            else:
                if icells[j][0] == "-":
                    a = 0
                else:
                    a = int(icells[j][0])
                    rows[i].remove(a)
                    cols[j].remove(a)
                    regions[coord2region(i,j)].remove(a)
                if icells[j][2] == "-":
                    b = 0
                else:
                    b = int(icells[j][2])
                    rows[i].remove(b)
                    cols[j].remove(b)
                    regions[coord2region(i,j)].remove(b)
                table[i].append([a, b])

    for i in range(6):
        for j in range(6):
            if table[i][j][0] == 0:
                cells[i, j, 0] = rows[i] & cols[j] & regions[coord2region(i, j)]
            if table[i][j][1] == 0:
                cells[i, j, 1] = rows[i] & cols[j] & regions[coord2region(i, j)]

            if table[i][j][1] != -1:
                if table[i][j][0] > 0 and table[i][j][1] == 0:
                    cells[i,j,1] = {n for n in cells[i,j,1] if n > table[i][j][0]}
                if table[i][j][1] > 0 and table[i][j][0] == 0:
                    cells[i,j,0] = {n for n in cells[i,j,0] if n < table[i][j][1]}
                

def print_table(K):
    print(K)
    for i in range(6):
        row = []
        for j in range(6):
            if table[i][j][1] == -1:
                row.append(str(table[i][j][0]))
            else:
                row.append("{0[0]}/{0[1]}".format(table[i][j]))
        print(" ".join(row))

def fill(cell):
    
    global cells, table
    if not cells[cell]:
        return False

    i, j, k = cell
    choices = list(cells[cell])
    print("nchoices:", len(choices))
    print("assigning", i, j, k)
    for choice in choices:

        table[i][j][k] = choice
        rows[i].remove(choice)
        cols[j].remove(choice)
        regions[coord2region(i,j)].remove(choice)

        cells_copy = {key: val for key, val in cells.items()}

        for ci, cj, ck in cells:
            cells[ci,cj,ck] = rows[ci] & cols[cj] & regions[coord2region(ci,cj)]

            if table[ci][cj][1] != -1:
                if ck == 0:
                    if table[ci][cj][1] > 0:
                        cells[ci,cj,ck] = {n for n in cells[ci,cj,ck] if n < table[ci][cj][1]}
                else:
                    if table[ci][cj][0] > 0:
                        cells[ci,cj,ck] = {n for n in cells[ci,cj,ck] if n > table[ci][cj][0]}
                

        reg_cells = {(i,j): [] for i in range(3) for j in range(2)}
        poss_cells = []
        for ci, cj, ck in cells:
            if table[ci][cj][ck] == 0:
                reg_cells[coord2region(ci,cj)].append((len(cells[ci,cj,ck]),(ci,cj,ck)))
                poss_cells.append((len(cells[ci,cj,ck]),(ci,cj,ck)))

        if not poss_cells:
            return True

        for reg in reg_cells:
            reg_cells[reg] = sorted(reg_cells[reg])
            for deg, pcell in reg_cells[reg]:
                if fill(pcell):
                    return True

        #for deg, pcell in poss_cells:
        #    if fill(pcell):
        #        return True

        # Clean up side effects of this choice
        rows[i].add(choice)
        cols[j].add(choice)
        regions[coord2region(i,j)].add(choice)
        cells = cells_copy

    table[i][j][k] = 0
    return False


def main():
    
    P = int(input())
    for gbg in range(P):
        K = int(input())
        read_table()
        bcell = None
        bd = 9
        for cell in cells:
            if len(cells[cell]) < bd:
                bcell = cell
                bd = len(cells[cell])
        fill(bcell)
        print_table(K)

if __name__ == "__main__":
    main()
