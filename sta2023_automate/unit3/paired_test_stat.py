import math

if __name__ == "__main__":

    p1_hat = float(input("p1: "))
    n1 = int(input("n1: "))
    p2_hat = float(input("p2: "))
    n2 = int(input("n2: "))

    ts = (p1_hat - p2_hat) / (math.sqrt((0.5 ** 2) * (1 / n1 + 1 / n2)))

    print(ts)