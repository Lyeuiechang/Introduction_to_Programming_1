#include <stdio.h>
#include <string.h>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now
    if(init_dir == 'N')
    {
        dir_now = NORTH;
    }
    else if(init_dir == 'S')
    {
        dir_now = SOUTH;
    }
    else if(init_dir == 'E')
    {
        dir_now = EAST;
    }
    else if(init_dir == 'W')
    {
        dir_now = WEST;
    }
}

void take_a_step()
{
    if (dir_now == NORTH){
        /// Detect wall first
        if (map[center_x-2][center_y-1]=='#' || map[center_x-2][center_y]=='#' || map[center_x-2][center_y+1]=='#'){

        }
        /// And then detect hill
        else if (map[center_x-2][center_y-1]=='^' || map[center_x-2][center_y]=='^' || map[center_x-2][center_y+1]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_x = center_x -1;
        }
    }
    else if (dir_now == SOUTH){
        /// Detect wall first
        if (map[center_x+2][center_y-1]=='#' || map[center_x+2][center_y]=='#' || map[center_x+2][center_y+1]=='#'){

        }
        /// And then detect hill
        else if (map[center_x+2][center_y-1]=='^' || map[center_x+2][center_y]=='^' || map[center_x+2][center_y+1]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_x = center_x +1;
        }
    }
    else if (dir_now == EAST){
        /// Detect wall first
        if (map[center_x-1][center_y+2]=='#' || map[center_x][center_y+2]=='#' || map[center_x+1][center_y+2]=='#'){

        }
        /// And then detect hill
        else if (map[center_x-1][center_y+2]=='^' || map[center_x][center_y+2]=='^' || map[center_x+1][center_y+2]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_y = center_y +1;
        }
    }
    else if (dir_now == WEST){
        /// Detect wall first
        if (map[center_x-1][center_y-2]=='#' || map[center_x][center_y-2]=='#' || map[center_x+1][center_y-2]=='#'){

        }
        /// And then detect hill
        else if (map[center_x-1][center_y-2]=='^' || map[center_x][center_y-2]=='^' || map[center_x+1][center_y-2]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_y = center_y -1;
        }
    }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
            if(map[j][k] == '$')
            {
                coin_amount++;
                map[j][k] = '=';
            }
        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now
    if(dir_now == NORTH)
    {
        dir_now = EAST;
    }
    else if(dir_now = SOUTH)
    {
        dir_now = WEST;
    }
    else if(dir_now = EAST)
    {
        dir_now = SOUTH;
    }
    else if(dir_now = WEST)
    {
        dir_now = NORTH;
    }
}

void take_two_steps()
{
    if (dir_now == NORTH){
        /// Detect wall first
        if (map[center_x-2][center_y-1]=='#' || map[center_x-2][center_y]=='#' || map[center_x-2][center_y+1]=='#' || map[center_x-3][center_y-1]=='#' || map[center_x-3][center_y]=='#' || map[center_x-3][center_y+1]=='#'){

        }
        /// And then detect hill
        else if (map[center_x-2][center_y-1]=='^' || map[center_x-2][center_y]=='^' || map[center_x-2][center_y+1]=='^' || map[center_x-3][center_y-1]=='^' || map[center_x-3][center_y]=='^' || map[center_x-3][center_y+1]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_x = center_x -2;
        }
    }
    else if (dir_now == SOUTH){
        /// Detect wall first
        if (map[center_x+2][center_y-1]=='#' || map[center_x+2][center_y]=='#' || map[center_x+2][center_y+1]=='#' || map[center_x+3][center_y-1]=='#' || map[center_x+3][center_y]=='#' || map[center_x+3][center_y+1]=='#'){

        }
        /// And then detect hill
        else if (map[center_x+2][center_y-1]=='^' || map[center_x+2][center_y]=='^' || map[center_x+2][center_y+1]=='^' || map[center_x+3][center_y-1]=='^' || map[center_x+3][center_y]=='^' || map[center_x+3][center_y+1]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_x = center_x +2;
        }
    }
    else if (dir_now == EAST){
        /// Detect wall first
        if (map[center_x-1][center_y+2]=='#' || map[center_x][center_y+2]=='#' || map[center_x+1][center_y+2]=='#' || map[center_x-1][center_y+3]=='#' || map[center_x][center_y+3]=='#' || map[center_x+1][center_y+3]=='#'){

        }
        /// And then detect hill
        else if (map[center_x-1][center_y+2]=='^' || map[center_x][center_y+2]=='^' || map[center_x+1][center_y+2]=='^' || map[center_x-1][center_y+3]=='^' || map[center_x][center_y+3]=='^' || map[center_x+1][center_y+3]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_y = center_y +2;
        }
    }
    else if (dir_now == WEST){
        /// Detect wall first
        if (map[center_x-1][center_y-2]=='#' || map[center_x][center_y-2]=='#' || map[center_x+1][center_y-2]=='#' || map[center_x-1][center_y-3]=='#' || map[center_x][center_y-3]=='#' || map[center_x+1][center_y-3]=='#'){

        }
        /// And then detect hill
        else if (map[center_x-1][center_y-2]=='^' || map[center_x][center_y-2]=='^' || map[center_x+1][center_y-2]=='^' || map[center_x-1][center_y-3]=='^' || map[center_x][center_y-3]=='^' || map[center_x+1][center_y-3]=='^') {

        }
        /// If there is no obstacle, take a step
        else {
            center_y = center_y -2;
        }
    }
}

void turn_left()
{
    /// Change direction depending on dir_now
    if(dir_now == NORTH)
    {
        dir_now = WEST;
    }
    else if(dir_now = SOUTH)
    {
        dir_now = EAST;
    }
    else if(dir_now = EAST)
    {
        dir_now = NORTH;
    }
    else if(dir_now = WEST)
    {
        dir_now = SOUTH;
    }
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;

    /// Raed problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            take_a_step();
            pick_the_coins();
        }

        else if (actions[i] == 'J'){

           /* TODO : Implement the instruction "J" here */
            take_two_steps();
            pick_the_coins();

       }
        else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}
