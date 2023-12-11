#include <iostream>
#include <fstream>
#include <ios>
#include <iostream>

int main(){
	std::cout << "Hello World :)\n";
	
	//read file
	std::ifstream file ("../Data/Input.txt", std::ifstream::in);
	if (file.is_open())
	{
		
		file.seekg(0, std::ifstream::end);
		int size = file.tellg();
		char *contents = new char [size];
		file.seekg (0, std::ifstream::beg);
		file.read (contents, size);
		file.close();
		//... do something with it
		
		int i=0;
		int firstNum, lastNum;
		int sum = 0;
		
		while (i<size)
		{

			if(isdigit(contents[i]))
			{
				if (firstNum == NULL)
				{
					firstNum = lastNum = contents[i] - '0';
				}
				else
				{
					lastNum = contents[i] - '0';
				}
			}
			if(contents[i]=='\n' || contents[i]=='\0'){
				sum += firstNum*10 + lastNum;
				firstNum = lastNum = NULL;
				
				
				std::cout << sum << '\n';
			}
			i++;
		}
	}
	
	
	system ("pause");
	
	return 0;
}