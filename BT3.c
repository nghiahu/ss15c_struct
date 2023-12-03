#include <stdio.h>
struct Student{
    char name[50];
    int age;
    int phoneNumber;
    char email[100];
};
typedef struct Student st;
void insert(st *a, int i){
    printf("Name: ");
    getchar();
    gets((a + i)->name);
    printf("Age: ");
    scanf("%d", &((a + i)->age));
    printf("PhoneNumber: ");
    scanf("%d", &((a + i)->phoneNumber));
    printf("Email: ");
    getchar();
    gets((a + i)->email);
}
void print(st *a, int i){
    printf("Thong tin sinh vien %i la:\n", i);
    printf("Name");
    puts((a + i)->name);
    printf("Age:");
    printf("%d", ((a + i)->age));
    printf("PhoneNumber=");
    printf("\n%d\n", ((a + i)->phoneNumber));
    printf("Email");
    puts((a + i)->email);
}
int i;
void delete(st *a, int j, int count){
    for ( i = j; i < count; i++){
        *(a + i) = *(a + i + 1);
    }
}
struct Student studens[50];

int main(){
    int n, currentIndex = 0, index = 0,updateIndex=0;
    do
    {
        printf("1. Them sinh vien\n");
        printf("2. Sua\n");
        printf("3. Xoa\n");
        printf("4. In ra danh sach hoc sinh");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap so sinh vien muon them \n");
            getchar();
            scanf("%d", &n);
            for ( i = 0; i < n; i++)
            {
                insert(students,currentIndex);
                currentIndex++;
            }
            for ( i = 0; i < currentIndex; i++)
            {
                print(student, i);
            }
            break;
        case 2:
            printf("Nhap vi tri phan tu ban muon xoa");
            scanf("%d",&updateIndex);
            if (updateIndex>=0&&updateIndex<currentIndex)
            {
                insert(&student,updateIndex);
            }
            else{
                printf("Vi tri ko hop le");
            }
            break;
        case 3:
            printf("Nhap vi tri phan tu muon xoa trong mang\n");
            scanf("%d", &index);
            if (index < currentIndex)
            {
                delete (student, index, currentIndex);
                currentIndex--;
                for (int i = 0; i < currentIndex; i++)
                {
                    print(student, i);
                }
            }
            else{
                printf("phan tu do ko ton tai");
            }
            break;
        case 4:
        for (int i = 0; i < currentIndex; i++)
        {
            print(student,i);
        }
            break;
        default:
            break;
        }
    } while (1);
}
