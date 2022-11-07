#include <stdio.h>

typedef struct{
    char*   weekday;
    int     date;
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


}