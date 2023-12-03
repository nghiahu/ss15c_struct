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
        printf("T�n S�ch: %s\n", arr[i].title);
        printf("T�c Gi?: %s\n", arr[i].author);
        printf("Gi� Ti?n: %f\n", arr[i].price);
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
    struct Book book2 = {2, "T�i th?y hoa v�ng tr�n c? xanh", "Nguy?n Nh?t �nh", 20, "romance"};

    struct Book bookList[100] = {book1, book2};
    int currentSize = 2;

    int choice;
    while (choice != 6)
    {
        printf("************* MENU *************\n");
        printf("1. Th�ng tin s�ch trong c?a h�ng\n");
        printf("2. C?p nh?t th�ng tin s�ch (Th�m/S?a/Xo�)\n");
        printf("3. S?p x?p s�ch theo gi� (T�ng/Gi?m)\n");
        printf("4. T?m ki?m s�ch (T�n t�c gi?)\n");
        printf("5. T?m ki?m s�ch (T�n s�ch)\n");
        printf("6. K?t th�c ch��ng tr?nh\n");

        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            /* In ra to�n b? th�ng tin v? to�n b? s�ch c� trong c?a h�ng */
            displayBook(bookList, currentSize);
            break;
        case 2:
            printf("************* Sub-menu *************\n");
            printf("2.1. Th�m s�ch m?i v�o c?a h�ng\n");
            printf("2.2. S?a th�ng tin s�ch\n");
            printf("2.3. Xo� s�ch kh?i c?a h�ng\n");
            float subChoice;
            scanf("%f", &subChoice);
            fflush(stdin);

            if (subChoice == 2.1f)
            {
                // Th�m s�ch
                struct Book newBook;

                printf("Nh?p v�o code c?a s�ch\n");
                scanf("%d", &newBook.code);
                fflush(stdin);

                printf("Nh?p v�o t�n c?a s�ch\n");
                gets(newBook.title);

                printf("Nh?p v�o t�c gi? c?a s�ch\n");
                gets(newBook.author);

                printf("Nh?p v�o gi� c?a s�ch\n");
                scanf("%f", &newBook.price);
                fflush(stdin);

                printf("Nh?p v�o category c?a s�ch\n");
                gets(newBook.category);

                bookList[currentSize] = newBook;
                currentSize++;

                displayBook(bookList, currentSize);
            }
            else if (subChoice == 2.2f)
            {
                // S?a th�ng tin s�ch
                char answer[100];
                printf("Nh?p v�o quy?n s�ch b?n mu?n ch?nh s?a: \n");
                gets(answer);

                int updateIndex = searchBook(bookList, currentSize, answer); // -1, index

                if (updateIndex != -1)
                {
                    printf("Nh?p v�o t�n c?p nh?t c?a s�ch\n");
                    gets(bookList[updateIndex].title);

                    printf("Nh?p v�o t�c gi? m?i c?a s�ch\n");
                    gets(bookList[updateIndex].author);

                    printf("Nh?p v�o gi� m?i c?a s�ch\n");
                    scanf("%f", &bookList[updateIndex].price);
                    fflush(stdin);

                    displayBook(bookList, currentSize);
                }
            }
            else if (subChoice == 2.3f)
            {
                // Xo� s�ch
                char answer[100];
                printf("Nh?p v�o quy?n s�ch b?n mu?n xo�: \n");
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
            // S?a th�ng tin s�ch
            char answer[50];
            printf("Nh?p v�o quy?n s�ch b?n mu?n t?m ki?m: \n");
            gets(answer);
            int searchIndex = searchBook(bookList, currentSize, answer); // -1 || index
            if (searchIndex == -1)
            {
                printf("Kh�ng t?m th?y quy?n s�ch m� b?n v?a nh?p v�o \n");
            }
            else
            {
                struct Book findBook = bookList[searchIndex];
                printf("Code: %d\n", findBook.code);
                printf("T�n S�ch: %s\n", findBook.title);
                printf("T�c Gi?: %s\n", findBook.author);
                printf("Gi� Ti?n: %f\n", findBook.price);
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
                printf("C?m �n b?n �? d�ng ch��ng tr?nh! Bye bye!!!!\n");
            }
            else
            {
                printf("Sai c� ph�p, m?i nh?p l?i!!!!\n");
            }
            break;
        }
    }

    return 0;
}
