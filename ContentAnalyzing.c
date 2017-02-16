/*
	Title: Create a command utility that can analyze the contents of a text file, and produce some analysis such as counting number of spaces, charactes, vowels, digits. Also, convert all the content in upper case and print it in another file as an output.

	Author Details:
	Name: Unnitkumar Metaliya
	StudentID: 104702352
	UserID: metaliy

	Date Created: 14/02/2017
*/

// Header Files
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// Main Function
int main(int argc, char *argv[]){
	int fd1, fd2; //Taking two file descriptors; one for input file, second for output file
	int spaceCount=0, charCount=0, digitCount=0, puncCount=0, vowelCount=0; //initializing all the counting variables as 0
	char buffer; //Character buffer which will temporarily store the value depending on the logic 
	long int i=0, fileSize=0;

	fd1=open(argv[1],O_RDONLY); //first input file will be having only read-only permission
	fd2=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0755); // second output file should have all these three permission i.e create, write and truncation
	
	while(read(fd1,&buffer,1)>0)
		fileSize++; //logic to let the cursor move ahead in given file
	lseek(fd1,0,SEEK_SET); //setting up the cursor

	while(++i<=fileSize){
		read(fd1,&buffer,1);
				
		if(isalpha(buffer)) //using an in-built function for counting characters
		{
			charCount++;
		}
		else if(isspace(buffer))
		{
			spaceCount++;  //using an in-built function for counting spaces
		}
		else if(isdigit(buffer))		
		{
			digitCount++;  //using an in-built function for counting digits
		}
		else if(ispunct(buffer))
		{
			puncCount++;  //using an in-built function for counting punctuations
		}
		else
		{
			printf("File is Empty.."); //Will print "File is Empty.." if file is empty
		}

		if(buffer>=97 && buffer<=122)
                {
                        buffer=toupper(buffer); //logic for converting lowercase letter to upper case letters
                }
		
		if(buffer=='a' || buffer=='A' || buffer=='e' || buffer=='E' || buffer=='i' || buffer=='I' || buffer=='o' || buffer=='O' || buffer=='u' || buffer=='U')
                {
                        vowelCount++; //logic for counting vowels
                }


		write(fd2,&buffer,1); //writing to another specified file
	}	

	//Printing all the details..
	printf("Number of Characters: %d \n",charCount);
	printf("Number of spaces: %d \n",spaceCount);
	printf("Number of digits: %d \n",digitCount);	
	printf("Number of Punctuations: %d \n",puncCount);
	printf("Number of Vowels: %d\n",vowelCount);

	//Closing both the files after completing operation
	close(fd1);
	close(fd2);
	
}
