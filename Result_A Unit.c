#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define question_number 80
#define data_number 3500
#define data_length 92
#define row 2
#define column data_number

    struct
    {
    int serial_number;
    int regi_number;
    char hsc_board[4];
    int hsc_roll;
    int set_code;
    char student_ans[question_number];
    int correct_ans;
    int wrong_ans;
    int not_answered;
    float student_marks;
        int admission_roll;
        int hsc_year;
        float hsc_gpa;
        float ssc_gpa;
        char line[300];
        char quota[3];
    }student_profile[data_number];
    struct
    {
        int regi_number;
        float total_marks;
        int position;

    }merit_list[data_number];
    struct
    {
        int regi_number;
        int correct_ans;
        int wrong_ans;
        int not_answered;
        float student_marks;
        char quota[3];

    }student_profile_quota[data_number];

main()
{

    char temp[5],temp1[6];
    int i,j,k,n,use;
    int index[2][column];

    char standard_ans[question_number];
    strcpy(standard_ans,"ABCDEAEDCABBEACDAABCDBCDAEDCABDCDEADAABBCCCCDEBEADEAEDABCDEABCDABCDEDDBCAAABBCDA");


    standard_ans[80]='\0';
for(i=0;i<data_number;i++)
{

     student_profile[i].correct_ans=0;
     student_profile[i].wrong_ans=0;
     student_profile[i].not_answered=0;
}

     FILE *fileptr;
     fileptr = fopen("C:\data_omr.txt","r");

// Initializing result struct
    printf("Reading file omr.txt ...");

    for(i=0;i<data_number;i++)
    {
        char temp[6],temp1[7],temp2[3];

        for(j=0;j<5;j++)
          {
              fscanf(fileptr,"%c",&temp[j]);
          }
        temp[j]='\0';
        student_profile[i].serial_number = atoi(temp);

        fscanf(fileptr,"%c");

        for(j=0;j<5;j++)
          {
              fscanf(fileptr,"%c",&temp[j]);
          }
        temp[j]='\0';
        student_profile[i].regi_number = atoi(temp);
        fscanf(fileptr,"%c");
        for(j=0;j<3;j++)
        {
           fscanf(fileptr,"%c",&student_profile[i].hsc_board[j]);
        }
        student_profile[i].hsc_board[j]='\0';
        fscanf(fileptr,"%c");
        for(j=0;j<6;j++)
        {
           fscanf(fileptr,"%c",&temp1[j]);
        }
        temp1[j]='\0';
        student_profile[i].hsc_roll=atoi(temp1);
        fscanf(fileptr,"%c");
        for(j=0;j<2;j++)
        {
           fscanf(fileptr,"%c",&temp[j]);
        }
        temp[j]='\0';
        student_profile[i].set_code=atoi(temp);
        fscanf(fileptr,"%c");

        for(j=0;j<80;j++)
        {
            fscanf(fileptr,"%c",&student_profile[i].student_ans[j]);
        }
        student_profile[i].student_ans[j]='\0';
        fscanf(fileptr,"\n");

   // compare with standard answer.
    }
    printf("... done successfully.\n\n");

    fileptr = fopen("C:\stt_data.txt","r");

    for(i=0;i<286;i++)
    {
        fscanf(fileptr,"%c",&student_profile[0].line[i]);
    }
    fscanf(fileptr,"\n");
for(i=0;i<3500;i++)
{
    for(j=0;j<14;j++)
    {
        fscanf(fileptr,"%c");
        //printf("%c",student_profile[i].fourth[j]);
    }
    for(j=0;j<5;j++)
    {
        fscanf(fileptr,"%c",&temp1[j]);
        //printf("%c",temp1[j]);
    }
    temp1[j]='\0';
        student_profile[i].admission_roll=atoi(temp1);
    for(j=0;j<74;j++)
    {
        fscanf(fileptr,"%c");
    }
    for(j=0;j<4;j++)
    {
        fscanf(fileptr,"%c",&temp[j]);
    }
    temp[j]='\0';
    student_profile[i].hsc_year=atoi(temp);
    for(j=0;j<44;j++)
    {
        fscanf(fileptr,"%c");
    }
    for(j=0;j<4;j++)
    {
        fscanf(fileptr,"%c",&temp[j]);
        //printf("%c",temp[j]);
    }
    student_profile[i].hsc_gpa=atof(temp);
    for(j=0;j<97;j++)
    {
        fscanf(fileptr,"%c");
        //printf("%c",student_profile[0].third[j]);
    }
    //printf("\n");
    for(j=0;j<4;j++)
    {
        fscanf(fileptr,"%c",&temp[j]);

    }
    temp[j]='\0';
    student_profile[i].ssc_gpa=atof(temp);
    for(j=0;j<5;j++)
    {
        fscanf(fileptr,"%c");
    }
    for(j=0;j<4;j++)
    {
        fscanf(fileptr,"%c",&student_profile[i].quota[j]);
        //printf("%c",student_profile[i].quota[j]);
    }
    student_profile[i].quota[j]='\0';
    fscanf(fileptr,"\n");
    /*/
    printf("\n%d",student_profile[i].admission_roll);
    printf("\n%d",student_profile[i].hsc_year);
    printf("\n%.2f",student_profile[i].hsc_gpa);
    printf("\n%.2f",student_profile[i].ssc_gpa);
    //*/
}


int an_temp;
float an_temp1;
char an_temp2[3];
   for(i=0;i<data_number;i++)
   {
       for(j=0;j<3500;j++)
       {
           if(student_profile[i].regi_number==student_profile[j].admission_roll)
           {
               an_temp=student_profile[j].admission_roll;
               student_profile[j].admission_roll=student_profile[i].admission_roll;
               student_profile[i].admission_roll=an_temp;

               an_temp=student_profile[j].hsc_year;
               student_profile[j].hsc_year=student_profile[i].hsc_year;
               student_profile[i].hsc_year=an_temp;

               an_temp1=student_profile[j].hsc_gpa;
               student_profile[j].hsc_gpa=student_profile[i].hsc_gpa;
               student_profile[i].hsc_gpa=an_temp1;

               an_temp1=student_profile[j].ssc_gpa;
               student_profile[j].ssc_gpa=student_profile[i].ssc_gpa;
               student_profile[i].ssc_gpa=an_temp1;

               for(k=0;k<3;k++)
               {
                   an_temp2[k]=student_profile[j].quota[k];
                   student_profile[j].quota[k]=student_profile[i].quota[k];
                   student_profile[i].quota[k]=an_temp2[k];
               }



           }
       }
   }



//.........................................

    printf("Procesing results ...");

for(i=0;i<data_number;i++)
{

    for(k=0;k<(question_number);k++)
        {
            if(student_profile[i].student_ans[k]==standard_ans[k])
                 student_profile[i].correct_ans++;
            else if(student_profile[i].student_ans[k]==' ')
                 student_profile[i].not_answered++;
            else
                 student_profile[i].wrong_ans++;
        }
    for(j=0;j<data_number;j++)
        {
            if(student_profile[i].regi_number==student_profile[j].admission_roll)
            {
                if(student_profile[j].hsc_year==2012)
                     student_profile[i].student_marks=(2.7*(student_profile[j].ssc_gpa+student_profile[j].hsc_gpa))+student_profile[i].correct_ans-(.25*student_profile[i].wrong_ans);
                else
                     student_profile[i].student_marks=(3.00*(student_profile[j].ssc_gpa+student_profile[j].hsc_gpa))+(student_profile[i].correct_ans-(.25*student_profile[i].wrong_ans));
            }

         }
}
//Quota processing.........................................
char quota[3]={'G','E','N'};
char quota_e[3]={'E','M','Q'};
char quota_d[3]={'D','I','Q'};
char quota_w[3]={'W','A','Q'};
char quota_f[3]={'F','F','Q'};
int qu=0,qu_match;
for(i=0,qu=0;i<3500;i++)
{
           if(quota[0]!=student_profile[i].quota[0])
           {
               //for(;qu<3500;qu++)
               {
               student_profile_quota[qu].regi_number=student_profile[i].regi_number;
               student_profile_quota[qu].correct_ans=student_profile[i].correct_ans;
               student_profile_quota[qu].not_answered=student_profile[i].not_answered;
               student_profile_quota[qu].wrong_ans=student_profile[i].wrong_ans;
               student_profile_quota[qu].student_marks=student_profile[i].student_marks;
               for(j=0;j<3;j++)
               {
                   student_profile_quota[qu].quota[j]=student_profile[i].quota[j];
               }
               qu++;
               //break;
               }
           }
}



//printing full quota list..........................

    fileptr = fopen("C:\quota_list.txt","w");
    fprintf(fileptr," QUOTA MERIT LIST..........................................\n\n");
    for(i=0;i<191;i++)
    {
        fprintf(fileptr,"%d\t",student_profile_quota[i].regi_number);
        fprintf(fileptr,"%d\t",student_profile_quota[i].correct_ans);
        fprintf(fileptr,"%d\t",student_profile_quota[i].not_answered);
        fprintf(fileptr,"%d\t",student_profile_quota[i].wrong_ans);
        fprintf(fileptr,"%.2f\t",student_profile_quota[i].student_marks);
        fprintf(fileptr,"%s\n",student_profile_quota[i].quota);
    }
    fclose(fileptr);

//*/
    printf("... done successfully.\n\n");


    printf("Saving results in data.results.txt ...");

//Sorting w.r.t. regi. no.--------------------------------------------------------------

     int  sort_temp, sort_temp1 ;
     for(i=0;i<column;i++)
     {
         for(j=0;j<2;++j)
         {
             index[0][i]=student_profile[i].regi_number;
             index[1][i]=i;
         }
         merit_list[i].regi_number=student_profile[i].regi_number;
         merit_list[i].total_marks=student_profile[i].student_marks;

         //merit_list[i].position=i+1;
     }
    //Bubble sorting is applieed on one first row while the other row is swapped

     for(j=1;j<column;j++)
     {
          for(i=0; i<column-1; i++)
          {
                if(index[0][i]>index[0][i+1])
                {
                    sort_temp=index[0][i];
                    index[0][i]=index[0][i+1];
                    index[0][i+1]=sort_temp;

                    sort_temp1 = index[1][i];
                    index[1][i] = index[1][i+1];
                    index[1][i+1]=sort_temp1;
                }
          }
     }

   float least, float_temp,greatest;
   int target,meri_temp;
   char sort_quota[3];
   for(i=0;i<data_number-1;i++)
   {
       greatest=merit_list[i].total_marks;
       target=i;
       for(j=i+1;j<data_number;j++)
       {
           if(greatest<merit_list[j].total_marks)
           {
               greatest=merit_list[j].total_marks;
               target=j;
           }
       }
       float_temp=merit_list[i].total_marks;
       merit_list[i].total_marks=merit_list[target].total_marks;
       merit_list[target].total_marks=float_temp;

       meri_temp=merit_list[i].regi_number;
       merit_list[i].regi_number=merit_list[target].regi_number;
       merit_list[target].regi_number=meri_temp;


   }

   for(i=0;i<data_number-1;i++)
   {
       greatest=student_profile_quota[i].student_marks;
       target=i;
       for(j=i+1;j<data_number;j++)
       {
           if(greatest<student_profile_quota[j].student_marks)
           {
               greatest=student_profile_quota[j].student_marks;
               target=j;
           }
       }
       float_temp=student_profile_quota[i].student_marks;
       student_profile_quota[i].student_marks=student_profile_quota[target].student_marks;
       student_profile_quota[target].student_marks=float_temp;

       meri_temp=student_profile_quota[i].regi_number;
       student_profile_quota[i].regi_number=student_profile_quota[target].regi_number;
       student_profile_quota[target].regi_number=meri_temp;

       for(j=0;j<3;j++)
       {
           sort_quota[j]=student_profile_quota[i].quota[j];
           student_profile_quota[i].quota[j]=student_profile_quota[target].quota[j];
           student_profile_quota[target].quota[j]=sort_quota[j];

       }

   }







//-------------------------------------------------------------------Sorting ends
merit_list[0].position=1;
    for(i=1,j=1;i<data_number;i++)
    {     if( merit_list[i].total_marks!=merit_list[i-1].total_marks)
          {
             j++;
          }
          merit_list[i].position=j;
    }



//
    fileptr = fopen("C:\data_result.txt","w");

    fprintf(fileptr,"Serial No. \t Reg.No. \t Correct Ans. \t Wrong Ans. \t Not Answered\n");
    fprintf(fileptr,"---------- \t ------- \t ------------ \t ---------- \t ------------\n");
    for(i=0;i<data_number;i++)
    {
        sort_temp1=index[1][i];
        fprintf(fileptr,"%d ",student_profile[sort_temp1].serial_number);
        fprintf(fileptr,"%12d ",index[0][i]);
        fprintf(fileptr,"%8d ",student_profile[sort_temp1].correct_ans);
        fprintf(fileptr,"%15d ",student_profile[sort_temp1].wrong_ans);
        fprintf(fileptr,"%15d",student_profile[sort_temp1].not_answered);
        fprintf(fileptr,"\n");
    }

    printf("... done successfully.\n\n");

    printf("Writing the file merit_list.txt ...");

    fileptr = fopen("C:\merit_list.txt","w");
    fprintf(fileptr,"Regi Number\t Total Marks\t Merit List\n");
    for(i=0;i<data_number;i++)
    {
        fprintf(fileptr,"%d ",merit_list[i].regi_number);
        fprintf(fileptr,"%14.4f ",merit_list[i].total_marks);
        fprintf(fileptr,"%12d ",merit_list[i].position);
        fprintf(fileptr,"\n");
        //for(j=0;j<10;j++)
    }
    fclose(fileptr);

    printf("... done successfully.\n\n");

    printf("Building given_merit_list.txt ...");


    fileptr = fopen("C:\given_merit_list.txt","w");
    fprintf(fileptr," MERIT LIST...........................................\n\n");
    int z,x;
    k=100;
    for(i=0;i<100;i++)
    {
        x=1;
        k=(15*i);
        z=k;
        for(j=z;j<(15+k);j++)
            {
                if(merit_list[j].position!=merit_list[j-1].position)
                {
                    fprintf(fileptr,"%6d(%3d) ",merit_list[j].regi_number,merit_list[j].position);
                    x=1;
                    fprintf(fileptr,"\t");
                }
                else
                {
                    sort_temp=merit_list[j-1].position;
                }
                 if(merit_list[j].position==sort_temp)
                {
                    for(;x<15;x++)
                    {
                        fprintf(fileptr,"%6d(%3d_%d) ",merit_list[j].regi_number,merit_list[j].position,x);
                        fprintf(fileptr,"\t");
                        x++;
                        break;
                    }
                }
            }
        fprintf(fileptr,"\n");
    }
    fprintf(fileptr,"\n\nEMQ MERIT LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j==5)
        {
        break;
        }
        if(quota_e[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
            j++;
        }

    }
    fprintf(fileptr,"\n\nFFQ MERIT LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j==5)
        {
        break;
        }
        if(quota_f[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
            j++;
        }

    }

    fprintf(fileptr,"\n\nDIQ MERIT LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j==5)
        {
        break;
        }
        if(quota_d[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
            j++;
        }

    }

    fprintf(fileptr,"\n\nWAQ MERIT LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j==5)
        {
        break;
        }
        if(quota_w[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
            j++;
        }

    }

    fclose(fileptr);

    printf("... done successfully.\n\n");

    printf("Building waiting_list.txt ...");

    fileptr = fopen("C:\waiting_list.txt","w");
    fprintf(fileptr," WAITING LIST..........................................\n\n");
    for(i=0;i<200;i++)
    {
        x=1;
        k=(1500+10*i);
        z=k;
        for(j=z;j<(10+k);j++)
            {
                if(merit_list[j].position!=merit_list[j-1].position)
                {
                    fprintf(fileptr,"%6d(%3d) ",merit_list[j].regi_number,merit_list[j].position);
                    x=1;
                    fprintf(fileptr,"\t");
                }
                else
                {
                    sort_temp=merit_list[j-1].position;

                }
                 if(merit_list[j].position==sort_temp)
                {
                    for(;x<15;x++)
                    {
                        fprintf(fileptr,"%6d(%3d_%d) ",merit_list[j].regi_number,merit_list[j].position,x);
                        fprintf(fileptr,"\t");
                        x++;
                        break;
                    }
                }
            }
        fprintf(fileptr,"\n");
    }

    fprintf(fileptr,"\n\nEMQ WAITING LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j>=5)
        {

        if(quota_e[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
        }
        }
        j++;
    }
    fprintf(fileptr,"\n\nFFQ WAITING LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j>=5)
        {

        if(quota_f[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
        }
        }
        j++;
    }

    fprintf(fileptr,"\n\nDIQ WAITING LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j>=5)
        {

        if(quota_d[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
        }
        }
        j++;

    }

    fprintf(fileptr,"\n\nWAQ WAITING LIST.............\n\n");
    for(i=0,j=0;i<191;i++)
    {
        if(j>=5)
        {

        if(quota_w[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d(%d)\t",student_profile_quota[i].regi_number,j+1);
        }
        }
        j++;

    }


    fclose(fileptr);


    fileptr = fopen("C:\sort_quota_list.txt","w");
    fprintf(fileptr,"SORTED QUOTA LIST...........................\n");
    for(i=0;i<191;i++)
    {
            fprintf(fileptr,"%d\t",student_profile_quota[i].regi_number);
            fprintf(fileptr,"%.2f\t",student_profile_quota[i].student_marks);
            fprintf(fileptr,"%s\n",student_profile_quota[i].quota);
    }
    fileptr = fopen("C:\sort_EMQ_quota_list.txt","w");
    fprintf(fileptr,"SORTED EMQ QUOTA LIST...........................\n");
    for(i=0;i<191;i++)
    {
        if(quota_e[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d\t",student_profile_quota[i].regi_number);
            fprintf(fileptr,"%.2f\t",student_profile_quota[i].student_marks);
            fprintf(fileptr,"%s\n",student_profile_quota[i].quota);
        }

    }
    fileptr = fopen("C:\sort_FFQ_quota_list.txt","w");
    fprintf(fileptr,"SORTED FFQ QUOTA LIST...........................\n");
    for(i=0;i<191;i++)
    {
        if(quota_f[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d\t",student_profile_quota[i].regi_number);
            fprintf(fileptr,"%.2f\t",student_profile_quota[i].student_marks);
            fprintf(fileptr,"%s\n",student_profile_quota[i].quota);
        }

    }
    fileptr = fopen("C:\sort_DIQ_quota_list.txt","w");
    fprintf(fileptr,"SORTED DIQ QUOTA LIST...........................\n");
    for(i=0;i<191;i++)
    {
        if(quota_d[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d\t",student_profile_quota[i].regi_number);
            fprintf(fileptr,"%.2f\t",student_profile_quota[i].student_marks);
            fprintf(fileptr,"%s\n",student_profile_quota[i].quota);
        }

    }
    fileptr = fopen("C:\sort_waq_quota_list.txt","w");
    fprintf(fileptr,"SORTED WAQ QUOTA LIST...........................\n");
    for(i=0;i<191;i++)
    {
        if(quota_w[0]==student_profile_quota[i].quota[0])
        {
            fprintf(fileptr,"%d\t",student_profile_quota[i].regi_number);
            fprintf(fileptr,"%.2f\t",student_profile_quota[i].student_marks);
            fprintf(fileptr,"%s\n",student_profile_quota[i].quota);
        }

    }

    printf("... done successfully.\n\n");

fclose(fileptr);

}
