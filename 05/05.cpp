#include "../Utility.h"

int p1(std::vector<std::string> in){
	
	long long r=std::numeric_limits<long long>::max();
	
	struct m{
		long long d_start;
		long long s_start;
		long long	range;
	};
	
	std::vector<long long> seeds;
	std::vector<std::vector<m>> maps;
	
	
	//read seeds
	for(std::string s : util::split(util::split(in[0], ": ").at(1), " "))
	{
		seeds.push_back(stoll(s));
	}
	
	//read maps
	int map_n = 0;
	int line = 0;
	maps.push_back(std::vector<m>());
	for(int i = 3; i<in.size(); i++)
	{
		if(in[i] == ""){
			i++;
			i++;
			map_n++;
			line = 0;
			maps.push_back(std::vector<m>());
		}
		
		maps[map_n].push_back(m());
		std::vector<std::string> s = util::split(in[i], " ");
		maps[map_n][line].d_start = stoll(s[0]);
		maps[map_n][line].s_start = stoll(s[1]);
		maps[map_n][line].range   = stoll(s[2]);
		
		line++;
	}
	
	//calculate seeds and find nearest
	
	auto start = std::chrono::high_resolution_clock::now();
	
	long long n;
	for(long long s : seeds)
	{
		n=s;
		for(std::vector<m> map: maps){
			for(m l : map){
				if(n>=l.s_start && n<(l.s_start+l.range))
				{
					n= n + l.d_start-l.s_start;
					break;
				}
			}
			
		}
		
		//update shortest
		r = std::min(n,r);
	}
	auto stop = std::chrono::high_resolution_clock::now();
	
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
	// To get the value of duration use the count()
	// member function on the duration object
	//std::cout << duration.count() << std::endl;
		
	return r;
}

struct m{
		long long d_start;
		long long s_start;
		long long	range;
	};

long long find_min(std::vector<std::vector<m>> *maps, int layer, long long min, long long max, int map_line)
{
	long long r=std::numeric_limits<long long>::max();
	
	if(layer == 7)
	{
		return min;
	}
	
	
	if(map_line>=(*maps)[layer].size())
	{
		r=std::min(r, find_min(maps, layer+1, min, max, 0));
		
	}else{

		int i = map_line;
			
		long long min_lay = (*maps)[layer][i].s_start;
		long long max_lay =(*maps)[layer][i].s_start+(*maps)[layer][i].range;
		long long shift = (*maps)[layer][i].d_start-(*maps)[layer][i].s_start;
		
		if(min_lay >= max || max_lay <= min ){ //ranges don't overlap
			r=std::min(r, find_min(maps, layer, min, max, i+1));
		}
		else if(min >= min_lay && max <= max_lay){ //src range is fully in layer range
			r=std::min(r, find_min(maps, layer+1, min+shift, max+shift, 0));
			//if this happens, we shouldn't need to go through the rest of the map lines. (but we still do)
		}
		else if(min_lay >= min && max_lay<=max){ //layer range is fully in src range
			r=std::min(r, find_min(maps, layer+1, min_lay+shift, max_lay+shift, 0));
			
			//check the 2 snippet edges
			r=std::min(r, find_min(maps, layer, min, min_lay, i+1));
			r=std::min(r, find_min(maps, layer, max_lay, max, i+1));
		}
		else if(min >= min_lay){ //partial overlap with min in the center of layer range
			r=std::min(r, find_min(maps, layer+1, min+shift, max_lay+shift, 0));
			
			r=std::min(r, find_min(maps, layer, max_lay, max, i+1));
		}
		else if(max <= max_lay){ //partial overlap with max in the center of layer range
			r=std::min(r, find_min(maps, layer+1, min_lay+shift, max+shift, 0));
			
			r=std::min(r, find_min(maps, layer, min, min_lay, i+1));
		}
		else { std::cout<<"This should not be a possible case!!!!"<<std::endl;}
		
	}
	
	
	return r;
	
}

int p2(std::vector<std::string> in){
	
	long long r=std::numeric_limits<long long>::max();
	
	
	
	std::vector<long long> seeds;
	std::vector<std::vector<m>> maps;
	
	
	//read seeds
	for(std::string s : util::split(util::split(in[0], ": ").at(1), " "))
	{
		seeds.push_back(stoll(s));
	}
	
	//read maps
	int map_n = 0;
	int line = 0;
	maps.push_back(std::vector<m>());
	for(int i = 3; i<in.size(); i++)
	{
		if(in[i] == ""){
			i++;
			i++;
			map_n++;
			line = 0;
			maps.push_back(std::vector<m>());
		}
		
		maps[map_n].push_back(m());
		std::vector<std::string> s = util::split(in[i], " ");
		maps[map_n][line].d_start = stoll(s[0]);
		maps[map_n][line].s_start = stoll(s[1]);
		maps[map_n][line].range   = stoll(s[2]);
		
		line++;
	}
	
	for(int i=0; i<seeds.size(); i+=2){
		r= std::min(r, find_min(&maps, 0, seeds[i], seeds[i]+seeds[i+1], 0));
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