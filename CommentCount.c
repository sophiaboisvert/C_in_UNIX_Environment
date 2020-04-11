//use input redirection to input the file to be read from
//Ex: ./a.out < fileName.c


#include <stdio.h>

main()
{
	int c;
	int charCount = 0; //counts the number of commented characters
	int wordCount = 0; //counts the number of words
	
	while((c = getchar()) != EOF)
	{
		//if the character may indicate a comment
		if(c == '/')
		{
			//if there is a single line comment
			if((c = getchar()) != EOF && c == '/')
			{
      
				//include the first word
 			      	wordCount++;

				while((c = getchar()) != EOF && c != '\n')
				{
		  			if(c == ' ' || c == '\t')
			  			wordCount++;
				  	charCount++;
				}
				//include the final newline character
				charCount++;
			}
			//if there is a block comment
			else if(c == '*')
			{
				//include the first word
				wordCount++;
				int prevChar = c;
        
				while((c = getchar()) != EOF && (c != '/' || prevChar != '*'))
				{
					//if a new word occurs
					if((c == ' ' || c == '\n' || c == '\t') && (prevChar != ' ' && prevChar != '\n' && prevChar != '\t'))
						wordCount++;
					charCount++;
					prevChar = c;
				}
				//account for counting the last * as a character
				charCount--;
			}
		}
	}

	//output results
	printf("The total number of commented characters is: %d", charCount);
	printf("\nThe total number of commented words is: %d\n", wordCount);

}
