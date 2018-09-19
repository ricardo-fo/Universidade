#include <stdio.h>
#include <math.h>

void calc_esfera(float r, float * area, float * volume);

int main()
{
    float raio, main_area, main_volume;

    scanf("%f", &raio);
    calc_esfera(raio, &main_area, &main_volume);
    printf("raio: %f\narea: %f\nvolume: %f\n", raio, main_area, main_volume);

    return 0;
}

void calc_esfera(float r, float * area, float * volume)
{
    *area = 4 * M_PI * r * r;
    *volume = (4/3.0) * M_PI * r * r * r;
}
