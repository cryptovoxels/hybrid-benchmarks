#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>

struct Timer {
  std::clock_t tick;
  std::string mName;
  int mIterations;
 
  Timer( const std::string &name, int iterations) : mName( name ), mIterations(iterations) {
    tick = clock();
  }
 
  ~Timer() {
    clock_t end = clock();
    double elapsed_secs = double(end - tick) / CLOCKS_PER_SEC;
    std::cout << "Timer " << mName << ", elapsed time " << (elapsed_secs / mIterations * 1000.0) << "ms\n";
  }
};

class Vector3 {
  public:
    float x, y, z;

    Vector3 (float ix, float iy, float iz) {
      x = ix;
      y = iy;
      z = iz;
    }

    static float Distance(const Vector3& value1, const Vector3& value2);
    static float DistanceSquared(const Vector3& value1, const Vector3& value2);
};

float Vector3::Distance(const Vector3& value1, const Vector3& value2)
{
  return std::sqrt(Vector3::DistanceSquared(value1, value2));
}

float Vector3::DistanceSquared(const Vector3& value1, const Vector3& value2)
{
  const float x = value1.x - value2.x;
  const float y = value1.y - value2.y;
  const float z = value1.z - value2.z;

  return (x * x) + (y * y) + (z * z);
}

float r () {
  return (rand() % 80000 - 40000) / 100.0;
}

int main () {
  const int iterations = 1000;

  std::vector<Vector3> parcels;

  for (int i = 0; i < 35000; i++) {
    Vector3 v(r(), r(), r());
    parcels.push_back(v);
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  Timer myTimer("Sort idiomatic c++", iterations);

  for(int i=0; i < iterations; ++i) {
    Vector3 camera(r(), r(), r());

    std::sort(parcels.begin(), parcels.end(), [camera] (Vector3 const& a, Vector3 const& b) { 
      return Vector3::DistanceSquared(a, camera) < Vector3::DistanceSquared(b, camera); 
    });

    // std::cout << parcels[0].x << ", ";
  }

  std::cout << parcels[0].x << "\n";
}