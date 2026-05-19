#include "vect2.hpp"
#include <iostream>
# include <cassert>

int main()
{
    vect2 v1; // 0, 0
    assert(v1.x == 0 && v1.y == 0);
    vect2 v2(1, 2); // 1, 2
    assert(v2.x == 1 && v2.y == 2);
    const vect2 v3(v2); // 1, 2
    assert(v2.x == 1 && v2.y == 2);

    vect2 v4 = v2; // 1, 2
    assert(v2.x == 1 && v2.y == 2);


    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << v4++ << std::endl; // 2, 3
    assert(v4.x == 2 && v4.y == 3);

    std::cout << ++v4 << std::endl; // 3, 4
    assert(v4.x == 3 && v4.y == 4);

    std::cout << v4-- << std::endl; // 2, 3
        assert(v4.x == 2 && v4.y == 3);

    std::cout << --v4 << std::endl; // 1, 2
        assert(v4.x == 1 && v4.y == 2);

    v2 += v3; // 2, 4
    assert(v4.x == 1 && v4.y == 2);

    v1 -= v2; // -2, -4
    v2 = v3 + v3 *2; // 3, 6
    v2 = 3 * v2; // 9, 18
    v2 += v2 += v3; // 20, 40
    v1 *= 42; // -84, -168
    v1 = v1 - v1 +v1;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
}