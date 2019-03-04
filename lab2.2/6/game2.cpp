#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

enum {WHITE, GRAY, BLACK};
enum {FIRST, SECOND};

vector<int> color;
vector<int> winning_pos;
vector< vector<int> > graph;

void dfs(int v)
{
    for (int u : graph[v])
    {
        if (color[u] == WHITE)
        {
            dfs(u);
        }
    }

    winning_pos[v] = SECOND;

    for (int u : graph[v])
    {
        if (winning_pos[u] == SECOND)
        {
            winning_pos[v] = FIRST;
            break;
        }
    }

    color[v] = BLACK;
}

int main()
{
    ifstream file_in("game.in");
    ofstream file_out("game.out");

    unsigned int n_vertices = 0, n_edges = 0, start = 0;
    file_in >> n_vertices >> n_edges >> start;

    start--;

    graph.resize(n_vertices);
    color.resize(n_vertices, WHITE);
    winning_pos.resize(n_vertices);

    for (int foo = 0; foo < n_edges; ++foo)
    {
        unsigned int from = 0, to = 0;
        file_in >> from >> to;

        graph[from - 1].push_back(to - 1);
    }

    dfs(start);

    file_out << (winning_pos[start] == FIRST ? "First player wins" : "Second player wins");

    return 0;
}
