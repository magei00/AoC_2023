#include "../Utility.h"

int p1(std::vector<std::string> in){
	
	int r = 0;
	std::vector<std::vector<int>> win_nums;
	std::vector<std::vector<int>> my_nums;
	
	int i=0;
	for(std::string l : in)
	{
		std::string g = util::split(l, ": ").at(1);
		std::vector<std::string> wn = util::split(util::split(g, " | ").at(0), " ");
		std::vector<std::string> mn = util::split(util::split(g, " | ").at(1), " ");
		
		win_nums.push_back(std::vector<int>());
		my_nums.push_back(std::vector<int>());
		
		for(std::string w : wn){
			win_nums[i].push_back(stoi(w));
			//std::cout<<w;
		}
		for(std::string m : mn){
			my_nums[i].push_back(stoi(m));
		}
		i++;
	}
	
	//calculate winnings
	for (int i{0}; i<win_nums.size(); i++){
		int score =0;
		for(int j{0}; j<win_nums[i].size(); j++){
			for (int k{0}; k<my_nums[i].size(); k++){
				if(win_nums[i][j] == my_nums[i][k])
				{
					score = (score == 0) ? score=1 : score*=2;
				}
			}
		}
		r+=score;
	}
	
	return r;
}


//calculate winnings
int calc_cards(int from, int to, std::vector<std::vector<int>>* win_nums, std::vector<std::vector<int>>* my_nums) {
	int cards = 0;
	int max = (*win_nums).size();
	for (int i = from; i<std::min(to, max ); i++){
		cards++;
		int score=0;
		for(int j{0}; j<(*win_nums)[i].size(); j++){
			for (int k{0}; k<(*my_nums)[i].size(); k++){
				if((*win_nums)[i][j] == (*my_nums)[i][k])
				{
					score+=1;
				}
			}
		}
		
		if(score>0)
		{
			cards += calc_cards(from+1, from+1+score, win_nums, my_nums);
		}
		
	}
	return cards;
}

int p2(std::vector<std::string> in){
	
	int r = 0;
	std::vector<std::vector<int>> win_nums;
	std::vector<std::vector<int>> my_nums;
	
	int i=0;
	for(std::string l : in)
	{
		std::string g = util::split(l, ": ").at(1);
		std::vector<std::string> wn = util::split(util::split(g, " | ").at(0), " ");
		std::vector<std::string> mn = util::split(util::split(g, " | ").at(1), " ");
		
		win_nums.push_back(std::vector<int>());
		my_nums.push_back(std::vector<int>());
		
		for(std::string w : wn){
			win_nums[i].push_back(stoi(w));
			//std::cout<<w;
		}
		for(std::string m : mn){
			my_nums[i].push_back(stoi(m));
		}
		i++;
	}
	
	std::vector<int> no_cards(win_nums.size(), 1);
	
	//calculate winnings
	for (int i{0}; i<win_nums.size(); i++){
		int score =0;
		for(int j{0}; j<win_nums[i].size(); j++){
			for (int k{0}; k<my_nums[i].size(); k++){
				if(win_nums[i][j] == my_nums[i][k])
				{
					score +=1;
				}
			}
		}
		
		//now add cards based on number of current card and score
		
		for(int m = 0; m<score; m++)
		{
			if(i+m+1>=no_cards.size()){break;}
			no_cards[i+m+1]+=(1*no_cards[i]);
		}
	}
	
	//now count cards
	for (int i : no_cards)
	{
		r+=i;
	}
	
	//this recursive solution is not great, would be better to just calculate points per cards and make an algorithm multiplying recursively
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