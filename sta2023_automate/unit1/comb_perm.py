from scipy.special import comb, perm

if __name__ == '__main__':
    n = int(input('N = '))
    k = int(input('k = '))

    print('n choose k: {}\nk permutations of n: {}'.format(comb(n, k), perm(n, k)))