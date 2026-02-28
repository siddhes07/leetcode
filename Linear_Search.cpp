#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10,20,30,40};
    int target = 30;
    for (int i=0;i<v.size();i++)
        if (v[i]==target) {
            cout << "Found at " << i;
            return 0;
        }
    cout << "Not Found";
}