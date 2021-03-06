#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        printf("\n");

        record_preferences(ranks);
    }

    add_pairs();
    sort_pairs();

    for (int i = 0; i < pair_count; i++)
    {
        printf("%d, %d\n", pairs[i].winner, pairs[i].loser);
    }
    lock_pairs();
    print_winner();
    return 0;
}


// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int win, los;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            win = ranks[i];
            los = ranks[j];
            preferences[win][los]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] != preferences[j][i])
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[k].winner = i;
                    pairs[k].loser = j;
                    pair_count++;
                    k++;
                }
                else
                {
                    pairs[k].winner = j;
                    pairs[k].loser = i;
                    pair_count++;
                    k++;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int win1, win2, los1, los2;
    int temp1, temp2, first, second;
    int k = 0;

    for (int i = 0; i < pair_count - 1; i++)
    {
        win1 = pairs[i].winner;
        los1 = pairs[i].loser;

        win2 = pairs[i + 1].winner;
        los2 = pairs[i + 1].loser;

        first = preferences[win1][los1] - preferences[los1][win1];
        second = preferences[win2][los2] - preferences[los2][win2];
        if (first < second)
        {
            temp1 = win1;
            temp2 = los1;

            pairs[k].winner = win2;
            pairs[k].loser = los2;

            pairs[k + 1].winner = temp1;
            pairs[k + 1].loser = temp2;
            k++;
        }
    }

    return;
}

bool makes_cycle(int winner, int loser)
{
    if (locked[loser][winner])
    {
        return true;
    }
    else
    {
        for (int i = 0; i < pair_count; i++)
        {
            if (locked[loser][pairs[i].winner]) //if loser has locked with any winner already locked
            {
                if (locked[pairs[i].winner][winner]) //if loser's loser is loser's winner then there is a cycle
                {
                    return true;
                }
                else
                {
                    //else put this point in loop at a safe place and
                    //call this function again with the most recent loser
                    return makes_cycle(winner, pairs[i].winner);
                }
            }
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int x, y;
    for (int i = 0; i < pair_count; i++)
    {
        x = pairs[i].winner;
        y = pairs[i].loser;
        if (!makes_cycle(x, y))
        {
            locked[x][y] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    //The winner / source of the graph is the candidate who has
    //all false in ther column, means no one is point to them

    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return;
}

