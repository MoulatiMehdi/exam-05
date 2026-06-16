# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct 
{
    int x;
    int y;
    bool on;
} t_pen;

typedef struct 
{
    char **grid;
    int ** adj;
    int w;
    int h;
    int i;
    t_pen pen;
} t_map;

void print(t_map * map)
{
    for(int i = 0; i < map->h; i ++ )
    {
        for(int j = 0; j < map->w; j ++)
        {
            putchar(map->grid[i][j]);
        }
        putchar('\n');
    }
}

bool isvalid(t_map * map,int x,int y)
{
    return map->w > x && map->h > y && x >= 0 & y >= 0;
}

void move(t_map *map,int dx,int dy)
{
    map->pen.x += dx;
    map->pen.y += dy;
    if(isvalid(map,map->pen.x,map->pen.y) && map->pen.on)
        map->grid[map->pen.y][map->pen.x] = 'O';
}

void init(t_map* map,int argc,char ** argv)
{    
    map->pen = (t_pen){0,0,false};
    map->w = atoi(argv[1]);
    map->h = atoi(argv[2]);
    map->i = atoi(argv[3]);
    
    map->grid = malloc(map->h * sizeof(char *));
    map->adj = malloc(map->h * sizeof(int *));
    for(int i = 0; i < map->h; i ++)
    {
        map->grid[i] = malloc(map->w * sizeof(char));
        map->adj[i] = malloc(map->w * sizeof(int *));

        for(int j = 0; j < map->w; j++)
        {
            map->grid[i][j] = '.';
            map->adj[i][j] = 0;
        }
    }
}
void fill(t_map * map)
{
    long bytes = 0;
    char c;
    while(true)
    {
        bytes = read(0,&c,1);
        if(bytes <= 0)
            break;
        switch(c)
        {
            case 'w':
               move(map,0,-1);
                break;
            case 's' : 
                move(map,0,1);
                break;
            case 'a' : 
                move(map,-1,0);
                break;
            case 'd' :
                move(map,1,0);
                break;
            case 'x' :
                map->pen.on = !map->pen.on;  
                move(map,0,0);
        }
    }
}

int adj(t_map * map,int x,int y)
{
    int count = 0;
    for(int i = -1; i < 2; i ++)
    {
        for(int j = -1; j < 2 ; j++)
        {
            if(i == 0 && j == 0)
                continue;
            if(isvalid(map,x + j,y + i) && map->grid[i + y][j + x] == 'O')
                count ++;
        }
    }
    return count;
}


void apply(t_map * map)
{
    for(int i = 0; i < map->h; i++)
    {
        for(int j = 0; j < map->w; j++)
        {
            map->adj[i][j] = adj(map,j,i); 
        }
    }
    for(int i = 0; i < map->h; i++)
    {
        for(int j = 0; j < map->w; j++)
        {
            if(map->grid[i][j] == 'O')
            {
                if(map->adj[i][j] < 2 || map->adj[i][j] > 3)
                    map->grid[i][j] = '.';

            }
            else if(map->adj[i][j] == 3)
                map->grid[i][j] = 'O'; 
        }
    }
}



int main(int argc,char ** argv)
{
    if(argc!= 4)
        return 1;
    t_map map;

    init(&map,argc,argv);
    fill(&map);
    print(&map);
    putchar('\n');
    for(int i = 0; i < map.i; i ++)
    {
        apply(&map);
    }
    print(&map);

}