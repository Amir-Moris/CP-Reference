const long double PI = acos(-1);
const double EPS = 1e-9;
// Don`t forget to change the DataType !!
struct point {
    DataType x, y;
    point() {}
    point(DataType x, DataType y): x(x), y(y) {}
    point operator -(const point & other)const {
        return point(x - other.x, y - other.y);
    }
    point operator +(const point & other)const {
        return point(x + other.x, y + other.y);
    }
    point operator *(DataType c) const {
        return point(x * c, y * c);
    }
    point operator /(DataType c) const {
        return point(x / c, y / c);
    }
    point prep() {
        return point(-y, x);
    }
};
double dot(point p1, point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double cross(point p1, point p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double abs(point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}
double dist(point p1, point p2) {
    return sqrt((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}
// angle between [0 , pi]
double angle(point P1, point P2) {
    return acos(dot(P1, P2) / (abs(P1) * abs(P2)));
}
