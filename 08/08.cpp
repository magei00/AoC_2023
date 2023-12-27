#include "../Utility.h"

struct node{
	std::string name;
	std::string left;
	std::string right;
};

struct node2{
	std::string name;
	node2* left;
	node2* right;
};

int p1(std::vector<std::string> in){
	
	std::vector<node> nodes;
	std::string directions = in[0];
	
	node current_node;
	
	for (int i = 2; i<in.size(); i++)
	{
		node n;
		n.name = in[i].substr(0,3);
		n.left = in[i].substr(7,3);
		n.right = in[i].substr(12,3);
		//std::cout<<n.left1<<std::endl;
		nodes.push_back(n);
		
		if(n.name == "AAA"){current_node = n;}
	}
	
	bool end_reached= false;
	int moves = 0;
	while(!end_reached){
	for(char dir : directions){
		
		std::string next_node = (dir == 'L' ? current_node.left : current_node.right);
		
		for(node n : nodes){
			if(n.name == next_node){
				current_node = n;
				moves++;
				
				if(current_node.name == "ZZZ"){end_reached=true;}
				break;
			}
		}
		
		if(end_reached){
			break;
		}
	}
	}
	
	
	int r = moves;
	return r;
}

int p2(std::vector<std::string> in){

	std::vector<node2> nodes;
	nodes.reserve(1000);
	std::string directions = in[0];
	
	std::vector<node2 *> current_nodes;
	
	//create nodes
	for (int i = 2; i<in.size(); i++)
	{
		node2 n;
		n.name = in[i].substr(0,3);
		//std::cout<<n.left1<<std::endl;
		nodes.push_back(n);
		
		if(n.name[2] == 'A'){
			current_nodes.push_back(&nodes.back());
		}
	}
	
	//link nodes
	for (int i = 2; i<in.size(); i++)
	{
		
		std::string l = in[i].substr(7,3);
		std::string r = in[i].substr(12,3);
		for(node2 &n : nodes){
			if(n.name == l){
				nodes[i-2].left = &n;
			}
			if(n.name == r){
				nodes[i-2].right = &n;
			}
		}
		
	}
	
	
	bool end_reached = false;
	int moves = 0;
	
	
	//solution i ended up with was to find the moves for each starting node to end node, and finding the smallest common multiple.
	//this assumes that the sequences loop starting at the start node, and that the moves for 1 loop is stable, and maybe more I still don't see the whole picture.
	std::vector<std::vector<int>> indi_moves (current_nodes.size(), std::vector<int>());
	std::vector<int> indi_moves_prev (current_nodes.size(), 0);

	
	while(!end_reached){
	for(char dir : directions){
		
		for(node2* &cn : current_nodes){
			cn = (dir == 'L' ? (*cn).left : (*cn).right);
		}
		moves++;
		
		//check if all at ..Z
		end_reached = true;
		for(int i = 0 ; i<current_nodes.size(); i++){
			if((*current_nodes[i]).name[2] != 'Z'){
				end_reached = false;
			}else
			{
				indi_moves[i].push_back(moves-indi_moves_prev[i]);
				indi_moves_prev[i]= moves;
				
			}
		}
		
		if(end_reached){
			break;
		}
	}
	}
	
	
	int r = moves;
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