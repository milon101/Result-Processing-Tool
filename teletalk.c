#include<stdio.h>
#define data_number 3500

main()
{
    int row,i,h,int_temp,a,b,match_found,n;
    float j[15],k=0;
   struct
    {
        int regi_number;
        char student_name[6];
        char mothers_name[6];
        char fathers_name[6];
        char *quota;
    }teletalk[4000];


    FILE *fileptr;
    fileptr = fopen("C:\stt_data.txt","w");
    fprintf(fileptr,"Serial number\t");
    fprintf(fileptr,"Admission roll\t");
    fprintf(fileptr,"Student Name\t");
    fprintf(fileptr,"    Mothers Name\t");
    fprintf(fileptr,"    Fathers Name\t");
    fprintf(fileptr,"H.S.C board\t");
    fprintf(fileptr,"h.s.c year\t");
    fprintf(fileptr,"BANGLA\t");
    fprintf(fileptr,"ENGLISH\t");
    fprintf(fileptr,"MATH\t");
    fprintf(fileptr,"PHYSICS\t");
    fprintf(fileptr,"CHEMISTRY\t");
    fprintf(fileptr,"BIOLOGY\t");
    fprintf(fileptr,"ICT\t");
    fprintf(fileptr,"   H.S.C GPA\t");

    fprintf(fileptr,"S.S.C board\t");
    fprintf(fileptr,"S.s.c year\t");
    fprintf(fileptr,"BANGLA\t");
    fprintf(fileptr,"ENGLISH\t");
    fprintf(fileptr,"MATH\t");
    fprintf(fileptr,"PHYSICS\t");
    fprintf(fileptr,"CHEMISTRY\t");
    fprintf(fileptr,"BIOLOGY\t");
    fprintf(fileptr," SOCIOLOGY\t");
    fprintf(fileptr," HIGHER MATH\t");
    fprintf(fileptr,"ISLAM\t");
    fprintf(fileptr,"COMPUTER\t");
    fprintf(fileptr,"S.S.C GPA\t");
    fprintf(fileptr,"QUOTA\n");
    for(i=0;i<3500;i++)
    {
        //
        //repeat_rand:
        int_temp = 20000+rand()%(data_number+1);
        for(n=0;n<i;n++)
        {
            match_found = 0;
            if(teletalk[n].regi_number==int_temp)
            {
                match_found = 1;
                break;
                //goto repeat_rand;
            }
        }
        if(match_found==0)
        {
            teletalk[i].regi_number = int_temp;
        }
        //
        if(match_found==1)
        {
            i--;
        }
        //*/
        for(a=0;a<7;a++)
        {
            int_temp=rand()%7;
            if(int_temp==0)teletalk[i].student_name[a]='A';
            else if(int_temp==1)teletalk[i].student_name[a]='B';
            else if(int_temp==2)teletalk[i].student_name[a]='C';
            else if(int_temp==3)teletalk[i].student_name[a]='D';
            else if(int_temp==4)teletalk[i].student_name[a]='E';
            else if(int_temp==5)teletalk[i].student_name[a]='F';
            else if(int_temp==6)teletalk[i].student_name[a]='G';

        }

        teletalk[i].student_name[a]='\0';
        for(a=0;a<7;a++)
        {
            int_temp=rand()%7;
            if(int_temp==0)teletalk[i].mothers_name[a]='A';
            else if(int_temp==1)teletalk[i].mothers_name[a]='B';
            else if(int_temp==2)teletalk[i].mothers_name[a]='C';
            else if(int_temp==3)teletalk[i].mothers_name[a]='D';
            else if(int_temp==4)teletalk[i].mothers_name[a]='E';
            else if(int_temp==5)teletalk[i].mothers_name[a]='F';
            else if(int_temp==6)teletalk[i].mothers_name[a]='G';

        }

        teletalk[i].mothers_name[a]='\0';
        for(a=0;a<7;a++)
        {
            int_temp=rand()%7;
            if(int_temp==0)teletalk[i].fathers_name[a]='A';
            else if(int_temp==1)teletalk[i].fathers_name[a]='B';
            else if(int_temp==2)teletalk[i].fathers_name[a]='C';
            else if(int_temp==3)teletalk[i].fathers_name[a]='D';
            else if(int_temp==4)teletalk[i].fathers_name[a]='E';
            else if(int_temp==5)teletalk[i].fathers_name[a]='F';
            else if(int_temp==6)teletalk[i].fathers_name[a]='G';

        }

        teletalk[i].fathers_name[a]='\0';
        int_temp=20000+rand()%1000;
        for(b=0;b<i;b++)
        {
            match_found=0;
            if(teletalk[b].regi_number==int_temp)
            {
                match_found=1;
                break;
            }
        }
        int_temp=rand()%69;
        if(int_temp==6)
            teletalk[i].quota="FFQ";
        else if(int_temp==60)
            teletalk[i].quota="EMQ";
        else if(int_temp==56)
            teletalk[i].quota="DIQ";
        else if(int_temp==35)
            teletalk[i].quota="WAQ";
        else
            teletalk[i].quota="GEN";
    }

        printf("%s",teletalk[1].quota);
    for(row=0;row<3500;row++)
    {
        fprintf(fileptr,"%5d\t",10001+row);
        fprintf(fileptr,"%13d\t",20000+row);
        fprintf(fileptr,"%27s\t",teletalk[row].student_name);
        fprintf(fileptr,"%12s\t",teletalk[row].mothers_name);
        fprintf(fileptr,"%11s\t",teletalk[row].fathers_name);
        fprintf(fileptr,"%14s\t","SYLHET");
        fprintf(fileptr,"%8d\t",h=2012+rand()%2);
        fprintf(fileptr,"%8.2f\t",j[0]=2.5+rand()%3);k+=j[0];
        fprintf(fileptr,"%.2f\t",j[1]=2.5+rand()%3);k+=j[1];
        fprintf(fileptr,"%.2f\t",j[2]=2.5+rand()%3);k+=j[2];
        fprintf(fileptr,"%.2f\t",j[3]=2.5+rand()%3);k+=j[3];
        fprintf(fileptr,"%.2f\t",j[4]=2.5+rand()%3);k+=j[4];
        fprintf(fileptr,"%8.2f\t",j[5]=2.5+rand()%3);k+=j[5];
        fprintf(fileptr,"%.2f\t",j[6]=2.5+rand()%3);k+=j[6];
        k=(k-2)/6;
        fprintf(fileptr,"%.2f\t",k);

        fprintf(fileptr,"%10s\t","sylhet");
        fprintf(fileptr,"%8d\t",h-2);
        fprintf(fileptr,"%8.2f\t",j[0]=2.5+rand()%3);k+=j[0];
        fprintf(fileptr,"%.2f\t",j[1]=2.5+rand()%3);k+=j[1];
        fprintf(fileptr,"%.2f\t",j[2]=2.5+rand()%3);k+=j[2];
        fprintf(fileptr,"%.2f\t",j[3]=2.5+rand()%3);k+=j[3];
        fprintf(fileptr,"%4.2f\t",j[4]=2.5+rand()%3);k+=j[4];
        fprintf(fileptr,"%8.2f\t",j[5]=2.5+rand()%3);k+=j[5];
        fprintf(fileptr,"%5.2f\t",j[6]=2.5+rand()%3);k+=j[6];
        fprintf(fileptr,"%9.2f\t",j[7]=2.5+rand()%3);k+=j[7];
        fprintf(fileptr,"%12.2f\t",j[8]=2.5+rand()%3);k+=j[8];
        fprintf(fileptr,"%8.2f\t",j[9]=2.5+rand()%3);k+=j[9];
        k=(k-2)/9;
        fprintf(fileptr,"%.2f\t",k);
        fprintf(fileptr,"%7s\n",teletalk[row].quota);

        //printf("%.1f\n",k);

    }
    /*/
    for(i=0;i<5000;i++)
    {
        //printf("%d",teletalk[i].num);
        printf("%s\t",teletalk[i].student_name);
        printf("%s\t",teletalk[i].mothers_name);
        printf("%s\t",teletalk[i].fathers_name);
        printf("\n");
    }
//*/
    fclose(fileptr);
}
