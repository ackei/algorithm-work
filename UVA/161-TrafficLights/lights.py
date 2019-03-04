def on(cycle_t, t):
    return t % (2*cycle_t) < cycle_t - 5

def sim(times):
    for t in range(min(times)-5, 5*60*60+1):
        all_go = True
        for time in times:
            if not on(time, t):
                all_go = False
                break
        if all_go:
            hr = t // 3600
            t %= 3600
            minut = t // 60
            t %= 60
            sec = t
            print("{:02d}:{:02d}:{:02d}".format(hr,minut,sec))
            return
    print("Signals fail to synchronise in 5 hours")


def main():
    l = []
    while True:
        n = [int(i) for i in input().split()]
        if len(n) >= 3 and n[0] == n[1] == 0:
            return
        else:
            for i in n:
                if i:
                    l.append(i)
                else:
                    sim(l)
                    l = []

main()

