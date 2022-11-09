#include <stdio.h>

typedef struct {
    char weekday[10];
    char date[6];
    double time;
    char team1[5];
    char team2[5];
    int scoreteam1;
    int scoreteam2;
    int spectators;
} gamesPlayed;

typedef struct {
    char *team;
    int points;
    int goals_out;
    int goals_in;
} teams;


int main(void) {
    gamesPlayed games_array[132];
    teams teams_array[12];

    FILE *ptr = fopen("kampe-2020-2021.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }

    while (fscanf(ptr, "%s %s %lf %s %*s %s %d %*s %d %d",
                  games_array->weekday, games_array->date, &games_array->time, games_array->team1, games_array->team2,
                  &games_array->scoreteam1, &games_array->scoreteam2, &games_array->spectators) == 8)
        printf("%s %s %lf %s %s %d %d %d\n", games_array->weekday, games_array->date, games_array->time,
               games_array->team1, games_array->team2, games_array->scoreteam1, games_array->scoreteam2,
               games_array->spectators);
    return 0;



}