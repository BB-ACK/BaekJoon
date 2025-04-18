#include <iostream>
#include <stack>
using namespace std;

void findDecimal(int start, int end) {
    int first = -1;
    int sum = 0;
    
    for(int i = start; i <= end; i++) {
        if(i == 2) {
            first = i;
            sum += i;
            continue;
        }
        for (int j = 2; j < i; j++) {
            
            if(i % j == 0)
                break;

            if(j == i - 1) {
                sum += i;
                if(first == -1)
                    first = i;
            }
        }

    }

    if(sum != 0)
        cout << sum << endl;
    cout << first << endl;
}

int main()
{
    int start, end;
    cin >> start >> end;

    findDecimal(start, end);

    return 0;
}