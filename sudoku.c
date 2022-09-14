#include <stdio.h>

int main()
{
    int s_arr[9][9] = {{7,9,6,4,1,5,8,2,3},
                      {2,4,3,8,6,9,5,7,1},
                      {8,1,5,2,7,3,9,4,6},
                      {5,8,9,3,2,7,1,6,4},
                      {6,2,1,5,8,4,3,9,7},
                      {3,7,4,6,9,1,2,5,8},
                      {9,3,7,1,4,2,6,8,5},
                      {4,5,8,9,3,6,7,1,2},
                      {1,6,2,7,5,8,4,3,9}};


    int i, j, ct = 0;
    int base_i = 0;
    int base_j = 0;
    //rows
    for(i = 0 ; i < 9; i++)
    {
        for(j = 0 ; j < 9; j++)
            ct += s_arr[i][j];

        if (ct != 45  )
        {
                printf(" 1 NOT OK ! arr[%d] [%d]", i, j);
                return 1;
        }else
           ct=0;
    }
    //colums
    for(i = 0 ; i < 9; i++)
    {
        for(j = 0 ; j<9;j++)
            ct += s_arr[i][j];
        if (ct != 45  )
        {
                printf(" 2 NOT OK !");
                return 1;
        }else
             ct=0;
    }
    //sqares
    for(int tt = 0; tt < 9; tt++)
    {
            for(i = 0; i<3;i++)
            {
                for(j = 0; j<3 ;j++)
                {
                    ct += s_arr[base_i+i][base_j+j];
                    printf("%d ", s_arr[base_i+i][base_j+j]);
                }
                printf("\n");
            }
            if (ct != 45  )
            {
                printf(" 1 NOT OK ! arr[%d] [%d]", base_i+i, base_j+j);
                return 1;
            }
            ct=0;
            if(base_i == 6)
            {
                base_i = 0;
                base_j += 3;
            }
            else
                base_i += 3;
             putchar('\n');
    }
    printf(" OK ! \n");

}
