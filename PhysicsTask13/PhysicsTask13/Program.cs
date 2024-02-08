using System;

namespace PhysicsTask13
{
    class Program
    {
        static void Main()
        {
            Console.Write("What is the charge of the first point charge (in C)? ");
            double chargeA = double.Parse(Console.ReadLine());
            Console.Write("What is the charge of the second point charge (in C)? ");
            double chargeB = double.Parse(Console.ReadLine());
            Console.Write("What is the position of the first point charge (in m right of the 0 point)? ");
            double positionA = double.Parse(Console.ReadLine());
            Console.Write("What is the position of the second point charge (in m right of the 0 point)? ");
            double positionB = double.Parse(Console.ReadLine());
            Console.Write("At what point would you like to measure the electric field strength (in m right of the 0 point)? ");
            double positionC = double.Parse(Console.ReadLine());

            //calculates the distance between the points
            double distanceAC = positionC - positionA;
            if (distanceAC < 0)
                distanceAC *= -1;
            double distanceBC = positionC - positionB;
            if (distanceBC < 0)
                distanceBC *= -1;

            //calculates the electric field on the point from eeach of the two charges
            double electricFieldAC = ((9000000000 * chargeA) / (Math.Pow(positionC - positionA, 2)));
            double electricFieldBC = ((9000000000 * chargeB) / (Math.Pow(positionC - positionB, 2)));

            if (positionC < positionA)//converts the field to negative if it is in the lefward direction
                electricFieldAC *= -1;
            if (positionC < positionB)
                electricFieldBC *= -1;

            //adds the two values to get the toal electric field
            double electricField = electricFieldAC + electricFieldBC;

            double electricPotential = (9000000000 * chargeA) / (distanceAC) + (9000000000 * chargeB) / (distanceBC);//calculates the electric potential

            if (electricField >= 0)//if the electric field is to the right
                Console.WriteLine("The electric field strength is: {0:0.00}C [Right]", electricField);
            else//if the electric field is to the left
                Console.WriteLine("The electric field strength is: {0:0.00}C [Left]", electricField * -1);
            Console.WriteLine("The electric potential is: {0:0.00}C", electricPotential);//outputs the electric potential
        }
    }
}
