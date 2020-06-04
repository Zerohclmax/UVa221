#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100;

struct Building {
    int id;
    double x, y, d, w, h;

    bool operator<(const Building &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
} b[maxn];

int n;
double x[maxn * 2];

bool cover(int i, double ma) {
    return b[i].x <= ma && b[i].x + b[i].d >= ma;
}

bool is_visit(int i, double ma) {
    if (!cover(i, ma)) { return false; }
    for (int j = 0; j < n; j++) {
        if (b[j].x < b[i].x && b[j].x + b[j].d > b[i].x && b[j].h < b[i].h) {
            return true;
        }
    }
    return false;
}

int main() {
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
            //这里是个小技巧，在存入数据的同时将其首末位置都存入x数组中
            x[i * 2] = b[i].x;
            x[i * 2 + 1] = b[i].x + b[i].w;
            b[i].id = i + 1;
        }
    }
    sort(b,b+n);
    sort(x,x+n*2);
    

