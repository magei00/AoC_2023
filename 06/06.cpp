#include "../Utility.h"

int p1(std::vector<std::string> in){
	
	int r=1;
	
	std::vector<int> times, distances;
	
	
	std::stringstream ss(in[0]);
	std::string s;
	ss>>	s;
	while(ss>>s)
	{
		times.push_back(std::stoi(s));
	}
	
	std::stringstream ss2(in[1]);
	ss2>>	s;
	while(ss2>>s)
	{
		distances.push_back(std::stoi(s));
	}

	
	for(int i =0; i<times.size(); i++)
	{
		for(int j=1; j<times[i]; j++)
		{
			if(j*(times[i]-j) > distances[i]){
				r*=(times[i]+1-(j*2));
				break;
			}
		}
	}
	
	return r;
}

int p2(std::vector<std::string> in){
	
	int r=0; //20048742
	
	long long time = 34908986;
	long long distance = 204171312101780;
	
	
	// I used wolfram alpha to solve the equations
	for(long long j=7430120; j<time; j++) //7430122
	{
		if(j*(time-j) > distance){
			r=(time+1-(j*2));
			break;
		}
	}
	
	
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