#include "prime.h"

int next_prime(int num)
{
	num += 1;
	while(!is_prime(num++));
	return num;
}

bool is_prime(int num)
{
	if(num == 2)
		return true;
	if(num == 3)
		return true;
	if((num % 2) == 0)
		return false;
	if((num % 3) == 0)
		return false;

	int i(5), w(2);

	while((i * i) <= num)
	{
		if((num % i) == 0)
			return false;

		i += w;
		w = (6 - w);
	}

	return true;
}
