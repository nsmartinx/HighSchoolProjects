#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device randomSeed;
    uniform_int_distribution<> distribution(1, 100);
    mt19937 engine(randomSeed());

    float countWin = 0, countLose = 0;

    for (size_t i = 0; i < 1000000; i++)
    {
        int winChance = 40;
        
        while (winChance > 0 && winChance < 100)
        {
            if (distribution(engine) <= winChance)
                winChance += 10;
            else
                winChance -= 10;
        }

        if (winChance == 0)
            countLose++;
        else
            countWin++;
    }

    float winChance = countWin / countLose * 100;

    cout << "Win Count = " << countWin << endl;
    cout << "Lost Count = " << countLose << endl;
    cout << "Win Chance = " << winChance << "%" << endl;

}
