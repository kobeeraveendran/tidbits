import math
import sys
sys.path.append("..")
from scipy import stats

import argparse

from unit1.var_stddev import std_dev


if __name__ == "__main__":

    parser = argparse.ArgumentParser()

    parser.add_argument("--prop", dest = "prop", action = "store_true")
    parser.set_defaults(prop = False)

    args = parser.parse_args()

    if not args.prop:
        data1 = input("First group (space-separated): ").split(' ')
        data1 = [float(x) for x in data1]

        data2 = input("Second group (space-separated): ").split(' ')
        data2 = [float(x) for x in data2]

        diff = [x1 - x2 for x1, x2 in zip(data1, data2)]

        sample_mean = sum(diff) / len(diff)
        _, sample_std = std_dev(diff)

        alpha = float(input("alpha (1 - confidence): "))

        t_score = abs(stats.t.ppf(alpha / 2, len(diff) - 1))

        conf_interval = "{} +/- {} * ({} / sqrt({}))".format(sample_mean, t_score, sample_std, len(diff))

        print(conf_interval)

        bounds = (sample_mean - t_score * (sample_std / math.sqrt(len(diff))), sample_mean + t_score * (sample_std / math.sqrt(len(diff))))

        print("Bounds: ", bounds)

    else:
        p1_hat = float(input("p1: "))
        q1_hat = 1 - p1_hat
        n1 = int(input("n1: "))

        p2_hat = float(input("p2: "))
        q2_hat = 1 - p2_hat
        n2 = int(input("n2: "))

        alpha = 1 - float(input("Confidence (as %): ")) / 100

        p_diff = p1_hat - p2_hat
        print("p_diff: ", p_diff)

        #z = (p1_hat - p2_hat) / math.sqrt((p1_hat * q1_hat) / n1 + (p2_hat + q2_hat) / n2)

        #e = math.sqrt(((p1_hat * q1_hat) / n1) + ((p2_hat + q2_hat) / n2))
        e = math.sqrt(p1_hat * q1_hat / n1 + p2_hat * q2_hat / n2)
        z = abs(stats.norm.ppf(alpha/2))

        print("z: ", z)
        print("e: ", e)

        bounds = (p_diff - z * e, p_diff + z * e)

        print("Bounds: ", bounds)