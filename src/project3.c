#include <stdio.h>
#include <string.h>
#include <search.h>


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
    char *name;
    int points;
    int goals_out;
    int goals_in;
    int goal_dif;
} teams;


void fill_games_array(FILE *file, gamesPlayed *array, int games);

void print_games_array(gamesPlayed *array, int games);

void snyder(gamesPlayed *games_array, teams *teams_array);

void reset_team_array(teams *teams_array);

void print_teams_array(teams *array, int games);

int team_array_sort_logic(const void *a, const void *b);

void sort_team_array(teams *array);

int nedern_h(char *name);

int main(void) {
    gamesPlayed games_array[132];
    teams teams_array[12] = {{"FCK", 0, 0, 0, 0},
                             {"SDR", 0, 0, 0, 0},
                             {"ACH", 0, 0, 0, 0},
                             {"AaB", 0, 0, 0, 0},
                             {"LBK", 0, 0, 0, 0},
                             {"RFC", 0, 0, 0, 0},
                             {"BIF", 0, 0, 0, 0},
                             {"FCM", 0, 0, 0, 0},
                             {"AGF", 0, 0, 0, 0},
                             {"VB",  0, 0, 0, 0},
                             {"FCN", 0, 0, 0, 0},
                             {"OB",  0, 0, 0, 0},};

    FILE *games_played = fopen("kampe-2020-2021.txt", "r");
    if (games_played == NULL) {
        printf("no such file.");
    }

    fill_games_array(games_played, games_array, 132);
    //print_games_array(games_array, 132);

    reset_team_array(teams_array);
    print_teams_array(teams_array, 12);
    snyder(games_array, teams_array);
    print_teams_array(teams_array, 12);
    sort_team_array(teams_array);
    printf("___________________________________\n");
    print_teams_array(teams_array, 12);

    return 0;


}

void fill_games_array(FILE *file, gamesPlayed *array, int games) {
    for (int i = 0; i < games; ++i) {
        fscanf(file, "%s %s %lf %s %*s %s %d %*s %d %d",
               array[i].weekday, array[i].date, &array[i].time,
               array[i].team1, array[i].team2, &array[i].scoreteam1, &array[i].scoreteam2,
               &array[i].spectators);
    }
}

void print_games_array(gamesPlayed *array, int games) {
    for (int i = 0; i < games; ++i) {
        printf("%s %s %lf %s %s %d %d %d\n", array[i].weekday, array[i].date, array[i].time,
               array[i].team1, array[i].team2, array[i].scoreteam1, array[i].scoreteam2,
               array[i].spectators);
    }
}

void print_teams_array(teams *array, int games) {
    printf(" Team    Points   Score\n");
    for (int i = 0; i < games; ++i) {
        printf("| %3s %5d %8d - %d |\n", array[i].name, array[i].points, array[i].goals_out, array[i].goals_in);
    }

}

void reset_team_array(teams *teams_array) {
    for (int i = 0; i < 12; ++i) {
        teams_array[i].goals_in = 0;
        teams_array[i].goals_out = 0;
        teams_array[i].points = 0;
    }
}

void snyder(gamesPlayed *games_array, teams *teams_array) {
    for (int j = 0; j < 132; ++j) {

        teams_array[nedern_h(games_array[j].team1)].goals_out += games_array[j].scoreteam1;
        teams_array[nedern_h(games_array[j].team2)].goals_out += games_array[j].scoreteam2;

        teams_array[nedern_h(games_array[j].team1)].goals_in += games_array[j].scoreteam2;
        teams_array[nedern_h(games_array[j].team2)].goals_in += games_array[j].scoreteam1;

        if (games_array[j].scoreteam1 == games_array[j].scoreteam2) {
            teams_array[nedern_h(games_array[j].team1)].points += 1;
            teams_array[nedern_h(games_array[j].team2)].points += 1;
        }
        if (games_array[j].scoreteam1 > games_array[j].scoreteam2) {
            teams_array[nedern_h(games_array[j].team1)].points += 3;
        } else if (games_array[j].scoreteam1 < games_array[j].scoreteam2) {
            teams_array[nedern_h(games_array[j].team2)].points += 3;
        }
    }
    for (int i = 0; i < 12; ++i) {
        teams_array[i].goal_dif = teams_array[i].goals_out - teams_array[i].goals_in;
    }
}


void sort_team_array(teams *array) {
    qsort(array, 12, sizeof(teams), team_array_sort_logic);
}

int team_array_sort_logic(const void *a, const void *b) {
    teams *teamA = (teams *) a;
    teams *teamB = (teams *) b;

    if (teamA->points > teamB->points)
        return -1;
    if (teamB->points > teamA->points)
        return 1;
    if (teamA->points == teamB->points) {
        if (teamA->goal_dif > teamB->goal_dif)
            return -1;
        if (teamB->goal_dif > teamA->goal_dif)
            return 1;
    }
    return 0;
}

int nedern_h(char *name) {
    if (strcmp("FCK", name) == 0)
        return 0;
    else if (strcmp("OB", name) == 0)
        return 1;
    else if (strcmp("AaB", name) == 0)
        return 2;
    else if (strcmp("ACH", name) == 0)
        return 3;
    else if (strcmp("SDR", name) == 0)
        return 4;
    else if (strcmp("RFC", name) == 0)
        return 5;
    else if (strcmp("LBK", name) == 0)
        return 6;
    else if (strcmp("BIF", name) == 0)
        return 7;
    else if (strcmp("AGF", name) == 0)
        return 8;
    else if (strcmp("FCM", name) == 0)
        return 9;
    else if (strcmp("FCN", name) == 0)
        return 10;
    else if (strcmp("VB", name) == 0)
        return 11;
    else
        return -1;
}