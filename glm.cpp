#define GLM_FORCE_INTRINSICS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_SIMD_AVX2

#include <array>
#include <type_traits>
#include <glm/glm.hpp>
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

float r () {
  return (rand() % 80000 - 40000) / 100.0;
}

#define Vector3 glm::vec4

float distanceSquared (Vector3 const &a, Vector3 const &b) {
  Vector3 temp = a - b;
  return glm::dot(temp, temp);
}

#define PARCEL_COUNT 35000

int main () {
  const int iterations = 1000;

  alignas(16) std::array<Vector3, PARCEL_COUNT> parcels;

  for (int i = 0; i < 35000; i++) {
    Vector3 v(r(), r(), r(), 0);
    parcels[i] = v;
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  Timer myTimer("Sort glm c++", iterations);

  for(int i=0; i < iterations; ++i) {
    Vector3 camera(r(), r(), r(), 0);

    std::sort(parcels.begin(), parcels.end(), [camera] (Vector3 const& a, Vector3 const& b) { 
      return distanceSquared(a, camera) < distanceSquared(b, camera); 
    });

    // std::cout << parcels[0].x << ", ";
  }

  std::cout << parcels[0].x << "\n";
}
