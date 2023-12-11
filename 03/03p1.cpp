#include <iostream>
#include <fstream>

int main(){
	
	
	
	std::ifstream file ("../Data/Input.txt", std::ifstream::in);
	if (file.is_open())
	{
		
		file.ignore( std::numeric_limits<std::streamsize>::max() );
		int size = file.gcount();
		char *contents = new char [size];
		file.seekg (0, std::ifstream::beg);
		file.read (contents, size);
		file.close();
	
	
		//get width
		int width=0;
		while(contents[width] != '\n')
		{
			width++;
		}

		//get height
		int i=0;
		int height=1;
		while(contents[i] != '\0')
		{
			if(contents[i] == '\n')
			{height++;}
			i++;
		}
		
		//add padding for cleaner algorithm
		height+=2;
		width+=2;

		
		char* arr = new char[height * width];
		
		//fill array with .
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++){
				arr[i*width + j] = '.';
			}
		std::cout<<'\n';
		}

		//fill array with chars
		
		for (int i=1; i<height-1; i++){
			for (int j=1; j<(width-1); j++){
				arr[i*width + j] = contents[(i-1)*(width-1)+(j-1)]; //kinda messy, a more readable version would be to clean the contents array from \n before copying it in.
				//std::cout<<arr[i*width + j];
			}
		//std::cout<<'\n';
		}
		//print array
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++){
				std::cout<<arr[i*width + j];
			}
		std::cout<<'\n';
		}
		
		//Do the algorithm to check for valid numbers


	system ("pause");
	}
	
	system ("pause");
	return 0;
}