#include <stdio.h>

typedef struct{
    char   weekday[10];
    char     date[6];
    double  time;
    char*   teams;
    char*   result;
    int     spectators;
}gamesPlayed;

typedef struct{
    char*   team;
    int     points;
    int     goals_out;
    int     goals_in;
}teams;

int main(void)
{
gamesPlayed games_array[132];
teams teams_array[12];
    FILE* ptr = fopen("kampe-2020-2021.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }

    /* Assuming that test.txt has content
       in below format
    NAME AGE CITY
    abc     12 hyderbad
    bef     25 delhi
    cce     65 bangalore */
    char buf[100];
    while (fscanf(ptr, "%s %s %lf %*s %*s %*s %*s %*s %*s %*s", games_array->weekday,games_array->date, &games_array->time, games_array->teams)== 3)
        printf("%s %s %lf\n",games_array->weekday,games_array->date,games_array->time);
    return 0;

}