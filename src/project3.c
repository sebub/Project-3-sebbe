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

void fill_games_array(FILE* file ,gamesPlayed *array, int games);
void print_games_array(gamesPlayed *array, int games);

int main(void) {
    gamesPlayed games_array[132];
    teams teams_array[12];

    FILE *games_played = fopen("kampe-2020-2021.txt", "r");
    if (games_played == NULL) {
        printf("no such file.");
    }

    fill_games_array(games_played,games_array, 132);
    print_games_array(games_array, 132);


    return 0;



}

void fill_games_array(FILE* file ,gamesPlayed *array, int games){
    for (int i = 0; i < games; ++i) {
        fscanf(file, "%s %s %lf %s %*s %s %d %*s %d %d",
               array[i].weekday, array[i].date, &array[i].time,
               array[i].team1, array[i].team2, &array[i].scoreteam1, &array[i].scoreteam2,
               &array[i].spectators);
    }
}

void print_games_array(gamesPlayed *array, int games){
    for (int i = 0; i < games; ++i) {
        printf("%s %s %lf %s %s %d %d %d\n", array[i].weekday, array[i].date, array[i].time,
               array[i].team1, array[i].team2, array[i].scoreteam1, array[i].scoreteam2,
               array[i].spectators);
    }
}