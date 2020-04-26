import math

z_table = {
    "80": 1.282,
    "85": 1.440, 
    "90": 1.645, 
    "95": 1.960, 
    "99": 2.576, 
    "99.5": 2.807, 
    "99.9": 3.291
}


if __name__ == '__main__':

    #mean = float(input("Mean: "))
    std = float(input("Std dev: "))
    conf = input("Confidence (as %): ")

    n = float(input("n: "))
    x_bar = float(input("Sample mean (x bar): "))

    conf_interval = str(x_bar) + " +/- " + str(z_table[conf]) + "({}/sqrt({})".format(std, n)

    print(conf_interval)

    bounds = (x_bar - z_table[conf] * (std / math.sqrt(n)), x_bar + z_table[conf] * (std / math.sqrt(n)))

    print("Bounds:\n", bounds)