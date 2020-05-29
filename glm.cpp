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

float distanceSquared (glm::vec3 const &a, glm::vec3 const &b) {
  glm::vec3 temp = a - b;
  return glm::dot(temp, temp);
}

int main () {
  const int iterations = 1000;

  std::vector<glm::vec3> parcels;

  for (int i = 0; i < 3500; i++) {
    glm::vec3 v(r(), r(), r());
    parcels.push_back(v);
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  Timer myTimer("Sort glm c++", iterations);

  for(int i=0; i < iterations; ++i) {
    glm::vec3 camera(r(), r(), r());

    std::sort(parcels.begin(), parcels.end(), [camera] (glm::vec3 const& a, glm::vec3 const& b) { 
      return distanceSquared(a, camera) < distanceSquared(b, camera); 
    });

    std::cout << parcels[0].x << ", ";
  }

  std::cout << parcels[0].x << "\n";
}
