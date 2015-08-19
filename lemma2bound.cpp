#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

std::vector<int>	values;
int					len;
/*
 *			 0
 *		  1     2 
 *		3   4 5   6
 *     7 8 9 
 *	0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
 *  1 2 3 4 5 6 7
 *  2 3 4 5 6 7 8*/
  bool test_chemin(int i) {
 		if (i >= len)
 			return true;
		else
 		{
			return (values[i] <= values[0] && (test_chemin(i * 2 + 1) || test_chemin(i * 2 + 2)));	
 		}
  }
 


int main(int ac, char **av) {
	int n, i;
	int	sum = 0;
	
	if (ac == 2)
	{
		n = std::atoi(av[1]);
		len = std::pow(2, n) - 1;
		for (i = 0; i < len; i++)
			values.push_back(i);
		sum += (test_chemin(0) ? 1 : 0);
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		auto gen = std::default_random_engine(seed);
		for(i = 0; i < 1000000; i++) {
			std::shuffle(values.begin(), values.end(), gen);
			sum += (test_chemin(0) ? 1 : 0);
		}
		std::cout << "On a binary tree of depth " << n << ", there is " << sum
			<< " possible ways for 10^7 random permutations." << std::endl;
	}
}
