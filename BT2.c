#include <stdio.h>
int main(){
	struct Student{
		char name[50];
		int age;
		char phoneNumber[15];
		char email[100]
	};
	fflush(stdin);
	struct Student st1;
	printf("Name = ");
	gets(st1.name);
	printf("Age = ");
	scanf("%d",&st1.age);
	fflush(stdin);
	printf("PhoneNumber = ");
	gets(st1.phoneNumber);
	printf("Email = ");
	gets(st1.email);
	
	printf("\nName: %s\n",st1.name);
	printf("Age: %d\n",st1.age);
	printf("PhoneNumber: %s\n",st1.phoneNumber);
	printf("Email: %s\n",st1.email);
	
	return 0;
}
