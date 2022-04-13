const double EPS=1e-9 ;

template<class T>
struct point {
    T x, y;
    point() {}
    point(T x, T y): x(x), y(y) {}

    T CrossProduct(point<int> b) {
        return x * b.y - y * b.x;
    }
    T DotProduct(point<int> b) {
        return x * b.x + y * b.y;
    }
};

long double PolygonArea(vector<point<int>> &p) {
    long double area = p[0].CrossProduct(p.back());;
    for(int i = 1; i < (int)p.size(); i++) {
        area += p[i].CrossProduct(p[i - 1]);
    }
    return fabs(area / 2.00);
}

