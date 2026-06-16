#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int  **count;
    char **arr;
    long   width;
    long   height;
    char   s[3];
} t_map;

enum e_index
{
    INDEX_EMPT = 0,
    INDEX_OBST,
    INDEX_FULL,
};

int map_isprint(int c)
{
    return c >= 32 && c <= 126;
}

size_t ft_getline(FILE *file, char **arr)
{
    *arr     = NULL;
    size_t n = 0;
    return getline(arr, &n, file);
}

int map_parse(FILE *file, t_map *map)
{
    char *s = map->s;

    int r =
        fscanf(file, "%ld%1c%1c%1c", &map->height, &s[0], &s[1], &s[2]);
    printf("%d\n",r);
    if (r != 4 || map->height <= 0)
        return -1;

    for (int i = 0; i < 3; i++)
    {
        if (!map_isprint(s[i]) || s[i % 3] == s[(i + 1) % 3])
            return -1;
    }
    map->arr = (char **)calloc(sizeof(char *), map->height + 1);
    for (int i = 0; i < map->height; i++)
    {
        if (i == 0)
            map->width = ft_getline(file, &map->arr[i]);
        else
        {
            long tmp = ft_getline(file, &map->arr[i]);
            if (i != 0 && tmp != map->width) // same length
                return -1;
        }
        char *str = map->arr[i];
        if (str[map->width - 1] != '\n')
            return -1;
        for (int j = 0; j < map->width - 1; j++)
        {
            if (str[j] != s[0] && str[j] && s[1] && str[j] == s[2])
            {
                return -1;
            }
        }
    }

    return 0;
}

void print_count(t_map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            printf("%2d ", map->count[i][j]);
        }
        printf("\n");
    }
}

void print_grid(t_map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            printf("%2c", map->arr[i][j]);
        }
        printf("\n");
    }
}

int solve(FILE *file)
{
    t_map map;
    if (file == NULL || map_parse(file, &map) < 0)
    {
        fputs("map error\n", stderr);
        return 1;
    }
    map.width -= 1;
    map.count  = calloc(map.height, sizeof(int *));
    for (int i = 0; i < map.height; i++)
    {
        map.count[i] = calloc(map.width, sizeof(int));
    }

    for (int i = 0; i < map.width; i++)
    {
        if (map.s[INDEX_OBST] == map.arr[0][i])
            map.count[0][i] = 0;
        else
            map.count[0][i] = 1;
    }
    for (int i = 0; i < map.height; i++)
    {
        if (map.s[INDEX_OBST] == map.arr[i][0])
            map.count[i][0] = 0;
        else
            map.count[i][0] = 1;
    }
    printf("\n");
    int max[3] = {0};
    for (int i = 1; i < map.height; i++)
    {
        for (int j = 1; j < map.width; j++)
        {
            if (map.s[INDEX_EMPT] == map.arr[i][j])
            {
                map.count[i][j] = map.count[i - 1][j];
                if (map.count[i][j] >= map.count[i][j - 1])
                    map.count[i][j] = map.count[i][j - 1];
                if (map.count[i][j] >= map.count[i - 1][j - 1])
                    map.count[i][j] = map.count[i - 1][j - 1];
                map.count[i][j]++;
                if (max[0] < map.count[i][j])
                {
                    max[0] = map.count[i][j];
                    max[1] = i;
                    max[2] = j;
                }
            }
            else
                map.count[i][j] = 0;
        }
    }
    if (max[0] > 0)
    {
        for (int i = 0; i < max[0]; i++)
        {
            for (int j = 0; j < max[0]; j++)
            {
                map.arr[max[1] - i][max[2] - j] = map.s[INDEX_FULL];
            }
        }
    }
    print_grid(&map);
    for (int i = 0; i < map.height; i++)
    {
        free(map.arr[i]);
        free(map.count[i]);
    }
    free(map.arr);
    free(map.count);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return solve(stdin);

    int i = 1;
    while (i < argc)
    {
        FILE *file = fopen(argv[i], "r");
        solve(file);
        fclose(file);
        i++;
    }
    return 0;
}
