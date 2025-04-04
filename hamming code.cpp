#include<iostream>
#include<cstring>
#define max 30
using namespace std;
int calculateCodeBits(char *data)
{
	
}

unsigned char calculateHammingCode(char data, int code_bits)
{
	
}

void checkReceivedData(unsigned char *data,int parity_no)
{
	
}

int main()
{
	unsigned char databits[max], tx[];
	cout<<"Enter your data:";
	cin>>databits;
	cout<<endl;
	
	//calculate number of bits for hamming code
	int code_bit = calculateCodeBits(databits);
	
	//calculate and append hamming code to databits
	tx=calculateHammingCode(databits, code_bit);
	
	//check the transferred data at receiver side
	checkReceivedData(tx,code_bit);
	
	return 0;
}
