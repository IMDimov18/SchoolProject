#include <iostream>
#include <string>
using namespace std;
struct CAFFE
{
    int table;
    char waiterName;
    char clientOrder;
    int time;
    float bill;
};
void createOrder(CAFFE* orders, int& orderCount, int& maxId)
{
    CAFFE order;
    cout << "Table number: ";
    cin >> order.table;
    cout << "Waiter name: ";
    cin >> order.waiterName;
    cout << "What did the client order?: ";
    cin >> order.clientOrder;
    cout << "For how long stayed the client?: ";
    cin >> order.time;
    cout << "How much did they pay?: ";
    cin >> order.bill;
}
bool showMainMenu(CAFFE* orders, int& orderCount, int& maxId)
{
    int choice;
    cout << "-------ORDER MENU-------" << endl;
    cout << "1. Create order" << endl;
    cout << "2. Show all orders" << endl;
    cout << "3. Edit order" << endl;
    cout << "4. Delete order" << endl;
    cout << "5. Report" << endl;
    cout << "6. Exit" << endl;
    cout << "What is your choice?: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        createOrder(orders, orderCount, maxId);
        break;
    case 2:

    }
}
int main()
{
    int orderCount = 0;
    int maxId = 1;
    CAFFE orders[500];
    bool showMenu;
    do {
        showMenu = showMainMenu(orders, orderCount, maxId);

    } while (showMenu);
}