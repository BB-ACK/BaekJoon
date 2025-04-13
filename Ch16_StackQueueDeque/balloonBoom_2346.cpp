#include <iostream>
#include <vector>
using namespace std;

struct balloon
{
    int number;
    int paper;
};

void boom(vector<balloon> arr)
{
    int idx = 0;

    while (!arr.empty())
    {
        while(idx < 0)
            idx += arr.size();
        idx %= arr.size();
        
        int tmp = arr[idx].paper;
        if(arr.size() == 1)
            cout << arr[idx].number;
        else 
            cout << arr[idx].number << " ";


        arr.erase(arr.begin() + idx);

        if(tmp > 0)
            tmp--;
        idx += tmp;
    }
}

int main()
{
    int num;
    cin >> num;
    vector<balloon> arr;

    for (int i = 1; i <= num; i++)
    {
        int paper;
        cin >> paper;
        arr.push_back({i, paper});
    }

    boom(arr);

    return 0;
}