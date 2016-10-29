def cyclic(line):
    iscyclic = True
    str_tmp = "{{:.{0}f}}".format(len(line))
    dbl = float(line) / 10**len(line)
    for i in range(2, len(line)+1):
        nx_dbl = i*dbl
        str_nxdbl = str_tmp.format(nx_dbl)
        if nx_dbl < 1.0:
            str_nxdbl = str_nxdbl[2:2+len(line)]
        else:
            str_nxdbl = str_nxdbl.replace(".", "")[:len(line)]
        if not line in str_nxdbl + str_nxdbl:
            #import pdb; pdb.set_trace()
            iscyclic = False
    else:
        if iscyclic:
            print(line, "is cyclic")
        else:
            print(line, "is not cyclic")

def main():

    with open("cyclic.in") as fh:
        lines = fh.readlines()

    for line in lines:
        cyclic(line.strip())

if __name__ == "__main__":
    main()
