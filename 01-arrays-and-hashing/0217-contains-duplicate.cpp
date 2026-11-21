#include <iostream>       /* first way */
#include <vector>         /* common */
#include <unordered_set>  /* first way */
#include <algorithm>      /* second way */

/**
 * nums = [1,2,3,1] true
 * nums = [1,2,3,4] false
 * nums = [1,1,1,3,3,4,3,2,4,2] true
 */

/* first way -> unordered_set */
class Solution {
public:
	bool contains_duplicate(std::vector<int> &nums)
	{
		std::unordered_set<int> seen_value;

		for (int num : nums) {
			if (seen_value.count(num) > 0)
				return true;

			seen_value.insert(num);
		}
		return false;
	}
};

/* second way -> sort and compare */
/*
class Solution {
public:
	bool contains_duplicate(std::vector<int> &nums)
	{
		std::sort(nums.begin(), nums.end());

		for (size_t i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1])
				return true;
		}
		return false;
	}
};
*/

int main(void)
{
	Solution solution;

	std::vector<int> example1 = {1, 2, 3, 1};		    /* true */
	std::vector<int> example2 = {1, 2, 3, 4};		    /* false */
	std::vector<int> example3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}; /* true */

	std::cout << std::boolalpha;
	std::cout << "Test 1: [1,2,3,1] -> "
		<< solution.contains_duplicate(example1) << '\n';
	std::cout << "Test 2: [1,2,3,4] -> "
		<< solution.contains_duplicate(example2) << '\n';
	std::cout << "Test 3: [1,1,1,3,3,4,3,2,4,2] -> "
		<< solution.contains_duplicate(example3) << '\n';

	return 0;
}
