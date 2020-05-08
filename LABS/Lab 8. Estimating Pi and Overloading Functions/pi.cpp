#include <cstdlib>
#include <cmath>

using std::sqrt;

double approx_pi(int seed, int n) {
    // seed the random number generator
    srand(seed);

    // TODO(student): implement the rest.
    // simulate the dart-throwing process
    // estimate the area of the quadrant
    // estimate the value of pi
    // return the estimated value of pi

    double x, y, r;
    double totalhit = 0;
    for (int i = 0; i < n; i++)
    {
        x = static_cast<double>(rand())/ RAND_MAX;
        y = static_cast<double>(rand())/ RAND_MAX;
        r = sqrt(x*x + y*y);
        if (r < 1)
        {
            totalhit += 1;
        }
    }
    double myguess = 4*(static_cast<double>(totalhit/n));
    return myguess;
}

