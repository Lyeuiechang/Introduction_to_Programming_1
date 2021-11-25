#include<stdio.h>
typedef struct Monster{
    int hp;
    int attack;
}Monster;
Monster Monsters[26];
int map[6][6] = {0};
int win = 0;
void fight(int cur_x, int cur_y, int hp, int attack)
{
    int location = map[cur_x][cur_y];
    if(location != 0)
    {
		int monster_hp = Monsters[location].hp;
        monster_hp = monster_hp - attack;
        while(monster_hp > 0)
        {
            hp = hp - Monsters[location].attack;
            monster_hp = monster_hp - attack;
        }
    }
    if(hp > 0)
    {
        if(cur_x < 5)
        {
            fight(cur_x+1, cur_y, hp, attack);
        }
        if(cur_y < 5)
        {
            fight(cur_x, cur_y+1, hp, attack);
        }
        if(cur_x == 5 && cur_y == 5)
        {
            win = 1;
        }
    }
}
int main(void)
{
    int i, hp, attack, k, hp_m, attack_m, x, y;
    scanf("%d %d %d",&hp, &attack, &k);
    for(i=1;i<=k;i++)
    {
        scanf("%d %d %d %d",&hp_m, &attack_m, &x, &y);
        map[x][y] = i;
        Monsters[i].hp = hp_m;
        Monsters[i].attack = attack_m;
    }
    /*
    printf("Monsters Data:\n");
    for(i=1;i<=k;i++)
    {
        printf("%d %d\n",Monsters[i].hp, Monsters[i].attack);
    }
    */
    fight(1,1,hp,attack);
    if(win==0)
    {
        printf("YOU DIED\n");
    }
    else
    {
        printf("HEIR OF FIRE DESTROYED\n");
    }
    return 0;
}
