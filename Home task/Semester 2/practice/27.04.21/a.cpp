#include <fstream>
#include <vector>



tempalate <typename T>
void write(T arg, const char* name)
{
	ofstream out(name, ios::binary);
	    out.write((char*)&arg, sizeof(arg));        
	out.close();                                	
}


tempalate <typename T>
std::vector<T> read(const char* name)
{
	std::vector<T> res(1);
	FILE *f = fopen(name, "rb");
	ifstream in(name, ios::binary);
 
 	int i{0};
 	while (fread(res[i], sizeof(res[i]), 1, f);)
 	{
 		i++;
 		T tmp;
 		res.push_back(tmp);
 	}
	

	out.close();                                	
}

