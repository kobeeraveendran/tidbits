import numpy as np

def poisson(mu, x):
    return (mu ** x * np.exp(-1 * mu)) / np.math.factorial(x)

if __name__ == '__main__':
    mu = float(input('Enter the mean (mu): '))
    x = int(input('Enter the number of successes (x): '))

    p_x = poisson(mu, x)

    print('P({}) = {}'.format(x, p_x))

    poisson_dist = [poisson(mu, i) for i in range(x+1)]

    # P(X <= x)
    p_cumulative = sum(poisson_dist)
    print('P(X <= {}) = {}'.format(x, p_cumulative))
    print('P(X < {}) = {}'.format(x, p_cumulative - p_x))

    #P(X > x)
    print('P(X > {}) = {}'.format(x, 1 - p_cumulative))
    print('P(X >= {}) = {}'.format(x, 1 - p_cumulative + p_x))