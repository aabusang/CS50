import sys
import csv

database = []

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    with open(sys.argv[1], "r") as file1:
        reader = csv.reader(file1)
        next(reader)
        for row in reader:
            rlen = len(row)
            database.append(row)

    with open(sys.argv[2], "r") as file2:
        sequence = file2.read()

    #read the sequence and put repitions to a list
    agatc_maxreps = max(STR_count(sequence, "AGATC"))
    ttttttct_maxreps = max(STR_count(sequence, "TTTTTTCT"))
    aatg_maxreps = max(STR_count(sequence, "AATG"))
    tctag_maxreps = max(STR_count(sequence, "TCTAG"))
    gata_maxreps = max(STR_count(sequence, "GATA"))
    tatc_maxreps = max(STR_count(sequence, "TATC"))
    gaaa_maxreps = max(STR_count(sequence, "GAAA"))
    tctg_maxreps = max(STR_count(sequence, "TCTG"))

    if rlen == 4:
        match4 = False
        for i in range(len(database)):
            if int(database[i][1]) == agatc_maxreps and int(database[i][2]) == aatg_maxreps and int(database[i][3]) == tatc_maxreps:
                print(database[i][0])
                match4 = True
        if not match4:
            print("No match")
    else: #rlen must equal 9
        match9 = False
        for j in range(len(database)):
            if  (int(database[j][1]) == agatc_maxreps and int(database[j][2]) == ttttttct_maxreps and
                int(database[j][3]) == aatg_maxreps and int(database[j][4]) == tctag_maxreps and int(database[j][5]) == gata_maxreps and
                int(database[j][6]) == tatc_maxreps and int(database[j][7]) == gaaa_maxreps and int(database[j][8]) == tctg_maxreps):

                print(database[j][0])
                match9 = True
                break
        if not match9:
            print("No match")


def STR_count(sequence, pattern):

    str_rep_list = []
    reps = 0
    for j in range(0, len(sequence), 1):
        start = j
        end = start + len(pattern)
        if pattern == sequence[start:end]:
            for counter in range(0, len(sequence), len(pattern)):
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

if __name__ == "__main__":
    main()