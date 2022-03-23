#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Items
{
    float price;
    char name[30];
    int item_id;
    char class;
};

int noOfStarters = 4;
int noOfMain = 4;
int noOfDesserts = 4;
int totalNumberOfItems = 12;

struct Items list[] = {{30, "samosa", 100, 's'}, {40, "idli", 101, 's'}, {50, "dosa", 102, 's'}, {60, "vada", 103, 's'}, {200, "Biryani", 104, 'm'}, {120, "Dal Makhani", 105, 'm'}, {250, "Shahi Paneer", 106, 'm'}, {180, "Rajma Chawal", 107, 'm'}, {60, "Ice Cream", 108, 'd'}, {80, "Gulab Jamun", 109, 'd'}, {70, "Rasmalai", 110, 'd'}, {50, "Kheer", 111, 'd'}};

void printItems(char c)
{
    for (int i = 0; i < totalNumberOfItems; i++)
    {
        if (list[i].class == c)
        {
            printf("%d  %s %.2f \n", list[i].item_id, list[i].name, list[i].price);
        }
    }
}

int main()
{
    int orderedItems[12][2];
    for (int i = 0; i < 12; i++)
    {
        orderedItems[i][0] = 100 + i;
        orderedItems[i][1] = 0;
    }

    printf("Hello, Welcome to Digital Waiter\n");
    printf("Tell us what you would like to order : \n");

    for (int i = 0; i < totalNumberOfItems; i++)
    {
        printf("%d  %s %.2f \n", list[i].item_id, list[i].name, list[i].price);
    }

    int ans = 1;
    while (ans != 3)
    {

        printf("Enter the item id of the food you want to order : \n");
        int id;
        scanf("%d", &id);
        printf("Enter the quantity of the item selected \n");
        scanf("%d", &orderedItems[id - 100][1]);
        printf("Do you want to add another item? \n");
        printf("Enter 1 for yes 2 for seeing menu once again and 3 for no\n");
        scanf("%d", &ans);
        if (ans == 3)
        {
            break;
        }
        else if (ans == 2)
        {
            printf("Which menu you want to see\n");
            int choice;
            printf("1 for starters \n2 for maincourse \n3 for desserts : \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printItems('s');
                break;

            case 2:
                printItems('m');
                break;

            default:
                printItems('d');
                break;
            }
        }
    }

    FILE *fp;
    fp = fopen("text.txt", "w+");
    // printf("Your final bill is : \n");
    float cost = 0;
    for (int i = 0; i < 12; i++)
    {
        if (orderedItems[i][1] != 0)
        {
            for (int j = 0; j < totalNumberOfItems; j++)
            {
                if (list[j].item_id == orderedItems[i][0])
                {
                    fprintf(fp ,"%d  %s %d %.2f \n", list[j].item_id, list[j].name, orderedItems[i][1], list[j].price * orderedItems[i][1]);
                    cost += list[j].price * orderedItems[i][1];
                }
            }
        }
    }
    fprintf(fp ,"Total amount to be paid : Rs %.2f \n", cost);

    printf("Your bill has been redirected to text.txt \n");

    printf("Thank you for stopping by. Do visit again! \n");

    return 0;
}