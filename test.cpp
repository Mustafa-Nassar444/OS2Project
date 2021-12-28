#include <bits/stdc++.h>
using namespace std;
fstream inv;
class Inventory
{
    int id, amount, snum, price;
    string name, type;

public:
    Inventory(int id = 0, string name = "", int amount = 0, int price = 0, string type = "", int snum = 0)
    {
        this->id = id;
        this->amount = amount;
        this->name = name;
        this->price = price;
        this->type = type;
        this->snum = snum;
    }
    int getprice() { return price; }
    int getamount() { return amount; }
    int getsnum() { return snum; }
    int getid() { return id; }
    string getname() { return name; }
    string getType() { return type; }
    void setname(string name) { this->name = name; }
    void setType(string type) { this->type = type; }
    void setid(int id) { this->id = id; }
    void setprice(int price)
    {
        this->price = price;
    }
    void setamount(int amount) { this->amount = amount; }
    void setsnum(int snum) { this->snum = snum; }
    friend ostream &operator<<(ostream &out, Inventory &iv)
    {
        out << iv.getid() << "|" << iv.getname() << "|" << iv.getprice() << "|" << iv.getamount() << "|" << iv.getType() << "|" << iv.getsnum() << endl;
        return out;
    }
    friend fstream &operator<<(fstream &file, Inventory &iv)
    {
        file << iv.getid() << "|" << iv.getname() << "|" << iv.getprice() << "|" << iv.getamount() << "|" << iv.getType() << "|" << iv.getsnum() << endl;
        return file;
    }
    friend istream &operator>>(istream &in, Inventory &iv)
    {
        in >> iv.id >> iv.name >> iv.price >> iv.amount >> iv.type >> iv.snum;
        return in;
    }
};
Inventory iv;
void StringtoInventory(const string record)
{
    stringstream strs(record);
    string sid, sname, sprice, samount, stype, ssnum;
    getline(strs, sid, '|');
    getline(strs, sname, '|');
    getline(strs, sprice, '|');
    getline(strs, samount, '|');
    getline(strs, stype, '|');
    getline(strs, ssnum, '\n');
    iv.setid(atoi(sid.c_str()));
    iv.setname(sname);
    iv.setprice(atoi(sprice.c_str()));
    iv.setamount(atoi(samount.c_str()));
    iv.setType(stype);
    iv.setsnum(atoi(ssnum.c_str()));
}
void Add()
{
    Inventory ss[100];
    int n = 0;
    string record;
    inv.open("Inventory.txt", ios::in | ios::app);
    if (!inv)
    {
        puts("\n Cannot open file!!");
        exit(1);
    }
    while (true)
    {
        inv >> record;
        if (inv.eof())
        {
            break;
        }
        StringtoInventory(record);
        ss[n].setid(iv.getid());
        ss[n].setname(iv.getname());
        ss[n].setprice(iv.getprice());
        ss[n].setamount(iv.getamount());
        ss[n].setType(iv.getType());
        ss[n].setsnum(iv.getsnum());
        n++;
    }
    inv.close();
    cout << "\nID  Name   Price   Amount   Type    Shelf_Number\n";
    cin >> ss[n];
    n++;
    char c;
    cout << " Do you want to save this record? Press Y or N" << endl
         << " ";
    cin >> c;
    if (c == 'Y' || c == 'y')
    {
        inv.open("Inventory.txt", ios::out);
        if (!inv)
        {
            puts("\n Cannot open file!!");
            exit(1);
        }
        for (int i = 0; i < n; ++i)
        {
            inv << ss[i];
        }
        cout << " Redo done!!" << endl;
    }
    else
    {
        cout << " Undo done!" << endl;
    }
    inv.close();
}
void LinearSearch()
{
    inv.open("Inventory.txt", ios::in);
    if (!inv)
    {
        puts("\n Cannot open file!!");
        exit(1);
    }
    int knum, q;
    string kname, ktype, record;
    puts(" ---To Search by Name press 1, by Type press 2, by Shelf_No. press 3---: \n ");
    cin >> q;
    switch (q)
    {
    case 1:
        cout << "\n Enter item name: \n ";
        cin >> kname;
        while (true)
        {
            inv >> record;
            if (inv.eof())
                break;
            StringtoInventory(record);
            if (iv.getname() == kname)
            {
                cout << iv;
                inv.close();
                return;
            }
        }
        puts(" --Item not found!!--");
        inv.close();
        return;
        break;
    case 2:
        cout << "\n Enter item type: ";
        cin >> ktype;
        while (true)
        {
            inv >> record;
            if (inv.eof())
                break;
            StringtoInventory(record);
            if (iv.getType() == ktype)
            {
                cout << iv;
                inv.close();
                return;
            }
        }
        puts(" --Item not found!!--");
        inv.close();
        return;
        break;
    case 3:
        cout << "\n Enter Shelf Number: ";
        cin >> knum;
        while (true)
        {
            inv >> record;
            if (inv.eof())
                break;
            StringtoInventory(record);
            if (iv.getsnum() == knum)
            {
                cout << iv;
                inv.close();
                return;
            }
        }
        puts(" --Item not found!!--");
        inv.close();
        return;
        break;
    }
}
void Update()
{
    string s, record;
    int n = 0, c = 0;
    inv.open("Inventory.txt", ios::in);
    if (!inv)
    {
        puts(" Cannot open file!!");
        exit(1);
    }
    while (true)
    {
        getline(inv, record);
        if (inv.eof())
        {
            break;
        }
        c++;
    }
    inv.close();
    Inventory ss[c];
    inv.open("Inventory.txt", ios::in);
    if (!inv)
    {
        puts("\n Cannot open file!!");
        exit(1);
    }
    cout << "\n Enter item name : ";
    cin >> s;
    while (true)
    {
        inv >> record;
        if (inv.eof())
        {
            break;
        }
        StringtoInventory(record);
        ss[n].setid(iv.getid());
        ss[n].setname(iv.getname());
        ss[n].setprice(iv.getprice());
        ss[n].setamount(iv.getamount());
        ss[n].setType(iv.getType());
        ss[n].setsnum(iv.getsnum());
        n++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (ss[i].getname() == s)
        {
            cout << "\n Old item info. :";
            cout << ss[i];
            cout << "\nEnter new item info"
                 << "\nID, Name, Price, Amount, Type, Shelf_No.\n";
            cin >> ss[i];
            break;
        }
    }
    inv.close();
    char t;
    cout << "--*Do you want to save this record? Press Y or N*--" << endl;
    cin >> t;
    if (t == 'Y' || t == 'y')
    {
        inv.open("Inventory.txt", ios::out);
        if (!inv)
        {
            puts("\n Cannot open file!!");
            exit(1);
        }
        for (int i = 0; i < n; ++i)
        {
            inv << ss[i];
        }
        cout << "Redo done!!" << endl;
    }
    else
    {
        cout << "Undo done!" << endl;
    }
    inv.close();
}
void Delete()
{
    string s, record;
    int n = 0;
    Inventory ss[100];
    inv.open("Inventory.txt", ios::in);
    if (!inv)
    {
        puts("\n Cannot open file!!");
        exit(1);
    }
    cout << "\n --*Enter item name*--: ";
    cin >> s;
    while (true)
    {
        inv >> record;
        if (inv.eof())
        {
            break;
        }
        StringtoInventory(record);
        ss[n].setid(iv.getid());
        ss[n].setname(iv.getname());
        ss[n].setprice(iv.getprice());
        ss[n].setamount(iv.getamount());
        ss[n].setType(iv.getType());
        ss[n].setsnum(iv.getsnum());
        n++;
    }
    int i = 0;
    for (; i < n; ++i)
    {
        if (ss[i].getname() == s)
        {
            break;
        }
    }
    if (i == n)
    {
        cout << "\n --Item not found--";
    }
    for (int j = i; j < n; ++j)
    {
        ss[j] = ss[j + 1];
    }
    n--;
    inv.close();
    char t;
    cout << "--*Do you want to save this record? Press Y or N*--" << endl;
    cin >> t;
    if (t == 'Y' || t == 'y')
    {
        inv.open("Inventory.txt", ios::out);
        if (!inv)
        {
            puts("\n Cannot open file!!");
            exit(1);
        }
        for (int i = 0; i < n; ++i)
        {
            inv << ss[i];
        }
        cout << "Redo done!!" << endl;
    }
    else
    {
        cout << "Undo done!" << endl;
    }
    inv.close();
}
void Displayall()
{
    string record;
    int n = 0;
    Inventory ss[100];
    inv.open("Inventory.txt", ios::in);
    if (!inv)
    {
        puts("\n Cannot open file!!");
        exit(1);
    }
    while (true)
    {
        inv >> record;
        if (inv.eof())
        {
            break;
        }
        StringtoInventory(record);
        ss[n].setid(iv.getid());
        ss[n].setname(iv.getname());
        ss[n].setprice(iv.getprice());
        ss[n].setamount(iv.getamount());
        ss[n].setType(iv.getType());
        ss[n].setsnum(iv.getsnum());
        n++;
    }
    {
        int i, j, min_idx;
        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (ss[j].getprice() < ss[min_idx].getprice())
                    min_idx = j;
            swap(ss[min_idx], ss[i]);
        }
    }
    inv.close();
    inv.open("Inventory.txt", ios::out);
    for (int x = 0; x < n; ++x)
    {
        inv << ss[x];
        cout << ss[x];
    }
    inv.close();
    puts("\nSorted by price");
}
int main()
{
    int c;
    while (true)
    {
        printf("\nAdd new Item--> 1");
        printf("\nSearch for Item--> 2");
        printf("\nUpdate Item--> 3");
        printf("\nDelete Item--> 4");
        printf("\nDisplay all Item Sorted--> 5");
        printf("\nQuit--> 6");
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            Add();
            break;
        case 4:
            Delete();
            break;
        case 3:
            Update();
            break;
        case 2:
            LinearSearch();
            break;
        case 5:
            Displayall();
            break;
        case 6:
            exit(1);
            break;
        default:
            puts("\n Wrong choice!!");
        }
    }
    return 0;
}
