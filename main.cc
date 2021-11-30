#include <iostream>
#include <vector>
using namespace std;

class point {
 private:
  double x, y;

 public:
  point(double x, double y) : x(x), y(y){};
  friend ostream &operator<<(ostream &out, const point &p);
};

ostream &operator<<(ostream &out, const point &p) {
  out << p.x << ", " << p.y << endl;
  return out;
}

int main(int argc, char **argv) {
  //  point a(1, 2);
  vector<double> a(10, 2);
  double sum;
  for (double i : a) i += 1;
  for (double i : a) sum += i;

  cout << sum;
  return 0;
}