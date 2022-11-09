#include <stdio.h>

typedef struct {
    char weekday[10];
    char date[6];
    double time;
    char *teams;
    char *result;
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

    while (fscanf(ptr, "%s %s %lf %*s %*s %*s %*s %*s %*s %*s", games_array->weekday, games_array->date,
                  &games_array->time) == 3)
        printf("%s %s %lf\n", games_array->weekday, games_array->date, games_array->time);
    return 0;

}