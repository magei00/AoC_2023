#include "../Utility.h"

bool all_z(std::vector<int> v){
	for(int i : v)
	{
		if(i!= 0){return false;}
	}
	return true;
}

int next_in_seq(std::vector<int> seq)
{
	if(all_z(seq)){return seq.back;}
	
	std::vector<int> next_seq(seq.size()-1, 0);
	
	for(int i=0; i<seq.size()-1;i++)
	{
		next_seq[i] = seq[i]-seq[i+1];
	}
	return next_in_seq(next_seq);
}

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