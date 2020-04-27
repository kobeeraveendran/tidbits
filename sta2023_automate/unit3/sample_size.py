import math
import argparse

z_table = {
    "80": 1.282,
    "85": 1.440, 
    "90": 1.645, 
    "95": 1.960, 
    "99": 2.576, 
    "99.5": 2.807, 
    "99.9": 3.291
}

if __name__ == "__main__":

    parser = argparse.ArgumentParser()

    parser.add_argument("--p", dest = "p", action = "store_true")
    parser.set_defaults(p = False)

    args = parser.parse_args()

    conf = input("Confidence (as %): ")
    e = float(input("Margin of error (E): "))

    if not args.p:

        std = float(input("Std dev: "))
        sample_size = ((z_table[conf] * std) / e) ** 2

        print("Required sample size: ", math.ceil(sample_size))

    else:
        p = float(input("p (if none provided, enter 0.5): "))
        q = 1 - p

        sample_size = p * q * (z_table[conf] / e) ** 2

        print("Required sample size: ", math.ceil(sample_size))