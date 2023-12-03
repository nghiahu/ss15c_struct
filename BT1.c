#include <stdio.h>

int main(){
	struct Student{
		int id;
		char name[50];
		int age;
		char phoneNumber[15];
		char email[100];
	};
	
	struct Student st1 = {1, "Ngo Huu Nghia", 18, "0948583775" , "nghia@gmail.com"};
	printf("%d\n",st1.id);
	printf("Name: %s\n",st1.name);
	printf("Age: %d\n",st1.age);
	printf("PhoneNumber: %s\n",st1.phoneNumber);
	printf("Email: %s",st1.email);
}
