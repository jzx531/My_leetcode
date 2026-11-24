#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    std::string balls;
    cin >> balls;

    std::vector<int> cost(n);
    for(int i = 0;i < n;i++)
    {
        cin >> cost[i];
    }

    for(int i = 0 ; i < n; i++)
    {
        printf("%c %d\n",balls[i],cost[i]);
    }

    


    return 0;
}