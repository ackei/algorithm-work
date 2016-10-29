def cyclic_int(line):

    iscyclic = True
    nbr = int(line)
    for i in range(2, len(line)+1):
        nx_nbr = i*nbr
        str_nx_nbr = str(nx_nbr)
        str_nx_nbr = str_nx_nbr[:len(line)]
        if not line in str_nx_nbr + str_nx_nbr:
            iscyclic = False
        str_nx_nbr = str(nx_nbr)
        str_nx_nbr = "0" + str_nx_nbr[:len(line)-1]
        if line in str_nx_nbr + str_nx_nbr:
            iscyclic = True
    else:
        if iscyclic:
            print(line, "is cyclic")
        else:
            print(line, "is not cyclic")

def main():

    with open("cyclic.in") as fh:
        lines = fh.readlines()

    for line in lines:
        cyclic_int(line.strip())

if __name__ == "__main__":
    main()
