#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(){
	std::ifstream file ("../Data/Input.txt", std::ifstream::in);
	if (file.is_open())
	{
		file.seekg(0, std::ifstream::end);
		int size = file.tellg();
		char *contents = new char [size];
		file.seekg (0, std::ifstream::beg);
		file.read (contents, size);
		file.close();
		
		
		std::map<std::string, int> maxOfColor;
 
		// Insert some values into the map
		maxOfColor["red"] = 12;
		maxOfColor["green"] = 13;
		maxOfColor["blue"] = 14;
		
		
		std::map<std::string, int> minOfColor;
 
		// Insert some values into the map
		minOfColor["red"] = 0;
		minOfColor["green"] = 0;
		minOfColor["blue"] = 0;
		
		int game = 1;
		int i = 0;
		int sum = 0;
		bool legalGame = true;
		
		
		while (i<size && contents[i]!='\0'){
			
			//find game number
			if (legalGame){
					
				while(contents[i] != ' '){
					i++;
				}
				if(contents[i] == ' ')
				{
					std::string gamenum = "";
					i++;
					while(contents[i] != ':'){
						gamenum +=contents[i];
						i++;
					}
					game = std::stoi(gamenum);
				
				}
			}
			
			//run through rounds
			while(legalGame && contents[i] != '\n' && contents[i] != '\0')
			{
				i++;
				i++;
				//find number
				std::string n = "";
				while(contents[i] != ' '){
					n+=contents[i];
					i++;
				}
				i++;
				
				//find color
				std::string c = "";
				while(contents[i] != ',' && contents[i] != ';' && contents[i]!= '\n' && contents[i]!= '\0'){
					c+=contents[i];
					i++;
				}
				
				//update minimum
				if(minOfColor.at(c) < std::stoi(n)){		
					minOfColor[c] = std::stoi(n);
				}
				
			}
			
			if(contents[i] == '\n' || contents[i] == '\0'){
				
				sum+=minOfColor["red"]*minOfColor["green"]*minOfColor["blue"];
				std::cout << sum << '\n';
				minOfColor["red"] = 0;
				minOfColor["green"] = 0;
				minOfColor["blue"] = 0;
			}
			
			i++;
		}
		
		
			
	}
	
	system("pause");
	
	
	return 0;
}