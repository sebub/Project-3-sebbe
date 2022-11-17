#include <stdio.h>
#include <string.h>
#include <search.h>
#include <stdlib.h>

#define numberofgames 132
#define numberofteams 12


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

/***
 *Transfers data about football games from txt file to an array.
 * @param file Takes file with game data
 * @param array Array of type gamesPlayed to be filled with the data from the file
 * @param games Number of games contained in the passed file
 */
void fill_games_array(FILE *file, gamesPlayed *array, int games);

/***
 * Assigns each index a team name and sets the values of goals_out, goals_in, goal_dif and points to 0.
 * @param teams_array Array of struct teams
 * @param team_names Array of team names
 */
void reset_team_array(teams *teams_array, char **team_names);

/***
 * Transfers from games_array to teams_array using a hash function and calculates points and score difference
 * @param games_array Array filled with data about games
 * @param teams_array Array with teams, points and score
 */
void fill_teams_array(gamesPlayed *games_array, teams *teams_array);

/***
 * Prints an array of struct teams
 * @param array Array of struct teams
 * @param teams Number of teams in the array
 */
void print_teams_array(teams *array, int teams);

void sort_team_array(teams *array);

/***
 * Logic for sorting team_array, sorts by points, then by score difference
 * @param a
 * @param b
 * @return
 */
int team_array_sort_logic(const void *a, const void *b);

/***
 * enables us to call an index in out team_array by a name in stead of index number
 * @param name
 * @return
 */
int team_name_hash(char *name);

int main(void) {
    char *team_names[numberofteams] = {"FCK", "SDR", "ACH", "AaB", "LBK", "RFC",
                                       "BIF", "FCM", "AGF", "VB", "FCN", "OB"};
    gamesPlayed games_array[numberofgames];
    teams teams_array[numberofteams];

    FILE *games_played_data = fopen("kampe-2020-2021.txt", "r");
    if (games_played_data == NULL) {//If file does not exist exit program
        printf("no such file.");
        exit(0);
    }

    fill_games_array(games_played_data, games_array, numberofgames);

    reset_team_array(teams_array, team_names);
    print_teams_array(teams_array, numberofteams);

    printf("___________________________________\n");
    fill_teams_array(games_array, teams_array);
    print_teams_array(teams_array, numberofteams);

    sort_team_array(teams_array);
    printf("___________________________________\n");
    print_teams_array(teams_array, numberofteams);

    return 0;


}

void fill_games_array(FILE *file, gamesPlayed *array, int games) {
    for (int i = 0; i < games; ++i) {
        fscanf(file, "%s %s %lf %s %*s %s %d %*s %d %d",
               array[i].weekday, array[i].date, &array[i].time,
               array[i].team1, array[i].team2, &array[i].scoreteam1, &array[i].scoreteam2,
               &array[i].spectators);
    }
    fclose(file);
}

void print_teams_array(teams *array, int teams) {
    printf(" Team    Points   Score\n");
    for (int i = 0; i < teams; ++i) {
        printf("| %3s %5d %8d - %d |\n", array[i].name, array[i].points, array[i].goals_out, array[i].goals_in);
    }

}

void reset_team_array(teams *teams_array, char **team_names) {
    for (int i = 0; i < 12; ++i) {
        teams_array[i].name = team_names[i];
        teams_array[i].goals_in = 0;
        teams_array[i].goals_out = 0;
        teams_array[i].points = 0;
    }
}

void fill_teams_array(gamesPlayed *games_array, teams *teams_array) {
    for (int j = 0; j < 132; ++j) {

        teams_array[team_name_hash(games_array[j].team1)].goals_out += games_array[j].scoreteam1;
        teams_array[team_name_hash(games_array[j].team2)].goals_out += games_array[j].scoreteam2;

        teams_array[team_name_hash(games_array[j].team1)].goals_in += games_array[j].scoreteam2;
        teams_array[team_name_hash(games_array[j].team2)].goals_in += games_array[j].scoreteam1;

        if (games_array[j].scoreteam1 == games_array[j].scoreteam2) {
            teams_array[team_name_hash(games_array[j].team1)].points += 1;
            teams_array[team_name_hash(games_array[j].team2)].points += 1;
        }
        if (games_array[j].scoreteam1 > games_array[j].scoreteam2) {
            teams_array[team_name_hash(games_array[j].team1)].points += 3;
        } else if (games_array[j].scoreteam1 < games_array[j].scoreteam2) {
            teams_array[team_name_hash(games_array[j].team2)].points += 3;
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

int team_name_hash(char *name) {
    char *team_names[numberofteams] = {"FCK", "SDR", "ACH", "AaB", "LBK", "RFC",
                                       "BIF", "FCM", "AGF", "VB", "FCN", "OB"};
    for (int i = 0; i < numberofteams; ++i) {
        if (strcmp(name, team_names[i]) == 0)
            return i;
    }
    return -1;
}