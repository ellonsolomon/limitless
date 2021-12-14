//Brightness, Sound volume, Resolution and keyboard listening
//SPproject.c

	//headers required to carry out the program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


//variables to hold the brightness level , sound level etc...

    char Resize[256];
    
    FILE *Resin;
    char BUFbr[256]; 
    char BUFrs[256];
    char BUFsd[256];
    int caseforsr;
    int mvol;
    int hvol;
    int micvol;
	
	//main function
int main(){


int choice;
	while(choice!=5)
  {
	   system("clear");
  printf("\n1. Change Brightness\n");
  printf("2. Change Sound volume\n");

  printf("3. Change Screen Resolution\n");
  printf("4. Listen keyboard\n");
  printf("5. Exit\n");
  printf("Choose the operation you want:\n");
  scanf("%i",&choice);			//asking a user for his/her input

 if(choice==1)
 {
    brightnessChanger();		//brightness changer function
 }

 else if(choice==2)
 {
  soundChanger();				// a function to change the sound volume
 }

 else if(choice==3)
 {
   screenResolutionChanger();	// a function to change the screen resoution
 }

 else if(choice==4)
 {
   keyboardListener();			// a function to listen to a keyboard
 }
 else
 {
   printf("unspecified option");
 }

  }

   }
   
	//sound changer funtion
int soundChanger(){

  printf("manage volume by selecting from the options\n\n");

  printf("   1 : Increase by 5 percent             ||                2: Decrease by 5  percent\n\n");
  printf("   3 : Increase by 10 percent            ||                4: Decrease by 10 percent\n\n");
  printf("   5 : Increase by 15 percent            ||                6: Decrease by 15 percent\n\n");
  scanf("%i", &mvol);			//input one of the options

if (mvol==1)
{
  char fiveup[]="5%+";
  snprintf(BUFsd, 255,"amixer set 'Master' %s",fiveup);
  system(BUFsd);				//increase the system sound by 5 %

}

else if (mvol==2)
{
  char fivedown[]="5%-";
  snprintf(BUFsd, 255,"amixer set 'Master' %s",fivedown);
  system(BUFsd);				//decrease the system sound by 5 %
}


else if (mvol==3)
{
  char tenup[]="10%+";
  snprintf(BUFsd, 255,"amixer set 'Master' %s",tenup);
  system(BUFsd);			//increase the system sound by 10 %
}

 else if (mvol==4)
{
  char tendown[]="10%-";
  snprintf(BUFsd, 255,"amixer set 'Master' %s",tendown);
  system(BUFsd);			//decrease the system sound by 10 %
}  

else if (mvol==5)
{
  char ffup[]="15%+";
  snprintf(BUFsd, 255,"amixer set 'Master' %s",ffup);
  system(BUFsd);		//increase the system sound by 15%
}

else if (mvol==6)
{
  char ffdown[]="15%-";
  snprintf(BUFsd, 255,"amixer set 'Master' %s",ffdown);
  system(BUFsd);			//decrease the system sound by 15 %
}
else
{
  printf("out of range");			// input is out of the option
}

}

//brightness change function
int brightnessChanger()
{
  char MonitorName[256];
  float BrightnessL;
    FILE *Monin;
    Monin=popen("xrandr | grep \" connected\" | cut -f1 -d \" \"", "r");
    fgets(MonitorName, 255, Monin);

int len = strlen(MonitorName);
   if(MonitorName[len-1]=='\n')
        MonitorName[len-1]='\0';

      char monitor[240];
    char ch[30];
  printf("\n The monitor your are about to make chenges is : %s\n", MonitorName);
  printf("Please Enter Brightness level you want\n");
 printf("Please mind your eye! Enter less than 2\n");
    scanf("%f", &BrightnessL);
    
    strcat(monitor,"xrandr --output ");
    strcat(monitor,MonitorName);
    strcat(monitor," --brightness ");
    sprintf(ch,"%.2f",BrightnessL);
    printf("number:%f\n",ch);
    strcat(monitor,ch);
 printf("%s\n",monitor);
  system(monitor);

   }

   //a function to change the screen resolution
  int screenResolutionChanger(){
  
  //options
  printf("\n Select screen resoution size\n\n");
  printf("   1 : 1024x576             ||                2: 1366x768\n\n");
  printf("   3 : 800x600              ||                4: 1280x720\n\n");
  printf("   5 : 1024x768             ||                6: 960x720\n\n");
  


  scanf("%i", &caseforsr);			//input
  
   switch(caseforsr)			//conditions for the input
     {
         case 1:
           system("xrandr --size 1024x576");			//a command line to set the screen resolution to option 1 	
           break;
           
         case 2:
           system("xrandr --size 1366x768");		//set the screen resolution to option 2
           
         case 3:
           system("xrandr --size 800x600");			//set the screen resolution to option 3

         case 4:
           system("xrandr --size 1280x720");		//set the screen resolution to option 4

         case 5:
           system("xrandr --size 1024x768");			//set the screen resolution to option 5

         case 6:
           system("xrandr --size 960x720");			//set the screen resolution to option 6
           
         default:
            printf("Not in the number range");		//input is out of options
            break;
           
    }


  }  


   // a function to listen to a keyboard action
int keyboardListener(){
 printf("Press any key from tthe keyboard");

 system(" xev | grep -A2 --line-buffered \'^KeyRelease\' \\		
    | sed -n \'/keycode /s/^.*keycode \\([0-9]*\\).* (.*, \\(.*\\)).*$/\\1 \\2/p\'");	
	//print out the key clicked and the keycode with it
}
  
   
