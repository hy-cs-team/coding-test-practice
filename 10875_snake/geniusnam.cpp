#include <stdio.h>
#include <vector>
#include <utility>

#define HORIZONTAL 0
#define VERTICAL 1
// vertical > 0
#define NORTH 2
#define SOUTH 1
// horizontal < 0
#define WEST -1
#define EAST -2

using namespace std;

class Point {
    int x;
    int y;

public:
    Point (int x, int y): x(x) y(y) {}
    friend Point operator+ (Point& p1, Point& p2) const;
    int getX() const;
    int getY() const;
    void setPoint(int _x, int _y);
};

class Line {
    Point points[2];
    int length;
    int dir;

public:
    Line (Point p1, Point p2, int dir): p1(p1) p2(p2) dir(dir) length(length) {}
    int getDirection() const;
    Point[] getPoints() const;
    int getLength() const;

};

bool isLineOutOfBoard(Line l, int L);

bool areCross(Line l1, Line l2) const;

void solution(int L, int n);

vector<Line> lines;

int main(int argc, char const *argv[])
{
    /* code */
    int L, n;
    int dir;
    int look = EAST;
    scanf("%d %d", &L, &n);
    Point p1 = new Point(0, 0);

    for (int i = 0; i < n; i++) {
        dir = HORIZONTAL;
        char direction;
        int t;
        scanf("%d %c", &t, &direction);
        int x, y;
        if(dir == HORIZONTAL) {
            y = p1.getY();
            if (look == EAST) {
                x = p1.getX() + t;
                if (direction == 'L') look = NORTH;
                else look = SOUTH;
            } else {
                x = p1.getX() - t;
                if (direction == 'L') look = SOUTH;
                else look = NORTH;
            }
        } else {
            x = p1.getX();
            if (look == NORTH) {
                y = p1.getY() + t;
                if (direction == 'L') look = WEST;
                else look = EAST;
            } else {
                y = p1.getY() - t;
                if (direction == 'L') look = EAST;
                else look = WEST;
            }
        }
        
        Point p2 = new Point(x, y);
        dir = !dir;            
        Line l = p1 + p2;
        lines.push_back(l); // 모든 선을 vector 에 추가
    }
    // 겹치는 것을 확인하고, 겹치는 순간까지의 선분을 계산 후,
    printf("%d\n", solution(L, n));

    return 0;
}

int solution(int L, int n) {
    int time = 0;
    int idx_lineOut = 0;
    int look;
    for(int i = 0; i < n; i++) {
        if(isLineOutOfBoard(Line l, int L)) { 
            idx_lineOut = i;
            break;
        }
    }

    if(idx_lineOut == 0) return L;

    time += lines[0].getLength();
    int i, j;
    for (i = 1; i <= idx_lineOut; i++) {
        for (j = 0; i < j; j++) {
            bool isCross = areCross(lines[i], lines[j]);
            if(isCross) break;
        } 
        if(i == j) {
            time += lines[i].getLength();
        } else {
            if (lines[i].getDirection() == HORIZONTAL) { 
                if (lines[i-1].getPoints()[0].getY() == lines[i].getPoints()[0].getY()) {
                    look = EAST;
                } else if (lines[i-1].getPoints()[1].getY() == lines[i].getPoints()[0].getY()) {
                    look = EAST; 
                } else if (lines[i-1].getPoints()[0].getY() == lines[i].getPoints()[1].getY()) {
                    look = WEST;
                } else {
                    look = WEST;
                }
                if (look == EAST) {
                    time += lines[j].getPoints()[0].getX() - lines[i].getPoints()[0].getX();
                } else {
                    time += lines[i].getPoints()[1].getX() - lines[j].getPoints()[1].getX();
                }
            } else {
                if (lines[i-1].getPoints()[0].getX() == lines[i].getPoints()[0].getX()) {
                    look = NORTH;
                } else if (lines[i-1].getPoints()[1].getX() == lines[i].getPoints()[0].getX()) {
                    look = NORTH; 
                } else if (lines[i-1].getPoints()[0].getX() == lines[i].getPoints()[1].getX()) {
                    look = SOUTH;
                } else {
                    look = SOUTH;
                }
                if(look == NORTH) { 
                    time += lines[i].getPoints()[0].getY() - lines[j].getPoints()[0].getY();
                } else {
                    time += lines[i].getPoints()[0].getY() - lines[j].getPoints()[1].getY();
                }
            }
            break;
        }
    }
    return time;
}

bool isLineOutOfBoard(Line l, int L) {
    Point p1 = l.getPoints()[0];
    Point p2 = l.getPoints()[1];
    bool result = true;
    for(int i = 0; i < 2; i++) {
        Point p = l.getPoints()[i];
        result = result && (p.getX() <= L && p.getX() >= -L && p.getY() <= L && p.getY() >= -L);
    }
    return result;
}

bool areCross(Line l1, Line l2) const {
    Point l1_p1 = l1.getPoints()[0];
    Point l1_p2 = l1.getPoints()[1];
    Point l2_p1 = l2.getPoints()[0];
    Point l2_p2 = l2.getPoints()[1];
    if (l1.getDirection() == l2.getDirection()) {
        if (l1.getDirection() == VERTICAL && l1_p1.getX() == l2_p1.getX()) {
            if (l1_p1.getY() < l2_p1.getY()) 
                return (l1_p2.getY() >= l2_p1.getY());
            else 
                return (l1_p1.getY() <= l2_p2.getY());
        } else if (l1.getDirection() == VERTICAL && l1_p1.getX() != l2_p1.getX()){
            return false;
        } else if (l1.getDirection() == HORIZONTAL && l1_p1.getY() == l2_p1.getY()) {
            if (l1_p1.getX() < l2_p1.getX()) 
                return (l1_p2.getX() >= l2_p1.getX());
            else 
                return (l1_p1.getX() <= l2_p2.getX());
        } else {
            return false;
        }
    } else {
        int v_x;
        int h_y;
        if (l1.getDirection() == VERTICAL) {
            v_x = l1_p1.getX();
            h_y = l2_p2.getY();
            return v_x >= l2_p1.getX() && v_x <= l2_p2.getX() && h_y >= l1_p1.getY() && h_y <= l1_p2.getY();
        } else {
            v_x = l2_p1.getX();
            h_y = l1_p2.getY();
            return v_x >= l1_p1.getX() && v_x <= l1_p2.getX() && h_y >= l2_p1.getY() && h_y <= l2_p2.getY();
        }
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setPoint(int _x, int _y) {
    x = _x;
    y = _y;
}

Point operator+ (Point& p1, Point& p2) const {
    int dir = (p1.getX() == p2.getX()) ? VERTICAL : HORIZONTAL;
    if (dir == VERTICAL) {
        if (p1.getY() < p2.getY()) return Line(p1, p2, dir, p2.getY()-p1.getY());
        else return Line(p2, p1, dir, p1.getY()-p2.getY());
    } else {
        if (p1.getX() < p2.getX()) return Line(p1, p2, dir, p2.getX()-p1.getX());
        else return Line(p2, p1, dir, p1.getX()-p2.getX());
    }
}

int Line::getDirection() const {
    return dir;
}

Point[] Line::getP1() const {
    return points;
}

int Line::getLength() const {
    return length;
}