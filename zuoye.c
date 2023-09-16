#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N = 100, M = 1000;

typedef struct Shoppingitem
{
    char name[50];
    int quantity;
    struct Shoppingitem* next;
}Nodeer;

Nodeer* shoppinglist = NULL;
Nodeer* shoppinglist2 = NULL;

void addItem(char ItemName[], int itemQuantity)
{
    Nodeer* newItem = (Nodeer*)malloc(sizeof(Nodeer));

    strcpy(newItem->name, ItemName);

    newItem->quantity = itemQuantity;
    if (shoppinglist == NULL) {
        shoppinglist = newItem;
        newItem->next = NULL;
        shoppinglist->next = NULL;
    }
    else {
        newItem->next = shoppinglist;
        shoppinglist = newItem;
    }
}

void removeItem(char itemName[])
{
    Nodeer* current = shoppinglist;
    Nodeer* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (previous != NULL) previous->next = current->next;
            else
                shoppinglist = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displaylist()
{
    Nodeer* current = shoppinglist;

    printf("购物清单:\n");
    while (current != NULL)
    {
        printf("%s - 数量: %d\n", current->name, current->quantity);
        current = current->next;
    }
}

void updateQuantity(char itemName[], int newItemQuantity)
{
    Nodeer* current = shoppinglist;

    while (current != NULL)
    {
        if (strcmp(current->name, itemName) == 0)
        {
            current->quantity = newItemQuantity;
            break;
        }
        current = current->next;
    }
}

void clearlist()
{
    while (shoppinglist != NULL)
    {
        Nodeer* temp = shoppinglist;
        shoppinglist = shoppinglist->next;
        free(temp);
    }
}

int totalQuantity()
{
    Nodeer* current = shoppinglist;
    int total = 0;

    while (current != NULL)
    {
        total++;
        current = current->next;
    }

    return total;
}

void findItem(char itemName[])
{
    Nodeer* current = shoppinglist;

    printf("查找商品\"%s\" : \n", itemName);
    while (current != NULL)
    {
        if (strcmp(current->name, itemName) == 0)
        {
            printf("%s - 数量: %d\n", current->name, current->quantity);
            return;
        }
        current = current->next;
    }

    printf("未找到商品\"%s\"。 \n", itemName);
}

void sortlist()
{
    Nodeer* current = shoppinglist;
    Nodeer* nextItem = NULL;
    char tempName[50];
    int tempQuantity;

    while (current != NULL) {
        nextItem = current->next;

        while (nextItem != NULL) {
            if (strcmp(current->name, nextItem->name) > 0)
            {
                strcpy(tempName, current->name);
                strcpy(current->name, nextItem->name);
                strcpy(nextItem->name, tempName);

                tempQuantity = current->quantity;
                current->quantity = nextItem->quantity;
                nextItem->quantity = tempQuantity;
            }
            nextItem = nextItem->next;
        }
        current = current->next;
    }
}
//void mergeLists(struct ShoppingItem **list1,struct ShoppingItem **list2){
	struct ShoppingItem *current=*list1;
	//
	
	;
	current->next=*list2; 
	*list2=NULL;
}
void deleteItem(char itemName[], int deleteALL)
{
    Nodeer* current = shoppinglist;
    Nodeer* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (prev == NULL) {
                Nodeer* temp = shoppinglist;
                current = shoppinglist = shoppinglist->next;
                free(temp);
                if (!deleteALL) break;
            }
            else {
                prev->next = current->next;
                free(current);
                current = prev->next;
                if (!deleteALL) break;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

int main()
{
    int n,k,c;
    char a[M][N];
    int b;

    scanf("%d", &n);

    for (int k = 0; k < n; k++)
    {
        scanf("%s%d",\ a[i], &b);
        addItem(a[i], b);
    }
    c=totalQuantity();
    printf("商品的总数量 = %d\n", c);

    printf("把第11件商品数量改为26\n");
    updateQuantity(item[11], 26);
    displaylist();

    printf("查找12号商品:\n");
    findItem(a[12]);
    displaylist();
    

    printf("删掉第a[10]商品:\n");
    removeItem(a[10]);
    displaylist();
    
    printf("排序");
    sortlist();
    displaylist();
    
    printf("删除a[20]的商品\n");
    deleteItem(a[20], 1);
    displaylist();

    printf("清空clear: \n");
    clearlist();
    displaylist();

    return 0;
}