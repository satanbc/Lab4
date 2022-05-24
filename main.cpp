#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int travellingSalesmanProblem(int graph[][4], int a)
{
    vector<int> distances;
    for (int i = 0; i < 4; i++)
    {
        if (i != a)
        {
            distances.push_back(i);
        }
    }

    int min_length = INT_MAX;
    do {

        int length = 0;

        int b = a;
        for (int distance : distances)
        {
            length += graph[b][distance];
            b = distance;
        }
        length += graph[b][a];

        min_length = min(min_length, length);

    } while (
            next_permutation(distances.begin(), distances.end()));

    return min_length;
}

int main()
{
    int graph[][4] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };

    cout << travellingSalesmanProblem(graph, 0);
}