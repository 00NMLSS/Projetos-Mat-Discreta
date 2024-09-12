#include <stdio.h>

int main (void)
{
    int starting_population, target_population, years, population_increase, population_decrease; 
    do
    {
        printf("Insert starting population: ");
        scanf("\n%d",&starting_population);

        printf("Insert target population: ");
        scanf("\n%d",&target_population);

    } while (starting_population < 0 || target_population < 0 );

    for (years = 0 ; starting_population <= target_population; years++)
    {
        population_increase = (starting_population/3);
        population_decrease = (starting_population/4);
        starting_population += (population_increase - population_decrease);
    }
    
    printf("It took %d years to reach %d llamas\n", years, target_population);

}   
