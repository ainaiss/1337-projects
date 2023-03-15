#include <iostream>
#include <string>
#include <cstdint>

typedef struct Data_t {
	std::string Str;
	int Nbr;
	char c;
} Data;

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw)); 
}

int main()
{
	Data    data;
    data.Nbr = 42;
    data.Str = "1337";
    data.c    = 'a';

    std::cout << &data << " " << data.Nbr << " " << data.Str << " " << data.c << std::endl;

    uintptr_t tmp = serialize(&data);
    std::cout << &data << " " << data.Nbr << " " << data.Str << " " << data.c << std::endl;

    Data *data_R = deserialize(tmp);
    std::cout << &data_R << " " << data_R->Nbr << " " << data_R->Str << " " << data_R->c << std::endl;
    return 0;
}
