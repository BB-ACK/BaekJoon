#include <iostream>
using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minX, minY;
    minX = (x < w - x) ? x : w - x;
    minY = (y < h - y) ? y : h - y;
    int min = (minX < minY) ? minX : minY;

    cout << min;
    
    return 0;
}