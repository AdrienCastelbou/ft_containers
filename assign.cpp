
#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "vector.hpp"

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
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

void vector_tests()
{
          time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            ft::vector<std::string> ft_v1(1e6, "string2");
            std::vector<std::string> v1(1e6, "string2");
            
			std::vector<std::string> v2(1e4, "string2");
            start = get_time();
            v2.assign(v1.begin(), v1.end());
            end = get_time();
            diff = end - start;
			std::cout << diff << std::endl;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            // ft::vector<std::string>    ft_v1(1e6, "string2");
            ft::vector<std::string> ft_v2(1e4, "string2");
            start = get_time();
            ft_v2.assign(ft_v1.begin(), ft_v1.end());
            end = get_time();
            diff = end - start;
			std::cout << diff << std::endl;
}
void alarm_handler(int seg)
{
    (void)seg;
    std::cout << "\033[1;33mTLE\033[0m\n";
    kill(getpid(), SIGINT);
}

int main(void)
{
    std::cout << RED << "________________________________________________________________________________________________________" << std::endl;
    std::cout << RED << "**** The test is taking so much time to test the all cases and the time complexity of each method ****" << std::endl;
    std::cout << RED << "--------------------------------------------------------------------------------------------------------" << RESET << std::endl;
    signal(SIGALRM, alarm_handler);
    vector_tests();
    return 0;
}
