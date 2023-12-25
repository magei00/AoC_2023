#include "../Utility.h"

	
struct set{
	std::string hand;
	int bid;
};

int categorize(std::string hand) {
	
	int hncards=0;
	int shncards=0;
	int jokers=0;
	
	while(hand.size() > 0){
		char c = hand[0];
		int nc = 1;
		for(int i = 1; i <hand.size(); i++)
		{
			if(c == hand[i]){nc++;}
		}
		if(c=='1'){ //count jokers
			jokers=nc;
		}
		else if(nc > hncards)
		{
			shncards = hncards;
			hncards = std::max(hncards, nc);
		}
		else{
			shncards = std::max(shncards, nc);
		}
		
		hand.erase(remove(hand.begin(), hand.end(), c), hand.end()); //remove c from string
   
		
	}
	
	//add jokers to highest card
	hncards+=jokers;
	
	if(hncards ==5) {return 6;}
	else if(hncards ==4) {return 5;}
	else if(hncards ==3 && shncards ==2) {return 4;}
	else if(hncards ==3) {return 3;}
	else if(hncards ==2 && shncards ==2) {return 2;}
	else if(hncards ==2) {return 1;}
	else if(hncards ==1) {return 0;}
	else {
		std::cout << "Should not be possible" << std::endl;
		return -1;
	}
	
}

bool isStronger(set s1, set s2)
{
	for(int i = 0; i<s1.hand.size(); i++)
	{
		if(s1.hand[i] > s2.hand[i])
		{
			return true;
		}
		else if (s1.hand[i] < s2.hand[i])
		{
			return false;
		}
	}
	return false;
}

int insert(std::vector <set> *sets, set s){
	
	for(int i=0; i<(*sets).size(); i++)
	{
		if(isStronger(((*sets)[i]), s)){
			(*sets).insert((*sets).begin()+i, s);
			return 0;
		}
	}
	(*sets).push_back(s);
	return 0;
}

int p1(std::vector<std::string> in){
	
	int r=0;

	
	std::vector<std::vector <set>> sets(7, std::vector<set>());
	
	//replace symbols by sortable A-E;
	for(std::string& l :in)
	{
		std::replace(l.begin(), l.end(), 'A', 'E');
		std::replace(l.begin(), l.end(), 'T', 'A');
		std::replace(l.begin(), l.end(), 'J', 'B');
		std::replace(l.begin(), l.end(), 'Q', 'C');
		std::replace(l.begin(), l.end(), 'K', 'D');
	}
	
	
	for(std::string l :in)
	{
		set s;
		std::stringstream ss(l);
		ss >> s.hand;
		ss >> s.bid;
		
		//sort
		int category = categorize(s.hand);
		
		insert(&sets[category], s);
	}
	
	//count score
	int rank=1;
	for(std::vector <set> cats : sets){
		for(set s : cats){
			r+=rank*s.bid;
			rank++;
		}
	}
	
	return r;
}

int p2(std::vector<std::string> in){
	
	int r=0;
	
	std::vector<std::vector <set>> sets(7, std::vector<set>());
	
	//replace symbols by sortable A-E;
	for(std::string& l :in)
	{
		std::replace(l.begin(), l.end(), 'A', 'E');
		std::replace(l.begin(), l.end(), 'T', 'A');
		std::replace(l.begin(), l.end(), 'J', '1');
		std::replace(l.begin(), l.end(), 'Q', 'C');
		std::replace(l.begin(), l.end(), 'K', 'D');
	}
	
	
	for(std::string l :in)
	{
		set s;
		std::stringstream ss(l);
		ss >> s.hand;
		ss >> s.bid;
		
		//sort
		int category = categorize(s.hand);
		
		insert(&sets[category], s);
	}
	
	//count score
	int rank=1;
	for(std::vector <set> cats : sets){
		for(set s : cats){
			r+=rank*s.bid;
			rank++;
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