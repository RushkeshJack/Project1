#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>

struct data{

 char FirstName[100],LastName[100],Mail[100];
 long long Number;

}person;

FILE *fp,*ft;

void addcontact()
{
    int o,opt;
    system("cls");
    fp=fopen("contactlist.txt","a");
    fflush(stdin);

    printf("\n\n\t----------Add Contact----------");

    printf("\n\n\tFirst Name : ");
    scanf("%[^\n]s",person.FirstName);
    fflush(stdin);

    printf("\n\tLast Name : ");
    scanf("%[^\n]s",person.LastName);
    fflush(stdin);

    printf("\n\tNumber : ");
    scanf("%lld",&person.Number);
    fflush(stdin);

    printf("\n\tMail : ");
    scanf("%s",person.Mail);

    fwrite(&person,sizeof(person),1,fp);

    fclose(fp);

    printf("\n\n\t\t\tWant to Add more contact \n\n\t  press [1] for Yes \t\t press [0] for No\t\t");
    scanf("%d",&opt);
    if(opt==1)
    {
        addcontact();
    }
    else
    {
        main();
    }

}
void viewcontact()
{
    int o;
    int k=1;
    system("cls");
    printf("\n\n\t----------View Contact----------\n\n");
    printf("\n\n\tS.N  \tFirst Name \tLast Name  \t\tNumber  \t\tMail\n\n");
    fp=fopen("contactlist.txt","r");

    while(fread(&person,sizeof(person),1,fp))
    {
        printf("\t%d",k);
        printf("\t%s",person.FirstName);
        printf("\t%s",person.LastName);
        printf("\t\t%lld",person.Number);
        printf("\t\t%s",person.Mail);
        printf("\n");
        k++;
    }

    fclose(fp);

    printf("\n\n\tEnter any key to continue : ");
    getch();
    main();
}

void searchcontact()
{
    int o,i,found=0;
    system("cls");
    printf("\n\n\t\t----------Search Contact----------\n\n");

    char Nametosearch[100],ch[100];
    printf("\n\tEnter the First Name to search : ");
    scanf("%s",ch);

    fp=fopen("contactlist.txt","r");

    while(fread(&person,sizeof(person),1,fp))
    {
        for(i=0;i<strlen(ch);i++)
        {
            Nametosearch[i]=person.FirstName[i];
        }

        if(strcmp(Nametosearch,ch)==0)
        {
            printf("\n\t\tMATCH FOUND!!");
            printf("\n\n");
            printf("\t\tFirst Name    : %s\n",person.FirstName);
            printf("\t\tLast Name     : %s\n",person.LastName);
            printf("\t\tMobile Number : %lld\n",person.Number);
            printf("\t\tMail ID       : %s\n",person.Mail);
            printf("\n");
            found++;
        }

    }
    fclose(fp);
    if(found==0)
    {
      printf("\n\t\tMATCH NOT FOUND!! :( \n");
    }

    printf("\n\tEnter any key to continue : ");
    getch();
    main();
}

void deletecontact()
{
    int o;
    system("cls");
    fflush(stdin);
    printf("\n\n\t\t----------Delete Contact----------\n\n");

    char dltfirstname[100],dltlastname[100];
    printf("\n\tEnter the First name to delete : ");
    scanf("%s",dltfirstname);
    printf("\n\tEnter the Last name to delete : ");
    scanf("%s",dltlastname);

    fflush(stdin);

    fp=fopen("contactlist.txt","r+");
    ft=fopen("temp.txt","a+");

    while(fread(&person,sizeof(person),1,fp)==1)
    {

        if(strcmp(dltfirstname,person.FirstName)==0 && strcmp(dltlastname,person.LastName)==0)
        {
           printf("\n\n\t\tContact is successfully Deleted !!\n\n");
        }
        else
        {
           fwrite(&person,sizeof(person),1,ft);
        }

    }

    fclose(fp);
    fclose(ft);

    remove("contactlist.txt");
    rename("temp.txt","contactlist.txt");

    printf("\n\tEnter any key to continue : ");
    getch();
    main();

}

int main()
{
    system("cls");
    int i,o;
    printf("\n\t------Contact management system------\n");
    printf("\n\t\t--> Main Menu <--");
    printf("\n\n\t 1.Add contact");
    printf("\n\t 2.View contact");
    printf("\n\t 3.Search contact");
    printf("\n\t 4.Delete contact");
    printf("\n\t 5.Exit");

    printf("\n\n\tEnter your choice = ");
    scanf("%d",&o);

    switch(o)
    {
        case 1:
            addcontact();
            break;
        case 2:
            viewcontact();
            break;
        case 3:
            searchcontact();
            break;
        case 4:
            deletecontact();
            break;
        case 5:
            system("cls");
            printf("\n\n\n\t\t'Thank You'\n\n\n");
            exit(1);
    }

    return 0;
}


