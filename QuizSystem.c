// Quiz System

/* Zhao Changxu 201610234008 */
/* Zhang Libo   201610234033 */
/* Chen Xinyi   201610234012 */
/* Lei Fan      201610234060 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct qanda
{
	char question[100];
	char canswer[50];
	char answer1[50];
	char answer2[50];
	char answer3[50];
};
void menu1(void);
void menu2(void);
void managequestion(struct qanda qa[]);
float quizfuction(struct qanda qa[]);
void question_print(struct qanda qa[]);
void question_add(struct qanda qa[]);
void question_delete(struct qanda qa[]);
void question_edit(struct qanda qa[]);
float question_random(struct qanda qa[]);

int main()
{
	struct qanda qa[8];
	int choice1,i=0,j;
	float score,string[100];
	strcpy(qa[0].question,"Where is the capital of the Netherlands ?");
	strcpy(qa[0].canswer,"Amsterdam");
	strcpy(qa[0].answer1,"Hague");	
	strcpy(qa[0].answer2,"Breda");
	strcpy(qa[0].answer3,"Twente");
	strcpy(qa[1].question,"What is the national day of Netherlands ?");
	strcpy(qa[1].canswer,"April 30th");
	strcpy(qa[1].answer1,"April 1th");	
	strcpy(qa[1].answer2,"May 1th");
	strcpy(qa[1].answer3,"May 30th");
	strcpy(qa[2].question,"What is the offical language of the Netherlands ?");
	strcpy(qa[2].canswer,"Dutch");
	strcpy(qa[2].answer1,"English");	
	strcpy(qa[2].answer2,"Chinese");
	strcpy(qa[2].answer3,"German");
	strcpy(qa[3].question,"What is the Dutch National Anthem of the Netherlands ?");
	strcpy(qa[3].canswer,"HET Wilhelmus");
	strcpy(qa[3].answer1,"Welcome to NewYork");	
	strcpy(qa[3].answer2,"Sweet");
	strcpy(qa[3].answer3,"Rainy Day");
	strcpy(qa[4].question,"What is the most popular fish in the Netherlands ?");
	strcpy(qa[4].canswer,"herring");
	strcpy(qa[4].answer1,"goldfish");	
	strcpy(qa[4].answer2,"whale");
	strcpy(qa[4].answer3,"shark");
	strcpy(qa[6].question,"What kind of flower is the Netherlands's national flower?");
    strcpy(qa[6].canswer,"Tulip");
    strcpy(qa[6].answer1,"Tose");
    strcpy(qa[6].answer2,"Lily");
    strcpy(qa[6].answer3,"Violet");
	strcpy(qa[5].question,"Which of following artist is from the Netherlands?");
	strcpy(qa[5].canswer,"Vincient van Gogh");
	strcpy(qa[5].answer1,"Paul Gauguin");
	strcpy(qa[5].answer2,"Claude Monet");
	strcpy(qa[5].answer3,"Wolfgang Amadeus Mozart");
	
	
	do
	{
		printf("\t\tWelcome to Quiz System\n");
		printf("---------------------------------------------------------\n");
		menu1();
		do
		{
			printf("enter your choice: ");
			scanf("%d", &choice1);
			getchar();
		} while(choice1!=1&&choice1!=2&&choice1!=3&&choice1!=0);
 	    switch(choice1)
	    {
		    case 1: managequestion(qa);		    /* manage question */
			        break;
		    case 2: score=quizfuction(qa);		/* start a quiz */
					if(score+1==1)
		    		{
		    			score=0;
					}     	    				
			        string[i]=score;
			        i++;
					break;
		    case 3: if(score+1==1)				/* show the score and rank */
		    		{
		    			score=0;
					}
					printf("\nYour latest score is %.2f  ",score);
		    		printf("\n---------------------------------------------------------\n");
					printf("\nAll score£º\n");
					for(j=0;j<i;j++)
					printf("\t\t%.2f\n",string[j]);
					getchar();					
			        break;
		    case 0: return 0;
		            break;
	    }
	}while(choice1);

	getchar();
	return 0;
}


/* menu for the mian function */
void menu1(void)
{
	system("cls");
	printf("\t\t\tWelcome to Quiz System\n");
	printf("--------------------------------------------------------------\n");
	printf("\t\t\t1.Manage question\n");
	printf("\t\t\t2.Start a quiz\n");
	printf("\t\t\t3.Show the score and ranking\n");
	printf("\t\t\t0.Close the system\n\n");
	return;
}



/* menu for manage questions */
void menu2(void)
{
	system("cls");
	printf("\t\t\tWelcome to Quiz System\n");
	printf("--------------------------------------------------------------\n");
	printf("\t\t1.Print all questions and answers\n");
	printf("\t\t2.Add a question with 4 answers\n");
	printf("\t\t3.Delete a question with its answers\n");
	printf("\t\t4.Edit a question and the answers\n");
	printf("\t\t0.Back to menu1\n\n");
	return;
}



/* manage question function */
void managequestion(struct qanda qa[])
{
	int choice2,i;
	for(i=0;i<100;i++)
	{
		qa[7].question[i]=0;
	}
	for(i=0;i<50;i++)
	{
		qa[7].canswer[i]=0;	
		qa[7].answer1[i]=0;
		qa[7].answer2[i]=0;
		qa[7].answer3[i]=0;
	}
	do
	{	
		menu2();
		do
		{
			printf("enter your choice: ");
			scanf("%d", &choice2);
			getchar();
		}while(choice2!=1&&choice2!=2&&choice2!=3&&choice2!=4&&choice2!=0);
 	    switch(choice2)
	    {
		    case 1: question_print(qa);				     /* print all questions */
		    		
		    		
			        break;
		    case 2: question_add(qa);
					printf("Add Successfully!");		 /* add a question */
		    		getchar();
		    
			        break;
		    case 3: question_delete(qa);
					getchar();				             /* delete a question */
		    		printf("Delete Successfully!");
					getchar();
			        break;
			case 4: question_edit(qa);				     /* edit a question */
					printf("Edit Successfully!");		 /* add a question */
		    		getchar();
			
					break;
		    case 0: printf("\n\n");
					break;
	    }
	}while(choice2);
}



/* quiz function */
float quizfuction(struct qanda qa[])
{
	float score;
	score=question_random(qa);
	return score;
}






/* question delete */
void question_delete(struct qanda qa[])
{
	int del,i;
	do
	{
	
		printf("please input the sequence number you want to delete(betweem 1 and 8): ");
		scanf ("%d",&del);
	}while (del>8||del<1);
	del=del-1;
	for(i=0;i+del<7;i++)
	{
		strcpy(qa[del+i].question,qa[del+i+1].question);
		strcpy(qa[del+i].canswer,qa[del+i+1].canswer);
		strcpy(qa[del+i].answer1,qa[del+i+1].answer1);
		strcpy(qa[del+i].answer2,qa[del+i+1].answer2);
		strcpy(qa[del+i].answer3,qa[del+i+1].answer3);
	}
	for(i=0;i<100;i++)
	qa[7].question[i]=0;
	for(i=0;i<50;i++)
	{
	qa[7].canswer[i]=0;
	qa[7].answer1[i]=0;
	qa[7].answer2[i]=0;
	qa[7].answer3[i]=0;
	}
	return;
}



/* print question */
void question_print(struct qanda qa[])
{
	int i,j=1;
	


	for(i=0;i<8&&qa[i].question[0]!=0;i++)
	{
		printf("\n\n%d.",j);
		puts(qa[i].question);
		printf("\n");
		printf("A.");
		puts(qa[i].canswer);
		printf("\n");
		printf("B.");
		puts(qa[i].answer1);
		printf("\n");
		printf("C.");
		puts(qa[i].answer2);
		printf("\n");
		printf("D.");
		puts(qa[i].answer3);
		printf("\n");
		j+=1;
		
	}

	getchar();
	return;
}



/* add question */
void question_add(struct qanda qa[])
{
	printf("Input your new question: ");
	gets(qa[7].question);


	printf("Input the correct answer: ");
	gets(qa[7].canswer);
	
	printf("Input wrong answer1: ");
	gets(qa[7].answer1);
	
	printf("Input wrong answer2: ");
	gets(qa[7].answer2);
	
	printf("Input wrong answer3: ");
	gets(qa[7].answer3);

	return;
} 



/* edit question function */
void question_edit(struct qanda qa[])
{
	int edit;
	do
	{
	
		printf("Please input the sequence number you want to edit(betweem 1 and 8): ");
		scanf ("%d",&edit);
		getchar();
	}while (edit>8||edit<1);
	edit=edit-1;
	printf("Please input the edited problem  ");
	gets(qa[edit].question);
	printf("Please input the edited correct answer  ");
	gets(qa[edit].canswer);
	printf("Please input the edited wrong answer1  ");
	gets(qa[edit].answer1);
	printf("Please input the edited wrong answer2  ");
	gets(qa[edit].answer2);
	printf("Please input the edited wrong answer3  ");
	gets(qa[edit].answer3);

	return;
}



/* show the questions and answers randomly */
/* manage the user answer */
float question_random(struct qanda qa[])
{
	int i,j,n,a,b,c,d,array1[4],array2[4];
	char array[]={'A','B','C','D'},answer;
	float count;
	srand((int)time(0));
	do{
	array1[0]=rand()%8;
	a=array1[0];
	}while(qa[a].question[1]==0);
	for(j=1;j<4;j++)
	{
		do{
			array1[j]=rand()%8;
			a=array1[j];
			for(n=0;n<j;n++)
			{
				if(array1[n]==array1[j])
				{
					j--;
				}	
			}
		}while(qa[a].question[1]==0); 
	}
	

	for(j=0;j<4;j++)
	{
		printf("%d   ",j+1);
		a=array1[j];
		puts(qa[a].question);
		do
		{
				array2[0]=rand()%4+1;
				b=array2[0];
		}while(qa[b].canswer[1]==0);
		for(d=1;d<4;d++)
		{
		do{
			array2[d]=rand()%4+1;
			b=array2[d];
			for(n=0;n<d;n++)
			{
				if(array2[n]==array2[d])
				{
					d--;
				}	
			}
		}while(qa[b].canswer[1]==0); 
	}
		for(n=0;n<4;n++)
		{
			printf("%c   ",array[n]);
			b=array2[n];
			switch (b)
			{
				case 1:
					puts(qa[a].canswer);
					break;
				case 2:
					puts(qa[a].answer1);
					break;
				case 3:
					puts(qa[a].answer2);
					break;
				case 4:
					puts(qa[a].answer3);
					break;
			}
			if (b==1)
			i=n+1;
		}
		do{
		printf("\n");
		printf("For this question, your answer is(write your answer in CAPITAL): ");
		scanf("%c",&answer);
		getchar();
		}while(answer!='A'&&answer!='B'&&answer!='C'&&answer!='D');

		switch(answer)
		{
			case 'A':
				c=1;
				break; 
			case 'B':
				c=2;
				break; 
			case 'C':
				c=3;
				break; 
			case 'D':
				c=4;
				break; 
		}
		if(c==i)
		{
			count=count+2.5;
			printf("Good, you are correct.\n\n");
		}
		else
		{
			printf("Sorry, you are wrong, the correct answer is %s\n\n",qa[a].canswer);
		}
	}
	

	getchar();
	return (count);
}






