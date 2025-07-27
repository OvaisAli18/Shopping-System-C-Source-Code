#include<iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include "queue1.h"
#include "stackme.h"

using namespace std;

int search(int);
int display();
void customer_portal();

struct node
{
    int ID;
    string proName;
    double prePrice;
    int quantity;
    struct node *next;
};

struct node *head = NULL;

void beg()
{
    
    int id, quant;
    string name;
    double pre;
    struct node *t = new node;
    struct node *p = head;

    cout << "\t\t\tEnter product ID:-";
    cin >> id;
    t->ID = id;
    cout << "\t\t\tEnter product Name:-";
    cin >> name;
    t->proName = name;
    cout << "\t\t\tEnter product price:-";
    cin >> pre;
    t->prePrice = pre;
    cout << "\t\t\tEnter product quantity:-";
    cin >> quant;
    t->quantity = quant;

    t->next = NULL;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }

    
    cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}

int search(int id)
{
    int count = 1;
    struct node *p = head;
    while (p != NULL)
    {
        if (p->ID == id)
            break;
        count++;
        p = p->next;
    }
    return count;
}

void delPro()
{
   
    display();
    int id;
    cout << "\n\nEnter ID to delete that product:\n\n";
    cin >> id;

    if (head == NULL)
    {
        
        cout << "List is empty" << endl;
        return;
    }

    struct node *cur = head;
    struct node *pre = NULL;

    if (head->ID == id)
    {
        head = head->next;
        delete cur;
       
        cout << "\n<<item is deleted>>\n";
        return;
    }

    while (cur != NULL && cur->ID != id)
    {
        pre = cur;
        cur = cur->next;
    }

    if (cur == NULL)
    {
        cout << "\n<<<Not found>>>\n\n";
    }
    else
    {
        pre->next = cur->next;
        delete cur;
        
        cout << "\n<<item is deleted>>\n";
    }
}

void modify()
{
    int id, nid, nq;
    double pre;
    string pName;

    if (head == NULL)
    {
        system("cls");
        cout << "List is empty" << endl;
        return;
    }

    display();
    cout << "\n\nEnter ID to modify product Name and its price:\n";
    cin >> id;

    struct node *cur = head;
    int count = display();
    int pos = search(id);

    if (pos > count)
    {
        cout << id << " is <<<Not found>>>\n\n";
        return;
    }

    while (cur->ID != id)
    {
        cur = cur->next;
    }

    cout << "\nOld ID : " << cur->ID << endl;
    cout << "\nOld Name : " << cur->proName << endl;
    cout << "\nOld Price : " << cur->prePrice << endl;
    cout << "\nOld Quantity : " << cur->quantity << endl;

    cout << "\nEnter new ID:";
    cin >> nid;
    cur->ID = nid;
    cout << "Enter new Name:";
    cin >> pName;
    cur->proName = pName;
    cout << "Enter new Price:";
    cin >> pre;
    cur->prePrice = pre;
    cout << "Enter new Quantity:";
    cin >> nq;
    cur->quantity = nq;
}

int display()
{
   
    int c = 0;
    struct node *p = head;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\t Price\t\tQuantity\n";
    cout << "=================================================================|\n";

    while (p != NULL)
    {
        cout << p->ID << "\t\t" << p->proName << "\t\t" << p->prePrice << "\t\t" << p->quantity << "\n";
        p = p->next;
        c++;
    }

    cout << "\nTotal products in our store is : " << c << "\n\n\n";
    return c;
}

void buy()
{
   
    display();

    string products[20];
    int pay = 0, no, c = 0, price, id, i = 1;

    if (head == NULL)
    {
        cout << "\n<<<<There are no items to buy>>>>\n\n";
        return;
    }

    cout << "How many items do you want to buy? ";
    cin >> no;

    int count = display();

    while (i <= no)
    {
        struct node *cur = head;
        int quant;
    a:
        cout << "Enter the ID of the item you want to buy: ";
        cin >> id;

        if (id == -1)
        {
            system("cls");
            return;
        }

        int pos = search(id);
        if (pos <= count)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }

            cout << "How many quantities do you want: ";
            cin >> quant;

            if (cur->quantity < quant)
            {
                cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
                cout << "\n\t\t\t-----(Press -1 to return to the Main Menu)------" << endl;
                goto a;
            }

            products[c] = cur->proName;
            c++;

            pay += (cur->prePrice * quant);
            cur->quantity -= quant;
            i++;
        }
        else
        {
            cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
        }
    }

    price = pay * 0.90;
    cout << "\n\n\n\n\t\t\tYou have bought: ";
    for (int i = 0; i < c; i++)
    {
        cout << products[i] << ", ";
    }

    cout << "\n\nOriginal price: " << pay;
    cout << "\nWith 10% discount: " << price << "\nThank you for shopping!\n\n";
}

void administrator()
{
   
    int ch;

    do
    {
        cout << "\t\t============================================" << endl;
        cout << "\t\t|          Administrator Portal              |" << endl;
        cout << "\t\t============================================" << endl;

        cout << "\t\t     Enter 1 to ADD a new product    " << endl;
        cout << "\t\t     Enter 2 to display all products   " << endl;
        cout << "\t\t     Enter 3 to MODIFY an Existing product" << endl;
        cout << "\t\t     Enter 4 to Delete a particular product item" << endl;
        cout << "\t\t     Enter 5 to view Customers List " << endl;
        cout << "\t\t     Enter 6 to Dequeue a customer" << endl;
        cout << "\t\t     Enter 7 to View sold items" << endl;
        cout << "\t\t     Enter 0 to Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            beg();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            delPro();
            break;
        case 5:
            displayQueue();
            break;
        case 6:
            dequeue();
            break;
        case 7:
            display();
            break;
        case 0:
            customer_portal();
            return;
        default:
            cout << "Invalid input";
        }
    } while (ch != 0);
}

void customer_portal()
{
    int ch;
    do
    {
        system("cls");
        cout << "\t\t============================================" << endl;
        cout << "\t\t|                WELCOME!                   |" << endl;
        cout << "\t\t============================================" << endl;

        cout << "\t\t      Enter 1 for Admin Portal           " << endl;
        cout << "\t\t      Enter 2 for Customer Portal       " << endl;
        cout << "\t\t      Enter 0 to exit system" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            administrator();
            break;
        case 2:
            buy();
            break;
        case 0:
            return;
        default:
            cout << "Invalid input";
        }
    } while (ch != 0);
}

int main()
{
    customer_portal();
    return 0;
}
