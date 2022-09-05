#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int rear = -1, front = -1;
    int size, *q;
};
void creare_queue(Queue *Q, int size)
{
    Q->size = size;
    Q->q = new int(Q->size);
}
void Enqueue(Queue *Q, int d)
{
    if (Q->rear == Q->size - 1)
        cout << "Queue is full !";
    else
    {
        Q->rear++;
        Q->q[Q->rear] = d;
    }
}
int Dequeue(Queue *Q)
{
    int x = -1;
    if (Q->front == Q->rear)
        {cout << "Queue is empty !";
        Q->rear=Q->front=-1;}
    else
    {
        Q->front++;
        x = Q->q[Q->front];
        // delete Q->q[Q->front];
    }
    return x;
}
void display(Queue Q)
{
    for (int i = Q.front + 1; i <= Q.rear; i++)
        cout << Q.q[i] << " ";
    cout << endl;
}

int main()
{
    Queue Q;
    int size;
    cout << "Enter the size of the Queue: ";
    cin >> size;
    creare_queue(&Q, size);
    Enqueue(&Q, 1);
    display(Q);
    Enqueue(&Q, 2);
    display(Q);
    Enqueue(&Q, 3);
    display(Q);
    Enqueue(&Q, 4);
    display(Q);
    Enqueue(&Q, 5);
    display(Q);
    cout << Dequeue(&Q) << endl;
    cout << Dequeue(&Q) << endl;
    cout << Dequeue(&Q) << endl;
    cout << Dequeue(&Q) << endl;
    cout << Dequeue(&Q) << endl;
    cout << Dequeue(&Q) << endl;
    //display(Q);
    Enqueue(&Q, 1);
    display(Q);
    Enqueue(&Q, 2);
    display(Q);
    return 0;
}