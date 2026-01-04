#include <stdio.h>
#include <stdlib.h>
/*BASILE FILIPPOS-IOANNIS it2024065*/

// Υπολογισμός της ημέρας της εβδομάδας

int get_dow(int day,int month,int year)
{
    int dow;
    if (month==2 || month==1)
    {
        month+=12;
        year-=1;
    }

    if (year<=0)  
    {
        printf("Unvalied year\n");
        return 64;
    }

    if ((year<1752) || (year==1752 && month<9) )
    {
        dow= (day+(13*(month+1))/5+year+year/4+5)%7;
    }

    if ((year>1752) || (year==1752 && month>9))
    {
        dow= (day+(13*(month+1))/5+year+year/4-year/100+year/400)%7;
    }

    if (year==1752 && month==9 && day<=2)
    {
        dow= (day+(13*(month+1))/5+year+year/4+5)%7;
    }
    else
    {
        dow= (day+(13*(month+1))/5+year+year/4-year/100+year/400)%7;
    }
    if (dow==0)
    {
        return dow+7;
    }else {
        return dow;
    }
    
}

// Συνάρτηση για την εκτύπωση μήνα

void month_calendar(int yr,int mo)
{
  
      char months[][12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
      int max_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};   // Οι ημέρες του κάθε μήνα (εκτός του φλεβάρη σε περίπτωση δίσεκτου έτους)
      int days;
    
      if (mo!=2) //Ελέγχουμε εαν έχουμε ως μήνα τον φεβρουάριο
      {
          days=max_days[mo-1];  
       }
       else {
        if ((yr<=1752 && yr%4==0) || (yr>1752 && yr%4==0 && yr%100!=0) || (yr>1752 && yr%400==0)) {  //  Ελέγχουμε εαν έχουμε δίσεκτο έτος
            days=max_days[mo-1]+1;
        }else {
            days=max_days[mo-1];
        }       
       }

       // Αναζήτηση 1ης μέρας του μήνα με τη βοήθεια της "get_dow" συνάρτησης

       int FirstDayOfTheWeek=get_dow(1,mo,yr);

       if (FirstDayOfTheWeek==64)  // Ελέγχουμε εαν έχουμε έγκυρο έτος
       {        
         exit(1);
       }

       printf("         %s\n",months[mo-1]);   // Αρχικά τυπώνουμε τον ζητούμενο μήνα με τη βοήθεια πίνακα.
       printf("Su Mo Tu We Th Fr Sa\n");    // Έπειτα τυπώνουμε τις ημέρες
       
    // Εκτύπωση κενών μέχρι τη πρώτη μέρα της εβδομάδας

       for (int i = 1; i < FirstDayOfTheWeek; i++)
       {
         printf("   ");
       }


       if (yr!=1752 || mo!=9 ) // Ελέγχουμε εαν έχουμε Σεπτέμβριο του 1752 όπου γίνεται η αλλαγή απο Ιουλιανό σε Γρηγοριανό
       {        
        for (int i = 1; i <= days; i++) // Μια επανάληψη απο τη πρώτη μέρα εως και τη τελευταία του ζητούμενου μήνα 
        {
            printf("%2d ",i);
            if ((FirstDayOfTheWeek+i-1)%7==0)  //Ελέγχουμε εαν έχει φτάσει ο μήνας στο Σάββατο ώστε να αλλάξουμε γραμμή
            {   
                    printf("\n");   
            } 
         }
      }else{  
        for (int i = 1; i <=days; i++)  
        {
           if (i<=2 || i>=14) //Παραλείπτονται οι μέρες ανάμεσα στο 2 και 14
           {
             printf("%2d ",i);
           }
           
          if ((FirstDayOfTheWeek+i-12)%7==0)
            {
                if (FirstDayOfTheWeek+i-12>0)
                {
                    printf("\n");
                }
            }
        }

    }  
     printf("\n"); 
       
}

// Συνάρτηση για την εκτύπωση ενός έτους

void year_calendar(int year)
{
    // Τυπώνουμε τα κατάλληλα κενά και το ζητούμενο έτος
    printf("%30s","");
    printf("%d",year);
    printf("\n");

    // Ορίζουμε τις κατάλληλες μεταβλητές οι οποίες είναι χρήσιμες για την υλοποίηση του αλγορίθμου
    // Οι μήνες σε πίνακα
    char months[][12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"}; 
    // Αρχικοποιούμε τους 3 πρώτους μήνες κάθε σειράς 
    int month1=1,month2=2,month3=3,days1,days2,days3,MaxDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};         
    int CurrentDay1,CurrentDay2,CurrentDay3,flag;

    //  Πραγματοποιούμε μια επανάληψη 4 φορές και θα τυπώνουμε τους μήνες ανα 3

    for (int i = 1; i <= 4 ; i++)  
       

    {
        // Οι τωρινές μέρες του κάθε μήνα
        CurrentDay1=1;
        CurrentDay2=1;
        CurrentDay3=1;


        //   Υπολογίζουμε τις ημέρες κάθε μήνα με τη βοήθεια του πίνακα που ορίσαμε
        days1=MaxDays[month1-1];
        days3=MaxDays[month3-1];
        if (month2!=2)
        {
          days2=MaxDays[month2-1];
        }else{
            if ((year<=1752 && year%4==0) || (year>1752 && year%4==0 && year%100!=0) || (year>1752 && year%400==0)) {
            days2=MaxDays[month2-1]+1;
        }else {
            days2=MaxDays[month2-1];
        }              
        }
        // Ύστερα υπολογίζουμε τη πρώτη μέρα κάθε μήνα
        int FDOTW1=get_dow(1,month1,year);
        if (FDOTW1==64)
        {
            exit(1);
        }
        int FDOTW2=get_dow(1,month2,year),FDOTW3=get_dow(1,month3,year);
        // Τυπώνουμε τους 3 μήνες και απο κάτω τις ημέρες της εβδομάδας
        printf("         %s                   %s                   %s\n",months[month1-1],months[month2-1],months[month3-1]);
        printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa\n");

        
        for (int spaces1 = 1; spaces1 < FDOTW1; spaces1++) // Τυπώνουμε κενά μέχρι τη πρώτη μέρα του μήνα
        {
            printf("   ");
        }

        for (int i1 = 1; i1 <=days1 ; i1++)

        {

            flag=0;
            printf("%2d ",i1);
            CurrentDay1++;
            
         if ((FDOTW1+i1-1)%7==0||(i1==days1))  //Ελέγχουμε εαν τελείωσε η εβδομάδα ή τελειώσε ο μήνας 1
         {
            if (((FDOTW1+i1-1)%7)!=0) // Εαν έχει τελειώσει ο μήνας και συνεχίζουμε τη συμπλήρωση ενός άλλου τυπώνουμε τα κατάλληλα κενά
            {
                for (int spaces = 0; spaces < 7-(FDOTW1+i1-1)%7; spaces++)
                {
                    printf("   ");
                }
                
            }
            
            printf(" ");
            if (FDOTW1+i1-1==7)  // Ελέγχουμε εαν τελείωσε η 1η εβδομάδα του μήνα 1
            {
                for (int spaces2 = 1; spaces2 < FDOTW2; spaces2++)  // Τότε τυπώνουμε τα κατάλληλα κενά μέχρι τη μέρα του μήνα 2
               {
                  if (flag==1)  
                  {
                      break;
                  }                
                
                 printf("   ");
                
               }
            }
            
            for (int i2 = CurrentDay2; i2 <= days2; i2++)
            {
                if (flag==1)
                {
                    break;
                }
                printf("%2d ",i2);
                CurrentDay2++;
                
                if (((FDOTW2+i2-1)%7==0)||(i2==days2))
                { 
                    if (((FDOTW2+i2-1)%7)!=0)
                    {
                        for (int spaces = 0; spaces < 7-(FDOTW2+i2-1)%7; spaces++)
                        {
                            printf("   ");
                        }
                        
                    }
                    
                    printf(" ");                                                  
                    for (int spaces3 = 1; spaces3 < FDOTW3; spaces3++)
                    {
                        if (flag==1)
                        {
                            break;
                        }
                        if (FDOTW2+i2-1==7)
                        {
                            printf("   ");
                        }
                          
                    }
                    if (CurrentDay3-1==days3)
                    {
                        printf("\n");
                        flag=1;
                    }
                    
                    for (int i3 = CurrentDay3; i3 <=days3; i3++)
                    {
                        if (year!=1752 || month3!=9)
                        {
                             printf("%2d ",CurrentDay3);
                             CurrentDay3++;
                        }else                                                                                          
                        {    
                            if (i3<=2)
                            {
                                printf("%2d ",CurrentDay3);
                                CurrentDay3++;
                            }
                            if (i3==3)
                            {
                                CurrentDay3+=11;
                            }
                            if (i3>3)
                            {
                                printf("%2d ",CurrentDay3);
                                CurrentDay3++;
                            }    
                        }
                        
                       if (year!=1752 || month3!=9)
                       {
                          if (((FDOTW3+i3-1)%7==0)||(i3==days3))
                        {
                            printf("\n");
                            flag=1;
                            
                            break;      
                        }
                       }else{

                        if ((FDOTW3+CurrentDay3-13)%7==0 || CurrentDay3-1==days3)
                        {
                            if ((FDOTW3+CurrentDay3-13)>0)
                            {
                                printf("\n");
                                flag=1;   
                                break;
                            }   
                        }
                       }   
                    }   
                }   
            }  
         }
         
        }
        
        if ((CurrentDay2-1!=days2)||(CurrentDay3-1!=days3))
        {
            
           if (flag==1)
           {
                for (int spaces = 0; spaces < 7; spaces++)
                {
                   printf("   ");
                }
                printf(" ");
           }else{
                for (int spaces = 0; spaces < 7-(FDOTW1+days1); i++)
                {
                    printf("   ");
                }
           }
                      
            if (CurrentDay2-1!=days2)
            {
                            
                  for (int i2 = CurrentDay2; i2 <= days2; i2++)
                {
                    
                    
                    
                      printf("%2d ",CurrentDay2);
                      CurrentDay2++;
                    
                 }
                 for (int spaces= 0; spaces < 7-(FDOTW2+days2-1)%7; spaces++)
                 {
                    printf("   ");
                 }
                     
            }else{
                for (int spaces = 0; spaces < 7; spaces++)
                {
                    printf("   ");
                }
                printf(" ");
                
            }
            
            if (CurrentDay3-1!=days3)
            {
                for (int i3 = CurrentDay3; i3 <=days3; i3++)
              {
                    printf("%2d ",CurrentDay3);
                    CurrentDay3++;
              }
            }
        }
        
     month1+=3;
     month2+=3;
     month3+=3;
     printf("\n");
     printf("\n");
    }
}

//Ο main κώδικάς μας

int main()
{
    int m,y; // m:μήνας , y:έτος
    int res;
    printf("Welcome to the calendar\n");
    printf("Year: ");
    scanf("%d",&y);
    printf("Month (0 to print entire year): ");
    res=scanf("%d",&m);
    if ( (res!=1) || (m>12) || (m<0) )   // Έλεγχος για την εγκυρότητα των τιμών
    {
        printf("Error reading a month\n");
        exit(1);
    }

    if (m>0)   // Περίπτωση 1 : Εκτύπωση ενός μήνα ενός έτους
    {
       month_calendar(y,m);
            
    }else if (m==0)     //  Περίπτωση 2 : Εκτύπωση ολόκληρου του ζητούμενου έτους

    {
       year_calendar(y);
    }
    
}
