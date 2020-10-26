#include<stdio.h>
#include<conio.h>
#define question_number 80
#define data_length 92
#define data_number 3500


main()
{
    int i,j,k,n, int_temp, match_found,t;
    FILE *fileptr;
    char standard_ans[question_number];
    strcpy(standard_ans,"ABCDEAEDCABBEACDAABCDBCDAEDCABDCDEADAABBCCCCDEBEADEAEDABCDEABCDABCDEDDBCAAABBCDA");

    struct
    {
        int regi_number;
        char* hsc_board;
        int hsc_roll;
        int set_code;
        char std_answered[question_number+1];
    }student_profile[data_number];
    for(i=0;i<3500;i++)
    {
        student_profile[i].hsc_board="0";
    }
    printf("Scanning answerscripts ...");
    student_profile[0].regi_number = 20000+rand()%1000;
    strcpy(student_profile[0].std_answered,"ABCDEAE CABB ACDAABCDBCDAEDCABDC EADAABBCCCCDEBEADEAEDABCDEABCDA CDEDDBCAAABBCDA");
    for(i=1;i<3500;i++)
    {
        //repeat_rand:
        int_temp = 20000+rand()%(data_number+1);
        for(j=0;j<i;j++)
        {
            match_found = 0;
            if(student_profile[j].regi_number==int_temp)
            {
                match_found = 1;
                break;
                //goto repeat_rand;
            }
        }
        if(match_found==0)
        {
            student_profile[i].regi_number = int_temp;
        }
        else
        {
            i--;
        }

        for(j=0;j<30;j++)
        {
            int_temp = rand()%7;
            if(int_temp==0) student_profile[i].std_answered[j] = '*';
            else if(int_temp==1) student_profile[i].std_answered[j] = 'B';
            else if(int_temp==2) student_profile[i].std_answered[j] = 'C';
            else if(int_temp==3) student_profile[i].std_answered[j] = 'D';
            else if(int_temp==4) student_profile[i].std_answered[j] = 'E';
            else if(int_temp==5) student_profile[i].std_answered[j] = 'A';
            else student_profile[i].std_answered[j] = ' ';
        }
        for(j=30;j<80;j++)
        {
            student_profile[i].std_answered[j]= standard_ans[j];
        }
        student_profile[i].std_answered[j] = '\0';

    }

            for(j=0;j<2500;j++)
            {
                i=rand()%3500;
                int_temp = rand()%8;
            if(int_temp==0) student_profile[i].hsc_board = "DHA";
            else if(int_temp==1) student_profile[i].hsc_board = "RAJ";
            else if(int_temp==2) student_profile[i].hsc_board = "JES";
            else if(int_temp==3) student_profile[i].hsc_board = "COM";
            else if(int_temp==4) student_profile[i].hsc_board = "CHI";
            else if(int_temp==5) student_profile[i].hsc_board = "SYL";
            else if(int_temp==6) student_profile[i].hsc_board = "BAR";
            else if(int_temp==7) student_profile[i].hsc_board = "DIN";

            }
            for(i=0;i<3500;i++)
            {if(student_profile[i].hsc_board=="0")
            {
                int_temp = 8+rand()%3;
            if(int_temp==8) student_profile[i].hsc_board = "MAD";
            else if(int_temp==9) student_profile[i].hsc_board = "TEC";
            else if(int_temp==10) student_profile[i].hsc_board = "OTH";
            }
            }
     //student_profile[0].regi_number = 20000+rand()%(data_number+1);
     for(i=0;i<3500;i++)
     {
         student_profile[i].hsc_roll=100000+rand()%10001 ;
         student_profile[i].set_code=51+rand()%5;
     }

    printf("... done successfully.\n\n");

/*/
    for(i=0;i<10000;i++)
    {
        printf("%5d %s\n",student_profile[i].regi_number,student_profile[i].std_answered);
    }
//*/

     fileptr = fopen("C:\data_omr.txt","w");

     printf("Saving results in data_omr.txt ...");
     for(i=0;i<3500;i++)
     {
         fprintf(fileptr,"%d ",10000+i+1);
         fprintf(fileptr,"%d ",student_profile[i].regi_number);
         fprintf(fileptr,"%s ",student_profile[i].hsc_board);
         fprintf(fileptr,"%d ",student_profile[i].hsc_roll);
         fprintf(fileptr,"%d ",student_profile[i].set_code);
         fprintf(fileptr,"%s\n",student_profile[i].std_answered);
     }
     printf("... done successfully.\n\n");
     fclose(fileptr);

}
