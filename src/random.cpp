#include "random.hpp"

#include <ctime>
#include <random>

namespace Random {   
    int intInRange(int min, int max) {
        std::mt19937 gen;
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        gen.seed((time_t)ts.tv_nsec);
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }

    float floatInRange(float min, float max) {
        std::mt19937 gen;
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        gen.seed((time_t)ts.tv_nsec);
        std::uniform_real_distribution<float> dist(min, max);
        return dist(gen);
    }
}
