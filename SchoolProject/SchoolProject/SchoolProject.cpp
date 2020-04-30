#include <iostream>
#include <string>
using namespace std;
struct CAFFE
{
    char dof[3];
    int table;
    string waiterName;
    string clientOrder;
    string time;
    int bill;
    int id=1;
    float total = 0;
};
//CRUD
int getOrderById(CAFFE* orders, int& orderCount, int id)
{
    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
CAFFE getOrder(CAFFE* orders, int& orderCount, int id)
{
    int index = getOrderById(orders, orderCount, id);
    return orders[index];

}
float TotalPerDay(CAFFE* orders, int orderCount, char* dayOfWeek)
{
    float sum = 0;
    for (int i = 0; i < orderCount; i++)
    {
        if (_strcmpi(orders[i].dof, dayOfWeek) == 0)
        {
            sum = sum + orders[i].bill;
        }
    }
    return sum;
}
void createOrder(CAFFE* orders, int& orderCount, int& maxId, CAFFE newOrder)
{
    newOrder.id = maxId++;
    orders[orderCount] = newOrder;
    orderCount++;
}
void updateOrder(CAFFE* orders, int orderCount, int id, CAFFE newOrder)
{
    int index = getOrderById(orders, orderCount, id);
    orders[index] = newOrder;
}
void deleteOrder(CAFFE* orders, int& orderCount, int id)
{
    int index = getOrderById(orders, orderCount, id);
    for (int i = index; i < orderCount; i++)
    {
        orders[i] = orders[i + 1];
        orders[i].id--;
    }
    orderCount--;
}
void ReportChoice1(CAFFE* orders, int& orderCount)
{
    
    string dayOfWeek;
    cout << "Enter the day of the week: ";
    cin >> dayOfWeek;
    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].dof == dayOfWeek)
        {
            cout << "Day: " << orders[i].dof << " | " << "Waiter Name:" << orders[i].waiterName << " | " << "Table: " << orders[i].table << " | " << "Order:" << orders[i].clientOrder << " | " << "Stayed: " << orders[i].time << " | " << "Paid: " << orders[i].bill << endl;
        }
    }
}
void ReportChoice2(CAFFE* orders, int& orderCount)
{
    int money;
    cout << "enter the amount of money: ";
    cin >> money;
    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].bill > money)
        {
            cout << "Day: " << orders[i].dof << " | " << "Waiter Name:" << orders[i].waiterName << " | " << "Table: " << orders[i].table << " | " << "Order:" << orders[i].clientOrder << " | " << "Stayed: " << orders[i].time << " | " << "Paid: " << orders[i].bill << endl;
        }
    }
}
void ReportChoice3(CAFFE* orders, int& orderCount)
{
    int money;
    cout << "enter the amount of money: ";
    cin >> money;
    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].bill < money)
        {
            cout << "Day: " << orders[i].dof << " | " << "Waiter Name:" << orders[i].waiterName << " | " << "Table: " << orders[i].table << " | " << "Order:" << orders[i].clientOrder << " | " << "Stayed: " << orders[i].time << " | " << "Paid: " << orders[i].bill << endl;
        }
    }
}
void ReportChoice4(CAFFE* orders, int& orderCount)
{
    string waiter;
    cout << "Enter waiter/waitress name: ";
    getline(cin, waiter);
    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].waiterName == waiter)
        {
            cout << "Day: " << orders[i].dof << " | " << "Waiter Name:" << orders[i].waiterName << " | " << "Table: " << orders[i].table << " | " << "Order:" << orders[i].clientOrder << " | " << "Stayed: " << orders[i].time << " | " << "Paid: " << orders[i].bill << endl;
        }
    }
}
/*-------------------------Presentation Layer-----------------------------*/
void createOrderMenu(CAFFE* orders, int& orderCount, int& maxId)
{
    CAFFE order;
    cout << "Table number: ";
    cin >> order.table;
    cout << endl;
    cout << "Waiter name: ";
    cin >> order.waiterName;
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
void editOrderMenu(CAFFE* orders,int& orderCount)
{
    int Id;
    cout << "What is the number of the order you want to change?: ";
    cin >> Id;
    CAFFE order = getOrder(orders, orderCount, Id);
    cout << "1. Table" << endl;
    cout << "2. Waiter name" << endl;
    cout << "3. Client order" << endl;
    cout << "4. Duration" << endl;
    cout << "5. Bill" << endl;
    cout << "6. Day" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Table number: ";
        cin >> order.table;
        updateOrder(orders, orderCount, Id, order);
        break;
    case 2:
        cout << "Writer name: ";
        cin >> order.waiterName;
        updateOrder(orders, orderCount, Id, order);
        break;
    case 3:
        cout << "Client Order: ";
        cin >> order.clientOrder;
        updateOrder(orders, orderCount, Id, order);
        break;
    case 4:
        cout << "Duration: ";
        cin >> order.time;
        updateOrder(orders, orderCount, Id, order);
        break;
    case 5:
        cout << "Bill: ";
        cin >> order.bill;
        updateOrder(orders, orderCount, Id, order);
        break;
    case 6:
        cout << "Day: ";
        cin >> order.dof;
        updateOrder(orders, orderCount, Id, order);
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}
void deleteOrderMenu(CAFFE* orders, int& orderCount, int& maxId)
{
    int orderId;
    cout << "Enter order Id: ";
    cin >> orderId;
    deleteOrder(orders, orderCount, orderId);
}
void ReportMenu(CAFFE* orders, int& orderCount,int maxId)
{
    int choice;
    cout << "1. Show all orders from specific day " << endl;
    cout << "2. Show all orders with orders over specific amount of money." << endl;
    cout << "3. Show all orders with orders under specific amount of money." << endl;
    cout << "4. Show all orders from specific waiter/waitress" << endl;
    cout << "What is your choice?: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        ReportChoice1(orders, orderCount);
        break;
    case 2:
        break;

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
    case 3:
        editOrderMenu(orders, orderCount);
        break;
    case 4:
        deleteOrderMenu(orders, orderCount,maxId);
        break;
    case 5:
        ReportMenu(orders, orderCount,maxId);
        break;
    case 6:
        return false;
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