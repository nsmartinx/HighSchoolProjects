using System;

namespace Biology_Coin_Flip
{
    class Program
    {
        static void Main(string[] args)
        {
            var rand = new Random();
            float tailCount = 0, headCount = 0, flipCount = 0;
            int coin;
            for (int i = 0; i < 170; i++)
            {
                coin = rand.Next(2);
                if (coin == 0)
                {
                    tailCount++;
                }
                else
                {
                    headCount++;
                }
                flipCount++;
                /*
                Console.WriteLine("Coins Flipped: {0}", flipCount);
                Console.WriteLine("Tails: {0}", tailCount);
                Console.WriteLine("PercentTails: {0:p}\n", tailCount/flipCount);
                */
                Console.WriteLine("{0,8}{1,11}{2,15:p}", flipCount, tailCount, tailCount/flipCount);
            }
        }
    }
}
