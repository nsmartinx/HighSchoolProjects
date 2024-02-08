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

bool Pair(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (i != o && hand[i].denomination == hand[o].denomination)
                return true;
        }
    }
    return false;
}

bool TwoPair(Card* hand)
{
    vector<int> pairs;
    bool taken = false;
    int pairCount = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (i != o && hand[i].denomination == hand[o].denomination)
            {
                taken = false;
                for (int num : pairs)
                {
                    if (hand[i].denomination == num)
                        taken = true;
                }
                if (!taken)
                {
                    pairCount++;
                    pairs.push_back(hand[i].denomination);
                }
            }
        }
    }
    if (pairCount >= 2)
        return true;
    else
        return false;
}
bool ThreePair(Card* hand)
{
    vector<int> pairs;
    bool taken = false;
    int pairCount = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (i != o && hand[i].denomination == hand[o].denomination)
            {
                taken = false;
                for (int num : pairs)
                {
                    if (hand[i].denomination == num)
                        taken = true;
                }
                if (!taken)
                {
                    pairCount++;
                    pairs.push_back(hand[i].denomination);
                }
            }
        }
    }
    if (pairCount >= 3)
        return true;
    else
        return false;
}
bool ThreeOfAKind(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                if (i != o && i != p && o != p && hand[i].denomination == hand[o].denomination && hand[i].denomination == hand[p].denomination)
                    return true;
            }
        }
    }
    return false;
}
bool TwoThreeOfAKind(Card* hand)
{
    vector<int> pairs;
    bool taken = false;
    int pairCount = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                if (i != o && i != p && o != p && hand[i].denomination == hand[o].denomination && hand[i].denomination == hand[p].denomination)
                {
                    taken = false;
                    for (int num : pairs)
                    {
                        if (hand[i].denomination == num)
                            taken = true;
                    }
                    if (!taken)
                    {
                        pairCount++;
                        pairs.push_back(hand[i].denomination);
                    }
                }
            }
            
        }
    }
    if (pairCount >= 2)
        return true;
    else
        return false;
}
bool FullHouse(Card* hand)
{
    vector<int> pairs;
    bool taken = false;
    bool pair = false;
    bool threeOfAKind = false;
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                if (i != o && i != p && o != p && hand[i].denomination == hand[o].denomination && hand[i].denomination == hand[p].denomination)
                {
                    taken = false;
                    for (int num : pairs)
                    {
                        if (hand[i].denomination == num)
                            taken = true;
                    }
                    if (!taken)
                    {
                        threeOfAKind = true;
                        pairs.push_back(hand[i].denomination);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (i != o && hand[i].denomination == hand[o].denomination)
            {
                taken = false;
                for (int num : pairs)
                {
                    if (hand[i].denomination == num)
                        taken = true;
                }
                if (!taken)
                {
                    pair = true;
                    pairs.push_back(hand[i].denomination);
                    break;
                }
            }
        }
    }
    if (pair && threeOfAKind)
        return true;
    else
        return false;
}
bool FourOfAKind(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    if (i != o && i != p && o != p && i != q && o != q && p != q && hand[i].denomination == hand[o].denomination && hand[i].denomination == hand[p].denomination && hand[i].denomination == hand[q].denomination)
                        return true;
                }
            }
        }
    }
    return false;
}
bool FourOfAKindPair(Card* hand)
{
    vector<int> pairs;
    bool taken = false;
    bool fourOfAKind = false;
    bool threeOfAKind = false;
    
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    if (i != o && i != p && o != p && i != q && o != q && p != q && hand[i].denomination == hand[o].denomination && hand[i].denomination == hand[p].denomination && hand[i].denomination == hand[q].denomination)
                    {
                        taken = false;
                        for (int num : pairs)
                        {
                            if (hand[i].denomination == num)
                                taken = true;
                        }
                        if (!taken)
                        {
                            fourOfAKind = true;
                            pairs.push_back(hand[i].denomination);
                            break;
                        }
                    }
                }
            }
            
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (i != o && hand[i].denomination == hand[o].denomination)
            {
                taken = false;
                for (int num : pairs)
                {
                    if (hand[i].denomination == num)
                        taken = true;
                }
                if (!taken)
                {
                    threeOfAKind = true;
                    pairs.push_back(hand[i].denomination);
                    break;
                }
            }
        }
    }
    if (fourOfAKind && threeOfAKind)
        return true;
    else
        return false;
}
bool Straight(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    for (int w = 0; w < 9; w++)
                    {
                        if ((hand[o].denomination == hand[i].denomination + 1 || (hand[i].denomination == 14 && hand[o].denomination == 2)) && hand[p].denomination == hand[o].denomination + 1 && hand[q].denomination == hand[p].denomination + 1 && hand[w].denomination == hand[q].denomination + 1)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}
bool SixStraight(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    for (int w = 0; w < 9; w++)
                    {
                        for (int e = 0; e < 9; e++)
                        {
                            if ((hand[o].denomination == hand[i].denomination + 1 || (hand[i].denomination == 14 && hand[o].denomination == 2)) && hand[p].denomination == hand[o].denomination + 1 && hand[q].denomination == hand[p].denomination + 1 && hand[w].denomination == hand[q].denomination + 1 && hand[e].denomination == hand[w].denomination + 1)
                            return true;
                        }
                        
                    }
                }
            }
        }
    }
    return false;
}

bool Flush(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    for (int w = 0; w < 9; w++)
                    {
                        if (i != o && i != p && i != q && i != w && o != p && o != q && o != w && p != q && p != w && q != w)
                            if (hand[i].suit == hand[o].suit && hand[i].suit == hand[p].suit && hand[i].suit == hand[q].suit && hand[w].suit == hand[o].suit)
                            {
                                return true;
                            }
                                
                    }
                }
            }
        }
    }
    return false;
}
bool SixFlush(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    for (int w = 0; w < 9; w++)
                    {
                        for (int e = 0; e < 9; e++)
                        {
                            if (i != o && i != p && i != q && i != w && o != p && o != q && o != w && p != q && p != w && q != w && i != e && o != e && p != e && q != e && w != e)
                                if (hand[i].suit == hand[o].suit && hand[i].suit == hand[p].suit && hand[i].suit == hand[q].suit && hand[w].suit == hand[o].suit && hand[i].suit == hand[e].suit)
                                {
                                    return true;
                                }
                        }
                        

                    }
                }
            }
        }
    }
    return false;
}

bool StraightFlush(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    for (int w = 0; w < 9; w++)
                    {
                        if ((hand[o].denomination == hand[i].denomination + 1 || (hand[i].denomination == 14 && hand[o].denomination == 2)) && hand[p].denomination == hand[o].denomination + 1 && hand[q].denomination == hand[p].denomination + 1 && hand[w].denomination == hand[q].denomination + 1)
                            if (hand[i].suit == hand[o].suit && hand[i].suit == hand[p].suit && hand[i].suit == hand[q].suit && hand[w].suit == hand[o].suit)
                                return true;
                    }
                }
            }
        }
    }
    return false;
}
bool SixStraightFlush(Card* hand)
{
    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    for (int w = 0; w < 9; w++)
                    {
                        for (int e = 0; e < 9; e++)
                        {
                            if ((hand[o].denomination == hand[i].denomination + 1 || (hand[i].denomination == 14 && hand[o].denomination == 2)) && hand[p].denomination == hand[o].denomination + 1 && hand[q].denomination == hand[p].denomination + 1 && hand[w].denomination == hand[q].denomination + 1 && hand[e].denomination == hand[w].denomination + 1)
                                if (hand[i].suit == hand[o].suit && hand[i].suit == hand[p].suit && hand[i].suit == hand[q].suit && hand[w].suit == hand[o].suit && hand[i].suit == hand[e].suit)
                                {
                                    return true;
                                }
                        }

                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    float generate = 1000000;
    float pair = 0, twoPair = 0, threeOfAKind = 0, straight = 0, flush = 0, fullHouse = 0, fourOfAKind = 0, straightFlush = 0;
    float threePair = 0, twoThreeOfAKind = 0, fourOfAKindPair = 0, sixStraight = 0, sixFlush = 0, sixStraightFlush = 0;

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
    vector<int> drawn;
    bool taken = false;
    int draw;

    for (size_t i = 0; i < generate; i++)
    {
        
        if (i % 100 == 0)
            cout << i << endl;
        for (size_t i = 0; i < 9; i++)
        {
            do
            {
                taken = false;
                draw = drawCard(rng);
                for (int num : drawn)
                {
                    if (draw == num)
                    {
                        taken = true;
                        break;
                    }
                }
            } while (taken);
            drawn.push_back(draw);

            hand[i] = Card(deck[draw].denomination, deck[draw].suit);
        }

        drawn.clear();
        

        if (Pair(hand))
            pair++;
        if (TwoPair(hand))
            twoPair++;
        if (ThreeOfAKind(hand))
            threeOfAKind++;
        if (Straight(hand))
            straight++;
        if (Flush(hand))
            flush++;
        if (FullHouse(hand))
            fullHouse++;
        if (FourOfAKind(hand))
            fourOfAKind++;
        if (StraightFlush(hand))
            straightFlush++;
        if (ThreePair(hand))
            threePair++;
        if (TwoThreeOfAKind(hand))
            twoThreeOfAKind++;
        if (FourOfAKindPair(hand))
            fourOfAKindPair++;
        if (SixStraight(hand))
            sixStraight++;
        if (SixFlush(hand))
            sixFlush++;
        if (SixStraightFlush(hand))
            sixStraightFlush++;
    }
    
    cout << "Pair: " << pair << " :" << pair * 100 / generate << "%" << endl;
    cout << "Two Pair: " << twoPair << " :" << twoPair * 100 / generate << "%" << endl;
    cout << "Three Of A Kind: " << threeOfAKind << " :" << threeOfAKind * 100 / generate << "%" << endl;
    cout << "Straight: " << straight << " :" << straight * 100 / generate << "%" << endl;
    cout << "Flush: " << flush << " :" << flush * 100 / generate << "%" << endl;
    cout << "Full House: " << fullHouse << " :" << fullHouse * 100 / generate << "%" << endl;
    cout << "Four Of A Kind: " << fourOfAKind << " :" << fourOfAKind * 100 / generate << "%" << endl;
    cout << "Straight Flush: " << straightFlush << " :" << straightFlush * 100 / generate << "%" << endl;
    cout << "Three Pair: " << threePair << " :" << threePair * 100 / generate << "%" << endl;
    cout << "Two Three Of A Kind: " << twoThreeOfAKind << " :" << twoThreeOfAKind * 100 / generate << "%" << endl;
    cout << "Four Of A Kind Pair: " << fourOfAKindPair << " :" << fourOfAKindPair * 100 / generate << "%" << endl;
    cout << "Six Straight: " << sixStraight << " :" << sixStraight * 100 / generate << "%" << endl;
    cout << "Six Flush: " << sixFlush << " :" << sixFlush * 100 / generate << "%" << endl;
    cout << "Six Straight Flush: " << sixStraightFlush << " :" << sixStraightFlush * 100 / generate << "%" << endl;
}
