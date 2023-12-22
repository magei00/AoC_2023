#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){
	
	
	
	std::ifstream file ("../Data/Input.txt", std::ifstream::in);
	if (file.is_open())
	{
		
		//file.ignore( std::numeric_limits<std::streamsize>::max());

		std::vector<std::string> lines;
		
		for(std::string l; std::getline(file, l);)
		{
			lines.emplace_back(l);
		}
		
		file.close();
		
		//get width
		int width= lines[1].size();
		int height= lines.size();
		
		
		//add border padding for cleaner algorithm
		height+=2;
		width+=2;

		
		std::vector<std::vector<char>> arr(height, std::vector<char> (width, '.'));

		//fill array with chars, avoiding the border
		
		for (int i=1; i<height-1; i++){
			for (int j=1; j<(width-1); j++){
				arr[i][j] = lines[i-1][j-1];
			}
		}
		//print array
		/*for (int i=0; i<height; i++){
			for (int j=0; j<width; j++){
				std::cout<<arr[i][j];
			}
		std::cout<<'\n';
		}*/

		//Do the algorithm to check for valid numbers
		

		
		std::string n ="";
		int start_width, end_width = 0;
		int sum = 0;
		bool is_valid = false;
		
		for (int i=1; i<height-1; i++){
			for (int j=1; j<(width-1); j++){
				
				if(isdigit(arr[i][j])){
					start_width = j-1;
					while(isdigit(arr[i][j])){
						n += arr[i][j];
						j++;
					}
					end_width = j;
					
					//check if valid number
					for(int i2 = i-1; i2<i+2; i2++){
						for(int j2 = start_width; j2<=j;j2++){
							if(arr[i2][j2]!='.' && !isdigit(arr[i2][j2])){
								is_valid=true;
							}
						}
					}
					
					//add to sum and reset
					if(is_valid){sum += stoi(n);}
					n="";
					is_valid = false;
					
				}
				
			}
		
		}
		std::cout<<sum <<'\n';
	}
	
	//std::cin.get();
	return 0;
}
