# Kobee Raveendran
# 

# given a list of names and a number of bins (teams in this case), this will
# equally (or nearly equally) distribute them across the bins
import random
import argparse
import operator
import numpy as np

def random_assignment(args):
    # or, if list isn't available, enter line by line
    print('Enter players (one per line):')
    print('(press Enter again when done entering names)\n')

    curr_player = input()
    player_list = [curr_player]

    while True:
        curr_player = input()

        if curr_player == '':
            break

        player_list.append(curr_player)

    random.shuffle(player_list)

    # sort players into n bins
    n = args.num_buckets

    groups = {x: [] for x in range(n)}

    for i, player in enumerate(player_list):
        groups[i % n].append(player)

    # final teams
    for key, val in groups.items():
        print('\nTeam {}:\n'.format(key + 1))

        for player in val:
            print('   ', player)

        print('\n')

def weighted_assignment(args):

    print('Enter player names and KDR/XLRstats skill levels (separate names and KDR/stats with a space):')
    print('(press Enter again when done entering info)')

    '''
    curr_player_info = input().split(' ')
    
    player_list = [(curr_player_info[0], float(curr_player_info[1]))]

    while True:
        curr_player_info = input().split(' ')

        if curr_player_info[0] == '':
            break

        player_list.append((curr_player_info[0], float(curr_player_info[1])))

    # sorts by second param (either KDR or XLRstats rating)
    '''
    player_list = [('Phoenix', 2.86), 
                   ('Dreamtime', 2.15), 
                   ('Saood', 2.07), 
                   ('Reece', 1.51), 
                   ('meh???', 0.67), 
                   ('REY305', 6.73), 
                   ('grav', 3.02)]
    player_list.sort(key = operator.itemgetter(1))

    #print(player_list)

    n = args.num_buckets

    print('\nN: ', n)

    groups = {x: [] for x in range(n)}

    num_players = len(player_list)
    print(num_players % 2)

    skill_toggle = 1

    while len(player_list) != 0:
        for i in range(n):

            if len(player_list) == 0:
                break

            if skill_toggle:
                groups[i % n].append(player_list.pop(-1))

            else:
                groups[i % n].append(player_list.pop(0))

        skill_toggle = not skill_toggle

    print('num_players: ', num_players)
    print('n: ', n)

    #if num_players % n != 0:
    #    groups[n - 1].append(groups[0].pop(-1))

    for key, val in groups.items():
        print('\nTeam {}:\n'.format(key + 1))
        print('   Player Name\t\tKDA/XLR rating')

        for player in val:
            print('   {}\t\t{}'.format(player[0], player[1]))

        #print('Average skill (KDR/XLR): ', np.mean())
        print('\n')

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description = 'Bucket Team Randomizer')
    parser.add_argument('--num_buckets', default = 2, type = int, 
                        help = 'The number of groups you want to sort the players into')
    parser.add_argument('--delimiter', default = ',', type = str, 
                        help = "The character you'd like to use to separate player names, default is ,")
    parser.add_argument('--weighted', dest = 'weighted', default = False, action = 'store_true', 
                        help = 'Whether to assign teams randomly or balanced by skill/KD ratio.')
    
    args = parser.parse_args()

    # gather list of players
    #player_list = 'Dreamtime, Phoenix, Saood, REY305, Reece, Radiador, meh???'.split(',')
    #player_list = input("Enter list of players separated by a comma (,): ").split(',')
    #player_list = [x.strip() for x in player_list]

    if not args.weighted:
        random_assignment(args)

    else:
        weighted_assignment(args)