#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
int *deck_maker()
{
	static int deck1[26];
	int i;
	
	for ((i=0); (i<26); (i++)){
		deck1[i] = rand() % (14 + 1 - 2) + 2;
	}	

	return(deck1);

}
int main(void)
{
	char user_name1[7];
	char user_name2[6];
	strcpy(user_name1, "Chance");
	strcpy(user_name2, "Jamal");
	

	int jamal=0, chance=0, tie = 0;
	
	int*x ; 
	int*y ;
	int i;
	int deck1[26],deck2[26];
	x = deck_maker();

	for (i=0; i<26; i++){
      deck1[i] = *(x + i);

  }
  	y = deck_maker();

	for (i=0; i<26; i++){
      deck2[i] = *(y + i);
  }
  for (i=0; i<26; i++){
     if (deck2[i] != deck1[i]){
        printf("At %d Jamal has %d and Chance has %d\n",i,deck1[i],deck2[i]);
        printf("Jamal has %d points and Chace has %d points\n\n",jamal,chance);
      if (deck1[i]>deck2[i]){
      	jamal = jamal+1;
      }
    
     if (deck2[i]>deck1[i]){
      	chance  = chance + 1;
      }
     if (deck2[i] == deck1[i]){
     	tie = tie +1;
     	if (deck2[i+1] + deck2[i+2] < deck1[i+1] +deck1[i+2]){
     		chance = chance + 3;
     		i = i+2;
     	}
     	if (deck1[i+1] + deck1[i+2] < deck2[i+1] +deck2[i+2]){
     		chance = chance +3;
     		printf("At %d and %d Jamal has %d and Chance has %d\n",i+1,i+2,deck1[i+1] + deck1[i+2],deck2[i+1]+deck2[i+2]);
        printf("Jamal has %d points and Chace has %d points\n\n",jamal,chance);

        i = i+2;
      }
      }
		  
    }
   
  }
    

  printf("Jamal has %d points and Chance has %d\n",jamal,chance);
    if (jamal>chance)  {
    printf ("Jamal Wins\n");
  } 
  else {
    printf("Chance Wins\n");
  }
  printf("There were %d, ties",tie);
	return(0);
}