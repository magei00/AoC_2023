#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>


namespace util {
std::vector<std::string> split(std::string sentence, std::string delim){
	
	std::vector<std::string> r;

	std::string::size_type s{0}, e{0};
	while ((e = sentence.find(delim, s)) != sentence.npos) {
		if(e - s>0){ //only if string is not empty
			r.emplace_back(sentence.substr(s, e - s));
		}
		
		s = e + delim.length();
	}
	r.emplace_back(sentence.substr(s, sentence.length() - s));
	return r;

}


}