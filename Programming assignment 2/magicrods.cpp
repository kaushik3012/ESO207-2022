// CPP program to count number of visible rods.
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

//Creating node for the queue
struct QNode
{
    ll data;
    QNode* next;
    QNode(ll d)
    {
        data = d;
        next = NULL;
    }
};
 
//Structure for the Queue data structure
struct Queue
{
    QNode *front, *rear;
    ll size;

    Queue()
    {
        front = rear = NULL;
        size=0;
    }

    //Function to push element into the rear of queue
    void enQueue(ll x)
    {
 
        // Create a new LL node
        QNode* temp = new QNode(x);
 
        // If queue is empty, then new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            size++;
            return;
        }
 
        // Add the new node at the end of queue and change rear
        rear->next = temp;
        rear = temp;
        size++;
    }
 
    // Function to remove the front from given queue
    int deQueue()
    {
        // If queue is empty, return NULL.
        if ((front == NULL) || (rear == NULL))
        {
            size=0;
            return -1;
        }
 
        // Store previous front and move front one node ahead
        QNode* temp = front;
        front = front->next;
 
        // If front becomes NULL, then change rear also as NULL
        if (front == NULL)
            rear = NULL;
 
        delete(temp);
        size--;
        return 1;
    }
};

// return the minimum number of visible rods
ll minimumRods(ll arr[], ll n)
{
    Queue q;

    // sorting the array
    sort(arr, arr + n);

    q.enQueue(arr[0]);

    // traversing the array
    for (ll i = 1; i < n; i++) {

        ll now = (q.front)->data;

        // checking if current element
        // is greater than or equal to
        // twice of front element
        if (arr[i] >= 2 * now)
            q.deQueue();

        // Pushing each element of array
        q.enQueue(arr[i]);
    }

    return q.size;
}

// driver Program
int main()
{
    ll n;
    cin>>n;

    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    cout << minimumRods(arr, n) << endl;
    return 0;
}