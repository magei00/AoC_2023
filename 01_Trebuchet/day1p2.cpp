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
		
		const char* numbers[9] = 
		{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
		int numLen = sizeof(numbers) / sizeof(char*);
		
		int i=0;
		int firstNum = NULL, lastNum = NULL;
		int sum = 0;
		
		while (i<size)
		{
			
			//check if digit
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
			
			//check if spelt out digit
			for(int j=1; j<=numLen; j++){
				int k=0;
				while(*(numbers[j-1]+k) == contents[i+k]){
					if(*(numbers[j-1]+k+1) == '\0')
					{
						if (firstNum == NULL)
						{
							firstNum = lastNum = j;
						}
						else
						{
							lastNum = j;
						}
					}
					k++;
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