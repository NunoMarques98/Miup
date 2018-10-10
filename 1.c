#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int choose_pivot(int i,int j )
{
    return((i+j) /2);
}
 
void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        /* swap two elements */
        swap(&list[m],&list[j]);
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}

void updateVal(short u, short a[SIZE], short insert)
{

    a[insert] = u;
}

short * getMax(short a[SIZE], short insert, short res[3])
{
    int maxEnd = a[0];
    int maxFar = a[0];

    short init = 0;
    short last = 0;

    short x = 0;
    
    for(int i = 1; i < insert; i++)
    {
        x = a[i];

        if(x > maxEnd + x) {
            
            init = i;
            maxEnd = x;
            
        }

        else maxEnd += x;

        if( maxEnd > maxFar)
        {
            
            last = i;
            maxFar = maxEnd;
        } 
    }

    while(a[init] == 0 && init != last) init++;

    res[0] = init;
    res[1] = last;
    res[2] = maxFar;

    return res;
}

short getMedian(short *r, short a[SIZE], short insert)
{
    short init = r[0];
    short last = r[1];

    short len = last - init + 1;

    int sort[len];

    for(int i = 0; i < len; i++)
    {
        sort[i] = a[init + i];
    }

    quicksort(sort, 0, len);

    if(len % 2 != 0)
    {
        return sort[(len + 1)/2 - 1];
    }

    else
    {

        short first = sort[len / 2];
        short second = sort[(len + 2) / 2];

        return ((first + second) / 2);
    }
}

int main(int argc, char const *argv[])
{
    char input = ' ';
    short update = 0;

    short nums[SIZE];
    short insert = 0;

    short result[3];
    short med = 0;

    scanf(" %c", &input);

    while(input != 'x'){
    

        if(input == 'u')
        {
            scanf(" %hd", &update);

            updateVal(update, nums, insert);

            insert++;
        }
        
        else
        {
           getMax(nums, insert, result);

           med = getMedian(result, nums, insert);

           printf("%hd %hd %hd\n", result[0], result[1], med);
        }

        scanf(" %c", &input);
    }

    return 0;
}
