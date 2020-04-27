import sys
sys.path.append('..')
import math
import argparse
#from sta2023_automate.unit1.var_stddev import std_dev
from unit1.var_stddev import std_dev
from scipy import stats

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

    parser = argparse.ArgumentParser()

    parser.add_argument("--as_list", dest = 'as_list', action = 'store_true')
    parser.add_argument("--t_val", dest = 't_val', action = 'store_true')
    parser.add_argument("--prop", dest = 'prop', action = 'store_true')
    parser.set_defaults(as_list = False, t_val = False, prop = False)

    args = parser.parse_args()

    if args.as_list:
        vals = input("Enter space-separated values: ").split(' ')
        data = [float(x) for x in vals]
        n = len(data)

        x_bar = sum(data) / n

        _, std = std_dev(data)

        conf = float(input("Confidence (as %): "))
        conf /= 100.

        crit_val = stats.t.ppf(1 - ((1 - conf)/2.), n - 1)

        conf_interval = str(x_bar) + " +/- " + str(crit_val) + "({}/sqrt({})".format(std, n)

        bounds = (x_bar - crit_val * (std / math.sqrt(n)), x_bar + crit_val * (std / math.sqrt(n)))

        print("Bounds:\n", bounds)

    elif args.t_val:
        n = int(input("n: "))
        x_bar = float(input("Sample mean (x bar): "))
        std = float(input("Std dev: "))
        conf = float(input("Confidence (as %): "))
        conf /= 100.

        crit_val = stats.t.ppf(1 - ((1 - conf)/2.), n - 1)
        conf_interval = str(x_bar) + " +/- " + str(crit_val) + "({}/sqrt({})".format(std, n)

        print(conf_interval)

        bounds = (x_bar - crit_val * (std / math.sqrt(n)), x_bar + crit_val * (std / math.sqrt(n)))

        print("Bounds: ", bounds)

    elif args.prop:
        n = int(input("n: "))
        p = float(input("p numerator (success): ")) / n
        q = 1. - p

        conf = float(input("Confidence (as %): ")) / 100.

        z_score = stats.norm.ppf(1 - (1 - conf)/2)

        conf_interval = "{} +/- {} * sqrt({} * {} / {})".format(p, z_score, p, q, n)

        print(conf_interval)

        bounds = (p - z_score * math.sqrt((p * q) / n), p + z_score * math.sqrt((p * q) / n))

        #bounds = (p - z_table[conf] * (std / math.sqrt(n)), x_bar + crit_val * (std / math.sqrt(n)))

        print("Bounds: ", bounds)

    else:
        #mean = float(input("Mean: "))
        std = float(input("Std dev: "))
        conf = float(input("Confidence (as %): ")) / 100.

        n = float(input("n: "))
        x_bar = float(input("Sample mean (x bar): "))

        z_score = stats.norm.ppf(1 - (1 - conf)/2)

        conf_interval = str(x_bar) + " +/- " + str(z_score) + "({}/sqrt({})".format(std, n)

        print(conf_interval)

        bounds = (x_bar - z_score * (std / math.sqrt(n)), x_bar + z_score * (std / math.sqrt(n)))

        print("Bounds:\n", bounds)