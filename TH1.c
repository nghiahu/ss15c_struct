#include <stdio.h>
#include <string.h>


struct SinhVien {
    char ten[50];
    int maSV;
    float diemTB;
};

int main() {
    
    struct SinhVien sv1;
    strcpy(sv1.ten, "Nguyen Van A");
    sv1.maSV = 12345;
    sv1.diemTB = 8.5;

   
    printf("Thong tin sinh vien:\n");
    printf("Ten: %s\n", sv1.ten);
    printf("Ma sinh vien: %d\n", sv1.maSV);
    printf("Diem trung binh: %.2f\n", sv1.diemTB);

    return 0;
}
