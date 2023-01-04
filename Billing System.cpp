#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "____________________________________\n";
    cout << "                                    \n";
    cout << "||     SUPERMARKET MAIN MENU      ||\n";
    cout << "                                    \n";
    cout << "____________________________________\n";
    cout << "                                    \n";
    cout << "|         1. ADMINISTRATOR         |\n";
    cout << "|                                  |\n";
    cout << "|         2. BUYER                 |\n";
    cout << "|                                  |\n";
    cout << "|         3. EXIT                  |\n";
    cout << "|                                  |\n";
    cout << "____________________________________\n";
    
    cout << "\nSelect Option: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\nPlease Login ! \n\n";
        cout << "\nEnter Email: ";
        cin >> email;
        cout << "Enter Password: ";
        cin >> password;
        if (email == "nikhartiwari.etw@gmail.com" && password == "Nt@9536")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email/Password ! \n";
        }
        break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select from the given Options ! \n";
    }
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "________________________________\n";
    cout << "\n||     ADMINISTRATOR MENU     ||\n";
    cout << "________________________________\n\n";
    cout << "|      1. ADD PRODUCT          |\n";
    cout << "|                              |\n";
    cout << "|      2. MODIFY PRODUCT       |\n";
    cout << "|                              |\n";
    cout << "|      3. DELETE PRODUCT       |\n";
    cout << "|                              |\n";
    cout << "|      4. BACK TO MENU         |\n";
    cout << "________________________________\n";

    cout << "\n\nPlease Enter your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "\nInvalid Choice ! \n";
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << endl << endl;
    cout << "________________________________\n";
    cout << "\n||        BUYER MENU          ||\n";
    cout << "________________________________\n\n";
    cout << "|       1. BUY PRODUCT         |\n";
    cout << "|                              |\n";
    cout << "|       2. BACK TO MENU        |\n";
    cout << "________________________________\n";
    
    cout << "\n\nPlease Enter your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();

    default:
    cout << "\nInvalid Choice ! \n";
    }

    goto m;
}

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n||    ADD NEW PRODUCT    ||\n";
    cout << "                               \n";
    cout << "Product Code of the Product: ";
    cin >> pcode;
    cout << "Name of the Product: ";
    cin >> pname;
    cout << "Price of the Product: ";
    cin >> price;
    cout << "Discount on Product: ";
    cin >> dis;

    data.open("database.txt", ios::app | ios::out);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << " \n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << " \n";
            data.close();
        }
    }
    cout << "\nRecord Inserted ! \n\n";
}

void shopping ::edit()
{
m:
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\n||    MODIFY THE PRODUCT    ||\n";
    cout << "                                  \n";
    cout << "Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesn't Exists ! \n";
    }
    else
    {

        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\nProduct new Code: ";
                cin >> c;
                cout << "Name of the Product: ";
                cin >> pname;
                cout << "Price of the Product: ";
                cin >> p;
                cout << "Discount: ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << " \n";
                cout << "\nRecord Edited ! \n";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << " \n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\nRecord Not Found ! \n";
        }
    }
    goto m;
}

void shopping::rem()
{
m:
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n||    DELETE PRODUCT    ||\n";
    cout << "                              \n";
    cout << "\nProduct Code: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile doesn't Exists ! \n";
    }

    else
    {
        data1.open("database.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\nProduct Deleted Successfully ! \n";
                token++;
            }
            else
            {
                data << " " << pcode << " " << pname << " " << price << " " << dis << " \n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\nRecord not Found ! \n";
        }
    }
    goto m;
}

void shopping::list()
{    
    fstream data;
    data.open("database.txt", ios::in);
    cout << "|________________________________| \n";
    cout << "|P.No   Name    Price  Discount  | \n";
    cout << "|________________________________| \n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << "  " << pcode << "\t" << pname << "\t" << price << "\t" << dis << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

   cout << "\n\n||         PRODUCT LIST         ||\n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nEmpty Database ! \n";
    }

    else
    {
        data.close();

        list();
        cout << "\n\nPlease Place the Order !\n";
        do
        {
        m:
            cout << "\n\nEnter Product Code: ";
            cin >> arrc[c];
            cout << "\nEnter the Product Quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\nDuplicate Product Code, Please Try Again ! \n";
                    goto m;
                }
            }
            c++;
            cout << "\n\nDo you want to Buy another Product? If Yes, then Press 'y' else 'n' ! \n";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n||            RECEIPT           ||\n";
        cout << "\nP.No\tName\tQuantity\tPrice\tAmount \t Amount with Discount";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t" << pname << "  \t " << arrq[i] << " \t\t " << price << " \t " << amount << "  \t  " << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }

    cout << "\n\nTotal Amount: Rs. " << total << endl;

}
int main()
{
    shopping s;
    s.menu();
}