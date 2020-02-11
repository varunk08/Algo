#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Rectangle {
  int x, y, width, height;
};

bool IsIntersect(const Rectangle& R1, const Rectangle& R2) {
  return R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
         R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y;
}

int main()
{
  Rectangle R1 = { 0, 0, 5, 5 };
  Rectangle R2 = { 2, 2, 6, 6 };

  Rectangle intersection = {};
  if (false == IsIntersect(R1, R2)) {
    intersection = {0, 0, -1, -1};
  } else {
    intersection = {
                    max(R1.x, R2.x),
                    max(R1.y, R2.y),
                    min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
                    min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y),
    };
  }

  cout << intersection.x << endl;
  cout << intersection.y << endl;
  cout << intersection.width << endl;
  cout << intersection.height << endl;
  
  return 0;
}
