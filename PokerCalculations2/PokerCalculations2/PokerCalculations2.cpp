#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

struct Card
{
    Card() {};
    Card(int denomination, int suit) : denomination{ denomination }, suit{ suit } {}
    int denomination; //(2-14)
    int suit; //(0-3)
};

bool Pair(int* hand)
{
    for (size_t i = 0; i < 8; i++)
    {
        if (hand[i] == hand[i + 1])
            return true;
    }
    return false;
}

bool TwoPair(int* hand)
{
    bool pairFound = false;
    int pair = 0;
    for (size_t i = 0; i < 8; i++)
    {
        if (hand[i] == hand[i + 1] && hand[i] != pair)
        {
            pair = hand[i];
            if (pairFound)
                return true;
            pairFound = true;
        }
    }
    return false;
}
bool ThreePair(int* hand)
{
    bool pairFound = false, twoPairFound = false;
    int pair = 0, pair2 = 0;
    for (size_t i = 0; i < 8; i++)
    {
        if (hand[i] == hand[i + 1] && hand[i] != pair)
        {
            pair = hand[i];
            if (twoPairFound)
                return true;
            if (pairFound)
                twoPairFound = true;
            pairFound = true;
        }
    }
    return false;
}
bool ThreeOfAKind(int* hand)
{
    for (size_t i = 0; i < 7; i++)
    {
        if (hand[i] == hand[i + 1] && hand[i] == hand[i + 2])
            return true;
    }
    return false;
}
bool TwoThreeOfAKind(int* hand)
{
    bool pairFound = false;
    int pair = 0;
    for (size_t i = 0; i < 7; i++)
    {
        if (hand[i] == hand[i + 1] && hand[i] == hand[i + 2] && hand[i] != pair)
        {
            pair = hand[i];
            if (pairFound)
                return true;
            pairFound = true;
        }
    }
    return false;
}
bool FullHouse(int* hand)
{
    int three = 0;
    for (size_t i = 0; i < 7; i++)
    {
        if (hand[i] == hand[i + 1] && hand[i] == hand[i + 2])
        {
            three = hand[i];
        }
    }
    if (three != 0)
    {
        for (size_t i = 0; i < 8; i++)
        {
            if (hand[i] == hand[i + 1] && hand[i] != three)
                return true;
        }
    }
    return false;
}
bool FourOfAKind(int* hand)
{
    for (size_t i = 0; i < 6; i++)
    {
        if (hand[i] == hand[i + 1] && hand[i] == hand[i + 2] && hand[i] == hand[i + 3])
            return true;
    }
    return false;
}
bool FourOfAKindPair(int* hand)
{
    int three = 0;
    for (size_t i = 0; i < 6; i++)
    {
        if (hand[i] == hand[i + 1] && hand[i] == hand[i + 2] && hand[i] == hand[i + 3])
        {
            three = hand[i];
        }
    }
    if (three != 0)
    {
        for (size_t i = 0; i < 8; i++)
        {
            if (hand[i] == hand[i + 1] && hand[i] != three)
                return true;
        }
    }
    return false;
}
bool Straight(int* hand)
{
    int count = 0;
    int* hand2 = new int[9];
    int store;
    for (size_t i = 0; i < 9; i++)
    {
        bool inVector = false;
        for (size_t p = 0; p < 9; p++)
        {
            if (hand[i] == hand2[p])
                inVector = true;
        }

        if (!inVector)
        {
            hand2[count++] = hand[i];
            store = hand[i];
        }
    }
    for (size_t i = count; i < 9; i++)
    {
        hand2[i] = store;
    }
    if (9 >= 5)
    {
        for (size_t i = 0; i < 9 - 4; i++)
        {
            if (hand2[i] == hand2[i + 1] - 1 && hand2[i] == hand2[i + 2] - 2 && hand2[i] == hand2[i + 3] - 3 && hand2[i] == hand2[i + 4] - 4)
                return true;
        }
        if (hand2[9 - 1] == 14)
        {
            if (hand2[0] == 2 && hand2[0] == hand2[0 + 1] - 1 && hand2[0] == hand2[0 + 2] - 2 && hand2[0] == hand2[0 + 3] - 3)
                return true;
        }
    }

    return false;
    
}
bool SixStraight(int* hand)
{
    int count = 0;
    int* hand2 = new int[9];
    int store;
    for (size_t i = 0; i < 9; i++)
    {
        bool inVector = false;
        for (size_t p = 0; p < 9; p++)
        {
            if (hand[i] == hand2[p])
                inVector = true;
        }

        if (!inVector)
        {
            hand2[count++] = hand[i];
            store = hand[i];
        }
    }
    for (size_t i = count; i < 9; i++)
    {
        hand2[i] = store;
    }
    if (9 >= 5)
    {
        for (size_t i = 0; i < 9 - 5; i++)
        {
            if (hand2[i] == hand2[i + 1] - 1 && hand2[i] == hand2[i + 2] - 2 && hand2[i] == hand2[i + 3] - 3 && hand2[i] == hand2[i + 4] - 4 && hand2[i] == hand2[i + 5] - 5)
                return true;
        }
        if (hand2[9 - 1] == 14)
        {
            if (hand2[0] == 2 && hand2[0] == hand2[0 + 1] - 1 && hand2[0] == hand2[0 + 2] - 2 && hand2[0] == hand2[0 + 3] - 3 && hand2[0] == hand2[0 + 3])
                return true;
        }
    }

    return false;
}

bool Flush(Card* hand)
{
    int suit0 = 0, suit1 = 0, suit2 = 0, suit3 = 0;
    for (size_t i = 0; i < 9; i++)
    {
        if (hand[i].suit == 0)
            suit0++;
        if (hand[i].suit == 1)
            suit1++;
        if (hand[i].suit == 2)
            suit2++;
        if (hand[i].suit == 3)
            suit3++;
    }
    if (suit0 >= 5 || suit1 >= 5 || suit2 >= 5 || suit3 >= 5)
        return true;
    return false;
}
bool SixFlush(Card* hand)
{
    int suit0 = 0, suit1 = 0, suit2 = 0, suit3 = 0;
    for (size_t i = 0; i < 9; i++)
    {
        if (hand[i].suit == 0)
            suit0++;
        if (hand[i].suit == 1)
            suit1++;
        if (hand[i].suit == 2)
            suit2++;
        if (hand[i].suit == 3)
            suit3++;
    }
    if (suit0 >= 6 || suit1 >= 6 || suit2 >= 6 || suit3 >= 6)
        return true;
    return false;
}

bool StraightFlush(Card* hand)
{
    int suit = 5;
    int suitnum;
    int suit0 = 0, suit1 = 0, suit2 = 0, suit3 = 0;
    for (size_t i = 0; i < 9; i++)
    {
        if (hand[i].suit == 0)
            suit0++;
        if (hand[i].suit == 1)
            suit1++;
        if (hand[i].suit == 2)
            suit2++;
        if (hand[i].suit == 3)
            suit3++;
    }
    if (suit0 >= 5)
    {
        suit = 0;
        suitnum = suit0;
    }
    else if (suit1 >= 5)
    {
        suit = 1;
        suitnum = suit1;
    }
    else if (suit2 >= 5)
    {
        suit = 2;
        suitnum = suit2;
    }
    else if (suit3 >= 5)
    {
        suit = 3;
        suitnum = suit3;
    }
    else
        return false;
    int count = 0;
    int* hand1 = new int[suitnum];
    for (size_t i = 0; i < 9; i++)
    {
        if (hand[i].suit == suit)
            hand1[count++] = hand[i].denomination;
    }
    
    int* numbers = new int[suitnum];
    count = 0;
    for (size_t i = 0; i < suitnum; i++)
    {
        numbers[count++] = hand1[i];
    }
    sort(numbers, numbers + suitnum);
    count = 0;
    int* hand2 = new int[suitnum];
    int store;
    for (size_t i = 0; i < suitnum; i++)
    {
        bool inVector = false;
        for (size_t p = 0; p < suitnum; p++)
        {
            if (numbers[i] == hand2[p])
                inVector = true;
        }

        if (!inVector)
        {
            hand2[count++] = numbers[i];
            store = numbers[i];
        }
    }
    for (size_t i = count; i < suitnum; i++)
    {
        hand2[i] = store;
    }
    if (suitnum >= 5)
    {
        for (size_t i = 0; i < suitnum - 4; i++)
        {
            if (hand2[i] == hand2[i + 1] - 1 && hand2[i] == hand2[i + 2] - 2 && hand2[i] == hand2[i + 3] - 3 && hand2[i] == hand2[i + 4] - 4)
                return true;
        }
        if (hand2[suitnum - 1] == 14)
        {
            if (hand2[0] == 2 && hand2[0] == hand2[0 + 1] - 1 && hand2[0] == hand2[0 + 2] - 2 && hand2[0] == hand2[0 + 3] - 3)
                return true;
        }
    }

    return false;
}
bool SixStraightFlush(Card* hand)
{
    int suit = 5;
    int suitnum;
    int suit0 = 0, suit1 = 0, suit2 = 0, suit3 = 0;
    for (size_t i = 0; i < 9; i++)
    {
        if (hand[i].suit == 0)
            suit0++;
        if (hand[i].suit == 1)
            suit1++;
        if (hand[i].suit == 2)
            suit2++;
        if (hand[i].suit == 3)
            suit3++;
    }
    if (suit0 >= 6)
    {
        suit = 0;
        suitnum = suit0;
    }
    else if (suit1 >= 6)
    {
        suit = 1;
        suitnum = suit1;
    }
    else if (suit2 >= 6)
    {
        suit = 2;
        suitnum = suit2;
    }
    else if (suit3 >= 6)
    {
        suit = 3;
        suitnum = suit3;
    }
    else
        return false;
    int count = 0;
    int* hand1 = new int[suitnum];
    for (size_t i = 0; i < 9; i++)
    {
        if (hand[i].suit == suit)
            hand1[count++] = hand[i].denomination;
    }

    int* numbers = new int[suitnum];
    count = 0;
    for (size_t i = 0; i < suitnum; i++)
    {
        numbers[count++] = hand1[i];
    }
    sort(numbers, numbers + suitnum);
    count = 0;
    int* hand2 = new int[suitnum];
    int store;
    for (size_t i = 0; i < suitnum; i++)
    {
        bool inVector = false;
        for (size_t p = 0; p < suitnum; p++)
        {
            if (numbers[i] == hand2[p])
                inVector = true;
        }

        if (!inVector)
        {
            hand2[count++] = numbers[i];
            store = numbers[i];
        }
    }
    for (size_t i = count; i < suitnum; i++)
    {
        hand2[i] = store;
    }
    if (suitnum >= 6)
    {
        for (size_t i = 0; i < suitnum - 5; i++)
        {
            if (hand2[i] == hand2[i + 1] - 1 && hand2[i] == hand2[i + 2] - 2 && hand2[i] == hand2[i + 3] - 3 && hand2[i] == hand2[i + 4] - 4 && hand2[i] == hand2[i + 5] - 5)
                return true;
        }
        if (hand2[suitnum - 1] == 14)
        {
            if (hand2[0] == 2 && hand2[0] == hand2[0 + 1] - 1 && hand2[0] == hand2[0 + 2] - 2 && hand2[0] == hand2[0 + 3] - 3 && hand2[0] == hand2[0 + 4] - 4)
                return true;
        }
    }

    return false;
}

int main()
{
    int generate = 1000000000;
    int pair = 0, twoPair = 0, threeOfAKind = 0, straight = 0, flush = 0, fullHouse = 0, fourOfAKind = 0, straightFlush = 0;
    int threePair = 0, twoThreeOfAKind = 0, fourOfAKindPair = 0, sixStraight = 0, sixFlush = 0, sixStraightFlush = 0;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> drawCard(0, 51);

    Card deck[52];

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t o = 2; o < 15; o++)
        {
            deck[i * 13 + o - 2] = Card(o, i);
        }
    }

    Card hand[9];
    int drawn[9];
    bool taken = false;
    int draw;
    int count = 0;

    
    for (size_t i = 0; i < generate; i++)
    {
        count = 0;
        for (size_t i = 0; i < 9; i++)
        {
            drawn[i] = 100;
        }

        ///*
        if (i % 100000 == 0)
            cout << i << endl;
        for (size_t i = 0; i < 9; i++)
        {
            do
            {
                taken = false;
                draw = drawCard(rng);
                for (size_t i = 0; i < 9; i++)
                {
                    if (draw == drawn[i])
                    {
                        taken = true;
                        break;
                    }
                }
            } while (taken);
            drawn[count++] = draw;

            hand[i] = Card(deck[draw].denomination, deck[draw].suit);
        }

        
        //*/
        /*
        hand[0] = Card(2, 0);
        hand[1] = Card(3, 0);
        hand[2] = Card(4, 0);
        hand[3] = Card(5, 0);
        hand[4] = Card(6, 0);
        hand[5] = Card(7, 1);
        hand[6] = Card(8, 1);
        hand[7] = Card(9, 1);
        hand[8] = Card(10, 1);
        */
        int numbers[9];
        for (size_t i = 0; i < 9; i++)
        {
            numbers[i] = hand[i].denomination;
        }
        sort(begin(numbers), end(numbers));



        if (Pair(numbers))
            pair++;
        if (TwoPair(numbers))
            twoPair++;
        if (ThreeOfAKind(numbers))
            threeOfAKind++;
        if (Straight(numbers))
            straight++;
        if (Flush(hand))
            flush++;
        if (FullHouse(numbers))
            fullHouse++;
        if (FourOfAKind(numbers))
            fourOfAKind++;
        if (StraightFlush(hand))
            straightFlush++;
        if (ThreePair(numbers))
            threePair++;
        if (TwoThreeOfAKind(numbers))
            twoThreeOfAKind++;
        if (FourOfAKindPair(numbers))
            fourOfAKindPair++;
        if (SixStraight(numbers))
            sixStraight++;
        if (SixFlush(hand))
            sixFlush++;
        if (SixStraightFlush(hand))
            sixStraightFlush++;
    }

    cout << "Pair: " << pair << " :" << (float)pair * 100 / (float)generate << "%" << endl;
    cout << "Two Pair: " << twoPair << " :" << (float)twoPair * 100 / (float)generate << "%" << endl;
    cout << "Three Of A Kind: " << threeOfAKind << " :" << (float)threeOfAKind * 100 / (float)generate << "%" << endl;
    cout << "Straight: " << straight << " :" << (float)straight * 100 / (float)generate << "%" << endl;
    cout << "Flush: " << flush << " :" << (float)flush * 100 / (float)generate << "%" << endl;
    cout << "Full House: " << fullHouse << " :" << (float)fullHouse * 100 / (float)generate << "%" << endl;
    cout << "Four Of A Kind: " << fourOfAKind << " :" << (float)fourOfAKind * 100 / (float)generate << "%" << endl;
    cout << "Straight Flush: " << straightFlush << " :" << (float)straightFlush * 100 / (float)generate << "%" << endl;
    cout << "Three Pair: " << threePair << " :" << (float)threePair * 100 / (float)generate << "%" << endl;
    cout << "Two Three Of A Kind: " << twoThreeOfAKind << " :" << (float)twoThreeOfAKind * 100 / (float)generate << "%" << endl;
    cout << "Four Of A Kind Pair: " << fourOfAKindPair << " :" << (float)fourOfAKindPair * 100 / (float)generate << "%" << endl;
    cout << "Six Straight: " << sixStraight << " :" << (float)sixStraight * 100 / (float)generate << "%" << endl;
    cout << "Six Flush: " << sixFlush << " :" << (float)sixFlush * 100 / (float)generate << "%" << endl;
    cout << "Six Straight Flush: " << sixStraightFlush << " :" << (float)sixStraightFlush * 100 / (float)generate << "%" << endl;

}
