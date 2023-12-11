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
			while(legalGame && contents[i] != '\n')
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
				while(contents[i] != ',' && contents[i] != ';' && contents[i]!= '\n'){
					c+=contents[i];
					i++;
				}
				
				//check if legal
				if(maxOfColor.at(c)<(std::stoi(n))){legalGame = false;}
				
			}
			
			if(contents[i] == '\n' || contents[i] == '\0'){
				
				if(legalGame){sum+=game;}
				std::cout << sum << '\n';
				legalGame = true;
			}
			
			i++;
		}
		
		
			
	}
	
	system("pause");
	
	
	return 0;
}