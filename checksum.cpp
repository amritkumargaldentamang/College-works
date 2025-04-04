//Program to find checksum of the given data
#include<iostream>
#include<string.h>
#define MAXSIZE 30
using namespace std;

unsigned char binaryToByte(char *data_chunk)
{
	unsigned char val=0;
	int i;
	for(i=0; i<8; i++)
	{
		val <<=1;
		if(data_chunk[i] == '1')
		{
			val|=1;
		}
		return val;
	}
}
unsigned char calculateChecksum(char *data)
{
	int length = strlen(data);
	unsigned int sum=0;
	
	for(int i = 0; i < length; i += 8) {
        char data_chunk[9] = "00000000";
        for (int j = 0; j < 8 && (i + j) < length; j++) {
            data_chunk[j] = data[i + j];
        }

        unsigned char byte = binaryToByte(data_chunk);
        sum += byte;

        if (sum > 0xFF)
            sum = (sum & 0xFF) + 1; // wrap-around
    }
    return ~sum & 0xFF;
}

void bytetoString(unsigned char byte, char* out) {
    for (int i = 7; i >= 0; i--) {
        out[7 - i] = (byte & (1 << i)) ? '1' : '0';
    }
    out[8] = '\0';
}

int main()
{
	char databits[MAXSIZE];
	cout<<"Enter the binary data:\n";
	cin>>databits;
	
	unsigned char checksum;
	checksum = calculateChecksum(databits);
	
	//convert binary to string
	char checksumStr[9];
	bytetoString(checksum, checksumStr);
	
	strcat(databits, checksumStr);
	cout<<"\nFinal data with checksum:"<<databits<<endl;
	cout<<"Checksum is: "<<checksum;
	
	return 0;
}
