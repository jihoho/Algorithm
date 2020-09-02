#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
struct node {
    int x;
    int y;
};

node check[41];

node recursive(int n) {
    if (check[n].x != 0 && check[n].y != 0)
        return check[n];
    if (n == 0) {
        check[n].x = 1;
        check[n].y = 0;
        return check[n];
    }
    else if (n == 1) {
        check[n].x = 0;
        check[n].y = 1;
        return check[n];
    }
    else {
        check[n].x = recursive(n - 1).x + recursive(n - 2).x;
        check[n].y = recursive(n - 1).y + recursive(n - 2).y;
        return check[n];
    }
}


int main() {
    int t;
    int *d;
    cin >> t;
    d = new int[t];
    for (int i = 0; i < t; i++) {
        cin >> d[i];
    }

    memset(check, 0, sizeof(check));
    node ch;
    for (int i = 0; i < t; i++) {

        ch = recursive(d[i]);
        printf("%d %d\n", ch.x, ch.y);
    }

    return 0;
}