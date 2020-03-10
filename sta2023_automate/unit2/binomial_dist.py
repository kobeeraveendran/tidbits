from math import factorial
from math import sqrt

if __name__ == '__main__':
    n = int(input('N: '))
    p_x = float(input('P(x): '))
    print()

    distribution = []

    for var in range(n+1):
        ncr = factorial(n) / (factorial(var) * factorial(n - var))

        p_var = ncr * (p_x ** var) * ((1 - p_x) ** (n - var))
        print('P({}): {}'.format(var, p_var))
        distribution.append(p_var)

    mean = n * p_x
    print('\n\nMean (mu): ', mean)

    variance = n * p_x * (1 - p_x)
    print('Variance (sigma^2): ', variance)

    std_dev = sqrt(variance)
    print('Standard deviation (sigma): ', std_dev)

    print('\n')
    less_than = int(input('P(x < ?): '))
    print('P(x < {}): {}'.format(less_than, sum(distribution[:less_than])))

    greater_than = int(input('P(x > ?): '))   
    print('P(x > {}): {}'.format(greater_than, sum(distribution[greater_than+1:])))