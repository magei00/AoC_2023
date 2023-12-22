#include "../Utility.h"

int p1(std::vector<std::string> in){
	
	int r=0;
	
	return r;
}

int p2(std::vector<std::string> in){
	
	int r=0;
	
	return r;
}

int main(){
	
	std::vector<std::string> lines;
	
	std::ifstream file ("../Data/Input.txt", std::ifstream::in);
	if (file.is_open())	
	{	
		for(std::string l; std::getline(file, l);)
		{
			lines.emplace_back(l);
		}
		file.close();
	}
	
	std::cout<<p1(lines)<<std::endl;
	std::cout<<p2(lines)<<std::endl;
	
	return 0;
}