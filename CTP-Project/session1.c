#include <stdio.h>
#include <string.h>
struct Items
{
    float price;
    char name[30];
    int item_id;
};

struct Items starters[4] = {{30, "samosa", 0}, {40, "idli", 1}, {50, "dosa", 2}, {60, "vada", 3}};
struct Items mainCourse[4] = {{200, "Biryani", 4}, {120, "Dal Makhani", 5}, {250, "Shahi Paneer", 6}, {180, "Rajma Chawal", 7}};
struct Items desserts[4];
void printItems(struct Items menu[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d %s %.2f  \n", menu[i].item_id, menu[i].name, menu[i].price);
    }
}
int main()
{
    int noOfStarters = 4;
    int noOfMain = 4;
    int noOfDesserts = 4;
    printf("Hello, Welcome to Digital Waiter\n");
    printf("Tell us what you would like to order : \n");
    struct Items samosa, idli, dosa, vada;
    printItems(starters, noOfStarters);

    int orderedItems[12][2];
    for (int i = 0; i < 12; i++)
    {
        orderedItems[i][0] = i;
        orderedItems[i][1] = 0;
    }

    char ans = 'y';
    while (ans != 'n')
    {

        printf("Enter the item id of the food you want to order : \n");
        int id;
        scanf("%d", &id);
        printf("Enter the quantity of the item selected \n");
        scanf("%d", &orderedItems[id][1]);
        printf("Do you want to add another item? \n");
        printf("Enter y for yes s for seeing menu once again  and n for no\n");
        scanf("%c", &ans);
        if (ans == 'n'){
            ans='n';
            goto A;
        }
        else if (ans == 's')
        {
            ans='s';
            printf("Which menu you want to see\n");
            int choice;
            printf("1 for starters \n2 for maincourse \n3 for desserts : \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printItems(starters, noOfStarters);
                break;

            case 2:
                printItems(mainCourse, noOfMain);
                break;

            default:
                printItems(desserts, noOfDesserts);
                break;
            }
            A:
            printf("hi");
        }
    }
            
    

}