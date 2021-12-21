
#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "vector.hpp"
#include "map.hpp"
#include <map>
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 3 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

void map_tests()
{         time_t start, end, diff;
            int res, ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            res = m.lower_bound(1e5)->first;
            end = get_time();
            diff = end - start;
			std::cout << end << " - " << start << " = " << diff << std::endl;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            start = get_time();
            ft_res = ft_m.lower_bound(1e5)->first;
            end = get_time();

            diff = end - start;
			std::cout << end << " - " << start << " = " << diff << std::endl;
			std::cout << res << ", " << ft_res << std::endl;
}

int main(void)
{
    std::cout << RED << "________________________________________________________________________________________________________" << std::endl;
    std::cout << RED << "**** The test is taking so much time to test the all cases and the time complexity of each method ****" << std::endl;
    std::cout << RED << "--------------------------------------------------------------------------------------------------------" << RESET << std::endl;
    map_tests();
    return 0;
}
