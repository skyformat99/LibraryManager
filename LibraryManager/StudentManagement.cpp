/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "StudentManagement.h"
#include "StudentComponents.h"

/* Starting EditStudent SubMenu
Input : ESSubMenu		 choice
Output: choice
*/
 void ESSubMenu(int number) {
	//system("cls");
	int choice;
	while (true)
	{
		if (number > 0 && number <= studentcounter)
		{
			system("cls");
			printf("\n");
			printf("=================== TUY CHON CHINH SUA DOC GIA ==================\n");
			printf("           1. Tiep tuc chinh sua doc gia thu %d                  \n", number);
			printf("           2. Xem thong tin da chinh sua cua doc gia thu %d      \n", number);
			printf("           3. Thoat chinh sua                                    \n");
			printf("=================================================================\n");
			printf("    Nhap vao lua chon cua ban : ");
			scanf_s("%d", &choice);
			if (choice == 3) break;
			switch (choice)
			{
			case 1: StudentEditing(number); break;
			case 2: SeeLocalChanges(number); break;
			default: printf("Chuc nang ban nhap vao khong hop le ! \n");
				break;
			}
		}
		else
		{
			printf("Du lieu hoc sinh khong ton tai trong thu vien ! Vui long thu lai ..\n");
			Sleep(1000);
			break;
		}
	}
	//_getch();
}
/* Starting StudentDeclaraion
Input : LibraryID, Name, ID, Birth, Sex, Email, Address
Output : Initial first student informations
*/
 void StudentDeclaration() {
	while (true) {
		if (studentcounter >= Max) printf("Khong du bo nho de tao hoac cap nhat doc gia !");
		else
			while (studentcounter < Max)
			{
				printf(" ================= THONG TIN DOC GIA THU %d ===================\n", studentcounter + 1);
			 // Clear the caches
				// Input the informations
				printf("  -> Ma so doc gia thu %d : ", studentcounter + 1);
				gets_s(LibraryID[studentcounter]);
				printf("  -> Ten doc gia thu %d : ", studentcounter + 1);
				gets_s(Name[studentcounter]);
				printf("  -> CMND doc gia thu %d : ", studentcounter + 1);
				gets_s(ID[studentcounter]);
				printf("  -> Ngay thang nam sinh doc gia thu %d : ", studentcounter + 1);
				gets_s(Birth[studentcounter]);
				printf("  -> Gioi tinh doc gia thu %d (Nam hoac Nu) : ", studentcounter + 1);
				gets_s(Sex[studentcounter]);
				printf("  -> Email doc gia thu %d : ", studentcounter + 1);
				gets_s(Email[studentcounter]);
				printf("  -> Dia chi doc gia thu %d (luu y khong dung dau cham hay dau phay) : ", studentcounter + 1);
				gets_s(Address[studentcounter]);
				//Library card creating
				printf("  -> Nhap vao thoi gian lam the thu vien : \n");
				DayCreating();
				// Automatic evaluate expired time
				DayExpired();
				studentcounter++; break;
			}
		if (studentcounter >= 1) break;
	}
}
/* Starting DayCreate function
Input : None
Output: Day, month, year of library card for first use
*/
 void DayCreating() {
	printf("\t  -> Nhap ngay lap the : ");
	scanf_s("%d", &DayCre[studentcounter]);
	printf("\t  -> Nhap thang lap the : ");
	scanf_s("%d", &MonthCre[studentcounter]);
	printf("\t  -> Nhap nam lap the : ");
	scanf_s("%d", &YearCre[studentcounter]);
}
/* Starting DayExpired function with automatically evaluate the expiration
Input : DayCre, MonthCre, YearCre
Output: DayEx, MonthEx, YearEx
*/
 void DayExpired() {
	DayEx[studentcounter] = DayCre[studentcounter];
	MonthEx[studentcounter] = MonthCre[studentcounter];
	YearEx[studentcounter] = YearCre[studentcounter] + 4;
}
/* Starting StudentListing function
Input : None
Output : students list
*/
 void StudentListing() {
	printf("\t\t================ DANH SACH CAC DOC GIA THU VIEN ================\n\n");
	if (studentcounter <= 0) printf("Hien tai chua co hoc sinh nao trong du lieu thu vien. Vui long cap nhat hoac them doc gia !\n");
	else {
		for (int i = 0; i < studentcounter; i++) {
			printf("=============== THONG TIN DOC GIA THU %d ============= \n", i + 1);
			printf("\n");
			printf(" -> Ma thu vien la : ");
			puts(LibraryID[i]);
			printf(" -> Ten cua doc gia : ");
			puts(Name[i]);
			printf(" -> So CMND : ");
			puts(ID[i]);
			printf(" -> Ngay thang nam sinh : ");
			puts(Birth[i]);
			printf(" -> Gioi tinh : ");
			puts(Sex[i]);
			printf(" -> Email : ");
			puts(Email[i]);
			printf(" -> Dia chi : ");
			puts(Address[i]);
			printf(" -> Thoi gian lam the thu vien : %d/%d/%d\n", DayCre[i], MonthCre[i], YearCre[i]);
			printf(" -> Ngay het han  : %d/%d/%d\n", DayEx[i], MonthEx[i], YearEx[i]);
			printf("\n");
		}
	}
	_getch();
}
/* Starting StudentCreating function
Input : arrays with student informations
Output : student added
*/
void StudentCreating() {
	while (true)
	{
		system("cls");
		fflush(stdin);
		int choice;
		printf("===================== MENU TAO DOC GIA ========================\n");
		printf("                 -> 1. Tao doc gia moi                         \n");
		printf("                 -> 2. Thoat                                   \n");
		printf("===============================================================\n");
		printf("      -> Nhap vao lua chon cua ban : ");
		scanf_s("%d", &choice);
	if (choice==1)
	{
			if (studentcounter > Max) printf("Khong du bo nho de tao hoac cap nhat doc gia !");
			else
			{
				printf(" ============== THONG TIN DOC GIA THU  %d =============\n", studentcounter + 1);
				fflush(stdin);
				getchar();// Clear the caches
							   // Input the informations
				printf("  -> Ma so doc gia thu %d : ", studentcounter + 1);
				gets_s(LibraryID[studentcounter]);
				printf("  -> Ten doc gia thu %d : ", studentcounter + 1);
				gets_s(Name[studentcounter]);
				printf("  -> CMND doc gia thu %d : ", studentcounter + 1);
				gets_s(ID[studentcounter]);
				printf("  -> Ngay thang nam sinh doc gia thu %d : ", studentcounter + 1);
				gets_s(Birth[studentcounter]);
				printf("  -> Gioi tinh doc gia thu %d : ", studentcounter + 1);
				gets_s(Sex[studentcounter]);
				printf("  -> Email doc gia thu %d : ", studentcounter + 1);
				gets_s(Email[studentcounter]);
				printf("  -> Dia chi doc gia thu %d (luu y khong dung dau cham hay dau phay) : ", studentcounter + 1);
				gets_s(Address[studentcounter]);
				//Library card creating
				printf("  -> Nhap vao thoi gian lam the thu vien : \n");
				DayCreating();
				// Automatic evaluate expired time
				DayExpired();
				studentcounter++;
				Sleep(1000);
				printf("Tao doc gia moi thanh cong !");
				Sleep(500);
				break;
			}
		//	continue;
	}
	else if (choice == 2) break;
	else
	{
		printf("Lua chon khong phu hop ! Vui long thu lai !");
		Sleep(1000);
		continue;
	}
	}
}
/* Starting StudentEditing function
Input : student position
Output : local changed 
*/
 void StudentEditing(int number) {
	while (true)
	{
		if (number> 0 && number <= studentcounter)
		{
			int choice;
			printf("================ MENU CHINH SUA DOC GIA ===============\n");
			printf("  -> 1. Chinh sua Ma thu vien                          \n");
			printf("  -> 2. Chinh sua ten doc gia                          \n");
			printf("  -> 3. Chinh sua CMND cua doc gia                     \n");
			printf("  -> 4. Chinh sua ngay thang nam sinh cua doc gia      \n");
			printf("  -> 5. Chinh sua gioi tinh                            \n");
			printf("  -> 6. Chinh sua email                                \n");
			printf("  -> 7. Chinh sua dia chi                              \n");
			printf("  -> 8. Chinh sua thoi gian tao the thu vien           \n");
			printf("  -> 0. Huy bo chinh sua                               \n");
			printf("=======================================================\n");
			printf("   Nhap lua chon cua ban : ");
			scanf_s("%d", &choice);
			if (choice == 0) break;
			switch (choice)
			{
			case 8: {
				system("cls");
				fflush(stdin);
				int dayedit, monthedit, yearedit;
				printf("============ NOI DUNG CHINH SUA =============\n");
				printf(" -> Nhap ngay muon sua : ");
				scanf_s("%d", &dayedit);
				printf(" -> Nhap thang muon sua : ");
				scanf_s("%d", &monthedit);
				printf(" -> Nhap nam muon sua : ");
				scanf_s("%d", &yearedit);
				DayCre[number-1] = dayedit;
				MonthCre[number-1] = monthedit;
				YearCre[number-1] = yearedit;
				DayEx[number-1] = dayedit;
				MonthEx[number-1] = monthedit;
				YearEx[number-1] = yearedit + 4;
				
			} break;
			case 1: {
				getchar();
				fflush(stdin);
				char LibIDNew[25];
				printf("Nhap vao ma thu vien moi : ");
				gets_s(LibIDNew);
				strcpy_s(LibraryID[number - 1], LibIDNew);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 2: {
				getchar();
				fflush(stdin);
				char NewName[25];
				printf("Nhap vao ten moi : ");
				gets_s(NewName);
				strcpy_s(Name[number - 1], NewName);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 3: {
				getchar();
				fflush(stdin);
				char NewID[25];
				printf("Nhap vao CMND moi : ");
				gets_s(NewID);
				strcpy_s(ID[number - 1], NewID);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 4: {
				getchar();
				fflush(stdin);
				char NewBirth[25];
				printf("Nhap vao ngay thang nam sinh moi : ");
				gets_s(NewBirth);
				strcpy_s(Birth[number - 1], NewBirth);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 5: {
				getchar();
				fflush(stdin);
				char NewSex[25];
				printf("Nhap vao gioi tinh moi : ");
				gets_s(NewSex);
				strcpy_s(Sex[number - 1], NewSex);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 6: {
				getchar();
				fflush(stdin);
				char NewEmail[25];
				printf("Nhap email moi : ");
				gets_s(NewEmail);
				strcpy_s(Email[number - 1], NewEmail);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 7: {
				getchar();
				fflush(stdin);
				char NewAddress[50];
				printf("Nhap dia chi moi : ");
				gets_s(NewAddress);
				strcpy_s(Address[number - 1], NewAddress);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			default:
			{
				printf("Chuc nang ban nhap khong hop le! Vui long kiem tra lai.");
				Sleep(1000);
				break;
			}
			}
			system("cls");
		}
		else
		{
			printf("Du lieu hoc sinh khong ton tai hoac khong trung khop ! Vui long thoat ra va chon lai..\n");
			_getch();
			Sleep(1000);
		}
		break;
	}
}
/* Starting SeeLocalChanges function
Input : student position
Output: Student info */
 void SeeLocalChanges(int number) {
	printf("\n");
	printf("============== THONG TIN DOC GIA THU %d SAU KHI CHINH SUA =============\n", number);
	printf("\n");
	printf(" -> Ma thu vien la : ");
	puts(LibraryID[number-1]);
	printf(" -> Ten cua doc gia : ");
	puts(Name[number-1]);
	printf(" -> So CMND : ");
	puts(ID[number-1]);
	printf(" -> Ngay thang nam sinh : ");
	puts(Birth[number-1]);
	printf(" -> Gioi tinh : ");
	puts(Sex[number-1]);
	printf(" -> Email : ");
	puts(Email[number-1]);
	printf(" -> Dia chi : ");
	puts(Address[number-1]);
	printf(" -> Thoi gian lam the thu vien : %d/%d/%d\n", DayCre[number-1], MonthCre[number-1], YearCre[number-1]);
	printf(" -> Ngay het han  : %d/%d/%d\n", DayEx[number-1], MonthEx[number-1], YearEx[number-1]);
	Sleep(1000);
	_getch();
}
/*Starting StudentDelete function
Input: Student position
Output : Deleted student, listing student available*/
 void StudentDeleting(int number) {
	int flag = 0;
	if (number > 0 && number <= studentcounter)
	{
		char answer;
		fflush(stdin);
		getchar();
		printf("  -> Ban co chac chan muon xoa hay khong ? (Y) de xoa, (N) de huy bo. : ");
		answer = getchar();
		if (answer == 'y' || answer == 'Y')
		{
			for (int i = number - 1; i < studentcounter - 1; i++)
			{
				strcpy_s(LibraryID[i], LibraryID[i + 1]);
				strcpy_s(Name[i], Name[i + 1]);
				strcpy_s(ID[i], ID[i + 1]);
				strcpy_s(Birth[i], Birth[i + 1]);
				strcpy_s(Sex[i], Sex[i + 1]);
				strcpy_s(Email[i], Email[i + 1]);
				strcpy_s(Address[i], Address[i + 1]);
				//Timing library card
				DayCre[i] = DayCre[i + 1];
				MonthCre[i] = MonthCre[i + 1];
				YearCre[i] = YearCre[i + 1];
				// Timing expired card
				DayEx[i] = DayEx[i + 1];
				MonthEx[i] = MonthEx[i + 1];
				YearEx[i] = YearEx[i + 1];
			}
			studentcounter--; flag = 1;
		}
		else if (answer == 'n' || answer == 'N') return;
	}
	if (flag == 1) {
		printf("Xoa thanh cong !\n");
		printf("\n");
		Sleep(1000);
		StudentListing();
	}
	else
	{
		printf("Co loi khi xoa, vui long thu lai..");
		Sleep(1000);
	}
	
}
/* Starting SearchByID function
Input : Identity (ID) of student
Output : Student info
*/
 void SearchByID(char id[25]) {
	int flag = 0;
	printf("================ KET QUA TIM KIEM ==================\n");
	for (int i = 0; i < studentcounter; i++) {
		printf("\n");
		if (strcmp(id, ID[i]) == 0) {
			printf("   -> Ma doc gia : ");
			puts(LibraryID[i]);
			printf("   -> Ten doc gia : ");
			puts(Name[i]);
			printf("   -> CMND doc gia : ");
			puts(ID[i]);
			printf("   -> Ngay thang nam sinh : ");
			puts(Birth[i]);
			printf("   -> Gioi tinh : ");
			puts(Sex[i]);
			printf("   -> Email : ");
			puts(Email[i]);
			printf("   -> Dia chi : ");
			puts(Address[i]);
			printf("   -> Thoi gian lap the thu vien : %d/%d/%d\n", DayCre[i], MonthCre[i], YearCre[i]);
			printf("   -> Ngay het han : %d/%d/%d\n", DayEx[i], MonthEx[i], YearEx[i]);
			printf("====================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d hoc sinh duoc tim thay.\n", flag);
	}
	_getch();
}
/*Starting SearchByName function 
Input: Name student
Output : Student info if it matched
*/
 void SearchByName(char name[25]) {
	int flag = 0;
	printf("================ KET QUA TIM KIEM ==================\n");
	for (int i = 0; i < studentcounter; i++) {
		printf("\n");
		if (strcmp(name, Name[i]) == 0) {
			printf("   -> Ma doc gia : ");
			puts(LibraryID[i]);
			printf("   -> Ten doc gia : ");
			puts(Name[i]);
			printf("   -> CMND doc gia : ");
			puts(ID[i]);
			printf("   -> Ngay thang nam sinh : ");
			puts(Birth[i]);
			printf("   -> Gioi tinh : ");
			puts(Sex[i]);
			printf("   -> Email : ");
			puts(Email[i]);
			printf("   -> Dia chi : ");
			puts(Address[i]);
			printf("   -> Thoi gian lap the thu vien : %d/%d/%d\n", DayCre[i], MonthCre[i], YearCre[i]);
			printf("   -> Ngay het han : %d/%d/%d\n", DayEx[i], MonthEx[i], YearEx[i]);
			printf("====================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d hoc sinh duoc tim thay.\n", flag);
	}
	_getch();
}
