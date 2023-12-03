#include <stdio.h>
#include <string.h>

struct Book
{
    int code;
    char title[50];
    char author[50];
    float price;
    char category[50];
};

void displayBook(struct Book arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Code: %d\n", arr[i].code);
        printf("Tên Sách: %s\n", arr[i].title);
        printf("Tác Gi?: %s\n", arr[i].author);
        printf("Giá Ti?n: %f\n", arr[i].price);
        printf("Th? Lo?i: %s\n", arr[i].category);
        printf("------------------\n");
    }
}

int searchBook(struct Book arr[], int size, char answer[50])
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].title, answer) == 0)
        {
            index = i;
        }
    }
    return index;
}
int searchBookByAuthor(struct Book arr[], int size, char answer[50]);

int main()
{
    struct Book book1 = {1, "Harry Potter", "JK Rowling", 20, "fiction"};
    struct Book book2 = {2, "Tôi th?y hoa vàng trên c? xanh", "Nguy?n Nh?t Ánh", 20, "romance"};

    struct Book bookList[100] = {book1, book2};
    int currentSize = 2;

    int choice;
    while (choice != 6)
    {
        printf("************* MENU *************\n");
        printf("1. Thông tin sách trong c?a hàng\n");
        printf("2. C?p nh?t thông tin sách (Thêm/S?a/Xoá)\n");
        printf("3. S?p x?p sách theo giá (Tãng/Gi?m)\n");
        printf("4. T?m ki?m sách (Tên tác gi?)\n");
        printf("5. T?m ki?m sách (Tên sách)\n");
        printf("6. K?t thúc chýõng tr?nh\n");

        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            /* In ra toàn b? thông tin v? toàn b? sách có trong c?a hàng */
            displayBook(bookList, currentSize);
            break;
        case 2:
            printf("************* Sub-menu *************\n");
            printf("2.1. Thêm sách m?i vào c?a hàng\n");
            printf("2.2. S?a thông tin sách\n");
            printf("2.3. Xoá sách kh?i c?a hàng\n");
            float subChoice;
            scanf("%f", &subChoice);
            fflush(stdin);

            if (subChoice == 2.1f)
            {
                // Thêm sách
                struct Book newBook;

                printf("Nh?p vào code c?a sách\n");
                scanf("%d", &newBook.code);
                fflush(stdin);

                printf("Nh?p vào tên c?a sách\n");
                gets(newBook.title);

                printf("Nh?p vào tác gi? c?a sách\n");
                gets(newBook.author);

                printf("Nh?p vào giá c?a sách\n");
                scanf("%f", &newBook.price);
                fflush(stdin);

                printf("Nh?p vào category c?a sách\n");
                gets(newBook.category);

                bookList[currentSize] = newBook;
                currentSize++;

                displayBook(bookList, currentSize);
            }
            else if (subChoice == 2.2f)
            {
                // S?a thông tin sách
                char answer[100];
                printf("Nh?p vào quy?n sách b?n mu?n ch?nh s?a: \n");
                gets(answer);

                int updateIndex = searchBook(bookList, currentSize, answer); // -1, index

                if (updateIndex != -1)
                {
                    printf("Nh?p vào tên c?p nh?t c?a sách\n");
                    gets(bookList[updateIndex].title);

                    printf("Nh?p vào tác gi? m?i c?a sách\n");
                    gets(bookList[updateIndex].author);

                    printf("Nh?p vào giá m?i c?a sách\n");
                    scanf("%f", &bookList[updateIndex].price);
                    fflush(stdin);

                    displayBook(bookList, currentSize);
                }
            }
            else if (subChoice == 2.3f)
            {
                // Xoá sách
                char answer[100];
                printf("Nh?p vào quy?n sách b?n mu?n xoá: \n");
                gets(answer);

                int deleteIndex = searchBook(bookList, currentSize, answer); // -1, index

                if (deleteIndex != -1)
                {
                    // { book1, book2, book4, book5} ... }
                    for (int i = deleteIndex; i < currentSize; i++)
                    {
                        bookList[i] = bookList[i + 1];
                    }
                    currentSize--;
                    displayBook(bookList, currentSize);
                }
            }
            break;
        case 4:
        {
            // S?a thông tin sách
            char answer[50];
            printf("Nh?p vào quy?n sách b?n mu?n t?m ki?m: \n");
            gets(answer);
            int searchIndex = searchBook(bookList, currentSize, answer); // -1 || index
            if (searchIndex == -1)
            {
                printf("Không t?m th?y quy?n sách mà b?n v?a nh?p vào \n");
            }
            else
            {
                struct Book findBook = bookList[searchIndex];
                printf("Code: %d\n", findBook.code);
                printf("Tên Sách: %s\n", findBook.title);
                printf("Tác Gi?: %s\n", findBook.author);
                printf("Giá Ti?n: %f\n", findBook.price);
                printf("Th? Lo?i: %s\n", findBook.category);
                printf("------------------\n");
            }
            break;
        }
        case 5:
            // Gi?ng h?t case 4
            break;
        default:
            if (choice == 6)
            {
                printf("C?m õn b?n ð? dùng chýõng tr?nh! Bye bye!!!!\n");
            }
            else
            {
                printf("Sai cú pháp, m?i nh?p l?i!!!!\n");
            }
            break;
        }
    }

    return 0;
}
