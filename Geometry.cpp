const long double EPS = 1e-9;
const long double PI = acos(-1);

struct point {
    int x, y;

    point() {}

    point(int x, int y) : x(x), y(y) {}

    int CrossProduct(point &b) {
        return x * b.y - y * b.x;
    }

    int DotProduct(point &b) {
        return x * b.x + y * b.y;
    }
};

long double PolygonArea(vector<point> &p) {
    long double area = p[0].CrossProduct(p.back());;
    for (int i = 1; i < (int) p.size(); i++) {
        area += p[i].CrossProduct(p[i - 1]);
    }
    return fabs(area / 2.0);
}

bool collinear(point &p1, point &p2, point &p3) {
    ll a = p1.x * 1LL * (p2.y - p3.y) + p2.x * 1LL * (p3.y - p1.y) + p3.x * 1LL * (p1.y - p2.y);
    return a == 0;
}
