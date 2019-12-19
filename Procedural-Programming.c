/*
 * ASM Procedural Programming x.c
 *
 *  Created on: Jun 25, 2017
 *      Author: Soi Lan Tron
 */
/*
 ============================================================================
 Name        : asm.c
 Author      : Soi Lan Tron
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

int i = 0;
typedef struct STUDENT
{

	char sID[8];
	char sName[30];
	/*int sDoB;
	int sMoB;
	int sYoB;*/
	char sDoB[11];
	char sEmail[30];
	char sPhone[14];
	char sAddress[50];
	int delete;
	int num;
}STUDENT;
STUDENT sList[50];



// count = continues
	int cont = 1;

	char select;



void getID(){
		int h,dem=0;                  // h, dem khoi tao = 0
		char compare[8];              // so sanh

		int length;
		while(1){                       // vong lap
			gets(sList[i].sID);

					strcpy(compare, sList[i].sID);    // coppy nguyen chuoi
					dem=0;							 // vong lap h -> i - so sanh tung mang struct trong bien so sanh vua so sanh neu giong thi tang bien dem len
					for (h = 0; h < i; h++){

						if (strcmp(compare,sList[h].sID) == 0){      // strcmp so sanh neu bang 0 thi bi trung  / cho y strcmp so sanh giong het luon
							printf("ID is duplicated. \n");
							dem++;
						break;
						}

						}

					if(dem!=1){             // neu ko bang 1 chay tiep


			length = strlen(sList[i].sID);   // strlen kiem tra do dai
			if (length !=7)
				printf(" The length of the id is wrong, please enter the whole id again: ");   // het code
				else{
					printf(" the length of the id is right");

					int result1, result2, result3;

					result1 = strncmp(sList[i].sID, "GC", 2);      // strncmp so sanh 2 ki tu dau tien cua chuoi
					result2 = strncmp(sList[i].sID, "GT", 2);

							int j = 2;           		// kiem tra ki tu thu 3
							do{
							result3 = isdigit(sList[i].sID[j]);      // kiem tra chuoi sau co phai so ko   - neu sai thi bang 0
							j++;
									if (result3 ==0)	         				// kiem tra co ki tu la chu thi result 3 = 0
									break;  								// break thoat khoi vong lap
								}		 while (j < strlen(sList[i].sID));     // kiem tra do dai chuoi

											if ((result1==0) || (result2==0)){
												printf(", The first 2 letter are true");
											if(result3 !=0){                               // neu chay vong lap do while neu 5 ki tu la so thi dung
												printf(", the remaining letter are right");
											break;
												}else
														printf(", Please check id follow GCxxxxx or GTxxxx (with 'GC' ,'GT' are UPPERCASE and remaining xxxx are digit):   \n CHECK the digit\t");    // kiem tra so
												}	else
															printf(", Please check id follow GCxxxxx or GTxxxx (with 'GC' ,'GT' are UPPERCASE and remaining xxxx are digit ):    \n CHECK UPPERCASE\t");   // kiem tra chu

							}
						}
				else{

					printf("Please retype another ID: \n");
				}

			}

	}
	
	/*  To determine if a character is a letter or digit, call isalnum( ).
To determine if a character is a letter, call isalpha( ).

To determine if a character is a digit, call isdigit( ).   */

void addnewstudent(){
	printf("ADD NEW STUDENT FUNCTION\n");
	printf("INPUT STUDENT %d\n", i+1);
	sList[i].num= i+1;                    // so thu tu num = No

	printf("Please input student ID:");
	fflush(stdin);
	getID();

	printf("Please input student Name:");
	fflush(stdin);
	gets(sList[i]. sName);


	printf("Please input student Birth:");
	fflush(stdin);
	gets(sList[i]. sDoB);


	printf("Please input student Email:");
	fflush(stdin);
	gets( sList[i]. sEmail);


	printf("Please input student Phone:");
	fflush(stdin);
	gets( sList[i]. sPhone);


	printf("Please input student Address:");
	fflush(stdin);
	gets( sList[i]. sAddress);

	printf(
			"No.\t  ID   \t    NAME    \t BIRTH DATE\t\t EMAIL \t \t\t    PHONE\t   ADDRESS\n");
	printf("%-3d\t%-7s\t%-20s\t%-10s\t%-30s\t%-10s\t%-50s\n", sList[i].num,
			sList[i].sID, sList[i].sName, sList[i].sDoB, sList[i].sEmail,
			sList[i].sPhone, sList[i].sAddress);
	i++;
	getch();
}



void viewstudent()
	{
		int m;


		 if (i!=0)   // %d in ra chu   %s in ra so      / if i != 0 thi  in ra     else i = 0 thi khong ton tai hoc sinh trong he thong
			{
			printf(
						"No.\t  ID   \t    NAME    \t BIRTH DATE\t\t EMAIL \t\t\t     PHONE\t   ADDRESS\n");
				for (m = 0; m < i; m++)   													// m tang tuan tu in ra tuan tu cac hoc sinh
				printf("%-3d\t%-7s\t%-20s\t%-10s\t%-30s\t%-10s\t%-50s\n", sList[m].num,
						sList[m].sID, sList[m].sName, sList[m].sDoB, sList[m].sEmail,
						sList[m].sPhone, sList[m].sAddress);
	//% chuoi dinh dang
			}
			else 	printf("Database no information\n");



	}



  void searchstudent()
	{

	 printf("3.Search student\n\n");
	 char searchName[30];
	 ;

	 viewstudent();
	 fflush(stdin);
		if (i==0){		// chay getch

			//	printf("Database no information");	
				getch();}      // getch dung man hinh
		else {
         
			 printf("please input student  name: \n ");


	 gets( searchName);

	printf(
	 						"No.\t  ID   \t    NAME    \t|BIRTH DATE\t\t EMAIL \t\t\t     PHONE\t   ADDRESS\n");
	 int l;
	 for (l = 0; l < i; l++)
	 	 {

		 if(strstr(searchName, sList[l]. sName) != NULL){       // strstr  - tuong tu so sanh


	 	 			printf("%-3d\t%-7s\t%-20s\t%-10s\t%-30s\t%-10s\t%-50s\n", sList[l].num,
	 	 								sList[l].sID, sList[l].sName, sList[l].sDoB, sList[l].sEmail,
	 	 								sList[l].sPhone, sList[l].sAddress);

	 	 	 		}
		 }
   	}

}




void deletestudent()
		{
	printf("4. Delete student \n");
	viewstudent();

	int l,j;
	char searchid[8];
	if (i==0){		// chay getch

		//	printf("Database no information");

	getch();}      // getch dung man hinh
	else {

	printf("4. Delete student: Please input student ID: \n");
	fflush(stdin);
	gets(/*"%c",  &inputID*/ searchid);
	printf(
	 						"No.\t  ID   \t    NAME    \t|BIRTH DATE\t\t EMAIL \t\t\t     PHONE\t   ADDRESS\n");

	for(l=0; l < i; l++){
		if(strcmp( sList[l]. sID, searchid)==0){
			printf("%-3d\t%-7s\t%-20s\t%-10s\t%-30s\t%-10s\t%-50s\n", sList[l].num,
				 	 								sList[l].sID, sList[l].sName, sList[l].sDoB, sList[l].sEmail,
				 	 								sList[l].sPhone, sList[l].sAddress);
			for (j = l; j < i; j++) {
				strcpy(sList[j].sID, sList[j + 1].sID);
				strcpy(sList[j].sName, sList[j + 1].sName);
				strcpy(sList[j].sDoB, sList[j + 1].sDoB);
				strcpy(sList[j].sEmail, sList[j + 1].sEmail);
				strcpy(sList[j].sPhone, sList[j + 1].sPhone);
				strcpy(sList[j].sAddress, sList[j + 1].sAddress);
		}
		i--;
		//	break;
		
	   }
			else
				{
								
									printf("Wrong ID, ID haven't in database', Please input another student ID:  \n");
									getch();

				}

	
			}
	}
}



void updatestudent(){
	printf("5. Update student: \n ");

	viewstudent();

		
	char searchid[8], block[50];
	int h,dem, check_enter= 0;

		if (i==0){		// chay getch

		//	printf("Database no information");

	getch();}      // getch dung man hinh
	else {

		printf("5. Search student. Input ID to search: ");
		fflush(stdin);


	while(1){

	gets(searchid);
		dem=0;
		for (h = 0; h < i; h++){     // kiem tra trung lap

					if (strcmp(searchid,sList[h].sID) == 0){

					dem++;
					break;
						}

						}

					if(dem==1){


		printf("Students which have the id %s is: \n", searchid);
		printf(
				"No.  ID   \t    NAME    \t BIRTH DATE \t\t EMAIL \t\t\t     PHONE   ADDRESS\n");

	 	 	printf("%-3d\t%-7s\t%-20s\t%-10s\t%-30s\t%-10s\t%-50s\n", sList[h].num,
	 	 								sList[h].sID, sList[h].sName, sList[h].sDoB, sList[h].sEmail,
	 	 								sList[h].sPhone, sList[h].sAddress);

				printf("old id is: %s\n", sList[h].sID);
				printf("press Enter to skip OR enter a new id ");
				while (1) {
					fflush(stdin);
					gets(block);
					check_enter = strlen(block);
					if (check_enter == 0 )
						break;
					else {

						if (check_enter != 7)
							printf(
									"the length of the id is wrong, please enter the whole id again: ");
						else {
							printf("the length of the id is right");
							int result1, result2, result3;
							result1 = strncmp(block, "GC", 2);
							result2 = strncmp(block, "GT", 2);
							int j = 2; //because you count from index=2(the first x character of digit characters xxxxx) in the array of student id
							do {
								result3 = isdigit(block[j]);
								j++;
								if (result3 == 0)
									break;
							} while (check_enter < strlen(block));
							if ((result1 == 0) || (result2 == 0)) {
								printf(", AND the first 2 letters are true");
								if (result3 != 0) {
									printf(
											", AND the remaining letters are right\n");
									strcpy(sList[h].sID, block);
									break;
								} else
									printf(
											", BUT the remaining letters are wrong, please enter the whole id again(the letters are digit): ");
							} else
								printf(
										", BUT the first 2 letters are wrong, please enter the whole id again(the letters are UPPERCASE): ");
						}
					}
				}

				printf("old name is: %s\n", sList[h].sName);
				printf("press Enter to skip OR enter a new name ");
				fflush(stdin);
				gets(block);
				check_enter = strlen(block); // kiem tra do dai block
				if (check_enter != 0)    // neu do dai block khac 0
					strcpy(sList[h].sName, block); // chen du lieu block vao name

				printf("old date of birth is: %s\n", sList[h].sDoB);
				printf("press Enter to skip OR enter a new date of birth ");
				fflush(stdin);
				gets(block);
				check_enter = strlen(block);  			// kiem tra do dai
				if (check_enter != 0)                    // kiem tra do dai neu ko nhap thi giu nguyen giu lieu
					strcpy(sList[h].sDoB, block);

				printf("old email is: %s\n", sList[h].sEmail);
				printf("press Enter to skip OR enter a new email ");
				fflush(stdin);
				gets(block);
				check_enter = strlen(block);
				if (check_enter != 0)
					strcpy(sList[h].sEmail, block);

				printf("old phone is: %s\n", sList[h].sPhone);
				printf("press Enter to skip OR enter a new phone ");
				fflush(stdin);
				gets(block);
				check_enter = strlen(block);
				if (check_enter != 0)
					strcpy(sList[h].sPhone, block);

				printf("old address is: %s\n", sList[h].sAddress);
				printf("press Enter to skip OR enter a new address ");
				fflush(stdin);
				gets(block);
				check_enter = strlen(block);
				if (check_enter != 0)
					strcpy(sList[h].sAddress, block);

		break;
	}
	else
	{

									printf("Wrong ID, ID haven't in database', Please input another student ID:  \n");

			}
}

}
}

void menu() {
	char choose; //the variable is used to read the key on the keyboard
	while (1) {	//the content of the while loop will be perform forever execpt that user press number 6
		system("cls");
		printf("===============MENU==============\n");
		printf("1. Add new student\n");
		printf("2. View all student\n");
		printf("3. Search student\n");
		printf("4. Delete student\n");
		printf("5. Update student\n");
		printf("6.EXIT\n");
		printf("=========================\n");



		printf("--------HELP---------");
		printf("This program is to help users to manage student's information\n");
		printf("there are 5 main functionalities\n\n");

		printf("Functionality 1: Add new students\n");
		printf("1.In order to add new student, user has to press 1 in the menu\n");
		printf("1.1 After pressing 1 in the menu, user need to fill in the following information\n");
		printf("1.2 1st information is User ID: each student has a unique ID, under the format of GTxxxxx or GCxxxxx\n");
		printf("1.3 If user input invalid ID or a wrong format ID, the program will inform message: incorrect ID format\n");
		printf("1.4 Noitice: If ID is duplicated, user should retype another ID\n\n");
	//	printf("1.5 The length of the id is wrong/ not UPPERCASE the first 2 letter/ and not fill enough 5 digit, user must retype ID \n\n");
		printf("Functionality 2: Press 2 on menu to view all student \n");
		printf("2.1 Noitice: If Database no information, user can't view \n\n");
		printf("Functionality 3: Press 3 on menu to search student you want  \n");
		printf("3.1 After press 3 in the menu, user should fill one of the name of student \n");
		printf("3.2 Noitice: If Database no information, user can't search \n\n");
		printf("Functionality 4: Press 4 on menu to delete student you want  \n");
		printf("4.1 After press 4 in the menu, user should fill one of the ID of student  \n");
		printf("4.2 Noitice: If Database no information, user can't delete\n");
		printf("4.3 Noitice: If user input Wrong ID / ID haven't in database', User shuould input another student ID\n\n");
		printf("Functionality 5: Press 5 on menu to update student you want  \n");
		printf("5.1 After press 5 in the menu, user should fill one of the ID of student  \n");
        printf("5.2 After that you choose a different ID/ Name/ DoB/ Email/ Phone/ Address you want to change \n");
        printf("5.3 Noitice: If Database no information, user can't update \n");
        printf("5.4 Noitice: If user input Wrong ID / ID haven't in database', User shuould input another student ID\n\n");
		printf("Functionality 6: Press 6 on menu to close program \n \n");

		printf("Please choose: ");	//require choose which function to do next
		fflush(stdin);
		choose = getchar();
		system("cls");
		
		switch(choose){
case '1':
		while(cont){
			addnewstudent();

			break;
		}
		break;



case '2':
		viewstudent();
		getch();
		break;
case '3': searchstudent();

	getch();
		break;

case '4': deletestudent();
			break;
case '5': updatestudent();
	break;
case '6':

	cont = 0;
	exit(0);
	 printf("6.Exit");

	break;


	}
}
}
void main(void)
{
	menu();
}







