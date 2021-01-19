import sys

def main():

    if len(sys.argv) != 2:
        print("Usage: python test1.py file.txt")
        sys.exit(1)

    with open(sys.argv[1], "r") as file:
        sequence = file.read()

    #do the comparisons
    pattern1 = "AGATC"
    pattern2 = "AATG"
    pattern3 = "TATC"

    agatclist = STRs_count(sequence, pattern1)
    aatglist = STRs_count(sequence, pattern2)
    tatclist = STRs_count(sequence, pattern3)
    # print(sequence)

    # print(agatclist)
    # print(aatglist)
    # print(tatclist)

    # print("Len of sequence: "+ str(len(sequence)))
    print("AGATC-Max: " + str(max(agatclist)))
    print("Length of agatlist: " + str(len(agatclist)))
    print("AATG-Max: " + str(max(aatglist)))
    print("Length of agatlist: " + str(len(aatglist)))
    print("TATC-Max: " + str(max(tatclist)))
    print("Length of agatlist: " + str(len(tatclist)))


def STRs_count(sequence, pattern):

    str_rep_list = []
    reps = 0
    for j in range(0, len(sequence), 1):
        start = j
        end = start + len(pattern)
        if pattern == sequence[start:end]:
            for counter in range(0, len(sequence), 4):
                start = j + counter
                end = start + len(pattern)
                if pattern == sequence[start:end]:
                    reps += 1
                else:
                    if reps > 0:
                        str_rep_list.append(reps)
                        reps = 0
                        break
        else:
            if reps > 0:
                str_rep_list.append(reps)
                reps = 0
    str_rep_list.append(reps)
    return str_rep_list


main()