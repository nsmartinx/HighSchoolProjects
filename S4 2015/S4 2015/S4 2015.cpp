#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct route
{
    int destination;
    int time;
    int damage;
    route(int destination, int time, int damage) : destination(destination), time(time), damage(damage) {}
};

int main()
{
    //Below lines are to read in the text file
    //ifstream inputFile("s4.15.in");
    int K, N, M, A, B, a, b, t, h; //all of the variables that will be read in from the text file: K: hull strength, N: number of islands, M: number of routes, A: starting island, B: ending island, a: route start island, b: route end island, t: route, time, h: route damage
    string input, input2, input3, input4;
    getline(cin, input, ' ');
    K = stoi(input);
    getline(cin, input, ' ');
    N = stoi(input);
    getline(cin, input);
    M = stoi(input);
    vector<route>* routes = new vector<route>[N + 1];//array of vectors. Each vector in the array stores all of the routes from the corresponding island (graph of all routes)
    int** distances = new int* [N + 1];//two dimensional array of distances to each point. Stores the shortest distance to each point at every hull strength remaining
    for (size_t i = 0; i < N + 1; i++)
    {
        distances[i] = new int[K];
    }

    queue<int> vertices;//queue of all vertices (islands) of the graph that have to be checked
    bool* inQueue = new bool[N + 1];//stores all of the islands currently in vertices
    for (size_t i = 0; i < N + 1; i++)//sets all values of the array to be false (nothing is currently in the queue
    {
        inQueue[i] = false;
    }

    for (size_t i = 0; i < M; i++)//reads in the routes
    {
        getline(cin, input, ' ');
        a = stoi(input);
        getline(cin, input, ' ');
        b = stoi(input);
        getline(cin, input, ' ');
        t = stoi(input);
        getline(cin, input);
        h = stoi(input);
        routes[a].push_back(route(b, t, h));//adds them to the graph (the graph is one diretional but the routes go both ways so they are added to both the start and end points)
        routes[b].push_back(route(a, t, h));
    }


    getline(cin, input, ' ');
    A = stoi(input);
    getline(cin, input);
    B = stoi(input);
    //Above lines are to read in the text file

    for (size_t i = 0; i < N + 1; i++)//sets all distances to be -1 (acting as infinite distance away)
    {
        for (size_t x = 0; x < K + 1; x++)
        {
            distances[i][x] = -1;
        }
        
    }
    for (size_t i = 0; i < K + 1; i++)//sets the starting islands distance to be 0 (0 time to get there)
    {
        distances[A][i] = 0;
    }
    
    vertices.push(A);//adds the starting value to the array
    inQueue[A] = true;
    
    while (!vertices.empty()) //will run until the queue has no more points to check
    {
        int u = vertices.front();//gets the front value from the queue
        vertices.pop();
        inQueue[u] = false;


        for (size_t i = 0; i < routes[u].size(); i++)//all of the routes from that island
        {
            for (int x = 0; x < K + 1; x++)//all of the hull values remaining
            {
                int v = routes[u][i].destination;
                int time = routes[u][i].time;
                int damage = routes[u][i].damage;

                if (x - damage >= 1 && distances[u][x] >= 0)//if the ship will not be dead after taking the route and the ship could actually make it to the starting point with the amount of hull reamining
                {
                    if (distances[v][x - damage] > distances[u][x] + time || distances[v][x - damage] == -1)//if the new routes is faster than the previous fastest route, or a route has not been discovered to that point
                    {
                        distances[v][x - damage] = distances[u][x] + time;//new fastest time

                        if (!inQueue[v]) //if the point is not in the queue, add it to the queue
                        {
                            vertices.push(v);
                            inQueue[v] = true;
                        }
                    }
                }
            }
        }
    }
    cout << distances[B][1];//prints the shortest distance to island B with at least 1 hull strength remaining
}