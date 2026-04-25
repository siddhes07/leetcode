#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    for(int i = 0; i < flowerbed.size(); i++)
    {
        bool leftEmpty  = (i == 0 || flowerbed[i-1] == 0);
        bool rightEmpty = (i == flowerbed.size()-1 || flowerbed[i+1] == 0);

        if(flowerbed[i] == 0 && leftEmpty && rightEmpty)
        {
            flowerbed[i] = 1;
            n--;
        }
    }
    return n <= 0;
}

int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    if(canPlaceFlowers(flowerbed, n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}