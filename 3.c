#include <stdio.h>

short getMaximum(short parties, float q[parties], int votes[parties])
{
    int max = q[0];
    short index = 0;
    
    for(int i = 1; i < parties; i++)
    {
        if(q[i] > max)
        {
            max = q[i];
            index = i;
        }

        else if (q[i] == max)
        {
            if(votes[i] > votes[max]) index = i;
        }
        
    }
    
    return index;
}

void getSeats(short parties, int votes[parties], float q[parties], short seats[parties], short seat)
{
    short max = getMaximum(parties, q, votes);

    for(int i = seat; i > 0; i--)
    {
        seats[max] += 1;
        q[max] = q[max] / (seats[max] + 1);

        max = getMaximum(parties, q, votes);
    }
}

int main(int argc, char const *argv[])
{
    
    short seat = 0;

    scanf("%hd", &seat);

    short parties = 0;

    scanf("%hd", &parties);

    int votes[parties];
    float q[parties];
    short seats[parties];

    
    for(int i = 0; i < parties; i++)
    {
        seats[i] = 0;
    }
    

    int vote = 0;
    
    for(int i = 0; i < parties; i++)
    {
        scanf("%d", &vote);

        votes[i] = vote;
        q[i] = vote;
    }

    getSeats(parties, votes, q, seats, seat);
    
    for(int i = 0; i < parties; i++)
    {
        printf("%hd\n", seats[i]);
    }
    

    return 0;
}
