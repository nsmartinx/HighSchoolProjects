using System;

namespace Coin_Flip_Simulation
{
    class Program
    {
        

        static void Main()
        {
            int timesAchievedHeads = 0;
            int timesToSimulate = 6000;
            for (int i = 0; i <= timesToSimulate; i++)
            {
                int headCount = 20;
                int heads = 0;
                int coinFlips = 100;

                bool achievedHeads = false;

                string flipS;

                Random rand = new Random();
                for (int n = 0; n <= coinFlips; n++)
                {
                    int flip = rand.Next(0, 2);
                    if (flip == 0)
                        flipS = "H";
                    else
                        flipS = "T";
                    Console.Write(" " + flipS);

                    if (flip == 0)
                    {
                        heads++;
                        if (heads >= headCount)
                            achievedHeads = true;
                    }
                    else
                        heads = 0;
                    
                }
                Console.WriteLine("\n" + achievedHeads);

                if (achievedHeads)
                    timesAchievedHeads++;
                Console.WriteLine(i);
            }
            Console.WriteLine("\n\nSuccessful: {0}\nTimes Simulated: {1}", timesAchievedHeads, timesToSimulate);
        }
    }
}
