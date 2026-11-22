#include <iostream>
#include <string>
#include <cstddef>

/**
 * Example 1
 * s = "anagram" -> a: 3 b: 0 c: 0 g: 1 m: 1 n: 1 r: 1
 * t = "nagaram" -> a: 3 B. 0 c: 0 g: 1 m: 1 n: 1 r: 1
 * return true
 *
 * Example 2
 * s = "rat" -> a: 1 b: 0 c: 0 r: 1 t: 1
 * t = "car" -> a: 1 b: 0 c: 1 r: 1 t: 0
 */

class Solution {
public:
	bool is_anagram(std::string s, std::string t)
	{
		if (s.size() != t.size())
			return false;

		int frequency[26] = {0};

		for (size_t i = 0; i < s.size(); ++i) {
			frequency[s[i] - 'a']++;
			frequency[t[i] - 'a']--;
		}

		for (size_t i = 0; i < 26; ++i) {
			if (frequency[i] != 0)
				return false;
		}
		return true;
	}
};

int main(void)
{
	Solution solution;

	std::string s1 = "anagram";
	std::string t1 = "nagaram";
	std::string s2 = "rat";
	std::string t2 = "car";

	std::cout << std::boolalpha;
	std::cout << s1 << " and " << t1 << ": "
		<< solution.is_anagram(s1, t1) << "\n";
	std::cout << s2 << " and " << t2 << ": "
		<< solution.is_anagram(s2, t2) << "\n";

	return 0;
}
