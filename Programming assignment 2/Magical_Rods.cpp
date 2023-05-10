#include <bits/stdc++.h>
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

ll partition(ll A[], ll p, ll r) 
{
    ll x = A[p]; // pivot
    ll i = p;
    ll j = r;
    while (1) 
    {

        while (A[i] > x) 
        {
            i++;
        }

        while (A[j] < x) 
        {
            j--;
        }
        if (i < j) 
        {
            ll temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        } 
        else 
        {
            return j;
        }
    }
}

void quicksort(ll A[], ll p, ll r) 
{
    if (p < r) 
    {
        ll q = partition(A, p, r);
        quicksort(A, p, q);
        quicksort(A, q + 1, r);
    }
}

// return the minimum number of visible Rods
ll minimumRods(ll arr[], ll n)
{
	// sorting the array
	quicksort(arr,0, n-1);

    Queue q;
    q.enQueue(arr[0]);
    
    ll count = 0;
	// traversing the array
	for (ll i = 1; i < n;) 
    {
		ll now = (q.front)->data;
        // cout<<now<<" "<<arr[i]<<"\n";
		if ( now >= 2*arr[i] )
        {
            q.deQueue();
            i++;
            if(i>=n)
                return q.size+count;
            count++;
        }
        else
        // Pushing each element of array
        q.enQueue(arr[i]);
        i+=1;
	}

	return q.size+count;
}

// // return the minimum number of visible rods
// ll minimumBoxs(ll arr[], ll n)
// {
//     queue<ll> q;
//     // ll count=1;
//     // sorting the array
//     sort(arr, arr + n, greater<int>());

//     q.push(arr[0]);

//     // traversing the array
//     for (ll i = 1; i < n; i++) {

//         ll now = q.front();

//         // checking if current element
//         // is greater than or equal to
//         // twice of front element
//         if (now>=2*arr[i])
//             q.pop();

//         // Pushing each element of array
//             q.push(arr[i]);
//     }

//     return q.size();
// }

int main()
{
    ll n;
    cin>>n;

    ll arr[n+1];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
        // arr[i] = (ll)(1e6);

	cout << minimumRods(arr, n) << endl;

    // while(1)
    // {
    //     srand(time(0)*time(0));
    //     ll N;
    //     N = rand()%(ll)(1e3)+1;
    //     cout<<N<<'\n';
    //     ll arr[N];
    //     for (ll i = 0; i < N; i++)
    //     {
    //         arr[i] = rand()%(ll)(1e6)+1;
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<"\n";

    //     ll countEx, countr;
    //     countr = minimumRods(arr, N);
    //     countEx = minimumBoxs(arr, N);

    //     if(countEx!=countr)
    //     {
    //         printf("Wrong\n");
    //         printf("Expected: \n");
    //         for(int i=0; i<N; i++)
    //         {
    //             printf("%lld ", countEx);
    //         }
    //         printf("\n");
    //         printf("Result: \n");
    //         for(int i=0; i<N; i++)
    //         {
    //             printf("%lld ", (countr));
    //         }
    //         printf("\n");
    //         break;
    //     }
    //     else
    //     {
    //         cout<<countr<<endl;
    //         printf("Correct\n");
    //     }
    //     printf("\n");
    // }
	return 0;
}
