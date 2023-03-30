#include "laps.h"
/**
 * race_state - a function that keeps track of the number of laps.
 * @id: an array of int representing the “identifier” of each car.
 * @size: the size of the array
 * Return: 0
*/

void race_state(int *id, size_t size)
{
    int p, q, aux, temp;
    size_t i, j, x, y = 0;
    static int car_nb[50], lap_nb[100], nb = 0;

    if (size == 0)
        return;
    for (i = 0; i < size; i++)
    {
        for (j = 0; id[i] != car_nb[j] && car_nb[j] != 0; j++)
        {
            
        }
            if (car_nb[j] != id[i])
            {
                printf("Car %d joined the race\n", id[i]);
                car_nb[j] = id[i];
                nb += 1;
            }
            else
            {
                lap_nb[j] += 1;
            }
    }
    for (p = 0; p < nb; p++)
    {
        q = p + 1;
        while (q < nb)
        {
            if (car_nb[p] > car_nb[q])
            {
                aux = car_nb[p];
                car_nb[p] = car_nb[q];
                car_nb[q] = aux;
                temp = lap_nb[p];
                lap_nb[p] = lap_nb[q];
                lap_nb[q] = temp;
            }
            q++;
        }
    }
    y = nb;
    printf("Race state:\n");
    for (x = 0; x < y; x++)
    {
        printf("Car %d [%d laps]\n", car_nb[x], lap_nb[x]);
    }
}