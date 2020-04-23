#include <iostream>
#include <string>
using namespace std;
struct CAFFE
{
    string dof;
    int table;
    string waiterName;
    string clientOrder;
    string time;
    string bill;
    int id=0;
};
void createOrder(CAFFE* orders, int& orderCount, int& maxId, CAFFE newOrder)
{
    newOrder.id = maxId++;
    orders[orderCount] = newOrder;
    orderCount++;
}
void createOrderMenu(CAFFE* orders, int& orderCount, int& maxId)
{
    CAFFE order;
    cout << "Table number: ";
    cin >> order.table;
    cout << endl;
    cout << "Waiter name: ";
    getline(cin,order.waiterName);
    cout << endl;
    cout << "What did the client order?: ";
    getline(cin, order.clientOrder);
    cout << endl;
    cout << "For how long stayed the client?: ";
    cin >> order.time;
    cout << endl;
    cout << "How much did they pay?: ";
    cin >> order.bill;
    cout << endl;
    cout << "What day is it?: ";
    cin >> order.dof;
    cout << endl;
    
    createOrder(orders, orderCount, maxId, order);
}
void showOrder(CAFFE* orders, int& orderCount, int& maxId)
{
    cout << "Here are all the orders: " << endl;
    for (int i = 0; i < orderCount; i++)
    {
        cout << orders[i].id << '.'<<"Day: "<< orders[i].dof << " | " <<"Waiter Name:"<< orders[i].waiterName << " | " <<"Table: "<< orders[i].table << " | " <<"Order:"<< orders[i].clientOrder << " | " <<"Stayed: "<< orders[i].time << " | " <<"Paid: "<< orders[i].bill << endl;
    }
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
        createOrderMenu(orders, orderCount, maxId);
        break;
    case 2:
        showOrder(orders, orderCount, maxId);
        break;
    }
    return true;
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