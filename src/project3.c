#include <stdio.h>
#include <string.h>


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
    char* name;
    int points;
    int goals_out;
    int goals_in;
} teams;



void fill_games_array(FILE* file ,gamesPlayed *array, int games);
void print_games_array(gamesPlayed *array, int games);
void snyder(gamesPlayed *games_array, teams *teams_array);
void reset_team_array(teams *teams_array);
void print_teams_array(teams *array, int games);

int main(void) {
    gamesPlayed games_array[132];
    teams teams_array[12]={{"FCK",0,0,0}};

    FILE *games_played = fopen("kampe-2020-2021.txt", "r");
    if (games_played == NULL) {
        printf("no such file.");
    }

    fill_games_array(games_played,games_array, 132);
    //print_games_array(games_array, 132);

    reset_team_array(teams_array);
    print_teams_array(teams_array,12);
    snyder(games_array,teams_array);
    print_teams_array(teams_array,12);

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

void print_teams_array(teams *array, int games){
    for (int i = 0; i < games; ++i) {
        printf("%s %d %d %d\n", array[i].name, array[i].goals_in, array[i].goals_out, array[i].points);
    }

}

void reset_team_array(teams *teams_array){
    for (int i = 0; i < 12; ++i) {
        teams_array[i].goals_in = 0;
        teams_array[i].goals_out = 0;
        teams_array[i].points = 0;
    }
}

void snyder(gamesPlayed *games_array, teams *teams_array) {
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 132; ++j) {
            if (strcmp(games_array[j].team1, teams_array[i].name) == 0) {
                teams_array[i].goals_out += games_array[j].scoreteam1;
                teams_array[i].goals_in += games_array[j].scoreteam2;
            }

        }

    }
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 132; ++j) {
            if (strcmp(games_array[j].team2, teams_array[i].name) == 0) {
                teams_array[i].goals_out += games_array[j].scoreteam2;
                teams_array[i].goals_in += games_array[j].scoreteam1;
            }

        }
    }
}